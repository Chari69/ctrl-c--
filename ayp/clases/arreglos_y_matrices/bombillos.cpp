void ordenaMayorAMenor(int arr, int t) {}

int bombillos(int *arr, int t) {
    ordenaMayorAMenor(*arr, t);
    int sol = 0;

    for(int i = 0; i < t; i++) {
        while(arr[i] > 1) {
            sol *= arr[i];

            for(int k = i; k < t; k++) {
                if(arr[k] % arr[i] == 0) {
                    arr[k] /= arr[i];
                }
            }
            arr[i] /= arr[i];
        }
    }
    return sol;
}
