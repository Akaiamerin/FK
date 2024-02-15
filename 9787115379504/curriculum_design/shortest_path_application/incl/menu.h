#pragma once

#include <vector>
#include <string>
#include "adj_mat.h"

#define FILE_PATH ".\\test\\scenic_spot.txt"

//创建图
void CrtGraph(AdjMat & graph, std::vector<std::string> vec);

//获取图的信息，用于写入文件
std::vector<std::string> GetGraphInfo(AdjMat & graph);

//菜单
void Menu();