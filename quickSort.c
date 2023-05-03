#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return i + 1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Informe o valor de n: ");
    scanf("%d", &n);

    int array[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        array[i] = rand() % 100;
    }

    clock_t ini, fim;
    double timer;

    ini = clock();

    quickSort(array, 0, n-1);

    fim = clock();

    timer = ((double) (fim - ini)) / (CLOCKS_PER_SEC / 1000);

    printf("Array aleatório em ordem crescente: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\nTempo de execução do código (em milissegundos): %f", timer);

    return 0;
}
