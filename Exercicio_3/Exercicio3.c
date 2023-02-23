#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

float CalculaDistancia(float altura, float angulo, float velocidade) 
{
    float const gravidade = 9.81;
    float radianos = angulo * M_PI / 180.0;

    return (pow(velocidade, 2) * sin(2 * radianos) + 2 * altura * gravidade) / gravidade;
}

int main()
{
    float altura, angulo, velocidade = 0;    

    printf("Digite a altura: ");
    scanf("%f", &altura);

    printf("Digite o angulo em graus: ");
    scanf("%f", &angulo);

    printf("Digite a velocidade inicial: ");
    scanf("%f", &angulo);

    printf("O objeto chegara ao chao depois de ");
    printf("%f", CalculaDistancia(altura, angulo, velocidade));
    printf(" metros.");

    scanf("%c");

    return 0;
}
