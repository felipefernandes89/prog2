#include <stdio.h>
int main(){
int x = 1; //variável int
float y = 10.0; //variável float
int *p1; //ponteiro para variável int
float *p2; //ponteiro para variável float
p1 = &x; //p1 aponta para x
p2 = &y; //p2 aponta para y

printf(" O end de x é: %p \n", p1); //imprime o endereço de x
printf(" O end de y é: %p \n", p2); //imprime o endereço de y
printf(" O valor de x é: %d \n", *p1); //imprime o valor de x usando o ponteiro p1
printf(" O valor de y é: %.2f\n", *p2); //imprime o valor de y usando o ponteiro p2
return 0;
}
