#include <stdio.h> 
//Operador unário (*)que devolve o conteúdo da variável localizada no endereço que o segue (ponteiro)

int main(){
int x = 31;
int y;
int *p1;
p1 = &x; // p1 recebe o endereço de memoria de x
y = *p1;  // y recebe o valor de x, que está localizado no endereço de memoria armazenado em p1
printf("O valor de y eh %d", y);
return 0;
}