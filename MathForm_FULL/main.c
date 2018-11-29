#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ColorNameAll.h>
#include <Calculadora.h>
int VERYF = 0;

int max_i = 1;
char * formuleSelecteds(char itemSelec[100]);

void selectsFormules(int max_selec){
int ch,temp,contPr,contfSelec,cont = 0;
contPr = 0;
contfSelec = 0;
SetColor(2);
selecFormula(0,0);
  while(1){
    ch=getch();
    if(ch != NULL){system("cls");}
    if(ch == 13 && cont == max_selec){
    exit(1);}
    else{
    if(ch == 13 && VERYF == 0 && (contPr == 1 || cont > 7)){
    allformules(cont,contfSelec);
    VERYF = 1;
    }else{
    VERYF = 0;
    if(ch == 77 && contPr <= 0){
     contPr = 1;
     contfSelec = 0;
    }
    if(ch == 75 && contPr >= 0){
     contPr = 0;
     contfSelec = 0;
    }
    if(ch == 72 && contfSelec > 0 && contPr == 1 ){
    contfSelec--;
    }else{
    if(ch == 80 && contfSelec < max_i-1  && contPr == 1 ){
    contfSelec++;}
    }
    if(ch == 72 && cont > 0 && (contPr == 0 || cont > 7)){
    cont--;
    contPr = 0;
    }else{
    if(ch == 80 && cont < max_selec  && (contPr == 0  || cont > 7)){
    cont++;
    contPr = 0;}
    }
    if((ch == 75 || ch == 72) || ch != NULL){selecFormula(cont,contPr,contfSelec);
    }else{
    if(ch == 80 || ch != NULL){ selecFormula(cont,contPr,contfSelec);}
    }
    }
   }
  }
}



void welcome(){
char *welc[500][500] ={{" "," "," "," ","*"," "," "," ","*"," "," "," "," "," "," "," "," "," ","*"," "," "," "," ","*","*","*","*","*","*","*"," ","*"," "," "," "," "," "," ","*"," ","*","*","*","*","*"," "," ","*"," ","*"," ","*"," "," "," "," ","*","*","*","*","*","*"," "," "," "," "," "," ","*"," "," "," ","*"},
{" "," "," ","*"," ","*"," ","*"," ","*"," "," "," "," "," "," "," ","*"," ","*"," "," "," "," "," "," ","*"," "," "," "," ","*"," "," "," "," "," "," ","*"," ","*"," "," "," "," "," ","*"," "," "," "," "," "," ","*"," "," ","*"," "," "," ","*"," "," "," "," "," "," ","*"," ","*"," ","*"," ","*"},
{" "," ","*"," "," "," ","*"," "," "," ","*"," "," "," "," "," ","*"," ","*"," ","*"," "," "," "," "," ","*"," "," "," "," ","*"," ","*","*","*","*"," ","*"," ","*","*","*","*"," ","*"," "," "," "," "," "," "," "," ","*"," ","*"," ","*"," "," "," "," "," "," "," ","*"," "," "," ","*"," "," "," ","*"},
{" ","*"," "," "," "," "," "," "," "," "," ","*"," "," "," ","*"," "," "," "," "," ","*"," "," "," "," ","*"," "," "," "," ","*"," "," "," "," "," "," ","*"," ","*"," "," "," "," "," ","*"," "," "," "," "," "," ","*"," "," ","*"," "," "," ","*"," "," "," "," ","*"," "," "," "," "," "," "," "," "," ","*"},
{"*"," "," "," "," "," "," "," "," "," "," "," ","*"," ","*"," "," "," "," "," "," "," ","*"," "," "," ","*"," "," "," "," ","*"," "," "," "," "," "," ","*"," ","*"," "," "," "," "," "," ","*"," ","*"," ","*"," "," "," "," ","*"," "," "," "," "," ","*"," ","*"," "," "," "," "," "," "," "," "," "," "," ","*"}};
        int j,t,q = 0;
    char *n1[5][78],nullVal[78],n2[5][78];
    SetColor(10);
    for(q = 0; q<=39;q++){
         system("cls");
        for(t=0;t<=4;t++){
         n1[t][q] = welc[t][q];
         n1[t][78-q] = welc[t][78-q];
        }
        printf("\n\n\n\n\n\n\n");
        for(t=0;t<=4;t++){
            for(j= 0; j<=77;j++){
                if(j > 78 && n1[t][j] == NULL){
                    break;
                }
                if(n1[t][j] == NULL){
                    printf("%s", " ");
                }else{
                    if((n1[t][j+5] == NULL || (n1[t][j-5] == NULL && j > 5)) && j <= 67){
                        SetColor(11);
                    }else{
                        SetColor(10);}
                    printf("%s",n1[t][j]);
                }
            }
            printf("\n");
        }
         Sleep(2);
    }

    Sleep(1000);
    system("cls");
    for(q = 0; q<=39;q++){
         system("cls");
        for(t=0;t<=4;t++){
         n1[t][39+q] = NULL;
         n1[t][39-q] = NULL;
        }
        printf("\n\n\n\n\n\n\n");
        for(t=0;t<=4;t++){
            for(j= 0; j<=77;j++){
                if(j > 78 && n1[t][j] == NULL){
                    break;
                }
                if(n1[t][j] == NULL){
                    printf("%s", " ");
                }else{
                    if((n1[t][j+5] == NULL || (n1[t][j-5] == NULL && j > 5)) && j <= 67){
                        SetColor(11);
                    }else{
                        SetColor(10);}
                    printf("%s",n1[t][j]);
                }
            }
            printf("\n");
        }
         Sleep(2);
    }

    system("cls");
    selectsFormules(9);
}

int main(){
welcome();
selectsFormules(9);
}

 void selecFormula(int selected, int contPr, int contfSelec){
 int nosl = 32;
 char *selecteds[10] = {nosl,nosl,nosl,nosl,nosl,nosl,nosl,nosl,nosl};
 int selec_options[11] = {nosl,nosl,nosl,nosl,nosl,nosl,nosl,nosl,nosl,nosl,nosl};
 int sl = 175;
 int i = 0;
         if(contPr == 0 || selected > 7){
         selecteds[selected] = sl;
         }
         selec_options[selected] = selected;
         printf("\n              %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
         printf("              %c                                                %c\n",219,219);
         SetColor(7);
         printf("              %c       ESCOLHA A FORMULA MATEMATICA             %c\n",219,219);
         printf("              %c ______________________________________________ %c\n",219,219);
         printf("              %c                                                %c\n",219,219);
         printf("              %c     %c SOMATORIO                                %c\n", 219,selecteds[0],219);
         formSelecs(i,selec_options[0],selected,contfSelec,contPr);
         printf("              %c     %c CONSTANTES                               %c\n", 219,selecteds[1],219);
         formSelecs(i,selec_options[1],selected,contfSelec,contPr);
         printf("              %c     %c LOGICA PROPOSICIONAL                     %c\n", 219,selecteds[2],219);
         formSelecs(i,selec_options[2],selected,contfSelec,contPr);
         printf("              %c     %c MATRIZ                                   %c\n", 219,selecteds[3],219);
         formSelecs(i,selec_options[3],selected,contfSelec,contPr);
         printf("              %c     %c COMBINATORIA                             %c\n", 219,selecteds[4],219);
         formSelecs(i,selec_options[4],selected,contfSelec,contPr);
         printf("              %c     %c FUNCAO                                   %c\n", 219,selecteds[5],219);
         formSelecs(i,selec_options[5],selected,contfSelec,contPr);
         printf("              %c     %c DERIVADA NUMERICA                        %c\n", 219,selecteds[6],219);
         formSelecs(i,selec_options[6],selected,contfSelec,contPr);
         printf("              %c     %c INTEGRACAO NUMERICA                      %c\n", 219,selecteds[7],219);
         formSelecs(i,selec_options[7],selected,contfSelec,contPr);
         printf("              %c     %c CALCULADORA CIENTIFICA                   %c\n", 219,selecteds[8],219);
         printf("              %c     %c SAIR                                     %c\n", 219,selecteds[9],219);
         printf("              %c                                                %c\n",219,219);
         printf("              %c                                                %c\n",219,219);
         printf("              %c                                                %c\n",219,219);
         printf("              %c                                                %c\n",219,219);
         SetColor(2);
         printf("              %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

}


void allformules(int selected, int selecFormle){
double x, k, a, b, dbT;
    switch (selected){
        case 0:{
            double n,m;
            cabecalho("SOMATORIO",selected,selecFormle);
            dbT = VerificaEntradas("DIGITE O PRIMEIRO VALOR: ");
            a = dbT;
            dbT = VerificaEntradas("DIGITE O SEGUNDO VALOR: ");
            n =  dbT;
            if(selecFormle > 0){
                dbT = VerificaEntradas("DIGITE O TERCEIRO VALOR: ");
                m = dbT;
            }else{
                m = 0;}
            k = 0;
            somatorio( k,  a,  n, m, selecFormle);
            break;
        }
        case 1:{
            cabecalho("CONSTANTES",selected,selecFormle);
            double n;
            n = VerificaEntradas("DIGITE O VALOR DE N: ");
            constantes(n,selecFormle);
            break;
        }
        case 2:{
            cabecalho("LOGICA PROPOSICIONAL",selected,selecFormle);
            int p,q;
            FormatEntrada("PARA P SELECIONE V PARA VERDADEIRO OU F PARA FALSO: ");
            scanf (" %c", &p);
            if(selecFormle > 0){
              FormatEntrada ("PARA Q SELECIONE V PARA VERDADEIRO OU Q PARA FALSO: ");
              scanf (" %c", &q);
            }
            logicaProposicional(selecFormle, p, q);
            break;
        }
        case 3:{
            cabecalho("MATRIZ",selected,selecFormle);
            switch (selecFormle){
                case 0:{
                  soma();
                   break;
                }
                 case 1:{
                   menos();
                    break;
                }
                 case 2:{
                   product();
                    break;
                }
                case 3:{
                   matrizPrencher();
                    break;
                }
            }
            break;
        }
        case 4:{
            cabecalho("COMBINATORIA",selected,selecFormle);
            double p,q,i,rept = 1;
              switch (selecFormle){
                case 0:{
                   dbT = VerificaEntradas("DIGITE O NUMERO DE REPETICOES: ");
                   p = dbT;
                   combinatoria(p,rept,selecFormle);
                   break;
                }
                 case 1:{
                    p = VerificaEntradas("DIGITE O NUMERO DE REPETICOES: ");
                    i  = VerificaEntradas("DIGITE O NUMERO DE LETRAS REPETIDAS: ");
                    int cont = 1;
                    for(cont = 1; cont <= i; cont++){
                        SetColor(2);
                        printf("\n\n              DIGITE O NUMERO DE REPETICOES DO %i NUMERO: ",cont);
                        SetColor(15);
                        q =  VerificaEntradas("");
                        rept*= permutacao(q);
                    }
                    combinatoria(p,rept,selecFormle);
                    break;
                }
            }
             if(selecFormle >1 ){
                p = VerificaEntradas("DIGITE A QUANTIDADE DE ELEMENTOS NO CONJUNTO: ");
                rept = VerificaEntradas("DIGITE O NUMERO DE ELEMENTOS NOS AGRUPAMENTOS: ");
                combinatoria(p,rept,selecFormle);
             }
            break;
        }
        case 5:{
        cabecalho("FUNCAO",selected,selecFormle);
        switch(selecFormle){
           case 0:
                validaFuncao1(k);
                Sucesso("F(x) = ", funcao1(*aux_k), " ");
                break;
            case 1:
                validaFuncao2(x, k);
                Sucesso("F(x) = ", funcao2(*aux_x, *aux_k), " ");
                break;
            case 2:
                validaFuncao3(k, x);
                Sucesso("F(x) = ", funcao3(*aux_k, *aux_x), " ");
                break;
            case 3:
                validaFuncao4(k, x);
                Sucesso("F(x) = ", funcao4(*aux_k, *aux_x), " ");
                break;
            case 4:
                grausParaRad(k);
                Sucesso("F(x) = ", funcao5(graus), " ");
                break;
            case 5:
                grausParaRad(k);
                Sucesso("F(x) = ", funcao6(graus), " ");
                break;
            case 6:
               validaFuncao7(k);
               Sucesso("F(x) = ", funcao7(graus), " ");
               break;
            case 7:
                validaFuncao8(x);
                Sucesso("F(x) = ", funcao8(*aux_x), " ");
                break;
            case 8:
                validaFuncao9(x);
                Sucesso("F(x) = ", funcao9(*aux_x), " ");
                break;
            case 9:
                validaFuncao10(x);
                Sucesso("F(x) = ", funcao10(*aux_x), " ");
                break;
            case 10:
                validaFuncao11(x);
                Sucesso("f(x = ", funcao11(*aux_x), " ");
                break;
                }
            break;
        }

        case 6:{
        cabecalho("DERIVADA",selected,selecFormle);
        switch(selecFormle){
            case 0:
                validaFuncao1(k);
                Sucesso("F'(x) = ", derivada1(*aux_k), " ");
                break;
            case 1:
                validaFuncao2(x, k);
                Sucesso("F'(x) = ", derivada2(*aux_x, *aux_k), " ");
                break;
            case 2:
                validaFuncao3(k, x);
                Sucesso("F'(x) = ", derivada3(*aux_k, *aux_x), " ");
                break;
            case 3:
                validaFuncao4(k, x);
                Sucesso("F'(x) = ", derivada4(*aux_k, *aux_x), " ");
                break;
            case 4:
                grausParaRad(k);
                Sucesso("F'(x) = ", derivada5(graus, graush), " ");
                break;
            case 5:
                grausParaRad(k);
                Sucesso("F'(x) = ", derivada6(graus, graush), " ");
                break;
            case 6:
                validaFuncao7(k);
                Sucesso("F'(x) = ", derivada7(graus, graush), " ");
               break;
            case 7:
                validaFuncao8(x);
                Sucesso("F'(x) = ", derivada8(*aux_x), " ");
                break;
            case 8:
                validaFuncao9(x);
                Sucesso("F'(x) = ", derivada9(*aux_x), " ");
                break;
            case 9:
                validaFuncao10(x);
                Sucesso("F'(x) = ", derivada10(*aux_x), " ");
                break;
            case 10:
                validaFuncao11(x);
                Sucesso("F'(x) = ", derivada11(*aux_x), " ");
                break;
                }
            break;
        }
        case 7:{
           cabecalho("INTEGRACAO NUMERICA",selected,selecFormle);
          switch(selecFormle){
            case 0:
                inputIntegral(a, b);
                Sucesso("F(x) = ", calculaIntegral1(*aux_a, *aux_b), " ");
                break;

            case 1:
                inputIntegral(a, b);
                Sucesso("F(x) = ", calculaIntegral2(*aux_a, *aux_b), " ");
                break;

            case 2:
                inputIntegral(a, b);
                Sucesso("F(x) = ", calculaIntegral3(*aux_a, *aux_b), " ");
                break;

            case 3:
                inputIntegral(a, b);
                Sucesso("F(x) = ", calculaIntegral4(*aux_a, *aux_b), " ");
                break;

            case 4:
                inputIntegralGraus(a, b);
                Sucesso("F(x) = ", calculaIntegral5(*aux_a, *aux_b), " ");
                break;

            case 5:
                inputIntegralGraus(a, b);
                Sucesso("F(x) = ", calculaIntegral6(*aux_a, *aux_b), " ");
                break;

            case 6:
                inputIntegralGraus(a, b);
                Sucesso("F(x) = ", calculaIntegral7(*aux_a, *aux_b), " ");
                break;

            case 7:
                inputIntegral(a, b);
                Sucesso("F(x) = ", calculaIntegral8(*aux_a, *aux_b), " ");
                break;

            case 8:
                inputIntegral(a, b);
                Sucesso("F(x) = ", calculaIntegral9(*aux_a, *aux_b), " ");
                break;

            case 9:
                inputIntegral(a, b);
                Sucesso("F(x) = ", calculaIntegral10(*aux_a, *aux_b), " ");
                break;

            case 10:
                inputIntegral(a, b);
                Sucesso("F(x) = ", calculaIntegral11(*aux_a, *aux_b), " ");
                break;
            }
            break;
        }
        case 8:{
            calculadora();
            break;
        }
}
    SetColor(2);
    printf("\n\n\n\n                      ENTER para voltar ao menu.");
}

char * formuleSelecteds(char itemSelec[100]){
    int i;
    static char attrS[50], nullS[50];
    strcpy(attrS,  itemSelec);
    strcpy(nullS, " ");
    for(i = 0; i< 39-strlen(itemSelec);i++){
        strcat(attrS, nullS);
    }
    return attrS;
}

int formSelecs(int i, int selec_options, int selected, int contfSelec, int verypr){
     if(verypr == 1){
     int nosl = 32;
    char selecTval[11] = {nosl,nosl,nosl,nosl,nosl,nosl,nosl,nosl,nosl,nosl,nosl};
     int sl = 16;
     selecTval[contfSelec] = sl;
       if(selec_options == selected){
         while(1){
            if(selecteds_cat[selected][i] == NULL){
               break;
            }
            if(contfSelec == i){
            printf("              %c       %c %s%c\n",219,selecTval[contfSelec],formuleSelecteds(selecteds_cat[selected][i]),219);
            }else{
            printf("              %c         %s%c\n",219,formuleSelecteds(selecteds_cat[selected][i]),219);
            }i++;
            max_i = i;}
        }
     }
}
