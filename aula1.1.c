#include <stdio.h>

//Um ponteiro é um tipo especial de variável que armazena um endereço de memória
/*
%s: String (texto)
%p: Endereço de memória (pointer)
%c: Caractere único (char)

%d ou %i: Número inteiro (int)

%f: Número com ponto flutuante/decimal (float)

%lf: Número decimal de alta precisão (double)

*/
int main(){
int x = 1;
int y = 10;
printf("O end de x eh %p \n", &x); //%p é usado para imprimir o endereço de memória de uma variável
printf("O end de y eh %p \n",&y);

return 0;
}