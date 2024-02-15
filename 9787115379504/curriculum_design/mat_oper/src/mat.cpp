#include "mat.h"

//初始化矩阵
Mat InitMat(Mat mat, int row, int col) {
    mat.row = row;
    mat.col = col;
    mat.arr = new int * [mat.row] {0};
    mat.arr[0] = new int[mat.row * mat.col] {0};
    for (int i = 1; i < mat.row; i++) {
        mat.arr[i] = mat.arr[0] + i * mat.col;
    }
    return mat;
}