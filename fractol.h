#include "./mlx/mlx.h"
#include <stdio.h>

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_img;

typedef struct s_complex
{
    double x;
    double y;
} t_complex;

typedef struct s_fractol
{
    char    *name;
    void    *mlx_connection;
    void    *mlx_window;
    t_img   img;
    double  escape_value;
    int iterations_definition;
    double  shift_x;
    double  shift_y;
    double  zoom;
    double  julia_x;
    double  julia_y;
}   t_fractal;

void    my_mlx_pixel_put(s_img *data, int x, int y, int color);
void show(s_img *img, int offset_x, int offset_y);
t_complex   sum_complex(t_complex ca, t_complex cb);
t_complex   mult_complex(t_complex ca, t_complex cb);