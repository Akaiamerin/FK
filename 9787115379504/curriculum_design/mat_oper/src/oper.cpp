#include <iostream>
#include "oper.h"

//输入矩阵
Mat InputMat(Mat & mat) {
    std::cout << "请输入矩阵的行数和列数：";
    std::cin >> mat.row >> mat.col;
    std::cout << "请输入矩阵的元素" << std::endl;
    mat = InitMat(mat, mat.row, mat.col);
    for (int i = 0; i < mat.row; i++) {
        for (int j = 0; j < mat.col; j++) {
            std::cout << "mat[" << i << "][" << j << "] = ";
            std::cin >> mat.arr[i][j];
        }
    }
    return mat;
}

//输出矩阵
void OutputMat(Mat mat) {
    for (int i = 0; i < mat.row; i++) {
        for (int j = 0; j < mat.col; j++) {
            std::cout << mat.arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//矩阵转置
Mat TransposeMat(Mat mat) {
    Mat ret = InitMat(ret, mat.col, mat.row);
    for (int i = 0; i < ret.row; i++) {
        for (int j = 0; j < ret.col; j++) {
            ret.arr[i][j] = mat.arr[j][i];
        }
    }
    return ret;
}

//矩阵相加
Mat PlusMat(Mat mat1, Mat mat2) {
    Mat ret = {0, 0, nullptr};
    if (mat1.row != mat2.row || mat1.col != mat2.col) {
        return ret;
    }
    ret = InitMat(ret, mat1.row, mat1.col);
    for (int i = 0; i < ret.row; i++) {
        for (int j = 0; j < ret.col; j++) {
            ret.arr[i][j] += mat1.arr[i][j] + mat2.arr[i][j];
        }
    }
    return ret;
}

//矩阵相减
Mat MinusMat(Mat mat1, Mat mat2) {
    Mat ret = {0, 0, nullptr};
    if (mat1.row != mat2.row || mat1.col != mat2.col) {
        return ret;
    }
    ret = InitMat(ret, mat1.row, mat1.col);
    for (int i = 0; i < ret.row; i++) {
        for (int j = 0; j < ret.col; j++) {
            ret.arr[i][j] += mat1.arr[i][j] - mat2.arr[i][j];
        }
    }
    return ret;
}

//矩阵相乘
Mat MulMat(Mat mat1, Mat mat2) {
    Mat ret = {0, 0, nullptr};
    if (mat1.col != mat2.row) {
        return ret;
    }
    ret = InitMat(ret, mat1.row, mat2.col);
    for (int i = 0; i < mat1.row; i++) {
        for (int j = 0; j < mat2.col; j++) {
            for (int k = 0; k < mat1.col; k++) {
                ret.arr[i][j] += mat1.arr[i][k] * mat2.arr[k][j];
            }
        }
    }
    return ret;
}