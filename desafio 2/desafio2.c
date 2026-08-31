#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hora, minuto;
} t_Momento;

void tempoatual(int percorrido, t_Momento *momento) {
    momento->hora = (percorrido / 60) % 24;
    momento->minuto = percorrido % 60;
}

int main(int argc, char *argv[]) {
    int n, i;
    t_Momento m1, m2, atual;
    int percorrido, d1, d2;

    if (argc < 2) return 1;

    n = atoi(argv[1]);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &m1.hora, &m1.minuto);
        scanf("%d %d", &m2.hora, &m2.minuto);
        scanf("%d", &percorrido);

        tempoatual(percorrido, &atual);

        d1 = abs(atual.hora - m1.hora);
        d2 = abs(atual.hora - m2.hora);

        if (d1 <= d2) {
            printf("%02d:%02d\n", m1.hora, m1.minuto);
        } else {
            printf("%02d:%02d\n", m2.hora, m2.minuto);
        }
    }

    return 0;
}