#include "cub3D.h"

void generate_3d_projection(t_data *data ,int i)
{
    float dst_project_plane;
    float project_wallheight;
    int wall_top_pixel;
    int wall_bottom_pixel;
    int pix;

    dst_project_plane = (WINDOW_WIDTH / 2) / tan(data->fov / 2);
    project_wallheight = (TILE_SIZE / (data->ray->distance * cos(data->ray->ray_angle - data->player->rotationAgnles))) * dst_project_plane;
    wall_top_pixel = (int)((WINDOW_HEIGHT / 2) - (project_wallheight / 2));
    wall_bottom_pixel =(int)((WINDOW_HEIGHT / 2) + (project_wallheight / 2));
    if (wall_top_pixel < 0)
        wall_top_pixel = 0;
    if(wall_bottom_pixel > WINDOW_HEIGHT)
        wall_bottom_pixel = WINDOW_HEIGHT;
    pix = wall_top_pixel;
    while(pix < wall_bottom_pixel)
    {
        // here fction for textures instead of the bellow
        my_mlx_pixel_put(data, i, pix, 0x00ffffff);
        pix++;
    }
}