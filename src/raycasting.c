/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:21:47 by moninechan        #+#    #+#             */
/*   Updated: 2022/12/07 23:47:03 by moninechan       ###   ########.fr       */
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

void    raycasting(t_prg *v)
{
    int x;

    x = 0;
    while (x < SCR_WIDTH)
    {    
        v->graphics.cameraX = 2 * x / (SCR_WIDTH) - 1;
        v->graphics.rayDirX = v->player.dirX + v->camera.planeX * v->graphics.cameraX;
        v->graphics.rayDirY = v->player.dirY + v->camera.planeY * v->graphics.cameraX;
        printf("x = %d - rayDirX =%f\n", x, v->graphics.rayDirX);
        printf("x = %d - rayDirY =%f\n", x, v->graphics.rayDirY);

        v->graphics.mapX = (int)v->player.posX;
        v->graphics.mapY = (int)v->player.posY;
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
        
        while (v->graphics.hit == 0)
        {
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
            if (v->map[v->graphics.mapX][v->graphics.mapY] == '1')
                v->graphics.hit = 1;
        } 

        if(v->graphics.side == 0)
            v->graphics.perpWallDist = (v->graphics.sideDistX - v->graphics.deltaDistX);
        else
            v->graphics.perpWallDist = (v->graphics.sideDistY - v->graphics.deltaDistY);
        

        v->graphics.lineHeight = (int)(SCR_HEIGHT / v->graphics.perpWallDist);
        
        v->graphics.drawStart = v->graphics.lineHeight * (-1) / 2 + SCR_HEIGHT / 2;
        if(v->graphics.drawStart < 0)
            v->graphics.drawStart = 0;

        v->graphics.drawEnd = v->graphics.lineHeight / 2 + SCR_HEIGHT / 2;
        if(v->graphics.drawEnd >= SCR_HEIGHT)
            v->graphics.drawEnd = SCR_HEIGHT - 1;
        
        printf("x =%d, perpWallDist =%f, lineHeight =%d, drawStart =%d ,drawEnd =%d \n", \
        x,
        v->graphics.perpWallDist,
        v->graphics.lineHeight,
        v->graphics.drawStart,
        v->graphics.drawEnd);

        if (v->map[v->graphics.mapX][v->graphics.mapY] == '1')
            v->graphics.color = RGB_RED;

        if (v->graphics.side == 1)
            v->graphics.color = v->graphics.color / 2;
        
        int counter;
        counter = v->graphics.drawStart;
        while (counter < v->graphics.drawEnd)
        {
            my_mlx_pixel_put(&v->data, x, counter, v->graphics.color);
            counter++;
        }
        x++;
    }

    // int h;
    // int w;
    // int x;
    // int y;
    
    // h = 100;
    // w = 200;
    // x = 10;
    // y = 20;

    // while (x < (w + 10))
    // {
    //     my_mlx_pixel_put(&v->data, x, 20, RGB_RED);
    //     x++;
    // }
    // x = 10;
    // while (x < (w + 10))
    // {
    //     my_mlx_pixel_put(&v->data, x, 120, RGB_GREEN);
    //     x++;
    // }

    // while (y < (h + 20))
    // {
    //     my_mlx_pixel_put(&v->data, 10, y, RGB_YELLOW);
    //     y++;
    // }
    // y = 20;
    // while (y < (h + 20))
    // {
    //     my_mlx_pixel_put(&v->data, 210, y, RGB_BLUE);
    //     y++;
    // }
    
    
}