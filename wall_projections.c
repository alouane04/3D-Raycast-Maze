#include "cub3D.h"

t_texturs *get_texture(t_data *data)
{
    if(!data->ray->was_hit_vertical && data->ray->is_ray_facing_up)
        return (data->texture[0]);
    if(!data->ray->was_hit_vertical && !data->ray->is_ray_facing_up)
        return (data->texture[1]);
    if(data->ray->was_hit_vertical && data->ray->is_ray_facing_right)
        return (data->texture[2]);
    else
        return (data->texture[3]);
}

void draw_text(t_data *data, int i, int y,int wall_bottom, double wall_height)
{
    int txt_x;
    int txt_y;
    int     offset;
    t_texturs *txt;

    txt = get_texture(data);
    
    if(data->ray->was_hit_vertical)
        txt_x = fmod(data->ray->wall_hitvy, TILE_SIZE) * (txt->width / TILE_SIZE);
    else
        txt_x = fmod(data->ray->wall_hithx, TILE_SIZE) * (txt->width / TILE_SIZE);
    
    while(y < wall_bottom)
    {
        offset = y +(wall_height- WINDOW_HEIGHT) / 2;
        txt_y =  offset * (txt->height / wall_height);
        my_mlx_pixel_put(data, i, y,((int *)txt->addr)[((txt->width * txt_y) + txt_x)]);
        y++;
    }
}

void generate_3d_projection(t_data *data ,int i)
{
    double dst_project_plane;
    double project_wallheight;
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
    draw_text(data, i, pix, wall_bottom_pixel, project_wallheight);
}