#include <stdio.h>

int main() {
    int x;
    int *p;

    p = &x; // CORREÇÃO: p agora guarda o endereço de x
    *p = 100; // Agora 100 é guardado com segurança dentro da variável x

    printf("x=%d p=%p\n", x, p);
    return 0;
}