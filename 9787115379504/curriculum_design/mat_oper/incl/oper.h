#pragma once

#include "mat.h"

//输入矩阵
Mat InputMat(Mat & mat);

//输出矩阵
void OutputMat(Mat mat);

//矩阵转置
Mat TransposeMat(Mat mat);

//矩阵相加
Mat PlusMat(Mat mat1, Mat mat2);

//矩阵相减
Mat MinusMat(Mat mat1, Mat mat2);

//矩阵相乘
Mat MulMat(Mat mat1, Mat mat2);