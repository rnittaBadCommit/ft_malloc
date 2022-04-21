#include <stdlib.h>
#include "ft_malloc.h"

void    func()
{
    int    *p;

    p = ft_malloc(sizeof(int) * 5);
    ft_malloc(sizeof(char **) * 20);
}

int main(void)
{
    char    *s;

    s = ft_malloc(100);
    func();
    ft_free_all();
}
