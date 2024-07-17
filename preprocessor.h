#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <stdio.h>

// Function declarations

// Checks if the current line contains a macro order
int check_macro(char line[]);

// Opens a file for reading
int open_file_read(FILE **fp, const char *fileName);

// Opens a file for writing
int open_file_write(FILE **fp, const char *fileName);

// Gets the next line from a file
char *get_next_line(FILE *fp);

// Marks a line for deletion or skip processing
void delete_line(void);

// Gets the first character of a line
char first_char(char line[]);

// Copies a line to an output file
void copy_paste(char line[], FILE *output_file);

// Arranges blanks in a line (trim leading/trailing spaces, reduce multiple spaces)
void arrange_blanks_in_line(char line[]);

// Adds a macro line to the output file
void add_macro(char line[], FILE *output_file);

// Saves a macro to dynamic storage
void save_macro(char line[]);

// Processes a line based on its content
int process_line(char line[], FILE *output_file);

// Preprocesses the input file
int preprocessor(const char *fileName);

#endif // PREPROCESSOR_H
