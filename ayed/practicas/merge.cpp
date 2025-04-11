// Mi propia implementación del .merge() que será utilizado en un futuro en un MergeSort.
#include <iostream>
using namespace std;

int* merge(int *arr1, int *arr2, int arr1_size, int arr2_size) {
    int i = 0, j = 0, k = 0;

    int size = arr1_size + arr2_size;
    int *array = new int[size];

    while (i < arr1_size && j < arr2_size) {
        if(arr1[i] <= arr2[j]) {
            array[k++] = arr1[i++];
        } else {
            array[k++] = arr2[j++];
        }
    }

    while (i < arr1_size) {
        array[k++] = arr1[i++];
    }

    while (j < arr2_size) {
        array[k++] = arr2[j++];
    }

    return array;
}

// Caso de Prueba
int main() {
    int a1[3] = {5, 13, 24};
    int a2[3] = {7, 15, 22};

    int arr1_s = sizeof(a1)/sizeof(a1[0]);
    int arr2_s = sizeof(a2)/sizeof(a2[0]);

    int *arr = merge(a1, a2, arr1_s, arr2_s);

    for (int i = 0; i < arr1_s + arr2_s; i++) {
        cout << arr[i] << endl;
    }
}
