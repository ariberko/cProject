#include "first_scan.h"

int starts_with_label(char line[])
{
    /*checks if the line starts with one of the six lables*/
}

int enter_label(int location, int count, char word[])
{
    /*gives the label the right adress and counts the spaces for the next label*/
}

int includes_instruction(line)
{
    /* checks if there is a '.' in the line and returns 1 if true or 0 if false*/
}

int includes_order(line)
{
}

int first_line_process_line(char line[])
{
    if (line == NULL)
    {
        delete_line();
    }
    else if (first_char(line) == ';')
    {
        delete_line();
    }

    char *word[] = get_first_word(line);
    if (starts_with_label(word))
    {
        int location = 100;
        int count = count_words_in_line(line);
        enter_label(location, count, word);
    }

    else if (includes_order(line) == 1)
    {
        *word = find_order(line);
        switch_to_binary(&word);
    }

    else if (includes_instruction(line) == 1)
    {
        *word = find_order(line);
        switch_to_binary(&word);
    }
}

int first_scan(const char *fileName)
{
    FILE *input_file = NULL;
    if (open_file_read(&input_file, fileName) != 0)
        return 1;

    char *line;
    while ((line = get_next_line(input_file)) != NULL)
    {
        first_scan_process_line(line);
    }

    fclose(input_file);
    return 0;
}