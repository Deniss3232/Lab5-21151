#include <stdio.h>
#include <omp.h>

int count_key(int *a, int size, int key) {
    int count = 0;

    // Iniciamos la paralelización
    #pragma omp parallel for reduction(+:count)
    for (int i = 0; i < size; i++) {
        if (a[i] == key) {
            count++;
        }
    }
    return count;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 2, 1, 2, 2};
    int key = 2;
    int size = sizeof(a) / sizeof(a[0]);

    // Medimos el tiempo de ejecución
    double start_time = omp_get_wtime();
    
    int result = count_key(a, size, key);
    
    double end_time = omp_get_wtime();
    
    printf("El valor %d aparece %d veces en el vector.\n", key, result);
    printf("Tiempo de ejecución: %f segundos\n", end_time - start_time);

    return 0;
}
