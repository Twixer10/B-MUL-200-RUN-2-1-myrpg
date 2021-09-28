/*
** EPITECH PROJECT, 2020
** MY LYB
** File description:
** MY EPITECH LIB FOR C PROGRAMING
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_asprintf.h"
#define BASE_X "0123456789ABCDEF"
#define BASE_MINX "0123456789abcdef"
#define BASE_O "01234567"
#define CNULL(src, ret)              \
if (src == NULL)                     \
return (ret);
#define MALLOC(src, size, ret)       \
src = malloc(size);                  \
if (!(src))                          \
return (ret);
typedef int my_bool;
#define TRUE 1
#define FALSE 0
#define UNUSED __attribute__((unused))

//alloc
void delete_string(char **bin);
void delete_array(char ***bin);
void *my_calloc(size_t mem, size_t size);
void *my_memset(void *v, char c, size_t size);
void *mmemcpy(void *rec, void const *src, size_t size);
void *do_realloc(void *ptr, size_t osiz, size_t nsiz);
void *mrealloc(void *ptr, size_t osiz, size_t nsiz);
//array
int nb_split(char *str, char op);
int len_split(char *str, char op);
char **my_split(char *str, char op);
int nb_stwa(const char *str);
int len_stwa(const char *str);
char **stwa(char const *str);
char **my_strtok(char *str, char delim);
//char
int char_is_op(char c, char op);
int char_is_chariot(char c, char cn);
int char_is_alpha_num(char c);
//get
int str_len(char const *str);
int array_len(char **array);
int get_nbr_char(char str);
int get_nbr(char const *str);
char *get_only_nbr(char *str);
int get_nbr_from_ptn(char **s);
char *my_itoa(int nb);
//my_printf
void my_printf(char const *str, ...);
void get_flags(va_list ap, char const *str);
void basic_flag(int i, va_list ap, char const *str);
void get_long(int i, va_list ap, char const *str);
void get_short(int i, va_list ap, char const *str);
void put_base_nbr(int nb, char *base);
void put_bin(int nb);
void put_unbr(unsigned int nb);
void put_add_pointer(long int nb);
void lflag(int i, va_list ap, char const *str);
void put_base_lnbr(long int nb, char *base);
void put_lnbr(long int nb);
void put_lunbr(unsigned long int nb);
void hflag(int i, va_list ap, char const *str);
void put_hnbr(short int nb);
void put_hunbr(unsigned short int nb);
void put_all_str(char *str);
void cond_all_str(int i, char *str);
//number
int is_neg(int n);
int is_prime(int nb);
int find_prime_sup(int nb);
int my_pow(int nb, unsigned int pow);
void my_swap(int *a, int *b);
int compute_square_root(int nb);
//string
char *str_lowcase(char *str);
char *str_upcase(char *str);
int is_lower(char const *str);
int is_upper(char const *str);
int is_alpha(char const *str);
int is_alphanum(char const *str);
int is_printable(char const *str);
int is_num(char const *str);
int str_cmp(char const *s1, char const *s2);
int str_ncmp(char const *s1, char const *s2, int n);
char *str_concat(char *dest , char  const *src);
char *str_nconcat(char *dest , char  const *src , int nb);
char *str_dup(char const *src);
char *str_cpy(char *dest, char const *src);
char *str_ncpy(char *dest, char const *src, int n);
char *rev_str(char *str);
char *trim(char *str);
char *clean_str(char *str);
char *remove_chariot(const char *str);
//write
void put_char(char c);
void put_cher(char c);
int put_nbr(int nb);
int put_str(char const *str);
int put_sterr(char *str);
//utility
int check_args(char **av, int i, char *arg);
int my_error(char *str, int err);

#endif /* !MY_H_ */