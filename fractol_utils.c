#include "fractol.h"

static void ft_my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(img->addr + offset) = color;
}

static void mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if (ft_strncmp(fractal->name, "julia", 5))
    {
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
    }
    else
    {
        c->x = z->x;
        c->y = z->y; 
    }
}

static void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    i = 0;
    z.x = (map(x, -2, +2, 0, W) * fractal->zoom) + fractal->shift_x;
    z.y = (map(y, +2, -2, 0, H) * fractal->zoom) + fractal->shift_y;

    mandel_vs_julia(&z, &c, fractal);
    while (i < fractal->iterations_definition)
    {
        z = sum_complex(sqr_complex(z), c);
        if ((z.x * z.x) + (z.y + z.y) > fractal->escape_value)
        {
            color = map(i, 0x000000, 0XFFFFFF, 0, fractal->iterations_definition);
            ft_my_pixel_put(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    ft_my_pixel_put(x, y, &fractal->img, 0xFFFFFF);
}

void    ft_fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < H)
    {
        x = -1;
        while (++x < W)
            handle_pixel(x, y, fractal);
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.addr, 0, 0);
}