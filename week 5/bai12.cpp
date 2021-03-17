void inputMatrix(int** matrix, int nRows, int nCols) {
    for (int i=0; i<nRows; i++) {
        for (int j=0; j<nCols; j++) {
            cin >> matrix[i][j];
        }
    }
}

int isSymmetric(int** matrix, int nRows, int nCols) {

    if (nRows != nCols) return 0;
    for (int i=0;i<nRows;i++) {
        for (int j=0;j<nCols;j++) {
            if (matrix[i][j]!=matrix[j][i]) return 0;
        }
    }
    return 1;
}