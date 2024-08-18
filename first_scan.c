#include "first_scan.h"

char *double_word_list[9] = {"clr", "not", "inc", "dec", "jmp", "bne", "red", "prn", "jsr"};
char *triple_word_list[5] = {"mov", "cmp", "add", "sub", "lea"};

int double_word(char line[])
{
    
}

int includes_order(char line[])
{

}

int valid_order_syntax(char line[])
{

}

int single_word(char line[])
{
    
}

int print_error(char line[])
{
    return 0;
}

int in_list(char *word, char *list[])
{

}

int treat_single_word(char line[])
{
    if((extract_order(line)!='rts') && (extract_order(line)!= 'stop'))
    {
        print_error(line);
    }
    else
    {
        save_word_to_memory(create_word(convert_order_to_value(extract_order(line)),0,0,0)); /*command , adressing 1 , adressing 2, are*/
    }
}


int treat_double_word(char line[])
{
    if(in_list(extract_order(line), double_word_list)==0)
    {
        print_error(line);
    }
    else
    {
        save_word_to_memory(create_word(convert_order_to_value(extract_order(line)),1,0,0)); /*command , adressing 1 , adressing 2, are*/
    }
}

treat_triple_word(char line[])
{
    if(in_list(extract_order(line), triple_word_list)==0)
    {
        print_error(line);
    }
    else
    {
        save_word_to_memory(create_word(convert_order_to_value(extract_order(line)),1,1,0)); /*command , adressing 1 , adressing 2, are*/
    }
}

int treat_data(char line[])
{
    if(is_data_line_valid(line)!=1) /*checks if the line is valid for data structure*/
        print_error(line); /*reports the error*/
    if(includes_label(line)==1)
    {
        extract_label(line);
        give_label_value();
        insert_label_to_chart();
    }
    allocate_memory_in_DC();
    move_DC();
    return 0;
}

int treat_string(char line[])
{
    extract_string(line);
    if(includes_label(line)==1)
    {
        extract_label(line);
        give_label_value();
        insert_label_to_chart();
    }
    move_DC();
    return 0;
}

int is_entry(char line[])
{
    if(starts_with_label(line)==1)
    {
        skip_label(line);
        print_warning(line);
    }
    treat_label(line);
    return 0;
}

int is_extern(char line[])
{
    if(starts_with_label(line)==1)
    {
        skip_label(line);
        print_warning(line);
    }
    if(label_was_with_entry(line)==1)
        print_error(line);
    else
        get_label_value();
    return 0;
}
int treat_instruction(char line[])
{
    if(valid_instruction_syntax(line)==1)
    {
        if(is_data(line))
        {
            treat_data(line);
        }
        if(is_string(line))
        {
            treat_string(line);
        }
        if(is_extern(line))
        {
            treat_extern(line);
        }
        else
        {
            treat_entry(line);
        }
    }
}

int treat_order(char line[])
{
    if(includes_order(line)==1)
    {
        if(valid_order_syntax(line)==1)
        {
            if(single_word(line))
            {
                treat_single_word(line);
            }
            else if(double_word(line))
            {
                treat_double_word(line);
            }
            else
            {
                treat_triple_word(line);
            }
        }
    }
    else
    {
        print_error(line);
        return 0;
    }
}

int includes_instruction(char line[])
{
     if(is_data(line) || is_string(line) || is_extern(line) || is_entry(line))
        return 1;
    return 0;
}


int empty_line(char line[])
{
    return 0;
}
int is_line_valid(char line[])
{
    return 0;
}
int treat_error(char line[])
{
    return 0;
}

int first_scan_process_line(char line[])
{
    if (line == NULL)
    {
        ignore_line();
    }
    else if (first_char(line) == ';')
    {
        ignore_line();
    }
    else if (is_line_valid(line) !=1)
    {
        treat_error(line);
    }
    else if (includes_instruction(line))
    {
        treat_instruction(line);
    }
    else
    {
        treat_order(line);
    }
    return 0;
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