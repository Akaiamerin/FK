#pragma once

struct EdgeNode {
    int adj_vex_index; //边终点的下标
    EdgeNode * next; //后继结点
    int weight; //权值
};

struct VexNode {
    char vex; //顶点元素
    EdgeNode * first; //首结点
};

struct AdjacencyList {
    int vex_num; //顶点数量
    int edge_num; //边数量
    VexNode vex_list[100]; //顶点元素链表
};

//查找顶点下标
int SrchVexIndex(AdjacencyList graph, char srch_vex);

//创建有向有权图
void CrtDirectedWeightedGraph(AdjacencyList & graph);