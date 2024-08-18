#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants
#define LINE_SIZE 80
#define MAX_MACROS 100

// Global variables
extern char *macros[MAX_MACROS];
extern int num_macros;

// Function prototypes
int check_macro(char line[]);
int open_file_read(FILE **fp, const char *fileName);
int open_file_write(FILE **fp, const char *fileName);
char *get_next_line(FILE *fp);
void ignore_line(void);
char first_char(char line[]);
void copy_paste(char line[], FILE *output_file);
void arrange_blanks_in_line(char line[]);
void add_macro(char line[], FILE *output_file);
void save_macro(char line[]);
int process_line(char line[], FILE *output_file);
int preprocessor(const char *fileName);

struct macro_node 
{
    char macro_name[80];
    char *macro_content;
    struct macro_node* next;
};

#endif // PREPROCESSOR_H
