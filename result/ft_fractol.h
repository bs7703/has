/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:38:47 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/11/29 23:40:44 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H

# define FT_FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define REPEAT 256
# define ESC 0x35
# define RST 0x23
# define WINX 800
# define WINY 800
# define SCUP 4
# define SCDN 5
# define RENDER 5
# define ZGR 2
# define KEY 0
# define WX 16
# define WY 17
# define X 18
# define Y 19
# define Z 20
# define JULX 21
# define JULY 22
# define JULTYPE 23
# define SET0 500
# define G 128
# define S 256
# define JULG 0.025f
# define POINTER 512
# define NUMBER 127
# define IV 0
# define BS 1
# define RS 2
# define RK 124
# define LK 123
# define UK 126
# define DK 125
# define AKS 0
# define DKS 2
# define SKS 1
# define WKS 13

int		ft_rgb(int red, int green, int blue, int filter);
int		ft_v(int type, int value);
float	ft_vd(int type, float value);
void	*ft_vp(int type, void	*value);
int		ft_key(int key);
int		ft_mouse(int button, int x, int y);
int		ft_cal(float x, float y);
int		ft_cal2(float x, float y);
void	ft_printf(char *str);
void	ft_printerr(void);
int		ft_strstr(char *to, char *find);
int		ft_decide(char *str, int type);
void	ft_instruct(void);
void	ft_init(void);
int		ft_color(int depth);
void	ft_paint(int x, int y, float z);
int		ft_print(void *p, void *q);

#endif
