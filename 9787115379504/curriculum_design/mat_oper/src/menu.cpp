#include <iostream>
#include "menu.h"
#include "mat.h"
#include "oper.h"

//菜单
void Menu() {
    Mat mat1 = InputMat(mat1);
    Mat mat2 = InputMat(mat2);
    while (true) {
        std::cout << "+—————————————+" << std::endl;
        std::cout << "|1. 矩阵转置  |" << std::endl;
        std::cout << "|2. 矩阵相加  |" << std::endl;
        std::cout << "|3. 矩阵相减  |" << std::endl;
        std::cout << "|4. 矩阵相乘  |" << std::endl;
        std::cout << "|5. 退出      |" << std::endl;
        std::cout << "+—————————————+" << std::endl;
        int opt = 0;
        std::cin >> opt;
        if (opt == 1) {
            system("cls");
            std::cout << "1. 第一个矩阵转置" << std::endl;
            std::cout << "2. 第二个矩阵转置" << std::endl;
            int transpose_opt = 0;
            std::cin >> transpose_opt;
            if (transpose_opt == 1) {
                std::cout << "原矩阵" << std::endl;
                OutputMat(mat1);
                std::cout << "转置矩阵" << std::endl;
                Mat ret = TransposeMat(mat1);
                OutputMat(ret);
            }
            else if (transpose_opt == 2) {
                std::cout << "原矩阵" << std::endl;
                OutputMat(mat2);
                std::cout << "转置矩阵" << std::endl;
                Mat ret = TransposeMat(mat2);
                OutputMat(ret);
            }
            else {
                std::cin.clear();
                std::cin.sync();
            }
            system("pause");
            system("cls");
        }
        else if (opt == 2) {
            system("cls");
            Mat ret = PlusMat(mat1, mat2);
            if (ret.row == 0 && ret.col == 0 && ret.arr == nullptr) {
                std::cout << "不满足矩阵相加条件" << std::endl;
            }
            else {
                OutputMat(ret);
            }
            system("pause");
            system("cls");
        }
        else if (opt == 3) {
            system("cls");
            Mat ret = MinusMat(mat1, mat2);
            if (ret.row == 0 && ret.col == 0 && ret.arr == nullptr) {
                std::cout << "不满足矩阵相减条件" << std::endl;
            }
            else {
                OutputMat(ret);
            }
            system("pause");
            system("cls");
        }
        else if (opt == 4) {
            system("cls");
            Mat ret = MulMat(mat1, mat2);
            if (ret.row == 0 && ret.col == 0 && ret.arr == nullptr) {
                std::cout << "不满足矩阵相乘条件" << std::endl;
            }
            else {
                OutputMat(ret);
            }
            system("pause");
            system("cls");
        }
        else if (opt == 5) {
            system("cls");
            break;
        }
        else {
            system("cls");
            std::cin.clear();
            std::cin.sync();
        }
    }
}