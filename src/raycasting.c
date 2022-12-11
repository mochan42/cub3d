/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:21:47 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/11 17:30:24 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    init_graphics(t_prg *v)
{
    v->graphics.cameraX = 0;
    v->graphics.deltaDistX = 0;
    v->graphics.deltaDistY = 0;
    v->graphics.hit = 0;
    v->graphics.side = 0;
}

void    fill_background(t_prg *v)
{
    int row;
    int col;
    int background_color;
    
    row = 0;
    background_color = 0x0000FFFF;
    while (row < SCR_HEIGHT)
    {
        col = 0;
        while(col < SCR_WIDTH)
        {
            my_mlx_pixel_put(&v->data, col, row, background_color);
            col++;
        }
        row++;
    }
}


void    raycasting(t_prg *v)
{
    int x;

    fill_background(v);
    x = 0;
    while (x < SCR_WIDTH)
    {    
        // printf("--⬇️ -- x = %d --------------------------------------------------------\n", x);
        v->graphics.cameraX = 2 * x / (double)SCR_WIDTH - 1;
        v->graphics.rayDirX = v->player.dirX + v->camera.planeX * v->graphics.cameraX;
        v->graphics.rayDirY = v->player.dirY + v->camera.planeY * v->graphics.cameraX;
        // printf("DirX =%f\n", v->player.dirX);
        // printf("DirY =%f\n", v->player.dirY);
        // printf("planeX =%f\n", v->camera.planeX);
        // printf("planeY =%f\n", v->camera.planeY);
        // printf("cameraX =%f\n", v->graphics.cameraX);
        // printf("rayDirX =%f\n", v->graphics.rayDirX);
        // printf("rayDirY =%f\n", v->graphics.rayDirY);

        v->graphics.mapX = (int)v->player.posX;
        v->graphics.mapY = (int)v->player.posY;
        // printf("mapX @Init = %d, \n", v->graphics.mapX);
        // printf("mapY @Init = %d, \n", v->graphics.mapY);
        v->graphics.deltaDistX = (v->graphics.rayDirX == 0) ? 1e30 : fabs(1/v->graphics.rayDirX);
        v->graphics.deltaDistY = (v->graphics.rayDirY == 0) ? 1e30 : fabs(1/v->graphics.rayDirY);
        
        if (v->graphics.rayDirX < 0)
        {
            v->graphics.stepX = -1;
            v->graphics.sideDistX = (v->player.posX - v->graphics.mapX) * v->graphics.deltaDistX;
        }
        else
        {
            v->graphics.stepX = 1;
            v->graphics.sideDistX = (v->graphics.mapX + 1.0 - v->player.posX) * v->graphics.deltaDistX;
        }
        if (v->graphics.rayDirY < 0)
        {
            v->graphics.stepY = -1;
            v->graphics.sideDistY = (v->player.posY - v->graphics.mapY) * v->graphics.deltaDistY;
        }
        else
        {
            v->graphics.stepY = 1;
            v->graphics.sideDistY = (v->graphics.mapY + 1.0 - v->player.posY) * v->graphics.deltaDistY;
        }
        
        int hit_counter;
            
        hit_counter = 0;
        v->graphics.hit = 0;
        while (v->graphics.hit == 0)
        {

            // printf("hit_counter =%d / v->graphics.mapY =%d\n", hit_counter, v->graphics.mapY);
            
            //jump to next map square, either in x-direction, or in y-direction
            if (v->graphics.sideDistX < v->graphics.sideDistY)
            {
                v->graphics.sideDistX += v->graphics.deltaDistX;
                v->graphics.mapX += v->graphics.stepX;
                v->graphics.side = 0;
            }
            else
            {
                v->graphics.sideDistY += v->graphics.deltaDistY;
                v->graphics.mapY += v->graphics.stepY;
                v->graphics.side = 1;
            }
            //Check if ray has hit a wall
            if (v->map[v->graphics.mapY][v->graphics.mapX] == '1')
                v->graphics.hit = 1;
            hit_counter++;
        } 

        // printf("mapX @End Of Loop = %d, \n", v->graphics.mapX);
        // printf("mapY @End Of Loop = %d, \n", v->graphics.mapY);
        
        if(v->graphics.side == 0)
        {
            // printf("sideDistX = %f\n", v->graphics.sideDistX);
            // printf("perpWallDist => Y ,");
            // printf("sideDistX =%f, deltaDistX =%f, \n", v->graphics.sideDistX, v->graphics.deltaDistX);
            v->graphics.perpWallDist = (v->graphics.sideDistX - v->graphics.deltaDistX);
        }    
        else
        {
            // printf("sideDistY = %f\n", v->graphics.sideDistY);
            // printf("perpWallDist => Y ,");
            // printf("sideDistY =%f, deltaDistY =%f, \n", v->graphics.sideDistY, v->graphics.deltaDistY);
            v->graphics.perpWallDist = (v->graphics.sideDistY - v->graphics.deltaDistY);
        }

        v->graphics.lineHeight = (int)(SCR_HEIGHT / v->graphics.perpWallDist);
        
        v->graphics.drawStart = v->graphics.lineHeight * (-1) / 2 + SCR_HEIGHT / 2;
        if(v->graphics.drawStart < 0)
            v->graphics.drawStart = 0;

        v->graphics.drawEnd = v->graphics.lineHeight / 2 + SCR_HEIGHT / 2;
        if(v->graphics.drawEnd >= SCR_HEIGHT)
            v->graphics.drawEnd = SCR_HEIGHT - 1;
        
        // printf("x =%d, perpWallDist =%f, lineHeight =%d, drawStart =%d ,drawEnd =%d \n", 
        // x,
        // v->graphics.perpWallDist,
        // v->graphics.lineHeight,
        // v->graphics.drawStart,
        // v->graphics.drawEnd);

        if (v->map[v->graphics.mapY][v->graphics.mapX] == '1')
        {
            if (v->graphics.side == 1 && v->graphics.rayDirY < 0)
                v->graphics.color = RGB_RED;
            if (v->graphics.side == 1 && v->graphics.rayDirY > 0)
                v->graphics.color = RGB_YELLOW;
            if (v->graphics.side == 0 && v->graphics.rayDirX < 0)
                v->graphics.color = RGB_GREEN;
            if (v->graphics.side == 0 && v->graphics.rayDirX > 0)
                v->graphics.color = RGB_BLUE;
        }
        
        int counter;
        counter = v->graphics.drawStart;
        while (counter < v->graphics.drawEnd)
        {
            my_mlx_pixel_put(&v->data, x, counter, v->graphics.color);
            counter++;
        }
        x++;  
    }
     mlx_put_image_to_window(v->data.mlx, v->data.mlx_win,v->data.img, 0, 0);
}