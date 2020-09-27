#ifndef __HEADER_H__
#define __HEADER_H__

#include "header.h"

int main()
{
 int c, emp;
 l1:
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE");
  printf("\n\t6. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  __fpurge(stdin);
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   goto l1;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   goto l1;
  case 3:
   search();
   goto l1;
  case 4:
    deletefile();
   goto l1;
  case 5:
   update();
   goto l1;
  case 6:
   exit(1);
   goto l1;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   goto l1;

  }
 return 0;
}
#endif 
