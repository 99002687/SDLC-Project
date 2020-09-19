#ifndef __HEADER_H__
#define __HEADER_H__
#include "header.h"
//    FUNCTION TO DELETE A RECORD


void deletefile()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Roll no you want to delete :");
 __fpurge(stdin);
 scanf("%d", &r);
 if (avlrollno(r) == 0)
  printf("Roll no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.rollno;
   if (s != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
   fwrite(&stud, sizeof(stud), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }

}
