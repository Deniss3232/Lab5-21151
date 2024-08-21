#include <stdio.h>
#include <omp.h>

#define N 1000000  

int lab5() {
    long long suma = 0;  
    double inicio, fin; 
    // variable para acumular el tiempo y la suma

    // Obtener el tiempo de inicio
    inicio = omp_get_wtime();
    
    //r
    #pragma omp parallel for reduction(+:suma)
    for (int i = 1; i <= N; i++) {
        suma += i;
    }
    
    // Obtener el tiempo de fin
    fin = omp_get_wtime();
    
    // resultado de la suma
    printf("La suma de los primeros %d números naturales es: %lld\n", N, suma);
    
    // Mostramos el tiempo que tomó ejecutar el ciclo 
    printf("Tiempo de ejecución: %f segundos\n", fin - inicio);
    
    return 0;
}
