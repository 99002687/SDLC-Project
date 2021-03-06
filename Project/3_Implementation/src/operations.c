#ifndef __HEADER_H__
#define __HEADER_H__
#include"header.h"
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the Roll no   :");
 scanf("%d", &stud.rollno);
 printf("Enter the Name      :");
 scanf("%s", &stud.name);
 printf("Enter the mark1      :");
 scanf("%d", &stud.mark1);
 
 printf("Enter the mark2      :");
 scanf("%d", &stud.mark2);
 printf("Enter the mark3      :");
 scanf("%d", &stud.mark3);
 stud.total=stud.mark1+stud.mark2+stud.mark3;
 stud.average=stud.total/3;
 fwrite(&stud, sizeof(stud), 1, fp);
 fclose(fp);
}

//    FUNCTION TO DISPLAY RECORDS
void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nRoll Number\tName\tMark1\tMark2\tMark3\tTotal\tAverage\n");
 while (fread(&stud, sizeof(stud), 1, fp1))
 printf("  %d\t\t%s\t%d\t%d\t%d\t%d\t%.2f\n", stud.rollno, stud.name, stud.mark1,stud.mark2,stud.mark3,stud.total,stud.average);
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void search()
{
 FILE *fp2;
 int r, s, avl;
 printf("\nEnter the Roll no you want to search  :");
 scanf("%d", &r);
 avl = avlrollno(r);
 if (avl == 0)
  printf("Roll No %d is not available in the file\n",r);
 else
 {
  fp2 = fopen("Record", "r");
  while (fread(&stud, sizeof(stud), 1, fp2))
  {
   s = stud.rollno;
   if (s == r)
   {
    printf("\nRoll no = %d", stud.rollno);
    printf("\nName    = %s", stud.name);
    printf("\nMark1    = %d\n", stud.mark1);
    printf("\nMark2    = %d\n", stud.mark2);
    printf("\nMark3    = %d\n", stud.mark3);
    printf("\nTotal    = %d\n", stud.total);
    printf("\nAverage    = %.2f\n", stud.average);
    
   }
  }
  fclose(fp2);
 }
}

//    FUNCTION TO UPDATE THE RECORD
void update()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter roll number to update:");
 scanf("%d", &r);
 avl = avlrollno(r);
 if (avl == 0)
 {
  printf("Roll number %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.rollno;
   if (s != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
   else
   {
    printf("\n\t1. Update Name of Roll Number %d", r);
    printf("\n\t2. Update Mark1 of Roll Number %d", r);
    printf("\n\t3. Update Mark2 of Roll Number %d", r);
    printf("\n\t4. Update Mark3 of Roll Number %d", r);
    printf("\n\t5. Update all Name and Mark of Roll Number %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name:");
     scanf("%s", &stud.name);
     break;
    case 2:
     printf("Enter Mark1 : ");
     scanf("%d", &stud.mark1);
     break;
     case 3:
     printf("Enter Mark2 : ");
     scanf("%d", &stud.mark2);
     break;
     case 4:
     printf("Enter Mark3 : ");
     scanf("%d", &stud.mark3);
     break;
    case 5:
     printf("Enter Name: ");
     scanf("%s", &stud.name);
     printf("Enter Mark: ");
     scanf("%d", &stud.mark1);
     printf("Enter Mark2 : ");
     scanf("%d", &stud.mark2);
      printf("Enter Mark3 : ");
     scanf("%d", &stud.mark3);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    stud.total=stud.mark1+stud.mark2+stud.mark3;
     stud.average=stud.total/3;
    fwrite(&stud, sizeof(stud), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
  {
   fwrite(&stud, sizeof(stud), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}
/* FUNCTION TO SORT THE RECORD */
void sort()
{
 int a[20], count = 0, i, j, t, c;
 FILE *fpo;
 fpo = fopen("Record", "r");
 while (fread(&stud, sizeof(stud), 1, fpo))
 {
  a[count] = stud.rollno;
  count++;
 }
 c = count;
 for (i = 0; i<count - 1; i++)
 {
  for (j = i + 1; j<count; j++)
  {
   if (a[i]>a[j])
   {
    t = a[i];
    a[i] = a[j];
    a[j] = t;
   }
  }
 }
 printf("Roll No.\tName\tMark1\tMark2\tMark3\tTotal\tAverage\n\n");
 count = c;
 for (i = 0; i<count; i++)
 {
  rewind(fpo);
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   if (a[i] == stud.rollno)
    printf("\n %d\t\t %s \t%d\t %d\t %d\t %d\t %.2f",stud.rollno, stud.name, stud.mark1, stud.mark2, stud.mark3, stud.total, stud.average);
  }

 }
}
//    FUNCTION TO CHECK GIVEN ROLL NO IS AVAILABLE //
int avlrollno(int rno)
{
 FILE *fp;
 int c = 0;
 fp = fopen("Record", "r");
 while (!feof(fp))
 {
  fread(&stud, sizeof(stud), 1, fp);

  if (rno == stud.rollno)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("Record", "r");
 while (fread(&stud, sizeof(stud), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}

#endif 
