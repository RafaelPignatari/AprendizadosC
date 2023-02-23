#include<stdio.h>

float CalculaMedia(int val1, int val2, int val3) 
{
    return (float)(val1 + val2 + val3) / 3;
}

int main(int argc, char const *argv[])
{
    int val1 = 0;
    int val2 = 0;
    int val3 = 0;
    
    printf("Digite o valor 1: ");
    scanf("%d", &val1);

    printf("Digite o valor 2: ");
    scanf("%d", &val2);

    printf("Digite o valor 3: ");
    scanf("%d", &val3);

    printf("Sua media: ");
    printf("%f", CalculaMedia(val1, val2, val3));

    scanf("%c");

    return 0;
}

