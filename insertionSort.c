#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int array[], int x) {
    int i, aux, k;
    for (i = 1; i < x; i++) {
        aux = array[i];
        k = i - 1;

        while (k >= 0 && array[k] > aux) {
            array[k + 1] = array[k];
            k--;
        }
        array[k + 1] = aux;
    }
}

int main() {
    int n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    int array[n];
    for(int i=0; i<n; i++){
        array[i] = rand() % 100;
    }
    // definindo o clock
    clock_t ini, fim;
    double timer;

    ini = clock();

    insertionSort(array, n);

    fim = clock();

    timer = ((double) (fim - ini)) / (CLOCKS_PER_SEC / 1000);

    printf("Array ordenado em ordem crescente: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\nO tempo de execução do código é (em milissegundos): %f", timer);

    return 0;
}
