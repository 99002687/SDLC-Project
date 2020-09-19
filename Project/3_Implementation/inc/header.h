#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include <stdio_ext.h>

struct student
{
 int rollno;
 char name[30];
 int mark1;
 int mark2;
 int mark3;
 int total;
float average;
}stud;

void insert();
void disp();
void search();
  void deletefile(void);
int deletecheck(int);
  void update();
  void sort();
  int avlrollno(int rno);
int empty();
