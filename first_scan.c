#include "first_scan.h"

int first_scan_process_line()
{
    
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