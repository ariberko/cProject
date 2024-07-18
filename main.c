#include "preprocessor.h"
#include "first_scan.h"
#include "second_scan.h"

int main ()
{
  preprocessor("test.as");
  first_scan();
  second_scan();
  return 0;
}
