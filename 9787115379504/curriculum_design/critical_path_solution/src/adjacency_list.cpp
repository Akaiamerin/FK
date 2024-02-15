#include <iostream>
#include "adjacency_list.h"

//查找顶点下标
int SrchVexIndex(AdjacencyList graph, char srch_vex) {
    for (int i = 0; i < graph.vex_num; i++) {
        if (graph.vex_list[i].vex == srch_vex) {
            return i;
        }
    }
    return -1;
}

//创建有向有权图
void CrtDirectedWeightedGraph(AdjacencyList & graph) {
    std::cout << "请输入工程的顶点数和边数：";
    std::cin >> graph.vex_num >> graph.edge_num;
    //最多有 n(n - 1) 条边
    if (graph.edge_num > graph.vex_num * (graph.vex_num - 1)) {
        std::cout << "输入错误：" << graph.edge_num << "个顶点最多有" << graph.vex_num * (graph.vex_num - 1) << "条边" << std::endl;
        return;
    }
    for (int i = 0; i < graph.vex_num; i++) {
        std::cout << "请输入第" << i + 1 << "个顶点的信息（字符形式）：";
        std::cin >> graph.vex_list[i].vex;
        graph.vex_list[i].first = nullptr;
    }
    for (int i = 0; i < graph.edge_num; i++) {
        std::cout << "请输入第" << i + 1 << "条边的信息（起点 终点 权值）：";
        char begin_vex = {};
        char end_vex = {};
        int weight = 0;
        std::cin >> begin_vex >> end_vex >> weight;
        int begin_vex_index = SrchVexIndex(graph, begin_vex);
        int end_vex_index = SrchVexIndex(graph, end_vex);
        EdgeNode * begin_edge_node = new EdgeNode;
        begin_edge_node->adj_vex_index = end_vex_index;
        begin_edge_node->next = graph.vex_list[begin_vex_index].first;
        begin_edge_node->weight = weight;
        graph.vex_list[begin_vex_index].first = begin_edge_node;
    }
}