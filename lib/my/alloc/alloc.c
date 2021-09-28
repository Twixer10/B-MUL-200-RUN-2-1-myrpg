/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-anthony.vienne
** File description:
** my_alloc
*/

#include "../../../include/my.h"

void *my_memset(void *v, char c, size_t size)
{
    int i = 0;
    unsigned char *tmp = v;

    while (i < size) {
        tmp[i] = c;
        i++;
    }
    return (v);
}

void *my_calloc(size_t mem, size_t size)
{
    void *ptr = malloc(mem * size);

    if (!ptr)
        return (NULL);
    my_memset(ptr, 0, mem * size);
    return (ptr);
}

void *mmemcpy(void *dest, void const *src, size_t size)
{
    unsigned char const *src_cpy = src;
    unsigned char *dest_cpy = dest;

    for (int counter = 0; counter < size; counter++)
        dest_cpy[counter] = src_cpy[counter];
    return (dest);
}

void *mrealloc(void *ptr, size_t osiz, size_t nsiz)
{
    if (!nsiz)
        return (NULL);
    else if (nsiz <= osiz)
        return (ptr);
    else
        return (do_realloc(ptr, osiz, nsiz));
}

void *do_realloc(void *ptr, size_t osiz, size_t nsiz)
{
    void *new_ptr = my_calloc(1, nsiz);

    if (ptr)
        mmemcpy(new_ptr, ptr, osiz);
    free(ptr);
    ptr = new_ptr;
    return (ptr);
}