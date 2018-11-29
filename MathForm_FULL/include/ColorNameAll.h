#ifndef COLORNAMEALL_H_INCLUDED
#define COLORNAMEALL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>

int find_c(char a[], int num_elements, char value);
int getColor(char chr);
int cor_selected(int selec);

void SetColor(int ForgC)
 {
 WORD wColor;
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

int getColor(char chr)
{
 char colorDef[20] = {'<','>','!','(',')','+','-','/','*','^','[',']','{','}'};
 return find_c(colorDef,strlen(colorDef),chr);
}

int find_c(char a[], int num_elements, char value)
{
   int i;
   for (i=0; i<num_elements; i++)
   {
	 if (a[i] == value)
	 {
        i = cor_selected(i);
	    return i;
	 }
   }
   return(NULL);
}

int cor_selected(int selec){
    int i = 0;

    switch (selec){
      case 0:
        {
            i= 14;
            break;
        }
      case 1:
        {
            i= 14;
            break;
        }
      case 2:
        {
            i= 1;
            break;
        }
      case 3:
        {
            i= 14;
            break;
        }
      case 4:
        {
            i= 14;
            break;
        }
      case 5:
        {
            i= 10;
            break;
        }
      case 6:
        {
            i= 10;
            break;
        }
      case 7:
        {
            i= 10;
            break;
        }
      case 8:
        {
            i= 10;
            break;
        }
      case 9:
        {
            i= 10;
            break;
        }
      case 10:
        {
            i= 14;
            break;
        }
      case 11:
        {
            i= 14;
            break;
        }
      case 12:
        {
            i= 14;
            break;
        }
      case 13:
        {
            i= 14;
            break;
        }

    }
    return i;
}
#endif // COLORNAMEALL_H_INCLUDED
