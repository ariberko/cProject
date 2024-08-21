#include "preprocessor.h"
#include "first_scan.h"
#include "second_scan.h"


int main ()
{
  preprocessor("test.as");
  first_scan("test.am");
  second_scan("test.am");
  return 0;
}
