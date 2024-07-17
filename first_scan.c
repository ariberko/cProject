#include "first_scan.h"
first_scan()
{
    open_file_read();
    while(!EOF())
    {
        get_nextLine();
        process_line();
    }
    close_file_read();
}
