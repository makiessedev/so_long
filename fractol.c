#include "fractol.h"

void    my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void show(t_mlx_data *img, int offset_x, int offset_y)
{
    int x = 0;
    int y = 0;
    while (x < 1000)
    {
        y = 0;
        while (y < 800)
        {
            if (((x - 500)*(x - 500) + (y - 400) * (y - 400) < 100*100) && (x - 500)*(x - 500) + (y - 400) * (y - 400) > 99*99)
                my_mlx_pixel_put(img, x + offset_x, y + offset_y, 0x00FF00);
            y++;
        }
        x++;
    }
}

t_complex   sum_complex(t_complex ca, t_complex cb)
{
    t_complex res;

    res.im = (ca.im + cb.im);
    res.re = (ca.re + cb.re);
    return (res);
}

t_complex   mult_complex(t_complex ca, t_complex cb)
{
    t_complex res;

    res.re = ca.re * cb.re - ca.im * cb.im;
    res.im = ca.re * cb.im + cb.re * ca.im;
    return (res);
}