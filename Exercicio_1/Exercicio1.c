#include<stdio.h>

int main(int argc, char const *argv[])
{
    int tempoRecebido = 0;

    printf("Digite um tempo a ser convertido (s): ");
    scanf("%d", &tempoRecebido);

    printf("Tempo em segundos: ");
    printf("%d", tempoRecebido);

    printf("\nTempo em minutos: ");
    printf("%d", tempoRecebido / 60);

    printf("\nTempo em horas: ");
    printf("%d", tempoRecebido / 3600);

    printf("\n");

    scanf("%c");

    return 0;
}
