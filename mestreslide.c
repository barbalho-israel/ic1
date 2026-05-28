#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int i, maior, menor;
    maior = 100;
    menor = 0;
    srand(time(NULL));
    int naleatorio = 98;

    int palpite = maior;

        printf("Bem vindo ao jogo!");

        palpite = menor + rand() % (maior);
        printf("\nPalpite %d", palpite);

    for(i= 1; palpite!= naleatorio; ++i){
        if(palpite > naleatorio){
            maior = palpite - 1;
            printf("\nE menor que %d\n", palpite);
            palpite = menor + rand() % (maior - menor + 1);
        }
        else if(palpite < naleatorio){
            printf("\nE maior que %d\n", palpite);
            menor = palpite + 1;
            palpite = menor + rand() % (maior - menor + 1);
        }
    }
    printf("\nVoce acertou! Era %d\n\nTentativas: %d\n", naleatorio, i);



    }

