/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_wall_strips.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:31:08 by ychng             #+#    #+#             */
/*   Updated: 2024/07/27 00:25:11 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_rect(t_main *main, int width, int height, int i)
{
	int	start_y;
	int	start_x;
	int	y;
	int	x;

	start_y = (main->mapdata.m_height / 2) - (height / 2);
	start_x = i * width;
	y = start_y;
	while (y < (start_y + height))
	{
		x = start_x;
		while (x < (start_x + width))
		{
			if (is_within_win_bounds(main, x, y))
				pixel_put(&main->minilibx.image, x, y, rgb(255, 0, 0));
			x++;
		}
		y++;
	}
}

void	draw_wall_strip(t_main *main, int i)
{
	t_ray	*ray;
	double	correct_wall_distance;
	double	distance_projection_plane;
	int		wall_strip_height;

	ray = &main->raycast.rays[i];
	correct_wall_distance = \
		ray->distance * cos(ray->ray_angle - main->player.rotation_angle);
	distance_projection_plane = \
		(main->mapdata.m_width / 2) / tan(main->raycast.fov_angle / 2);
	wall_strip_height = \
		(TILE_SIZE / correct_wall_distance) * distance_projection_plane;
	draw_rect(main, main->raycast.wall_strip_width, wall_strip_height, i);
}

void	cast_wall_strips(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->raycast.num_of_rays)
	{
		draw_wall_strip(main, i);
		i++;
	}
}