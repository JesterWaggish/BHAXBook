// Run: ./10mb < hs_alt_chr2.fa > rovid_genom.txt

#include <stdio.h>

int
main ()
{

  int counter = 0;
  while (counter < 10 * 1024 * 1024)
    {
      putchar (getchar ());
      counter++;
    }
  return 0;
}
