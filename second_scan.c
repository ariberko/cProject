#include "second_scan.h"
#include "first_scan.h"
#include "preprocessor.h"

int fill_double_word(char line[])
{

}

int fill_triple_word(char line[])
{

}

int fill_data(char line[])
{
    if (single_word(line))
    {
        ignore_line();
    }
    else if(double_word(line))
    {
        fill_double_word(line);
    }
    else
    {
        fill_triple_word(line);
    }
}

int treat_sentence(char line[])
{
    if(fill_data(line))
    {
        ignore_line();
    }

    else
    {
        fill_data(line);
    }
}

int treat_order_second_scan(char line[])
{
    if(single_word(line))
        {
           ignore_line();
        }
    else
        {
            treat_sentence(line);
        }
}

int second_scan_process_line(char line[])
{
    if (line == NULL)
    {
        ignore_line();
    }
    else if (first_char(line) == ';')
    {
        ignore_line();
    }
    else if (includes_instruction(line))
    {
        ignore_line();
    }
    else
    {
        treat_order_second_scan(line);
    }
    return 0;
}
int second_scan(const char *fileName)
{
    FILE *input_file = NULL;
    if (open_file_read(&input_file, fileName) != 0)
        return 1;

    char *line;
    while ((line = get_next_line(input_file)) != NULL)
    {
        second_scan_process_line(line);
    }

    fclose(input_file);
    return 0;
}