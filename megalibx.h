/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megalibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:16:51 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/22 11:49:12 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGALIBX_H
# define MEGALIBX_H

# include "minilibx_macos/mlx.h"
# include <fcntl.h>

# define SIZE_X 1920
# define SIZE_Y 1080
# define BG_COLOR 0
# define STEP_ZOOM 10
# define STEP_MOVE 30

typedef enum e_x11event
{
    KEY_PRESS = 2,
    KEY_RELEASE = 3,
    BUTTON_PRESS = 4,
    BUTTON_RELESE = 5,
    MOTION_NOTIFY = 6,
    ENTER_NOTIFY = 7,
    LEAVE_NOTIFY = 8,
    FOCUS_IN = 9,
    FOCUS_OUT = 10,
    KEYMAP_NOTIFY = 11,
    EXPOSE = 12,
    GRAPHICS_EXPOSE = 13,
    NO_EXPOSE = 14,
    VISIBILITY_NOTIFY = 15,
    CREATE_NOTIFY = 16,
    DESTROY_NOTIFY = 17,
    UNMAP_NOTIFY = 18,
    MAP_NOTIFY = 19,
    MAP_REQUEST = 20,
    REPARENT_NOTIFY = 21,
    CONFIGURE_NOTIFY = 22,
    CONFIGURE_REQUEST = 23,
    GRAVITY_NOTIFY = 24,
    RESIZE_REQUEST = 25,
    CIRCULATE_NOTIFY = 26,
    CIRCULATE_REQUEST = 27,
    PROPERTY_NOTIFY = 28,
    SELECTION_CLEAR = 29,
    SELECTION_REQUEST = 30,
    SELECTION_NOTIFY = 31,
    COLORMAP_NOTIFY = 32,
    CLIENT_MESSAGE = 33,
    MAPPING_NOTIFY = 34,
    GENERIC_EVENT = 35,
    LAST_EVENT = 36,
}                t_x11event;

typedef enum e_key
{
    KEY_A = 0,
    KEY_B = 11,
    KEY_C = 8,
    KEY_D = 2,
    KEY_E = 14,
    KEY_F = 3,
    KEY_G = 5,
    KEY_H = 4,
    KEY_I = 34,
    KEY_J = 38,
    KEY_K = 40,
    KEY_L = 37,
    KEY_M = 46,
    KEY_N = 45,
    KEY_O = 31,
    KEY_P = 35,
    KEY_Q = 12,
    KEY_R = 15,
    KEY_S = 1,
    KEY_T = 17,
    KEY_U = 32,
    KEY_V = 9,
    KEY_W = 13,
    KEY_X = 7,
    KEY_Y = 16,
    KEY_Z = 6,
    KEY_ZERO = 29,
    KEY_ONE = 18,
    KEY_TWO = 19,
    KEY_THREE = 20,
    KEY_FOUR = 21,
    KEY_FIVE = 23,
    KEY_SIX = 22,
    KEY_SEVEN = 26,
    KEY_EIGHT = 28,
    KEY_NINE = 25,
    KEY_BRACE_R = 30,
    KEY_BRACE_L = 33,
    KEY_TAB = 48,
    KEY_PLUS = 69,
    KEY_MINUS = 78,
    KEY_SEMI = 41,
    KEY_LEFT = 123,
    KEY_RIGHT = 124,
    KEY_DOWN = 125,
    KEY_UP = 126,
    KEY_ESCAPE = 53,
    KEY_LESS = 43,
    KEY_GREATER = 47,
    KEY_SPACE = 49,
    KEY_PAGE_UP = 116,
    KEY_PAGE_DOWN = 121,
    KEY_F2 = 120,
}                t_key;

typedef struct s_color_rgb {
	int	r;
	int	g;
	int	b;
}	t_color_rgb;

typedef struct s_coord_2d {
	int	x;
	int	y;
}	t_coord_2d;

typedef struct s_coord_3d {
	int	x;
	int	y;
	int	z;
}	t_coord_3d;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point_2d {
	t_coord_2d	coord;
	int			color;
}	t_point_2d;

typedef struct s_point {
	t_coord_3d	coord;
	int			color;
}	t_point;

typedef struct s_camera {
	t_coord_3d	coord;
	int			zoom;
}	t_camera;

typedef struct s_global {
	void		*mlx;
	void		*win;
	t_data		data;
	t_camera	*camera;
	int			input[256];
}	t_global;

typedef struct s_gradient {
	int	color1;
	int	color2;
	int	step;
	int	step_max;
}	t_gradient;

int			ft_get_int_color(t_color_rgb rgb);
t_color_rgb	ft_get_struct_color(int color);
int			ft_get_color_gradient(t_gradient gradient);

void		ft_draw_line(t_data *data, t_coord_2d c1, t_coord_2d c2, t_gradient grad);

t_global	*ft_init_mlx(void);

void		ft_put_pixel(t_data *data, t_coord_2d coord, int color);

t_coord_2d	ft_isometric(t_coord_3d coord, t_camera *cam);

#endif