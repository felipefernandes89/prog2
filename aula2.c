#include <stdio.h>

void salario_aumento( float *salario, float porcentagem){
    *salario = *salario + (*salario * porcentagem / 100); // o valor do salario vai alterar ao chamar ele na main
}
int main(){
    float meusalario= 2000.0;
    float aumento= 10.0;

    printf("Salario antes do aumento: %.2f\n", meusalario);
    salario_aumento(&meusalario, aumento); // o & passa o endereço de memoria da variavel meusalario para a função salario_aumento, assim a função pode alterar o valor da variavel meusalario diretamente
    printf("Salario depois do aumento: %.2f\n", meusalario);
    return 0;
}
    
