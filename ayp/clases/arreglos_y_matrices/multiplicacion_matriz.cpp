void mulmatrix(float **matrizR, float **matrizA, float **matrizB, int fa, int ca, int fb, int cb) {
    if(ca != fb) {
        return;
    }

    for(int i = 0; i < fb; i++) {
        for(int j = 0; j < ca; j++) {
            float r = 0;

            for(int k = 0; k < fb; k++) {
                r += matrizA[i][k] * matrizB[k][j];
            }
            matrizR[i][j] = r;
        }
    }
}