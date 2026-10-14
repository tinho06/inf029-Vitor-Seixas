// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

int bissexto(int bis0, int ano){
    bis0 = 1;
    
    if(ano % 4 != 0){
        bis0 = 0;
    }

    else if(ano % 4 == 0 && ano % 100 == 0 && ano % 400 != 0){
        bis0 = 0;
    }

    return bis0;

}

int data_para_inteiro(char data0[]){

    int resultado = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int achou_data = 0;
    int achou_mes = 0;
    int dia_inteiro;
    int mes_inteiro;
    int ano_inteiro;
    char dia[3];
    char mes[3];
    char ano[5];
    char data[11];

    while(!achou_data){
        if(data0[i] == '/'){
            achou_data = 1;
        }
        
        else{
            dia[i] = data0[i];
            i++;
        }
    }

    dia[i] = '\0';
    j = i + 1;

    while(!achou_mes){
        if(data0[j] == '/'){
            achou_mes = 1;
        }

        else{
            mes[k] = data0[j];
            j++;
            k++;
        }
    }

    mes[k] = '\0';
    l = j + 1;

    while(data0[l] != '\0'){
        ano[m] = data0[l];
        m++;
        l++;
    }

    ano[m] = '\0';

    dia_inteiro = atoi(dia);
    mes_inteiro = atoi(mes);
    ano_inteiro = atoi(ano);

    resultado = (ano_inteiro * 10000) + (mes_inteiro * 100) + dia_inteiro;

    return resultado;
    
}

int achar_numeros(int numero1, int numerobusca0)
{

    int n2 = 0;
    int n1 = 0;
    int potencia = 1;
    int casas_decimais = 0;
    int n0 = 0;
    int cont1 = 0;
    int cont2 = 0;

    for(n0 = numero1; n0 > 0; n0 /= 10){
        casas_decimais++;
    }

    n2 = numero1;

    while(cont1 < casas_decimais){
        n1 = n2 % 10;
       if(n1 == numerobusca0){
        cont2++;
       } 
        n2 /= 10;
        cont1++;
    
    }


    return cont2;
}


/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int valido = 1;

  int bis = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int achou_data = 0;
    int achou_mes = 0;
    int dia_inteiro;
    int mes_inteiro;
    int ano_inteiro;
    char dia[3];
    char mes[3];
    char ano[5];

    while(!achou_data){
        if(data[i] == '/'){
            achou_data = 1;
        }
        
        else{
            dia[i] = data[i];
            i++;
        }
    }

    dia[i] = '\0';
    j = i + 1;

    while(!achou_mes){
        if(data[j] == '/'){
            achou_mes = 1;
        }

        else{
            mes[k] = data[j];
            j++;
            k++;
        }
    }

    mes[k] = '\0';
    l = j + 1;

    while(data[l] != '\0'){
        ano[m] = data[l];
        m++;
        l++;
    }

    ano[m] = '\0';

    dia_inteiro = atoi(dia);
    mes_inteiro = atoi(mes);
    ano_inteiro = atoi(ano);

    bis = bissexto(bis, ano_inteiro);

    if(mes_inteiro == 4 || mes_inteiro == 6 || mes_inteiro == 9 || mes_inteiro == 11){
        if(dia_inteiro > 30){
            valido = 0;
        }
    }

    if(bis == 1 && mes_inteiro == 2 && dia_inteiro > 29){
        valido = 0;
    }

    if(bis == 0 && mes_inteiro == 2 && dia_inteiro > 28){
        valido = 0;
    }

    if(mes_inteiro == 1 || mes_inteiro == 3 || mes_inteiro == 5 || mes_inteiro == 7 || mes_inteiro == 8 || mes_inteiro == 10 || mes_inteiro == 12){
        if(dia_inteiro > 31){
            valido = 0;
        }
    }
    
    if(mes_inteiro > 12){
        valido = 0;
    }

    if(!dia_inteiro){
        valido = 0;
    }

  if (valido)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
        int data_inicial_inteira;
        int data_final_inteira;
        data_inicial_inteira = data_para_inteiro(datainicial);
        data_final_inteira = data_para_inteiro(datafinal);

        if(data_inicial_inteira > data_final_inteira){
            dma.retorno = 4;
            return dma;
        }

      //calcule a distancia entre as datas
        int ano1 = data_inicial_inteira / 10000;
        int mes1 = (data_inicial_inteira / 100) % 100;
        int dia1 = data_inicial_inteira % 100;

        int ano2 = data_final_inteira / 10000;
        int mes2 = (data_final_inteira / 100) % 100;
        int dia2 = data_final_inteira % 100;
        
        int qtdAnos = ano2 - ano1;
        int qtdMeses = mes2 - mes1;
        int qtdDias = dia2 - dia1;

        if(qtdDias < 0){
            qtdDias += 30;
            qtdMeses--;
        }
      
        if(qtdMeses < 0){
            qtdMeses += 12;
            qtdAnos--;
        }

        //se tudo der certo
      dma.qtdDias = qtdDias;
        dma.qtdMeses = qtdMeses;
        dma.qtdAnos = qtdAnos;
        dma.retorno = 1;
        return dma;
        dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

    if(isCaseSensitive == 1){
        for(int i = 0; texto[i] != '\0'; i++){
            if(c == texto[i]){
            qtdOcorrencias++;
            }

        }
    }
    
    else if(isCaseSensitive != 1){
        for(int i = 0; texto[i] != '\0'; i++){
            if(c == texto[i] || c - texto[i] == 32){
            qtdOcorrencias++;
            }

        }
    }
    
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int l = 0;
    int cont = 0;
    /*PERCORRER O VETOR*/
    for(int k = 0; strBusca[k] != '\0'; k++){
        cont++;
    }

    for(int i = 0; strTexto[i] != '\0'; i++){
        int achou = 1;
        for(int j = 0; j < cont; j++){
            if(strTexto[i + j] != strBusca[j] || strTexto[i + j] == '\0'){
                achou = 0;
                break;
            }
        
        }

        if(achou){
                qtdOcorrencias++;
                posicoes[l] = i + 1;
                l++;
                posicoes[l] = i + cont;
                l++;
            }

    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    int result = 0;
    int n2 = 0;
    int n1 = 0;
    int potencia = 1;
    int casas_decimais = 0;
    int n0 = 0;
    int cont = 0;

    for(n0 = num; n0 > 0; n0 /= 10){
        casas_decimais++;
    }

    for(int i = 1; i < casas_decimais; i++){
        potencia *= 10;
    }

    n2 = num;

    while(cont < casas_decimais){
        n1 = n2 % 10;
        n2 /= 10;
        result += n1 * potencia;
        potencia /= 10;
        cont++;
    
    }

    num = result;

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    char strBase[50];
    char strBusca[50];
    
    sprintf(strBase, "%d", numerobase);
    sprintf(strBusca, "%d", numerobusca);
    
    int qtdOcorrencias = 0;
    int tamBusca = strlen(strBusca);
    int tamBase = strlen(strBase);
    
    if (tamBusca > tamBase) {
        return 0;
    }
    
    for (int i = 0; i <= tamBase - tamBusca; i++) {
        int achou = 1;
        for (int j = 0; j < tamBusca; j++) {
            if (strBase[i + j] != strBusca[j]) {
                achou = 0;
                break;
            }
        }
        if (achou) {
            qtdOcorrencias++;
        }
    }
    
    return qtdOcorrencias;
    
    
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
     int achou = 0;
     
     int len = strlen(palavra);
    
    // Vetores de direção para as 8 direções possíveis (cima, baixo, esquerda, direita e diagonais)
    int dr[] = {-1, -1, -1,  0,  0,  1,  1,  1};
    int dc[] = {-1,  0,  1, -1,  1, -1,  0,  1};

    // 1. Percorre cada célula da matriz para tentar achar o início da palavra
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 10; c++) {
            
            // 2. Testa as 8 direções a partir da célula atual (r, c)
            for (int d = 0; d < 8; d++) {
                int k;
                
                // 3. Verifica letra por letra na direção escolhida
                for (k = 0; k < len; k++) {
                    int nr = r + k * dr[d];
                    int nc = c + k * dc[d];

                    // Se saiu dos limites da matriz ou a letra não bateu, interrompe essa direção
                    if (nr < 0 || nr >= 8 || nc < 0 || nc >= 10 || matriz[nr][nc] != palavra[k]) {
                        break;
                    }
                }
                
                // Se o loop completou todas as letras sem falhar, encontramos a palavra!
                if (k == len) {
                    achou = 1;
                    return achou;
                }
            }
        }
    }
     
     return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

