/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:31:22 by ychng             #+#    #+#             */
/*   Updated: 2024/07/17 05:32:08 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	key_press(int keycode, t_main *main)
{
	if (!(keycode >= 0 && keycode <= KEY_COUNT))
		exit_with_error("can't support keys range.");
	if (main->key_states[keycode] == 0)
		main->key_states[keycode] = 1;
	return (PASS);
}

int	key_release(int keycode, t_main *main)
{
	if (!(keycode >= 0 && keycode <= KEY_COUNT))
		exit_with_error("can't support keys range.");
	if (main->key_states[keycode] == 1)
		main->key_states[keycode] = 0;
	return (PASS);
}

void	apply_keystates(t_main *main)
{

	if (main->key_states[UBUNTU_ESC])
	{
		mlx_destroy_window(main->minilibx.mlx, main->minilibx.win);
		exit(PASS);
	}
	if (main->key_states[UBUNTU_LEFT_ARROW])
		rotate_player(main, -1);
	if (main->key_states[UBUNTU_RIGHT_ARROW])
		rotate_player(main, 1);
	if (main->key_states[UBUNTU_W_KEY])
		move_forward_backward(main, 1);
	if (main->key_states[UBUNTU_S_KEY])
		move_forward_backward(main, -1);
	if (main->key_states[UBUNTU_D_KEY])
		move_left_right(main, 1);
	if (main->key_states[UBUNTU_A_KEY])
		move_left_right(main, -1);
}