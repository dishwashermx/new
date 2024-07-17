/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 06:09:53 by ychng             #+#    #+#             */
/*   Updated: 2024/07/17 15:37:33 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_rays(t_main *main)
{
	int			i;
	t_points	points;
	t_ray		*ray;

	i = 0;
	while (i < main->raycast.num_of_rays)
	{
		ray = &main->raycast.rays[i];
		points.x0 = main->player.center_x;
		points.y0 = main->player.center_y;
		points.x1 = points.x0 + cos(ray->ray_angle) * LINE_LENGTH;
		points.y1 = points.y0 + sin(ray->ray_angle) * LINE_LENGTH;
		dda(main, &points);
		i++;
	}
}

void	cast_rays(t_main *main)
{
	t_ray	*ray;
	int		columnid;
	double	offset;
	double	angle_inc;
	double	ray_angle;

	columnid = 0;
	offset = main->raycast.fov_angle / 2;
	ray_angle = normalize_angle(main->player.rotation_angle - offset);
	while (columnid < main->raycast.num_of_rays)
	{
		ray = &main->raycast.rays[columnid];
		ray->columnid = columnid;
		ray->ray_angle = ray_angle;
		ray->is_facing_down = is_ray_facing_down(ray_angle);
		ray->is_facing_up = !ray->is_facing_down;
		ray->is_facing_right = is_ray_facing_right(ray_angle);
		ray->is_facing_left = !ray->is_facing_right;
		angle_inc = main->raycast.fov_angle / main->raycast.num_of_rays;
		ray_angle += normalize_angle(angle_inc);
		columnid++;
	}
	draw_rays(main);
}