#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/* string_functions.c */
int com_str(char *str1, char *str2);
int length_str(char *str);
char *concat_str(char *destination, char *source);
int check_start(const char *substring, const char *hay);

/* m_operationI.c */
void m_free(char **ss);
char *m_setting(char *m, char v, unsigned int num);
void *re_allo(void *r, unsigned int new_s, unsigned int prev_s);


/* m_operationII.c */
int ptr_free(void **p);


#endif
