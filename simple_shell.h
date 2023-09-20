#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/* write and read buffers */
#define W_BUFF_SIZE 1024
#define BUFF_FLUSH -1
#define R_BUFF_SIZE 1024

/* str_f.c */
int com_str(char *str1, char *str2);
int length_str(char *str);
char *concat_str(char *destination, char *source);
int check_start(const char *substring, const char *hay);

/* str_f_II.c */
char *_dup(const char *word);
char *_cpy(char *pasted, char *copied);
void _view(char *txt);
int _putchr(char a);

/* str_f_III.c */
char *_limconcat(char *txt1, char *txt2, int max);
char *_limcpy(char *txt2, char *txt1, int max);
char *_chrfind(char *txt, char chr);

/*str_f_IV.c */
char **strsplit(char *txt, char *del);
char **strsplit2(char *txt, char del);

/* m_operationI.c */
void m_free(char **ss);
char *m_setting(char *m, char v, unsigned int num);
void *re_allo(void *r, unsigned int new_s, unsigned int prev_s);


/* m_operationII.c */
int ptr_free(void **p);

/* operation_1.c */
int check_delimit( char ch, char *del);

#endif
