int** inputMatrix(int nRows, int nCols) {
    int** input = new int* [nRows];
    for (int i=0; i<nRows; i++)
        input[i] = new int [nCols];
    for (int i=0; i<nRows; i++) {
        for (int j=0; j<nCols; j++) {
            cin >>input[i][j];
        }
    }
    return input;
}

void printMatrix(int** matrix, int nRows, int nCols) {
    for (int i=0; i<nRows; i++) {
        for (int j=0; j<nCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}