#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  float e1[4]={0.0,0.0,1.0,1.0};
	float e2[4]={0.0,1.0,0.0,1.0};
	float tg[4]={0.0,1.0,1.0,0.0};

    float w1[3][3];
    float w2[3][3];
    float I[3][3];
    float O[3][3];
    float erro;
    int i,j,l;
    int cs;
    int epochs = 0;


    do{

    w1[0][0] = (rand()/2147483647.0)*40.0-20.0;
    w1[1][0] = (rand()/2147483647.0)*40.0-20.0;
    w1[2][0] = (rand()/2147483647.0)*40.0-20.0;

    w1[0][1] = (rand()/2147483647.0)*40.0-20.0;
    w1[1][1] = (rand()/2147483647.0)*40.0-20.0;
    w1[2][1] = (rand()/2147483647.0)*40.0-20.0;

    w2[0][0] = (rand()/2147483647.0)*40.0-20.0;
    w2[1][0] = (rand()/2147483647.0)*40.0-20.0;
    w2[2][0] = (rand()/2147483647.0)*40.0-20.0;

    epochs++;

	erro=0.0;
    for(cs=0;cs<4;cs++){

    I[0][0] = e1[cs];
    I[0][1] = e2[cs];
    I[0][2] = 1.0;


    O[0][0] = I[0][0];
    O[0][1] = I[0][1];
    O[0][2] = I[0][2];

    for(j = 0; j < 2; j++){
    	I[1][j]=0.0;
    	for(i = 0; i< 3; i++){
    		I[1][j] +=  w1[i][j]*O[0][i];
		}
		O[1][j]=1.0 / (1.0 + exp(-I[1][j]));
	}

    I[1][2]=1.0;
    O[1][2]=I[1][2];

   for(l = 0; l < 1; l++){
    	I[2][l]=0.0;
    	for(j = 0; j< 3; j++){
    			I[2][l] +=  w2[j][l]*O[1][j];
		}
		O[2][l]=1.0 / (1.0 + exp(-I[2][l]));
	}
    erro+=(tg[cs]-O[2][0])*(tg[cs]-O[2][0]);
}//close for cs

	erro=erro/4.0;
    printf("Resultado: %f \n",erro );
    printf("Resultado: %i\n",epochs);

    }while(erro>0.0001);

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
