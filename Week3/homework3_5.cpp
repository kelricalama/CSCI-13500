#include <iostream>
#include <vector>

int main() {
    const int size_3 = 3;
    const int size_6 = 6;

    int matrix_3x3[size_3][size_3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix_6x6[size_6][size_6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };

    for (int i = 0; i < size_3; i++) {
        for (int j = 0; j < size_3; j++) {
            if (i + j < size_3) {
                matrix_3x3[i][j] = 1;
            }
            else {
                matrix_3x3[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < size_6; i++) {
        for (int j = 0; j < size_6; j++) {
            if (i + j < size_6) {
                matrix_6x6[i][j] = 1;
            }
            else {
                matrix_6x6[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < size_3; i++) {
        for (int j = 0; j < size_3; j++) {
            std::cout << matrix_3x3[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < size_6; i++) {
        for (int j = 0; j < size_6; j++) {
            std::cout << matrix_6x6[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;

}
