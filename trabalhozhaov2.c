#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

// ----------- VARIÁVEIS GLOBAIS -----------

double n[5]; // ----------- NÚMEROS ESCOLHIDOS
int opcao; // ----------- OPÇÃO ESOLHIDA DO MENU
int iteracao = 1;
// ----------- FUNÇÕES -----------

void scan_numeros(){ // ----------- DEFINE OS NÚMEROS ESCOLHIDOS

    printf("    Digite o primeiro número: ");
    scanf("%lf", &n[0]);

    printf("    Digite o segundo número: ");
    scanf("%lf", &n[1]);

    printf("    Digite o terceiro número: ");
    scanf("%lf", &n[2]);

    printf("    Digite o quarto número: ");
    scanf("%lf", &n[3]);

    printf("    Digite o quinto número: ");
    scanf("%lf", &n[4]);

    printf("\n    Números definidos!\n");
}

void menu(){ // ----------- MENU DA CALCULADORA

    printf("\n     ______________________   Digite uma das operações:            \n"
           "    |  __________________  | \n"
           "    | |  Calculadora 2.0 | |  (0)  Definir números\n"
           "    | |__________________| |  (1)  Listar números\n"
           "    |  ___ ___ ___    ___  |  (2)  Média simples\n"
           "    | | 7 | 8 | 9 |  | / | |  (3)  Média ponderada\n"
           "    | |___|___|___|  |___| |  (4)  Maior e menor\n"
           "    | | 4 | 5 | 6 |  | x | |  (5)  Desvio padrão\n"
           "    | |___|___|___|  |___| |  (6)  Sair\n"
           "    | | 1 | 2 | 3 |  | - | |  \n"
           "    | |___|___|___|  |___| |  \n"
           "    | | = | 0 | , |  | + | |  \n"
           "    | |___|___|___|  |___| |  \n"
           "    |______________________|  \n"
           "                              \n");

}

void listar(){ // ----------- LISTA OS NÚMEROS ESCOLHIDOS

    printf("Primeiro número: %lf", n[0]);

    printf("\nSegundo número: %lf", n[1]);

    printf("\nTerceiro número: %lf", n[2]);

    printf("\nQuarto número: %lf", n[3]);

    printf("\nQuinto número: %lf\n", n[4]);

}

double media_a(){ // ----------- CALCULA A MÉDIA ARITIMÉTICA
    double md;
    md = (n[0]+n[1]+n[2]+n[3]+n[4])/5;
    return md;
}

void pesos(double p[5]){ // ----------- DEFINE OS PESOS DA MÉDIA PONDERADA
    printf("Forneça os valores dos pesos: \n\n");
    for(int i = 0; i < 5; i++)
    {
        printf("Peso para o %dº número (%lf): ", i+1, n[i]);
        scanf("%lf", &p[i]);
    }
}

double media_p(){ // ----------- CALCULA A MÉDIA PONDERADA
    double p[5];
    pesos(p);

    double soma = 0, spesos = 0;
    for(int i = 0; i < 5; i++)
    {
        soma += p[i] * n[i];
        spesos += p[i];
    }
    return soma / spesos;
}

void maior_menor(){ // ----------- DEFINE O MAIOR E O MENOR NUMERO

    double maior = n[0];
    double menor = n[0];

    for(int i = 1; i < 5; i++)
    {
        if(n[i] > maior)
            maior = n[i];
        else if(n[i] < menor)
            menor = n[i];
    }

    printf("Maior: %lf \nMenor: %lf\n", maior, menor);
}

double desvio_padrao(){ // ----------- CALCULA O DESVIO PADRÃO

    double md = media_a();

    double variancia = 0;
    for(int i = 0; i < 5; i++)
        variancia += pow(n[i] - md, 2);
    variancia /= 5;

    printf("Variância: %lf", variancia);

    return sqrt(variancia);

}

void opcoes(){ // ----------- EXECUTA FUNÇÕES COM BASE NO QUE O USUÁRIO ESCOLHER

    printf("\n      Escolha a operação: ");
    scanf("%d", &opcao);
    printf("\n");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    menu();

    switch(opcao){

    case 0:

        scan_numeros();
        break;

    case 1:

        listar();
        break;

    case 2:

        printf("\nMedia arimética: %lf\n", media_a());
        break;

    case 3:

        printf("\nMédia ponderada: %lf\n", media_p());
        break;

    case 4:

        maior_menor();
        break;

    case 5:

        printf("\nDesvio padrão: %lf\n", desvio_padrao());
        break;

    case 6:

        printf("Volte sempre!\n");
        break;

    default:
        printf("\nOperacao invalida!\n");
        break;
    }

}

// ----------- MAIN -----------

int main(){ // ----------- LOOP DE OPÇÕES

    setlocale(LC_ALL, "Portuguese"); // ----------- DEFINE O IDIOMA E PERMITE ACENTOS

    scan_numeros();
    menu();

    while(opcao != 6)
        opcoes();

    return 0;
}
