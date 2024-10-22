#include "./mlx/mlx.h"
#include <stdio.h>

# define W 800
# define H 800

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

void    my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex sqr_complex(t_complex z);
double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
double  atod(char *s);
int f_strncmp(char *s1, char *s2, int n);