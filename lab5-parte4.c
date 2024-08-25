#include <stdio.h>
#include <omp.h>

int main() {
    int N = 10;
    int variable1 = 0;
    int variable2;

    #pragma omp parallel for shared(variable1) private(variable2)
    for (int i = 0; i < N; i++) {
        variable2 = i * 2;
        variable1 += i;  // Compartida entre hilos
        printf("Hilo %d, variable2 (privada) = %d, variable1 (compartida) = %d\n", omp_get_thread_num(), variable2, variable1);
    }

    printf("Valor final de variable1 (compartida): %d\n", variable1);
    return 0;
}
