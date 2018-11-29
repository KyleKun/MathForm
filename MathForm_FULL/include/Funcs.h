#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

double permutacao(double n);
double *aux_k, *aux_x, *aux_a, *aux_b, graus, graush, h = 0.00001;
double VerificaEntradas(char formuleSelec[40]);
double dbTs, dbTs2;
char *selecteds_cat[9][20] = {
{"1.1 S(a^k)","1.2 S(a^k^m)","1.3 S(a^m^k)"},
{"2.1 PI","2.2 NEPERIANO"},
{"3.1 ~ P","3.2 P ^ Q","3.3 P V Q","3.4 P _V Q","3.5 P -> Q","3.6 P <-> Q"},
{"4.1 SOMA","4.2 SUBTRACAO","4.3 PRODUTO","4.4 DETERMINANTE"},
{"5.1 PERMUTACAO SIMPLES","5.2 PERMUTACAO COM REPETICAO","5.3 ARRANJO SIMPLES","5.4 ARRANJO COM REPETICAO","5.5 COMBINACAO SIMPLES","5.6 COMBINACAO COM REPETICAO"},
{"6.1  f(x) = k","6.2  f(x) = x^k","6.3  f(x) = k^x","6.4  f(x) = log k(x)","6.5  f(x) = sen(x)","6.6  f(x) = cos(x)","6.7  f(x) = tan(x)","6.8  f(x) = raiz(x)","6.9  f(x) = 1/x","6.10 f(x) = e^x","6.11 f(x) = ln(x)"},
{"7.1  f'(x) = k","7.2  f'(x) = x^k","7.3  f'(x) = k^x","7.4  f'(x) = log k(x)","7.5  f'(x) = sen(x)","7.6  f'(x) = cos(x)","7.7  f'(x) = tan(x)","7.8  f'(x) = raiz(x)","7.9  f'(x) = 1/x","7.10 f'(x) = e^x","7.11 f'(x) = ln(x)"},
{"8.1  f(x) = k","8.2  f(x) = x^k","8.3  f(x) = k^x","8.4  f(x) = log k(x)","8.5  f(x) = sen(x)","8.6  f(x) = cos(x)","8.7  f(x) = tan(x)","8.8  f(x) = raiz(x)","8.9  f(x) = 1/x","8.10  f(x) = e^x","8.11  f(x) = ln(x)"},
{"Calculadora Cientifica"},
};

void Error(char erro[100]){
   SetColor(12);
   printf("\n\n\n                 %s",erro);
   SetColor(15);
}

void Error_Inf(char erro[100]){
   SetColor(12);
   printf("\n                      %s\n ",erro);
   SetColor(15);
}

void Sucesso(char texto[100], double result, char finaltext[60]){
   SetColor(15);
   printf("\n\n\n                 %s",texto);
   SetColor(10);
   printf("%lf ",result);
   SetColor(15);
   printf("%s\n",   finaltext);
}

void SucessoC(char texto[100], char result[30]){
   SetColor(15);
   printf("\n\n\n                 %s",texto);
   SetColor(10);
   printf("%s\n",result);
   SetColor(15);
}

void FormatEntrada(char texto[100]){
   SetColor(2);
   printf("\n                 %s",texto);
   SetColor(15);
}

void FormatEntradaMatriz(char texto[100], int col, int row){
   SetColor(2);
   printf("\n                 %s coluna ",texto);
   SetColor(15);
   printf("%i ",col);
   SetColor(2);
   printf("linha ");
   SetColor(15);
   printf("%i: ",row);
   SetColor(10);
}

double VerificaEntradas( char formuleSelec[40]){
    int verifica = 1;
     char res[60];
    do{
     verifica = 1;
     if(formuleSelec[0] != NULL){
     FormatEntrada(formuleSelec);
     }
     scanf("%s", &res);
    for(int i=0;i<strlen(res);i++){
        if(isdigit(res[i]) == 0){
            verifica = 0;
            break;
        }
    }
    if(verifica == 0){
        Error_Inf("SOMENTE NUMEROS!");
    }else{
        return atof(res);
    }
    }while(verifica == 0);
}

void cabecalho(char formuleSelec[60], int selected, int selecformule){
 char ponts[90] = {};
 int i = 1;
 for(i=1; i<= 78-strlen(formuleSelec);i++){
    if(i == (39-(strlen(formuleSelec)/2))){
        strcat(ponts,formuleSelec);
    }else{
        strcat(ponts, "-");
    }
 }
 printf("\n\n\n\n\n %s \n", ponts);
 printf("\n         %s \n", selecteds_cat[selected][selecformule]);
}

	void grausParaRad(double k){
	    dbTs = VerificaEntradas("DIGITE O VALOR EM GRAUS: ");
		graus =  (dbTs * 3.14159265359)/ 180;
		graush = ((dbTs+h) * 3.14159265359)/ 180;
	}

	void validaFuncao1(double k){
		dbTs = VerificaEntradas("DIGITE O VALOR DE K: ");
		aux_k = &dbTs;
	}

	void validaFuncao2(double x, double k){
		dbTs = VerificaEntradas("DIGITE O VALOR DE X: ");
		dbTs2 = VerificaEntradas("DIGITE O VALOR DE K: ");
		aux_x = &dbTs;
		aux_k = &dbTs2;
	}

	void validaFuncao3(double k, double x){
		int validador = 0;
		while (validador == 0){
		dbTs = VerificaEntradas("DIGITE O VALOR DE K: ");
		dbTs2 = VerificaEntradas("DIGITE O VALOR DE X: ");
		if (dbTs < 0 || dbTs == 0){
			Error("DIGITE UM VALOR VALIDO PARA K!\n");
		} else{
			validador = 1;
			aux_k = &dbTs;
			aux_x = &dbTs2;
		}
	  }
	}

	void validaFuncao4(double k, double x){
		int validador = 0;
		while (validador == 0){
		dbTs = VerificaEntradas("DIGITE O VALOR DE K: ");
		dbTs2 = VerificaEntradas("DIGITE O VALOR DE X: ");
		if (dbTs == 0 || dbTs < 0 || dbTs2 == 0 || dbTs2 < 0){
			Error("DIGITE UM VALOR VALIDO PARA K E/OU X!\n");
		} else{
			validador = 1;
			aux_k = &dbTs;
			aux_x = &dbTs2;
		}
	}
}
	void validaFuncao7(double graus){
		int validador = 0;
		while(validador == 0){
		dbTs = VerificaEntradas("DIGITE UM VALOR EM GRAUS: ");
		if(dbTs == 90 || dbTs == 270 || dbTs > 360){
			Error("DIGITE UM VALOR VALIDO!\n");
		} else{
			validador = 1;
			grausParaRad(dbTs);
		}
	  }
	}
	void validaFuncao8(double x){
		int validador = 0;
		while (validador == 0){
		dbTs = VerificaEntradas("DIGITE O VALOR DE X: ");
		if (dbTs < 0){
			Error("DIGITE UM VALOR VALIDO PARA X!\n");
		} else{
			validador = 1;
			aux_x = &dbTs;
		}
	  }
	}

	void validaFuncao9(double x){
		int validador = 0;
		while (validador == 0){
		dbTs = VerificaEntradas("DIGITE O VALOR DE X: ");
		if (dbTs == 0){
			Error("DIGITE UM VALOR VALIDO PARA X!\n");
		} else{
			validador = 1;
			aux_x = &dbTs;
		}
	  }
	}

	void validaFuncao10(double x){
		dbTs = VerificaEntradas("DIGITE O VALOR DE X: ");
		aux_x = &dbTs;
	}

	void validaFuncao11(double x){
		int validador = 0;
		while (validador == 0){
		dbTs = VerificaEntradas("DIGITE O VALOR DE X: ");
		if (dbTs < 0 || dbTs == 0){
			Error("DIGITE UM VALOR VALIDO PARA X!\n");
		} else{
			validador = 1;
			aux_x = &dbTs;
		}
	  }
	}


	double funcao1(double k){
		return k;
	}

	double funcao2(double x, double k){
		return pow(x, k);
	}

	double funcao3(double k, double x){
		return pow(k, x);
	}

	double funcao4(double k, double x){
		return log(x) / log(k) ;
	}

	double funcao5(double graus){
		return sin(graus);
	}

	double funcao6(double graus){
		return cos(graus);
	}

	double funcao7(double graus){
		return tan(graus);
	}

	double funcao8(double x){
		return sqrt(x);
	}

	double funcao9(double x){
		return 1/x;
	}

	double funcao10(double x){
		return pow(2.7182818258 , x);
	}

	double funcao11(double x){
		return log(x);
	}

	double derivada1(double k){
		return ((funcao1(k) + h) - funcao1(k)) / h;
	}
	double derivada2(double x, double k){
		return ((funcao2(x+h, k) - funcao2(x, k)) / h);
	}
	double derivada3(double k, double x){
		return ((funcao3(k+h, x) - funcao3(k, x)) / h);
	}
	double derivada4(double k, double x){
		return ((funcao4(k, x+h) - funcao4(k, x)) / h);
	}
	double derivada5(double graus, double graush){
		return ((funcao5(graush) - funcao5(graus)) / h);
	}
	double derivada6(double graus, double graush){
		return ((funcao6(graush) - funcao6(graus)) / h);
	}
	double derivada7(double graus, double graush){
		return ((funcao7(graush) - funcao7(graus)) / h);
	}
	double derivada8(double x){
		return ((funcao8(x+h) - funcao8(x)) / h);
	}
	double derivada9(double x){
		return ((funcao9(x+h) - funcao9(x)) / h);
	}
	double derivada10(double x){
		return ((funcao10(x+h) - funcao10(x)) / h);
	}
	double derivada11(double x){
		return ((funcao11(x+h) - funcao11(x)) / h);
	}


    void inputIntegral (double a, double b){
        dbTs = VerificaEntradas("Digite o valor de a: ");
		dbTs2 = VerificaEntradas("Digite o valor de b: ");
		aux_a = &dbTs;
		aux_b = &dbTs2;
	}

	void inputIntegralGraus (double a, double b){
        dbTs = VerificaEntradas("Digite o valor de a: ");
		dbTs2 = VerificaEntradas("Digite o valor de b: ");
		dbTs = (dbTs* 3.14159265359)/ 180;
		dbTs2 = (dbTs2* 3.14159265359)/ 180;
		aux_a = &dbTs;
		aux_b = &dbTs2;
	}

	double calculaIntegral1(double a, double b){
		double soma = 0, xi, h, n = 9999;
		h = (b-a) / n;
		int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao1(xi)+soma;
		}
		return h/2 * (funcao1(a) + funcao1(b) + 2*soma);
	}


	double calculaIntegral2(double a, double b){
		double soma = 0, xi, h, n = 9999;
		dbTs = VerificaEntradas("Digite o valor do expoente: ");
        h = (b-a) / n;
        int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao2(xi, dbTs)+soma;
		}
		return h/2 * (funcao2(a, dbTs) + funcao2(b, dbTs) + 2*soma);
	}

	double calculaIntegral3(double a, double b){
		double soma = 0, xi, h, n = 9999;
		dbTs = VerificaEntradas("Digite o valor da base: ");
		h = (b-a) / n;
		int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao3(dbTs, xi)+soma;
		}
		return h/2 * (funcao3(dbTs, a) + funcao3(dbTs, b) + 2*soma);
	}

	double calculaIntegral4(double a, double b){
		double soma = 0, xi, h, n = 9999;
		dbTs = VerificaEntradas("Digite o valor da base: ");
		h = (b-a) / n;
		int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao4(dbTs, xi)+soma;
		}
		return h/2 * (funcao4(dbTs, a) + funcao4(dbTs, b) + 2*soma);
	}

	double calculaIntegral5(double a, double b){
		double soma = 0, xi, h, n = 9999;
		h = (b-a) / n;
		int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao5(xi)+soma;
		}
		return h/2 * (funcao5(a) + funcao5(b) + 2*soma);
	}

	double calculaIntegral6(double a, double b){
		double soma = 0, xi, h, n = 9999;
		h = (b-a) / n;
		int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao6(xi)+soma;
		}
		return h/2 * (funcao6(a) + funcao6(b) + 2*soma);
	}

	double calculaIntegral7(double a, double b){
		double soma = 0, xi, h, n = 9999;
		h = (b-a) / n;
		int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao7(xi)+soma;
		}
		return h/2 * (funcao7(a) + funcao7(b) + 2*soma);
	}

	double calculaIntegral8(double a, double b){
		double soma = 0, xi, h, n = 9999;
		h = (b-a) / n;
		int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao8(xi)+soma;
		}
		return h/2 * (funcao8(a) + funcao8(b) + 2*soma);
	}

	double calculaIntegral9(double a, double b){
		double soma = 0, xi, h, n = 9999;
		h = (b-a) / n;
		int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao9(xi)+soma;
		}
		return h/2 * (funcao9(a) + funcao9(b) + 2*soma);
	}

	double calculaIntegral10(double a, double b){
		double soma = 0, xi, h, n = 9999;
		h = (b-a) / n;
		int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao10(xi)+soma;
		}
		return h/2 * (funcao10(a) + funcao10(b) + 2*soma);
	}

    double calculaIntegral11(double a, double b){
		double soma = 0, xi, h, n = 9999;
		h = (b-a) / n;
		int i;
		for(i = 1; i <= n-1; i++){
			xi= a+i*h;
			soma = funcao11(xi)+soma;
		}
		return h/2 * (funcao11(a) + funcao11(b) + 2*soma);
	}


void somatorio(int k, int a,  int n, int m, int selected){
    double res = 0;
    switch (selected) {
         case 0:{
            for(k; k<= n; k++){
            res += pow(a,k);
            }
            Sucesso("S(A^K) = ",res, " ");
            break;
         }
         case 1:{
            for(k; k<= n; k++){
              res += pow(a,pow(k,m));
            }
             Sucesso("S(A^K^M) =",res, " ");
             break;
         }
         case 2:{
            for(k; k<= n; k++){
              res += pow(a,pow(m,k));
            }
             Sucesso("S(A^M^K) = ",res, " ");
             break;
         }
    }
}

void constantes(double n, int selected){
  double res,divs = 0;
  float k;
  res = 0;
      switch (selected) {
         case 0:{
             for(k=0; k<= n; k++){
                divs = (4*k+1)*(4*k+3);
                res += 8/divs;
             }
             Sucesso("PI = ",res, " ");
             break;
         }
         case 1:{
             k = n;
             divs = 1+(1/k);
             res = pow(divs,k);
             Sucesso("NEPERIANO = ",res, " ");
             break;
         }
     }
}

double permutacao(double n){
  double res = 1;
   for(n; n > 1; n--){
    res*= n;
   }
   return res;
}

void combinatoria(double n, double repeticoes, int selected){
   switch (selected) {
         case 0:{
            Sucesso("PERMUTACAO = ", permutacao(n), "POSSIBILIDADES");
            break;
         }
         case 1:{
            Sucesso("PERMUTACAO COM REPETICAO = ", permutacao(n)/repeticoes, "POSSIBILIDADES");
            break;
         }
         case 2:{
            Sucesso("ARRANJO SIMPLES = ", permutacao(n)/permutacao(n-repeticoes), "POSSIBILIDADES");
            break;
         }
         case 3:{
            Sucesso("ARRANJO COM REPETICAO = ", pow(n,repeticoes), "POSSIBILIDADES");
            break;
         }
         case 4:{
            Sucesso("COMBINACAO SIMPLES = ",permutacao(n)/(permutacao(repeticoes)*permutacao((n-repeticoes))), "POSSIBILIDADES");
            break;
         }
         case 5:{
            Sucesso("COMBINACAO COM REPETICAO = ",permutacao(n+repeticoes-1)/(permutacao(repeticoes)*permutacao(n-1)), "POSSIBILIDADES");
            break;
         }
   }
}

void logicaProposicional(int log_prop, char p, char q){
    switch (log_prop)
        {
            case 0:
                if (p=='V')
                {
                    SucessoC("PARA P=V, ~P E IGUAL A ","F");
                }
                else
                if (p=='F')
                {
                    SucessoC("PARA P=F, ~P E IGUAL A ","V");
                }
                else
                    Error("SOMENTE V E/OU F");
            break;

            case 1:
                if (p=='V' && q=='V')
                {
                    SucessoC("PARA P=V E Q=V, P ^ Q E  IGUAL A ","V");
                }
                else
                if (p=='V' && q=='F')
                {
                    SucessoC("PARA P=V E Q=F, P ^ Q E  IGUAL A ","F");
                }
                else
                if (p=='F' && q=='V')
                {
                    SucessoC("PARA P=F E Q=V, P ^ Q E  IGUAL A ","F");
                }
                else
                if (p=='F' && q=='F')
                {
                    SucessoC("PARA P=F E Q=F, P ^ Q E  IGUAL A ","F");
                }
                else
                    Error("SOMENTE V E/OU F");
            break;

            case 2:
                if (p=='V' && q=='V')
                {
                    SucessoC("PARA P=V E Q=V, P v Q E  IGUAL A ","V");
                }
                else
                if (p=='V' && q=='F')
                {
                    SucessoC("PARA P=V E Q=F, P v Q E  IGUAL A ","V");
                }
                else
                if (p=='F' && q=='V')
                {
                    SucessoC("PARA P=F E Q=V, P v Q E  IGUAL A ","V");
                }
                else
                if (p=='F' && q=='F')
                {
                    SucessoC("PARA P=F E Q=F, P v Q E  IGUAL A ","F");
                }
                else
                    Error("SOMENTE V E/OU F");
            break;


            case 3:
                if (p=='V' && q=='V')
                {
                    SucessoC("PARA P=V E Q=V, P _v Q E  IGUAL A ","F");
                }
                else
                if (p=='V' && q=='F')
                {
                    SucessoC("PARA P=V E Q=F, P _v Q E  IGUAL A ","V");
                }
                else
                if (p=='F' && q=='V')
                {
                    SucessoC("PARA P=F E Q=V, P _v Q E  IGUAL A ","V");
                }
                else
                if (p=='F' && q=='F')
                {
                    SucessoC("PARA P=F E Q=F, P _v Q E  IGUAL A ","F");
                }
                else
               Error("SOMENTE V E/OU F");
            break;

            case 4:
                if (p=='V' && q=='V')
                {
                    SucessoC("PARA P=V E Q=V, P -> Q E  IGUAL A ", "V");
                }
                else
                if (p=='V' && q=='F')
                {
                    SucessoC("PARA P=V E Q=F, P -> Q E  IGUAL A ", "F");
                }
                else
                if (p=='F' && q=='V')
                {
                    SucessoC("PARA P=F E Q=V, P -> Q E  IGUAL A ","V");
                }
                else
                if (p=='F' && q=='F')
                {
                    SucessoC("PARA P=F E Q=F, P -> Q E  IGUAL A ", "V");
                }
                else
                Error("SOMENTE V E/OU F");
            break;

            case 5:
                if (p=='V' && q=='V')
                {
                    SucessoC("PARA P=V E Q=V, P <-> Q E  IGUAL A ","V");
                }
                else
                if (p=='V' && q=='F')
                {
                    SucessoC("PARA P=V E Q=F, P <-> Q E  IGUAL A ","F");
                }
                else
                if (p=='F' && q=='V')
                {
                    SucessoC("PARA P=F E Q=V, P <-> Q E  IGUAL A ","F");
                }
                else
                if (p=='F' && q=='F')
                {
                    SucessoC("PARA P=F E Q=F, P <-> Q E  IGUAL A ","V");
                }
                else
                Error("SOMENTE V E/OU F");
            break;

            case 6:

            break;

            default :
           Error("ESTA NAO E UMA OPCAO VALIDA");
        }
}


void printMatriz(int cols, int rows , int mat[cols][rows]){
 int row, col ;
  SetColor(10);
    for(col = 0; col < cols; col++ )
    {    printf("\n                 ");
        for(row = 0; row < rows; row++)
        {
           printf("%d\t", mat[col][row]);
        }
    }
    SetColor(15);
}

void matrizPrencher(){
int def_col;
 dbTs = VerificaEntradas("Entre com o numero de linhas e colunas: ");
 def_col = dbTs;
 int row, col, deter[def_col][def_col];
    for(col = 0; col < def_col; col++ )
    {
        for(row = 0; row < def_col; row++)
        {
           FormatEntradaMatriz("O valor da", col+1,row+1);
           scanf("%d", &deter[col][row]);
        }
    }
    printMatriz(def_col,def_col,deter);
    Sucesso("Resultado da determinante: ", Determinante(def_col,deter)," ");
}

int soma()
{
   int m, n, c, d;
   dbTs = VerificaEntradas("Entre com o numero de linhas: ");
   m = dbTs;
   dbTs = VerificaEntradas("Entre com o numero de colunas: ");
   n = dbTs;
   int first[m][n], second[m][n],sum[m][n];
   FormatEntrada("Insira os elementos da primeira matriz: \n");
   for (c = 0; c < m; c++){
      for (d = 0; d < n; d++){
         FormatEntradaMatriz("O valor da", d+1,c+1);
         scanf("%d", &first[c][d]);
      }
   }
   FormatEntrada("Insira os elementos da segunda matriz: \n");
   for (c = 0; c < m; c++){
      for (d = 0 ; d < n; d++){
         FormatEntradaMatriz("O valor da", d+1,c+1);
         scanf("%d", &second[c][d]);
      }
   }
   FormatEntrada("Aqui esta o resultado da soma:\n");
   for (c = 0; c < m; c++)
   {
      for (d = 0 ; d < n; d++)
	  {
         sum[c][d] = first[c][d] + second[c][d];
      }
   }
   printMatriz(m,n,sum);
   return 0;
}

int menos()
{
   int m, n, c, d;
   dbTs = VerificaEntradas("Entre com o numero de linhas: ");
   m = dbTs;
   dbTs = VerificaEntradas("Entre com o numero de colunas: ");
   n = dbTs;
   int first[m][n], second[m][n],sub[m][n];
   FormatEntrada("Insira os elementos da primeira matriz: \n");
   for (c = 0; c < m; c++){
      for (d = 0; d < n; d++){
         FormatEntradaMatriz("O valor da", d+1,c+1);
         scanf("%d", &first[c][d]);
      }
   }
   FormatEntrada("Insira os elementos da segunda matriz: \n");
   for (c = 0; c < m; c++){
      for (d = 0 ; d < n; d++){
         FormatEntradaMatriz("O valor da", d+1,c+1);
         scanf("%d", &second[c][d]);
      }
   }
   FormatEntrada("Aqui esta o resultado da subtracao: ");
   for (c = 0; c < m; c++)
   {
      for (d = 0 ; d < n; d++)
	  {
	  	 if (first[c][d] > second[c][d])
		{
            sub[c][d] = first[c][d] - second[c][d];
		}  else
		    sub[c][d] = second[c][d] - first[c][d];
      }
   }
   printMatriz(m,n,sub);
   return 0;
}

int product()
{
  int m, n, p, q, c, d, k, sum = 0;
   dbTs = VerificaEntradas("Entre com o numero de linhas: ");
   m = dbTs;
   dbTs = VerificaEntradas("Entre com o numero de colunas: ");
   n = dbTs;
  int first[m][n], second[m][n], multiply[m][n];
  FormatEntrada("Insira os elementos da primeira matriz\n");
  for (c = 0; c < m; c++){
    for (d = 0; d < n; d++){
      FormatEntradaMatriz("O valor da", d+1,c+1);
      scanf("%d", &first[c][d]);
    }
  }
   dbTs = VerificaEntradas("Entre com o numero de linhas da segunda matriz: ");
   p = dbTs;
   dbTs = VerificaEntradas("Entre com o numero de colunas da segunda matriz: ");
   q = dbTs;
  if (n != p){
    Error("Matrizes nao podem ser multiplicadas!");
  }else{
    FormatEntrada("Insira os elementos da segunda matriz\n");
    for (c = 0; c < p; c++){
      for (d = 0; d < q; d++){
         FormatEntradaMatriz("O valor da", d+1,c+1);
         scanf("%d", &second[c][d]);
      }
    }
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        for (k = 0; k < p; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
        multiply[c][d] = sum;
        sum = 0;
      }
    }

    FormatEntrada("Aqui esta o resultado da multiplicacao: ");
      SetColor(10);
      printf("\n");
     for (c = 0; c < m; c++) {
        printf("\n                 ");
      for (d = 0; d < q; d++){
        printf("%d\t", multiply[c][d]);
      }
    }
      SetColor(15);
  }
  return 0;
}

int Determinante(int n, int a[n][n]){
    if(n == 1){
        return a[0][0];
    }else{
        int det = 0;
        int i, row, col, j_aux, i_aux;

        for(i = 0; i < n; i++){
            if (a[0][i] != 0) {
                int aux[n - 1][n - 1];
                i_aux = 0;
                j_aux = 0;
                for(row = 1; row < n; row++){
                    for(col = 0; col < n; col++){
                        if(col != i){
                            aux[i_aux][j_aux] = a[row][col];
                            j_aux++;
                        }
                    }
                    i_aux++;
                    j_aux = 0;
                }
                int factor = a[0][i]*pow((-1),2+i);
                det = det + factor * Determinante(n - 1, aux);
            }
        }
        return det;
    }
}


#endif // FUNCS_H_INCLUDED
