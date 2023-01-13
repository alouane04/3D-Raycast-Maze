#include "cub3D.h"

void wallhitxy(t_data * data,float *hitx,float *hity, char c)
{
    if(c == 'x')
    {
        *hity =  floor(data->player->y / TILE_SIZE) * TILE_SIZE;
        if (!data->ray->is_ray_facing_up)
            *hity += TILE_SIZE;
        *hitx = data->player->x - (*hity - data->player->y) / tan(data->ray->ray_angle);
    }
    else
    {
		*hitx =  floor(data->player->x / TILE_SIZE) * TILE_SIZE;
        if (data->ray->is_ray_facing_right)
		    *hitx += TILE_SIZE;
	    *hity = data->player->y - 
                ((*hitx - data->player->x)* tan(data->ray->ray_angle));
    }
}

void stepxy(t_data *data, float *stepx, float *stepy, char c)
{
    if(c == 'x')
    {
        *stepy = TILE_SIZE;
	    if(data->ray->is_ray_facing_up)
		    *stepy *= -1;
        *stepx = TILE_SIZE / tan(data->ray->ray_angle);
        if ((*stepx > 0 && !data->ray->is_ray_facing_right) || (*stepx < 0 && data->ray->is_ray_facing_right)) 
            *stepx *= -1;
    }
    else
    {
        *stepx = TILE_SIZE;
        if(!data->ray->is_ray_facing_right)
            *stepx *= -1;
        *stepy = TILE_SIZE * tan(data->ray->ray_angle);
        if((*stepy > 0 && data->ray->is_ray_facing_up) || (*stepy < 0 && !data->ray->is_ray_facing_up)) 
            *stepy *= -1 ;
    }
}

int has_wall_at(t_data *data, int x, int y, char c)
{
	if(x >= data->num_cols || y >= data->num_rows 
        || x <= 0 || y <= 0)
		return(1);
    if(data->ray->is_ray_facing_right && c == 'v' )
	    if(data->input->map[y][x] == '1')
		    return (1);
    if(data->ray->is_ray_facing_up && c == 'h')
	    if(data->input->map[y - 1][x] == '1')
		    return (1);
    if(!data->ray->is_ray_facing_right && c == 'v' )
	    if(data->input->map[y][x - 1] == '1')
		    return (1);
    if(!data->ray->is_ray_facing_up && c == 'h')
	    if(data->input->map[y][x] == '1')
		    return (1);
    
	return(0);
}

void horizontal_intersection(t_data *data)
{
	float stepx;
	float stepy;
    float hitx;
    float hity;

    wallhitxy(data, &hitx, &hity,'x');
	stepxy(data, &stepx, &stepy, 'x');
	while (hitx >= 0 && hity >= 0 && hitx <= WINDOW_WIDTH && hity <= WINDOW_HEIGHT)
	{
		if (has_wall_at(data, (int)hitx / TILE_SIZE, (int)hity / TILE_SIZE, 'h'))
		{
			data->ray->wall_hithx = hitx;
            data->ray->wall_hithy = hity; 
			break;
		}
		hitx += stepx;
		hity += stepy;
	}
        if(hitx > WINDOW_WIDTH || hity > WINDOW_HEIGHT)
    {
        data->ray->wall_hithx = WINDOW_WIDTH;
        data->ray->wall_hithy = WINDOW_HEIGHT;
    }
}

void vertical_intersection(t_data *data)
{
	float stepx;
	float stepy;
    float hitx;
    float hity;

    wallhitxy(data, &hitx, &hity,'y');
    stepxy(data, &stepx, &stepy, 'y');
	while (hitx >= 0 && hity >= 0 && hitx <= WINDOW_WIDTH && hity <= WINDOW_HEIGHT)
	{
		if (has_wall_at(data, (int)hitx / TILE_SIZE, (int)hity / TILE_SIZE, 'v'))
		{
			data->ray->wall_hitvx= hitx;
			data->ray->wall_hitvy = hity;
			break;
		}
		hitx += stepx;
		hity += stepy;
	}
    if(hitx > WINDOW_WIDTH || hity > WINDOW_HEIGHT)
    {
        data->ray->wall_hitvx = WINDOW_WIDTH;
        data->ray->wall_hitvy = WINDOW_HEIGHT;
    }
}

void distance(t_data *data)
{
    float dsth;
    float dstv;
    
    dsth = sqrt(pow(data->ray->wall_hithx - data->player->x, 2) 
            + pow(data->ray->wall_hithy - data->player->y, 2));
    dstv = sqrt(pow(data->ray->wall_hitvx - data->player->x, 2) 
            + pow(data->ray->wall_hitvy - data->player->y, 2));
    if(dsth < dstv)
    {
        data->ray->distance = dsth;
        data->ray->was_hit_vertical = 0;
    }
    else
    {
        data->ray->distance = dstv;
        data->ray->was_hit_vertical = 1;
    }
}