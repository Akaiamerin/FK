#pragma once

struct Mat {
    int row; //行数
    int col; //列数
    int ** arr; //二维数组，存放元素
};

//初始化矩阵
Mat InitMat(Mat mat, int row, int col);