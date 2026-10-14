#include <stdio.h>
#include <stdlib.h>

int achar_numeros(int numero1, int numerobusca)
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
       if(n1 == numerobusca){
        cont2++;
       } 
        n2 /= 10;
        cont1++;
    
    }


    return cont2;
}
