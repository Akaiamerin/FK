#include <climits>
#include <iostream>
#include "adj_mat.h"

//初始化邻接矩阵
AdjMat InitAdjMat(AdjMat & graph) {
    graph.vex_num = 0;
    graph.edge_num = 0;
    graph.vex[100] = {};
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i == j) {
                graph.edge[i][j] = 0;
            }
            else {
                graph.edge[i][j] = INT_MAX;
            }
        }
    }
    return graph;
}

//查找顶点下标
int SrchVexIndex(AdjMat graph, char srch_vex) {
    for (int i = 0; i < graph.vex_num; i++) {
        if (graph.vex[i] == srch_vex) {
            return i;
        }
    }
    return -1;
}

//增加顶点
bool InsVex(AdjMat & graph, char ins_vex) {
    if (graph.vex_num >= 100) {
        return false;
    }
    if (SrchVexIndex(graph, ins_vex) != -1) {
        return false;
    }
    graph.vex[graph.vex_num] = ins_vex;
    graph.vex_num++;
    return true;
}

//删除顶点
bool DelVex(AdjMat & graph, char del_vex) {
    int del_vex_index = SrchVexIndex(graph, del_vex);
    int last_vex_index = graph.vex_num - 1;
    if (del_vex_index == -1) {
        return false;
    }
    std::swap(graph.vex[del_vex_index], graph.vex[last_vex_index]);
    for (int i = 0; i < graph.vex_num; i++) {
        std::swap(graph.edge[del_vex_index][i], graph.edge[last_vex_index][i]);
    }
    for (int i = 0; i < graph.vex_num; i++) {
        std::swap(graph.edge[i][del_vex_index], graph.edge[i][last_vex_index]);
    }
    graph.vex_num--;
    return true;
}

//增加边
bool InsEdge(AdjMat & graph, char begin_vex, char end_vex, int weight) {
    int begin_vex_index = SrchVexIndex(graph, begin_vex);
    int end_vex_index = SrchVexIndex(graph, end_vex);
    if (begin_vex_index != -1 && end_vex_index != -1) {
        graph.edge[begin_vex_index][end_vex_index] = weight;
        graph.edge[end_vex_index][begin_vex_index] = weight;
        graph.edge_num++;
        return true;
    }
    return false;
}

//删除边
bool DelEdge(AdjMat & graph, char begin_vex, char end_vex) {
    int begin_vex_index = SrchVexIndex(graph, begin_vex);
    int end_vex_index = SrchVexIndex(graph, end_vex);
    if (begin_vex_index != -1 && end_vex_index != -1) {
        graph.edge[begin_vex_index][end_vex_index] = INT_MAX;
        graph.edge[end_vex_index][begin_vex_index] = INT_MAX;
        graph.edge_num--;
        return true;
    }
    return false;
}

//输出邻接矩阵
void OutputAdjMat(AdjMat graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        std::cout << graph.vex[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = 0; j < graph.vex_num; j++) {
            if (graph.edge[i][j] == INT_MAX) {
                std::cout << "∞ ";
            }
            else {
                std::cout << graph.edge[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}