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

  // Inputs I1, I2 e I3 (Bias)
  float input[3] = {1.0,0.0,1.0};

  // Pesos da Camada de Entrada para  a hidden layer
  float weights_layer_one[3][2];

  // Pesos da Camada Hidden para a camada final
  float weights_layer_two[3];

  // Vetor resultante da multiplicação da camada de entrada
  // com os dois neurônios da hidden.
  float output_hidden[2];

  // Inicialização dos Inputs
  input[0] = 1.0f;
  input[1] = 0.0f;
  input[2] = 1.0f;

  // inicializar pesos da primeira camada em relação ao neurônio 1.
  // [i -> Inputs][j -> 1 Neurônio da Hidden Layer ]
  weights_layer_one[0][0] = -70.0f;
  weights_layer_one[1][0] = -20.0f;
  weights_layer_one[2][0] = 30.0f;

  // Inicializar pesos da primeira camada em relação ao neurônio 2.
  // Todas as ligações com o 2 neurônio da hidden layer.
  weights_layer_one[0][1] = 90.0f;
  weights_layer_one[1][1] = 40.0f;
  weights_layer_one[2][1] = -20.0f;

  // Ligações da Camada 2 -> Output
  weights_layer_two[0] = 50.0f;
  weights_layer_two[1] = 40.0f;
  weights_layer_two[2] = -55.0f;

  // Foward Pass inputs -> hidden layer
  for(int j = 0; j<2; j++){
    double sum = 0.0;
    for (int i=0; i<3; i++){
      sum += input[i] * weights_layer_one[i][j];
    }
    output_hidden[j] = sigmoid(sum);
  }

  //Foward Pass Hidden -> Output
  double sum = 0.0;
  for(int i=0; i<2; i++){
    sum += output_hidden[i] * weights_layer_two[i];
  }

  // Soma com o bias da saída.
  sum = sum + weights_layer_two[2];

  double output = sigmoid(sum);

  printf("Resultado da XOR = %.4f\n",output);
  
  return 0;
}