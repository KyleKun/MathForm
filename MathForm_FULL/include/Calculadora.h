#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <math.h>
#include <ctype.h>
#include <Funcs.h>

double calculoTotal(char formule[]);
double operacao(char operacao[],char formule[], char num2[60]);
char * createStr(char formule[]);
double resultadoFinal(char formule[]);
int funcs_calculadora(char selec[], double result);
int funcs_verifica(char selec[]);
char * funcsDatails = { "            R(x) = RAIZ\n            S(x) = SENO\n            C(x) = COSSENO\n            T(x) = TANGENTE\n            F(x) = FATORIAL \n            L(x) = LOGARITMO\n"} ;


struct funcoes_p {
  char *valor[30];
  char multpl[60];
  int i;
};



double resultadoFinal(char formule[]){
    char res[60];
    sprintf(res, "%.0f",calculoTotal(createStr(formule)));
    if(strlen(res) > 18){
     Error("ERROR, O NUMERO MAXIMO DE CARACTERES E 16!");
    }else{
     Sucesso("RESULTADO FINAL = ", calculoTotal(createStr(formule)), " ");
    }
}

double operacao(char operacao[1], char num[60], char num2[60]){

    double  val;
    char* pEnd;
    switch(operacao[0]){
        case '+':{
            val = strtod(num, &pEnd) + strtod(num2, &pEnd);
            break;
        }
        case '-':{
            val = strtod(num, &pEnd) - strtod(num2, &pEnd);
            break;
        }
        case '/':{
            val = strtod(num, &pEnd) / strtod(num2, &pEnd);
            break;
        }
        case '*':{
             val = strtod(num, &pEnd) * strtod(num2, &pEnd);
            break;
        }
        case '^':{
            val = pow(strtod(num, &pEnd),strtod(num2, &pEnd));
            break;
        }
    }
    return val;
}



struct funcoes_p func(int i, char formule[], char operacao[1]){
 char nums[50] ={};
 char str[60];
 char strn[500] ={};
 char result[60];
 int j;
 double val;
 int very = 0;
 double num;
 char cont[2] ={};
 struct funcoes_p resultado;
 cont[0] = 1;
 char *returned_strs;
 int very_p=0;
 char res_final[255] = {};
 char verifFunc = 0;
 for (j=i; j<strlen(formule); j++)
   {
    if(funcs_verifica(formule[j]) == 1){
       verifFunc = formule[j];
    }else{
    if (formule[j] == '(' ){
        cont[0] += 1;
        very_p = 1;
    }
    if (formule[j] == ')' ){
        cont[1] += 1;
    }

	if (formule[j] == ')'  && cont[0]-1 == cont[1]){
	  if(verifFunc != 0){
       returned_strs = funcs_calculadora(verifFunc,calculoTotal(createStr(strn)));
       }else{
	   returned_strs = createStr(strn);
       }
       verifFunc =0;
       createStr(strn);
       strcat(res_final, returned_strs);
       sprintf(strn, "%c", NULL);
       very_p = 0;
    }
    if (cont[1] == cont[0]){
        resultado.i = j;
        break;
    }
    if(very_p == 1 && formule[j] != ')' && funcs_verifica(formule[j]) == 0 && formule[j] != '(' && formule[j] != NULL){
        sprintf(result, "%c", formule[j]);
        strcat(strn, result);
    }
    if(very_p == 0 && formule[j] != ')' && formule[j] && funcs_verifica(formule[j]) == 0 != '(' && formule[j] != NULL){
        sprintf(result, "%c", formule[j]);
        strcat(res_final, result);
	 }
    }
   }
    char *returned_str = createStr(res_final);

    if(funcs_verifica(operacao[0]) == 1){
        sprintf(resultado.multpl, "%s", funcs_calculadora(operacao[0],calculoTotal(returned_str)));
    }else{
        sprintf(resultado.multpl, "%f", calculoTotal(returned_str));}
    return (resultado);
}

double calculoTotal(char formule[]){
   char num[60];
   char num2[60];
   char veryNum[60];
   int i = 0 ;
   char opera[1];
   double resultado = 0;
   opera[0] = 0;
   num[0] =0;
   num2[0] =0;
 for (i=0; i<strlen(formule); i++)
   {
    if(numret(formule[i]) != NULL){
        if(opera[0] == 0 ){
        strcat(num, numret(formule[i]));
        }
     }else{
        if(formule[i] == '/' || formule[i] == '+' ||  formule[i] == '-' || formule[i] == '*' ||  formule[i] == '^'){
         opera[0] =  formule[i];
         i++;
             while(1){
               if(formule[i] == '/' || formule[i] == '+' ||  formule[i] == '-' || formule[i] == '*' ||  formule[i] == '^' ||  formule[i] == NULL){
                break;}
                strcat(num2, numret(formule[i]));
                i++;
             }
            i--;
            resultado = operacao(opera,num,num2);

            sprintf(veryNum, "%s", num2);
            sprintf(num, "%f", resultado);
            sprintf(num2, "%c", NULL);
      }
    }
  }
      if(veryNum[0] == NULL){
        char* pEnd;
        resultado = strtod(num, &pEnd);
        return resultado; }
        else{
        return resultado;
        }
}


char * createStr(char formule[]){

   char num[60];
   char num2[60];
   int i;
   char opera[1];
   opera[0] = 0;
   num[0] =0;
   num2[0] =0;
   char g[1];
   char rp[500] = {};
   double resultado = 0;
   char rlz[500] = {};
   rp[0] =0;
 for (i=0; i<strlen(formule); i++)
   {
    if(numret(formule[i]) != NULL){
            if(opera[0] == 0 ){
                if(formule[i] == '(' || funcs_verifica(formule[i]) == 1){
                struct funcoes_p resp;
                g[0] = formule[i];
                if(funcs_verifica(formule[i]) == 1){
                resp=func(i+2, formule, g);
                }else{
                resp=func(i+1, formule, g);
                }
                i = resp.i;
                strcat(num, resp.multpl);
              }else{
                strcat(num, numret(formule[i]));
              }
            }
    }else{
if(formule[i] == '/' || formule[i] == '+' ||  formule[i] == '-' || formule[i] == '*' ||  formule[i] == '^'){
 opera[0] =  formule[i];
 i++;
 while(1){
   if(formule[i] == '/' || formule[i] == '+' ||  formule[i] == '-' || formule[i] == '*' ||  formule[i] == '^' ||  formule[i] == NULL){
    break;}
   if(formule[i] == '(' || funcs_verifica(formule[i]) == 1){
                struct funcoes_p resp;
                g[0] = formule[i];
                if(funcs_verifica(formule[i]) == 1){
                resp=func(i+2, formule, g);
                }else{
                resp=func(i+1, formule, g);
                }
                i = resp.i;
                strcat(num2, resp.multpl);
              }else{
                strcat(num2, numret(formule[i]));
              }
    i++;
 }
 i = i-1;
        if(opera[0] == '*' || opera[0] == '/' || opera[0] == '^'){
            resultado = operacao(opera,num,num2);
            sprintf(num, "%.2f", resultado);
            sprintf(num2, "%c", NULL);
        }else{
            sprintf(rlz, "%c", opera[0]);
            strcat(rp,num);
            strcat(rp,rlz);
            sprintf(num, "%s", num2);
            sprintf(num2, "%c", NULL);
        }
      }
    }
  }
     static char str[20];
       strcat(rp,num);
       strcpy(str,rp);
    return str;
}

void calculadora(){
  cabecalho("CALCULADORA",8,0);
  printf("\n%s",funcsDatails);
  FormatEntrada("DIGITE A FORMULA: ");
 int  ps, i= 0;
 char formule[500] = {};
 char ch;
 while(1){
    ch = getch();
    if(ch == 13){
        resultadoFinal(formule);
        break;
    }else{
    if(ch == '\b'){
        i--;
        ps = 0;
        system("cls");
        SetColor(2);
        cabecalho("CALCULADORA",8,0);
        printf("\n%s",funcsDatails);
        FormatEntrada("DIGITE A FORMULA: ");
        formule[strlen(formule)-1] = NULL;
        for(ps = 0; ps < strlen(formule); ps++){
            if(getColor(formule[ps]) >= 1){
              SetColor(getColor(formule[ps]));
            }else{
              SetColor(7);
            }
            printf("%c", formule[ps]);
        }
    }else{
        if(getColor(ch) >= 1){
          SetColor(getColor(ch));
          formule[i] = ch;
          printf("%c", formule[i]);
        }else{
          SetColor(7);
          formule[i] = ch;
          printf("%c", formule[i]);
      }
      i++;
    }
   }
  }
}

int numret(char num[]){

    int t = num;
    char *i[1] = {};
  switch (t){
      case '0':
        {
            i[0]= "0";
            break;
        }
      case '1':
        {
            i[0]= "1";
            break;
        }
      case '2':
        {
            i[0]= "2";
            break;
        }
      case '3':
        {
            i[0]= "3";
            break;
        }
      case '4':
        {
            i[0]= "4";
            break;
        }
      case '5':
        {
            i[0]= "5";
            break;
        }
      case '6':
        {
            i[0]= "6";
            break;
        }
      case '7':
        {
            i[0]= "7";
            break;
        }
      case '8':
        {
            i[0]= "8";
            break;
        }
      case '9':
        {
            i[0]= "9";
            break;
        }
     case '.':
        {
            i[0]= ".";
            break;
        }
    case 'R':
        {
           i[0] = "R";
           break;
        }
    case 'S':
        {
            i[0] = "S";
            break;
        }
    case 'C':
        {
            i[0] = "C";
            break;
        }
    case 'T':
        {
            i[0] = "T";
            break;
        }
    case 'P':
        {
            i[0] = "P";
            break;
        }
    case 'F':
        {
            i[0] = "F";
            break;
        }
    case 'L':
        {
            i[0] = "L";
            break;
        }
    case '(':
        {
            i[0]= "(";
            break;
        }
    case ')':
        {
            i[0]= ")";
            break;
        }
    }
    return i[0];
}

int funcs_verifica(char selec[]){
 int verifica = 0;
 int t = selec;
  switch (t){
    case 'R':
        {
           verifica = 1;
           break;
        }
    case 'S':
        {
            verifica = 1;
            break;
        }
    case 'C':
        {
            verifica = 1;
            break;
        }
    case 'T':
        {
            verifica = 1;
            break;
        }
    case 'P':
        {
            verifica = 1;
            break;
        }
    case 'F':
        {
            verifica = 1;
            break;
        }
    case 'L':
        {
            verifica = 1;
            break;
        }
    }
    return verifica;

}

int funcs_calculadora(char selec[], double result){
 int t = selec;
 char * i[20] = {};
 char rest[17];
 double resultado;

  switch (t){
    case 'R':
        {
            resultado = sqrt(result);
            sprintf(rest, "%.2f", resultado);
            i[0] = rest;
            break;
        }
    case 'S':
        {
            resultado = sin((result * 3.14159265359)/ 180);
            sprintf(rest, "%.2f", resultado);
            i[0] = rest;
            break;
        }
    case 'C':
        {
            resultado = cos((result * 3.14159265359)/ 180);
            sprintf(rest, "%.2f", resultado);
            i[0] = rest;
            break;
        }
    case 'T':
        {
            resultado = tan((result * 3.14159265359)/ 180);
            sprintf(rest, "%.2f", resultado);
            i[0] = rest;
            break;
        }

    case 'F':
        {
            resultado = permutacao(result);
            sprintf(rest, "%.2f", resultado);
            i[0] = rest;
            break;
        }
    case 'L':
        {
            resultado = log(result);
            sprintf(rest, "%.2f", resultado);
            i[0] = rest;
            break;
        }
    }
    return i[0];

}


#endif // CALCULADORA_H_INCLUDED
