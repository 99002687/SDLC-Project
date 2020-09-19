#include<stdio.h>
struct student
{
 int rollno;
 char name[30];
 int mark1;
 int mark2;
 int mark3;
 
}stud;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the Roll no   :");
 __fpurge(stdin);
 scanf("%d", &stud.rollno);
 printf("Enter the Name      :");
 __fpurge(stdin);
 scanf("%s", &stud.name);
 printf("Enter the mark1      :");
 __fpurge(stdin);
 scanf("%d", &stud.mark1);
 printf("Enter the mark2      :");
 __fpurge(stdin);
 scanf("%d", &stud.mark2);
 printf("Enter the mark3      :");
 __fpurge(stdin);
 scanf("%d", &stud.mark3);
 fwrite(&stud, sizeof(stud), 1, fp);
 fclose(fp);
}

//    FUNCTION TO DISPLAY RECORDS
void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nRoll Number\tName\tMark1\tMark2\tMark3\n\n");
 while (fread(&stud, sizeof(stud), 1, fp1))
 printf("  %d\t\t%s\t%d\t%d\t%d\n", stud.rollno, stud.name, stud.mark1,stud.mark2,stud.mark3);
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void search()
{
 FILE *fp2;
 int r, s, avl;
 __fpurge(stdin);
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
   }
  }
  fclose(fp2);
 }
}
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
//    FUNCTION TO UPDATE THE RECORD
void update()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter roll number to update:");
 __fpurge(stdin);
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
    __fpurge(stdin);
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name:");
      __fpurge(stdin);
     scanf("%s", &stud.name);
     break;
    case 2:
     printf("Enter Mark1 : ");
      __fpurge(stdin);
     scanf("%d", &stud.mark1);
     break;
     case 3:
     printf("Enter Mark2 : ");
      __fpurge(stdin);
     scanf("%d", &stud.mark2);
     break;
     case 4:
     printf("Enter Mark3 : ");
      __fpurge(stdin);
     scanf("%d", &stud.mark3);
     break;
    case 5:
     printf("Enter Name: ");
      __fpurge(stdin);
     scanf("%s", &stud.name);
     printf("Enter Mark: ");
      __fpurge(stdin);
     scanf("%d", &stud.mark1);
     printf("Enter Mark2 : ");
      __fpurge(stdin);
     scanf("%d", &stud.mark2);
      printf("Enter Mark3 : ");
      __fpurge(stdin);
     scanf("%d", &stud.mark3);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
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
 printf("Roll No.\tName\t\tMark1\t\tMark2\t\tMark3\n\n");
 count = c;
 for (i = 0; i<count; i++)
 {
  rewind(fpo);
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   if (a[i] == stud.rollno)
    printf("\n %d\t\t %s \t\t %d\t\t %d\t\t %d",stud.rollno, stud.name, stud.mark1, stud.mark2, stud.mark3);
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
// MAIN PROGRAM
void main()
{
 int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. SORT");
  printf("\n\t7. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  __fpurge(stdin);
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   search();
   break;
  case 4:
   deletefile();
   break;
  case 5:
   update();
   break;
  case 6:
   emp = empty();
   if (emp == 0)
    printf("\n The file is EMPTY\n");
   else
    sort();
   break;
  case 7:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);
}
