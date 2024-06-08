#pragma once

struct AdjMat {
    int vex_num; //顶点数量
    int edge_num; //边数量
    char vex[100]; //顶点元素
    int edge[100][100]; //边权值
};

//初始化邻接矩阵
AdjMat InitAdjMat(AdjMat & graph);

//查找顶点下标
int SrchVexIndex(AdjMat graph, char srch_vex);

//增加顶点
bool InsVex(AdjMat & graph, char ins_vex);

//删除顶点
bool DelVex(AdjMat & graph, char del_vex);

//增加边
bool InsEdge(AdjMat & graph, char begin_vex, char end_vex, int weight);

//删除边
bool DelEdge(AdjMat & graph, char begin_vex, char end_vex);

//输出邻接矩阵
void OutputAdjMat(AdjMat graph);