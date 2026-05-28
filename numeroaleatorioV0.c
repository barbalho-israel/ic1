#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    int continuar = 0;

while(continuar == 0){

    int i = 1;
    int palpite;
    int maior = 100, menor = 0;

    srand(time(NULL));
    int naleatorio = rand() % 101;

        printf("\n  Bem vindo ao jogo!\n");

        printf("\n  Pensei em um número entre 0 e 100, tente advinhá-lo:\n\n");

    for(i= 1; palpite!= naleatorio; i++){

        printf("Palpite %d: ", i);
        scanf("%d", &palpite);

        if(palpite < naleatorio){
                menor = (palpite > 0) ? palpite : 0;
                printf("Ele é maior\n\n");
                }
        if(palpite > naleatorio){
                maior = (palpite < 100) ? palpite : 100;
                printf("Ele é menor\n\n");
                }

        printf("        Está entre %d e %d \n\n", menor, maior);

        }

    printf("\nVoce acertou! Era %d \nTentativas: %d\n", naleatorio, i-1);

    printf("\nDigite 0 para continuar ou qualquer outro número para sair:\n");
    scanf("%d", &continuar);

    }

    printf("\nVolte sempre!\n");

    return 0;

}
