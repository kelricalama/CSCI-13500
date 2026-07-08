#include <iostream>

// Reminder: Information about functions is on the specification PDF

void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total){

    std::cout << "Print2DArray Started!" << std::endl;

    for (int row = 0; row < matrix_local_rows_total; row++) {
        std::cout << "[ ";
        for (int column = 0; column < 3; column++) {
            std::cout << matrix_local[row][column];

            if (column < 2) {
                std::cout << " | ";
            }
        }
        std::cout << " ]" << std::endl;
    } 
    // Time Complexity: O(n*m)

    std::cout << "Print2DArray Finished!" << std::endl;
}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3], const int matrix_two_rows_total)
    {
        std::cout << "MatrixAddition Started!" << std::endl;

        if (matrix_one_rows_total != matrix_two_rows_total) {
            std::cout << "Invalid matrix dimensions" << std::endl;
            return;
    }

    int result[3][3];

    for (int row = 0; row < matrix_one_rows_total; row++) {
        for (int column = 0; column < 3; column++) {
            result[row][column] =
                matrix_one[row][column] + matrix_two[row][column];
        }
    }

    Print2DArray(result, matrix_one_rows_total);

    // Time Complexity: O(n*m)

    std::cout << "MatrixAddition Finished!" << std::endl;
    
}



void TransposeMatrix(const int matrix_local[][3], const int matrix_local_rows_total){
    std::cout << "TransposeMatrix Started!" << std::endl;

    int result[3][3];

    for (int row = 0; row < matrix_local_rows_total; row++) {
        for (int column = 0; column < 3; column++) {
            result[column][row] = matrix_local[row][column];
        }
    }

    Print2DArray(result, 3);

    // Time Complexity: O(n*m)

    std::cout << "TransposeMatrix Finished!" << std::endl;
}

void Determinant(const int matrix_local[][3], const int size){
    std::cout << "Determinant Started!" << std::endl;

    if (size != 2 && size != 3) {
        std::cout << "Invalid matrix size" << std::endl;
        return;
    }

    int determinant_value = 0;

    if (size == 2) {

        determinant_value =
            (matrix_local[0][0] * matrix_local[1][1]) -
            (matrix_local[0][1] * matrix_local[1][0]);

    } else if (size == 3) {

        determinant_value =
            matrix_local[0][0] *
            ((matrix_local[1][1] * matrix_local[2][2]) -
             (matrix_local[1][2] * matrix_local[2][1]))

            -

            matrix_local[0][1] *
            ((matrix_local[1][0] * matrix_local[2][2]) -
             (matrix_local[1][2] * matrix_local[2][0]))

            +

            matrix_local[0][2] *
            ((matrix_local[1][0] * matrix_local[2][1]) -
             (matrix_local[1][1] * matrix_local[2][0]));
    }

    std::cout << "Determinant = " << determinant_value << std::endl;

    // Time Complexity: O(1)

    std::cout << "Determinant Finished!" << std::endl;
}

void SearchValue(const int matrix_local[][3], const int rows, const int target){
    std::cout << "SearchValue Started!" << std::endl; 

    bool found = false;

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < 3; column++) {

            if (matrix_local[row][column] == target) {
                std::cout << "Found " << target
                          << " at [" << row << "][" 
                          << column << "]" << std::endl;
                found = true;
            }
        }
    }

    if (!found) {
        std::cout << target << " was not found in the matrix" << std::endl;
    }

    // Time Complexity: O(n*m)

    std::cout << "SearchValue Finished!" << std::endl;
}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3], 
                    const int rows_a, const int cols_a, 
                    const int rows_b, const int cols_b){
    
    std::cout << "MatrixMultiplication Started!" << std::endl;
    
    if (cols_a != rows_b) {
        std::cout << "Invalid matrix dimensions for multiplication"
                  << std::endl;
        return;
    }

    int result[3][3] = {};

    for (int row = 0; row < rows_a; row++) {
        for (int column = 0; column < cols_b; column++) {

            for (int index = 0; index < cols_a; index++) {
                result[row][column] +=
                    matrix_a[row][index] *
                    matrix_b[index][column];
            }
        }
    }

    Print2DArray(result, rows_a);

    // Time Complexity: O(n^3)

    std::cout << "MatrixMultiplication Finished!" << std::endl;
}

int main(){
    // Use these two matrices for basic testing.

    int testing_matrix_one[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int testing_matrix_two[3][3] = {
        {12,65,82},
        {83,2,8},
        {10,96,67}
    };


// Not used in this class, but it is nice to know other ways to find the size of primitive array.
// This method below is similar to how you will find the size of vectors (future material)
    // DO NOT USE IN THIS PROJECT FUNCTION, but you could test it yourselves.
    // int size_row_one = std::size(testing_matrix_one);
    // int size_col_one = std::size(testing_matrix_one[0]);


    // This is a way to find the dimensions of an array without hardcoding values.
    // It dynamically reflects the array's actual declared size, so if you change
    // the array dimensions, the calculation updates automatically.
    //
    // How it works:
    //
    // To find the number of ROWS:
    //   sizeof(testing_matrix_one)      = total bytes of the whole array = 3*9*4 = 108 bytes
    //   sizeof(testing_matrix_one[0])   = total bytes of one row         = 1*9*4 =  36 bytes
    //   108 / 36 = 3 rows
    
    int size_row_one = sizeof(testing_matrix_one)/sizeof(testing_matrix_one[0]);

    // To find the number of COLUMNS:
    //   sizeof(testing_matrix_one[0])      = total bytes of one row          = 1*9*4 = 36 bytes
    //   sizeof(testing_matrix_one[0][0])   = total bytes of one element(int) = 1*4   =  4 bytes
    //   36 / 4 = 9 cols
    
    int size_col_one = sizeof(testing_matrix_one[0])/sizeof(testing_matrix_one[0][0]);

    std::cout << "row: " << size_row_one<< " col: " << size_col_one<< std::endl << std::endl;

    Print2DArray(testing_matrix_one, size_row_one);

    return 0; 
}