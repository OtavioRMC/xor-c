#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  // Conjunto de entradas (XOR)
  float e1[4]={0.0,0.0,1.0,1.0};  // primeira entrada
  float e2[4]={0.0,1.0,0.0,1.0};  // segunda entrada
  float tg[4]={0.0,1.0,1.0,0.0};  // saída esperada (target)

  // Matrizes de pesos
  float w1[3][3];   // pesos da camada de entrada -> camada oculta
  float w2[3][3];   // pesos da camada oculta -> camada de saída
  float I[3][3];    // valores de entrada em cada camada
  float O[3][3];    // valores de saída em cada camada (após ativação)

  float erro;       // erro médio quadrático
  int i,j,l;        // índices de loops
  int cs;           // índice do caso de treinamento
  int epochs = 0;   // número de tentativas

  // Loop até encontrar pesos que resultem em erro aceitável
  do{

    // Inicializa os pesos w1 aleatoriamente entre -20 e 20
    w1[0][0] = (rand()/2147483647.0)*40.0-20.0;
    w1[1][0] = (rand()/2147483647.0)*40.0-20.0;
    w1[2][0] = (rand()/2147483647.0)*40.0-20.0;

    w1[0][1] = (rand()/2147483647.0)*40.0-20.0;
    w1[1][1] = (rand()/2147483647.0)*40.0-20.0;
    w1[2][1] = (rand()/2147483647.0)*40.0-20.0;

    // Inicializa os pesos w2 aleatoriamente entre -20 e 20
    w2[0][0] = (rand()/2147483647.0)*40.0-20.0;
    w2[1][0] = (rand()/2147483647.0)*40.0-20.0;
    w2[2][0] = (rand()/2147483647.0)*40.0-20.0;

    epochs++;

    erro=0.0;

    // Passa pelos 4 exemplos do XOR
    for(cs=0;cs<4;cs++){

      // Define entradas da rede (camada 0)
      I[0][0] = e1[cs];
      I[0][1] = e2[cs];
      I[0][2] = 1.0;       // bias

      O[0][0] = I[0][0];
      O[0][1] = I[0][1];
      O[0][2] = I[0][2];   // saída da camada de entrada

      // Propagação para a camada oculta
      for(j = 0; j < 2; j++){       // dois neurônios ocultos
        I[1][j]=0.0;
        for(i = 0; i< 3; i++){      // soma ponderada
          I[1][j] +=  w1[i][j]*O[0][i];
        }
        // Função de ativação sigmoide
        O[1][j]=1.0 / (1.0 + exp(-I[1][j]));
      }

      // Bias da camada oculta
      I[1][2]=1.0;
      O[1][2]=I[1][2];

      // Propagação para a camada de saída
      for(l = 0; l < 1; l++){       // apenas 1 neurônio de saída
        I[2][l]=0.0;
        for(j = 0; j< 3; j++){      // soma ponderada
          I[2][l] +=  w2[j][l]*O[1][j];
        }
        // Função de ativação sigmoide
        O[2][l]=1.0 / (1.0 + exp(-I[2][l]));
      }

      // Calcula erro quadrático para esse caso
      erro+=(tg[cs]-O[2][0])*(tg[cs]-O[2][0]);
    } // fim do loop de casos

    // Erro médio
    erro=erro/4.0;

    // Imprime erro e número de tentativas
    printf("Resultado: %f \n",erro );
    printf("Resultado: %i\n",epochs);

  }while(erro>0.0001);  // repete até erro ser pequeno o suficiente

  // Exibe os pesos finais encontrados
  for(j = 0; j < 2; j++){
    for(i = 0; i< 3; i++){
      printf("w1[%d][%d]=%f; \n",i,j,w1[i][j]);
    }
  }

  for(l = 0; l < 1; l++){
    for(j = 0; j< 3; j++){
      printf("w2[%d][%d]=%f; \n",j,l,w2[j][l]);
    }
  }

  return 0;
}
