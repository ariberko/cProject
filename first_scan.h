#ifndef FIRST_SCAN_H
#define FIRST_SCAN_H

#include <stdio.h>
#include "preprocessor.h"

// Global variables
extern char *double_word_list[9];
extern char *triple_word_list[5];

// Function prototypes
int double_word(char *line);
int print_error(char *line);
int in_list(char *word, char *list[]);
int treat_single_word(char *line);
int treat_double_word(char *line);
int treat_triple_word(char *line);
int treat_data(char line[]);
int treat_string(char line[]);
int is_entry(char line[]);
int is_extern(char line[]);
int treat_instruction(char *line);
int treat_order(char *line);
void ignore_line();
int includes_instruction(char line[]);
int empty_line(char line[]);
int is_line_valid(char line[]);
int treat_error(char line[]);
int first_scan_process_line(char line[]);
int first_scan(const char *fileName);
int includes_order(char line[]);
int valid_order_syntax(char line[]);
int single_word(char line[]);


#endif // FIRST_SCAN_H
