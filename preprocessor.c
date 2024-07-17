#include "preprocessor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lasr_char;
int open_file_read(FILE **fp, const char *fileName)
{
    *fp = fopen(fileName, 'r');
    if (*fp == NULL)
    {
        exit(1);
    }
}

int process_line(char[] line)
{
    if(line==NULL)
    {
        delete_line();
    }
    else if (last_char(line) == ';')
    {
        delete_line();
    }
    else if(check_macro(line)==false)
    {
        copy_paste(line, *output_file);
    }
}

int preprocessor(const char *fileName)
{
    FILE *fp;
    char line[];
    open_file_read(&fp, fileName);
    open_file_write();
    while (!eof())
    {
        line=get_nextLine(&fp);
        arrange_blanks_in_line(line); /*deletes all the unnecessary blanks*/
        process_line(line);
    }
    close_file_write();
    close_file_read();
}