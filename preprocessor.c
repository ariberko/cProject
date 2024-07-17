#include "preprocessor.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_SIZE 80
#define MAX_MACROS 100

char *macros[MAX_MACROS];
int num_macros = 0;

int check_macro(char line[])
{
    return (strncmp(line, "macr", 4) == 0);
}

int open_file_read(FILE **fp, const char *fileName)
{
    *fp = fopen(fileName, "r");
    if (*fp == NULL)
    {
        fprintf(stderr, "\nError opening file '%s' for reading\n", fileName);
        return 1;
    }
    return 0;
}

int open_file_write(FILE **fp, const char *fileName)
{
    *fp = fopen(fileName, "w");
    if (*fp == NULL)
    {
        fprintf(stderr, "\nError opening file '%s' for writing\n", fileName);
        return 1;
    }
    return 0;
}

char *get_next_line(FILE *fp)
{
    char *line = malloc(LINE_SIZE * sizeof(char));
    if (line == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for line\n");
        exit(EXIT_FAILURE);
    }

    if (fgets(line, LINE_SIZE, fp) != NULL)
    {
        return line; // Return the pointer to the allocated memory
    }

    free(line); // Free memory if fgets failed
    return NULL;
}

void delete_line(void)
{
    // Function can be expanded to handle line deletion if needed
}

char first_char(char line[])
{
    if (line[0] != '\0')
    {
        return line[0];
    }
    return '\0';
}

void copy_paste(char line[], FILE *output_file)
{
    fprintf(output_file, "%s", line);
}

void arrange_blanks_in_line(char line[])
{
    char *start = line;
    while (isspace((unsigned char)*start))
    {
        start++;
    }
    char *end = line + strlen(line) - 1;
    while (end > start && isspace((unsigned char)*end))
    {
        end--;
    }
    *(end + 1) = '\0';

    memmove(line, start, end - start + 2);

    char *source = line, *dst = line;
    int in_space = 0;
    while (*source)
    {
        if (isspace((unsigned char)*source))
        {
            if (!in_space)
            {
                *dst++ = ' ';
                in_space = 1;
            }
        }
        else
        {
            *dst++ = *source;
            in_space = 0;
        }
        source++;
    }
    *dst = '\0';
}

void add_macro(char line[], FILE *output_file)
{
    fprintf(output_file, "%s", line);
}

void save_macro(char line[])
{
    char*macro = (char*)strdup(line);
    if (macro == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for macro\n");
        exit(EXIT_FAILURE);
    }

    if (num_macros < MAX_MACROS)
    {
        macros[num_macros++] = macro;
    }
    else
    {
        fprintf(stderr, "Error: Exceeded maximum number of macros\n");
        free(macro);
    }
}

int process_line(char line[], FILE *output_file)
{
    if (line == NULL)
    {
        delete_line();
    }
    else if (first_char(line) == ';')
    {
        delete_line();
    }
    else
    {
        int macro_check = check_macro(line);
        if (macro_check == 0)
        {
            copy_paste(line, output_file);
        }
        else if (macro_check == 1)
        {
            add_macro(line, output_file);
            save_macro(line);
        }
    }
    return 0;
}

int preprocessor(const char *fileName)
{
    FILE *input_file, *output_file;
    if (open_file_read(&input_file, fileName) != 0)
        return 1;

    if (open_file_write(&output_file, "output.txt") != 0)
    {
        return 1;
    }

    char *line = get_next_line(input_file);
    while (line != NULL)
    {
        arrange_blanks_in_line(line);
        process_line(line, output_file);
        line = get_next_line(input_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
