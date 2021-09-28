/*
** EPITECH PROJECT, 2021
** include/my_asprintf
** File description:
** my_asprintf
*/

#ifndef MY_ASPRINTF_H_
#define MY_ASPRINTF_H_

#define BUFFER_SIZE (1024)

typedef struct my_alloc_sprintf_s
{
    int fd;
    int buffsize;
    char *buff;
    char **str_ptr;
} msasprintf_t;

void asflush(msasprintf_t *m);
void fill_buff_ptr(msasprintf_t *m);
int my_asprintf(char **str_ptr, const char *format, ...);
void get_asflags(msasprintf_t *m, va_list ap, char const *str);
void asbasic_flag(msasprintf_t *m, va_list ap, char c);
void asputchar(msasprintf_t *m, char const c);
void asputstr(msasprintf_t *m, char *str);
void asputnbr(msasprintf_t *m, int nb);

#endif /* !MY_ASPRINTF_H_ */