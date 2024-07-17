#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <stdio.h>

// Function to check if the current line contains a macro order
// Parameters:
//   line - a string containing the current line
// Returns:
//   1 if the current line contains a macro order, otherwise 0
int check_macro(char line[]);

// Function to open a file for reading
// Parameters:
//   fp - a pointer to a file pointer that will be set to the opened file
//   fileName - the name of the file to open
// Returns:
//   0 on success, 1 on failure
int open_file_read(FILE **fp, const char *fileName);

// Function to open a file for writing
// Parameters:
//   fp - a pointer to a file pointer that will be set to the opened file
//   fileName - the name of the file to open
// Returns:
//   0 on success, 1 on failure
int open_file_write(FILE **fp, const char *fileName);

// Function to get the next line from a file
// Parameters:
//   fp - a pointer to a file pointer from which to read the line
// Returns:
//   A pointer to the next line, or NULL if end of file is reached
char *get_next_line(FILE **fp);

// Function to mark a line for deletion or skip processing
// No parameters or return value, functionality can be defined as needed
void delete_line();

// Function to get the first character of a line
// Parameters:
//   line - a string containing the current line
// Returns:
//   The first character of the line, or '\0' if the line is empty
char first_char(char line[]);

// Function to copy a line to an output file
// Parameters:
//   line - a string containing the line to copy
//   output_file - a file pointer to the output file
// No return value
void copy_paste(char line[], FILE *output_file);

// Function to arrange blanks in a line (trim leading/trailing spaces, reduce multiple spaces)
// Parameters:
//   line - a string containing the line to arrange
// No return value
void arrange_blanks_in_line(char line[]);

// Function to add a macro line to the output file
// Parameters:
//   line - a string containing the macro line to add
//   output_file - a file pointer to the output file
// No return value
void add_macro(char line[], FILE *output_file);

// Function to save a macro to dynamic storage
// Parameters:
//   line - a string containing the macro line to save
// No return value
void save_macro(char line[]);

// Function to process a line based on its content
// Parameters:
//   line - a string containing the current line
//   output_file - a file pointer to the output file
// Returns:
//   0 on success, or an appropriate error code
int process_line(char line[], FILE *output_file);

// Function to preprocess the input file
// Parameters:
//   fileName - the name of the input file to preprocess
// Returns:
//   0 on success, 1 on failure
int preprocessor(const char *fileName);

#endif // PREPROCESSOR_H
