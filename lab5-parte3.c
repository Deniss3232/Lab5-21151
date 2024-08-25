#include <stdio.h>
#include <omp.h>

void factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial de %d: %d\n", n, fact);
}

void fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    printf("Serie Fibonacci hasta %d: %d, %d", n, t1, t2);
    for (int i = 3; i <= n; i++) {
        nextTerm = t1 + t2;
        printf(", %d", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

void max_in_array(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Máximo en el arreglo: %d\n", max);
}

int main() {
    int n = 5;
    int arr[] = {3, 5, 7, 2, 8, -1, 4, 10, 12};
    
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            factorial(n);
        }
        #pragma omp section
        {
            fibonacci(n);
        }
        #pragma omp section
        {
            max_in_array(arr, 9);
        }
    }

    return 0;
}
