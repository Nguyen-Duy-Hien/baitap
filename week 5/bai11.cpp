int** getImage (int nRows, int nCols) {
    int** getImage = new int* [nRows];
    for (int i=0; i<nRows; i++)
        getImage[i] = new int [nCols];
    for (int i=0; i<nRows; i++) {
        for (int j=0; j< nCols; j++) {
            cin >> getImage[i][j];
        }
    }
    return getImage;
}

void fillImage (int** image, int nRows, int nCols, int threshold) {
    for (int i=0; i<nRows; i++) {
        for (int j=0; j< nCols; j++) {
            if (image[i][j] < threshold) image[i][j] = 0;
        }
    }
}

void print (int** image, int nRows, int nCols) {
    for (int i=0; i<nRows; i++) {
        for (int j=0; j< nCols; j++) {
            cout << image[i][j] << " ";
        }
        cout <<endl;
    }
}