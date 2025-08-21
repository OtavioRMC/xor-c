/*
  Author: Otávio Ribeiro Moreira da Costa
  XOR implemented in C.
  Without Backpropagation.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  Função de Ativação Sigmoide
  Mantem o valor de x entre 0 e
*/
double sigmoid(double x) {
  return 1.0 / (1.0 + exp(-x));
}

int main(){

  float input[1][3];
  // Pesos da Camada de Entrada para  a hidden layer
  float weights_layer_one[3][2];

  // Pesos da Camada Hidden para a camada final
  float weights_layer_two[1][3];

 // Inicializar Inputs
  input[0][0] = 1.0f;
  input[0][1] = 0.0f;
  input[0][2] = 1.0f;

  // inicializar pesos da primeira camada em relação ao neurônio 1.
  // [i -> Inputs][j -> 1 Neurônio da Hidden Layer ]
  weights_layer_one[0][0] = -70.0f;
  weights_layer_one[1][0] = -20.0f;
  weights_layer_one[2][0] = 30.0f;

  // Inicializar pesos da primeira camada em relação ao neurônio 2.
  // Todas as ligações com o 2 neurônio da hidden layer.
  weights_layer_one[0][0] = 90.0f;
  weights_layer_one[0][1] = 40.0f;
  weights_layer_one[0][2] = 20.0f;

  // Ligações da Camada 2 -> Output
  weights_layer_two[0][0] = 50.0f;
  weights_layer_two[0][1] = 40.0f;
  weights_layer_two[0][2] = 55.0f;

  for(int i=0; i<3; i++){
    for(int j=0; )
  }


  return 0;
}