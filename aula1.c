#include  <stdio.h>
#include <string.h>
#include <ctype.h>


int ocorrencia(const char *str1, const char *str2){
    char s1[100], s2[100];
    int i;

    for(i=0; str1[i] != '\0'; i++){
        s1[i] = tolower(str1[i]);
    }
    s1[i] = '\0';

    for (i=0; str2[i] != '\0'; i++){
        s2[i] = tolower(str2[i]);
    }
    s2[i] = '\0';

    if (strstr(s1,s2) != NULL){ // O != NULL significa "é diferente de nulo". Ele é usado para testar se a função strstr encontrou a substring ou se ela falhou na busca.
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char str1[100];
    char str2[100];
    int resultado;
    printf("digite a primeira string: ");
    fgets(str1, sizeof(str1),stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove o 'Enter' retido no final
    printf("digite a segunda string: ");
    fgets(str2, sizeof(str2),stdin); // o fgets ele pega tudo que é digitado ate o esppaço em banco do espac, então usar sempre ele para texto com espaço, e não o scanf
    // scanf ele pega somente o primerio texto e se tiver espaço ele ingnora o texto que vem depois do espaço, então usar ele para texto sem espaço
    str2[strcspn(str2, "\n")] = '\0'; // Remove o 'Enter' retido no final

    resultado= ocorrencia(str1,str2);
    printf("O resultado é: %d\n", resultado);
    return 0;
}