#include <stdio.h>
#include <stdlib.h>

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

int main(){

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
    char data[11];

    printf("digite uma data:\n");
    fgets(data, sizeof(data), stdin);

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

    if(valido){
        printf("data valida\n");
    }

    else{
        printf("data_invalida\n");
    }
}