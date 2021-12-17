/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:53:38 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/11/29 23:53:41 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	main(int n, char **args)
{
	if (n < 2)
		ft_printerr();
	ft_v(S | RENDER, ft_decide(args[1], 0));
	if (ft_v(G | RENDER, 0) == 0)
		ft_printerr();
	if (ft_v(G | RENDER, 0) == 2 && n >= 3)
		ft_v(S | JULTYPE, ft_decide(args[2], 1));
	ft_init();
	ft_instruct();
	ft_vp(S | 0, mlx_init());
	ft_vp(S | 1, mlx_new_window(ft_vp(G | 0, 0),
			ft_v(G | WX, 0), ft_v(G | WY, 0), ""));
	mlx_key_hook(ft_vp(G | 1, 0), ft_key, 0);
	mlx_mouse_hook(ft_vp(G | 1, 0), ft_mouse, 0);
	ft_print(ft_vp(G | 0, 0), ft_vp(G | 1, 0));
	mlx_loop(ft_vp(G | 0, 0));
	return (0);
}
