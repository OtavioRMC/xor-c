#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float I[3][3];
    float O[3][3];
    float w1[3][2];
    float w2[3][1];

    w1[0][0] = 50;
    w1[1][0] = 40;
    w1[2][0] = -20;

    w1[0][1] = -60;
    w1[1][1] = -30;
    w1[2][1] = 70;

    w2[0][0] = 70;
    w2[1][0] = 90;
    w2[2][0] = -130;

    printf("Digite o valor da entrada 1: ");
    scanf("%f", &I[0][0]);

    printf("Digite o valor da entrada 2: ");
    scanf("%f", &I[0][1]);

    I[0][2] = 1;

    //Outputs

    O[0][0] = I[0][0];
    O[0][1] = I[0][1];
    O[0][2] = I[0][2];

    // Segunda camada

    I[1][0] = O[0][0] * w1[0][0] + O[0][1] * w1[1][0] + O[0][2] * w1[2][0];
    I[1][1] = O[0][0] * w1[0][1] + O[0][1] * w1[1][1] + O[0][2] * w1[2][1];
    I[1][2] = 1;

    // Sigmoid

    O[1][0] = 1/(1+exp(-I[1][0]));
    O[1][1] = 1/(1+exp(-I[1][1]));
    O[1][2] = I[1][2];

    // Saida

    I[2][0] = O[1][0] * w2[0][0] + O[1][1] * w2[1][0] + O[1][2] * w2[2][0];
    O[2][0] = 1/(1+exp(-I[2][0]));

    printf("\nResultado: %.0f", O[2][0]);
    return 0;
}