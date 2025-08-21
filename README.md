# Rede Neural (Multi Layer Perceptron) Implementada para resolver o problema da XOR

Existem duas formas de abstrair o problema matematicamente para ser representado em c.
o primeiro é demonstrado em main.c, onde os inputs e os weights são representados da seguinte forma:

Os inputs são definidos separadamente como um vetor.
Dim: (1x3)
$$
X=[x1​,x2​,1]
$$

Os pesos da entrada são uma matriz 3x2 $W^1$

$$
W^{(1)} =
\begin{bmatrix}
-70 & 90 \\
-20 & 40 \\
30 & -20
\end{bmatrix}​​
$$

Outra forma de representar é pensar nos inputs de modo diferente, utilizando uma matriz 3x3 onde as linhas representam as entradas de uma determinada camada e a coluna um neurônio, um elemento nessa matriz representa a entrada respectiva que um determinadno neurônio tem. ex: I[1][1] representa a entrada na camada 1 no neurônio 1., I[2][1] , a linha 2 representa as entraadas respectivas dos neurônios na camada 2.

Os valores I32 e I33 Não são inicializados pois existem somente um neurônio no final.

$$
I =
\begin{bmatrix}
I_{0,0} & I_{0,1} & I_{0,2} \\
I_{1,0} & I_{1,1} & I_{1,2} \\
I_{2,0} & - & -
\end{bmatrix}
$$