#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main()
{
    // Variáveis de controle
    int n,m;     // contadores de iteração
    int cs;      // índice aleatório para selecionar um dos 4 exemplos de treino
    float er;    // erro quadrático médio

    // Vetores para entradas e saídas em cada camada
    float I0[4],O0[4],I1[4],O1[4],I2[2],O2[2];

    // Pesos da camada de entrada -> camada oculta (w1) e oculta -> saída (w2)
    float  w1[4][4] ,w2[4][2];

    // Matrizes auxiliares para novos pesos (nw) e termos de momento (vw)
    float nw1[4][4],nw2[4][2];
    float vw1[4][4],vw2[4][2];

    // Gradientes de erro (delta)
    float d2,d1[3];

    // Conjunto de treinamento: problema XOR
    float E1[4]={0.0,0.0,1.0,1.0};  // primeira entrada
    float E2[4]={0.0,1.0,0.0,1.0};  // segunda entrada
    float  t[4]={0.0,1.0,1.0,0.0};  // saída desejada (XOR)

    // Inicialização aleatória dos pesos da primeira camada (entrada -> oculta)
    w1[1][1]=(rand()/2147483647.0)*4.0-2.0; vw1[1][1]=0.0;
    w1[2][1]=(rand()/2147483647.0)*4.0-2.0; vw1[2][1]=0.0;
    w1[3][1]=(rand()/2147483647.0)*4.0-2.0; vw1[3][1]=0.0;

    w1[1][2]=(rand()/2147483647.0)*4.0-2.0; vw1[1][2]=0.0;
    w1[2][2]=(rand()/2147483647.0)*4.0-2.0; vw1[2][2]=0.0;
    w1[3][2]=(rand()/2147483647.0)*4.0-2.0; vw1[3][2]=0.0;

    // Inicialização dos pesos da segunda camada (oculta -> saída)
    w2[1][1]=(rand()/2147483647.0)*4.0-2.0; vw2[1][1]=0.0;
    w2[2][1]=(rand()/2147483647.0)*4.0-2.0; vw2[2][1]=0.0;
    w2[3][1]=(rand()/2147483647.0)*4.0-2.0; vw2[3][1]=0.0;


    // Loop principal de épocas (treinamento)
    for(m=0;m<=1000;m++){
        er=0.0; // erro da época atual

        // Loop interno de iterações (apresentação de exemplos)
        for(n=0;n<=1000;n++){

            // Seleciona aleatoriamente um dos 4 padrões de entrada
            cs=rand()%4;

            // Camada de entrada (com bias fixo = 1.0)
            I0[1]=E1[cs];
            I0[2]=E2[cs];
            I0[3]=1.0;

            O0[1]=I0[1];
            O0[2]=I0[2];
            O0[3]=I0[3];

            // Cálculo da camada oculta (soma ponderada)
            I1[1]=O0[1]*w1[1][1]+O0[2]*w1[2][1]+O0[3]*w1[3][1];
            I1[2]=O0[1]*w1[1][2]+O0[2]*w1[2][2]+O0[3]*w1[3][2];
            I1[3]=1.0; // bias da camada oculta

            // Função de ativação sigmoide nos neurônios ocultos
            O1[1]=1.0/(1.0+exp(-I1[1]));
            O1[2]=1.0/(1.0+exp(-I1[2]));
            O1[3]=I1[3]; // bias passado direto

            // Cálculo da camada de saída
            I2[1]=O1[1]*w2[1][1]+O1[2]*w2[2][1]+O1[3]*w2[3][1];
            O2[1]=1.0/(1.0+exp(-I2[1]));

            // ------------------- BACKPROPAGATION -------------------

            // Cálculo do erro da saída (delta da camada de saída)
            d2=(t[cs]-O2[1])*O2[1]*(1.0-O2[1]);

            // Propagação do erro para a camada oculta
            d1[1]=O1[1]*(1.0-O1[1])*d2*w2[1][1];
            d1[2]=O1[2]*(1.0-O1[2])*d2*w2[2][1];

            // Atualização dos pesos camada oculta -> saída (com taxa de aprendizado=0.5 e momento)
            nw2[1][1]= w2[1][1]+0.5*d2*O1[1]+0.5*vw2[1][1];
            vw2[1][1]=nw2[1][1]-w2[1][1];
            w2[1][1]=nw2[1][1];

            nw2[2][1]= w2[2][1]+0.5*d2*O1[2]+0.5*vw2[2][1];
            vw2[2][1]=nw2[2][1]-w2[2][1];
            w2[2][1]=nw2[2][1];

            nw2[3][1]= w2[3][1]+0.5*d2*O1[3]+0.5*vw2[3][1];
            vw2[3][1]=nw2[3][1]-w2[3][1];
            w2[3][1]=nw2[3][1];

            // Atualização dos pesos entrada -> camada oculta (neurônio 1 da camada oculta)
            nw1[1][1]= w1[1][1]+0.5*d1[1]*O0[1]+0.5*vw1[1][1];
            vw1[1][1]=nw1[1][1]-w1[1][1];
            w1[1][1]=nw1[1][1];

            nw1[2][1]= w1[2][1]+0.5*d1[1]*O0[2]+0.5*vw1[2][1];
            vw1[2][1]=nw1[2][1]-w1[2][1];
            w1[2][1]=nw1[2][1];

            nw1[3][1]= w1[3][1]+0.5*d1[1]*O0[3]+0.5*vw1[3][1];
            vw1[3][1]=nw1[3][1]-w1[3][1];
            w1[3][1]=nw1[3][1];

            // Atualização dos pesos entrada -> camada oculta (neurônio 2 da camada oculta)
            nw1[1][2]= w1[1][2]+0.5*d1[2]*O0[1]+0.5*vw1[1][2];
            vw1[1][2]=nw1[1][2]-w1[1][2];
            w1[1][2]=nw1[1][2];

            nw1[2][2]= w1[2][2]+0.5*d1[2]*O0[2]+0.5*vw1[2][2];
            vw1[2][2]=nw1[2][2]-w1[2][2];
            w1[2][2]=nw1[2][2];

            nw1[3][2]= w1[3][2]+0.5*d1[2]*O0[3]+0.5*vw1[3][2];
            vw1[3][2]=nw1[3][2]-w1[3][2];
            w1[3][2]=nw1[3][2];

            // Acumula erro quadrático
            er+= (t[cs]-O2[1])*(t[cs]-O2[1]);
        }// fim do loop interno (padrões)

        // Média do erro na época
        er=er/1000.0;
        printf("%d %f \n",m,er);
    }// fim do loop externo (épocas)

    // Impressão final dos pesos treinados
    printf("%f %f %f\n",w1[1][1],w1[2][1],w1[3][1]);
    printf("%f %f %f\n",w1[1][2],w1[2][2],w1[3][2]);
    printf("%f %f %f\n",w2[1][1],w2[2][1],w2[3][1]);

}
