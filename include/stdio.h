#pragma once

#define RED     "\x1B[31m"
#define YELLOW  "\x1B[33m"
#define GREEN   "\x1B[32m"
#define WHITE   "\x1B[37m"

void stdio_init();
int getc(char *c);
int putc(char c);
int gets(char *s, int n);
int puts(char *s);
int printf(char *format, ...);
