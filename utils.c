#include "fractol.h"

int f_strncmp(char *s1, char *s2, int n)
{
    if (s1 == NULL || s2 == NULL || n <= 0)
        return (0);
    while (*s1 == *s2 && n > 0 && *s1 != '\0')
    {
        s1++;
        s2++;
        n--;
    }
    return (*s1 - *s2);
}

double  atod(char *s)
{
    long    int_part;
    double  frac_part;
    double  pow;
    int sign;

    int_part = 0;
    frac_part = 0;
    sign = +1;
    pow = 1;
    while ((*s >= 9 && *s <= 13) || *s == 32)
        s++;
    while (*s == '+' || *s == '-')
    {
        if (sign == '-')
            sign = -sign;
    }
    while (*s != '.' && *s)
        int_part = (int_part * 10) + (*s++ - 48);
    if (*s == '.')
        s++;
    while (*s)
    {
        pow /= 10;
        frac_part = frac_part + (*s++ - 48) * pow;
    }
    return ((int_part + frac_part) * sign);
}

double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_max;
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex res;
    res.x = z1.x + z2.x;
    res.y = z1.y + z2.y;
    return (res);
}

t_complex sqr_complex(t_complex z)
{
    t_complex res;
    res.x = (z.x * z.x) - (z.y * z.y);
    res.y = 2 * z.x * z.y;
    return (res);
}