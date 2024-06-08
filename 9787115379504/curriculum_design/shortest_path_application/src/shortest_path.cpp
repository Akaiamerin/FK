#include <iostream>
#include "shortest_path.h"

//Dijkstra 算法
void ShortestPathByDijkstra(AdjMat graph, char vex) {
    int vex_index = SrchVexIndex(graph, vex);
    int prev_vex[graph.vex_num]; //prev_vex[i] 为起点到 vex[i] 的最短路径所经历的全部顶点中， vex[i] 前驱顶点
    int min_weight[graph.vex_num]; //起点到 vex[i] 最小权值(最短路径长度)
    //初始化
    for (int i = 0; i < graph.vex_num; i++) {
        min_weight[i] = graph.edge[vex_index][i];
    }
    min_weight[vex_index] = 0; //初始化自己
    bool shortest_path_tag[graph.vex_num] = {false}; //是否找到起点到 vex[i] 的最短路径
    shortest_path_tag[vex_index] = true;
    for (int i = 0; i < graph.vex_num - 1; i++) {
        int cur_min_weight = INT_MAX;
        int min_weight_index = -1; //查找在未获取最短路径的点中距离顶点最近的点
        for (int j = 0; j < graph.vex_num; j++) {
            if (shortest_path_tag[j] == false && min_weight[j] < cur_min_weight) {
                cur_min_weight = min_weight[j];
                min_weight_index = j;
            }
        }
        shortest_path_tag[min_weight_index] = true;
        //更新
        for (int i = 0; i < graph.vex_num; i++) {
            int temp_min_weight = INT_MAX;
            if (graph.edge[min_weight_index][i] < INT_MAX) {
                temp_min_weight = cur_min_weight + graph.edge[min_weight_index][i];
            }
            if (shortest_path_tag[i] == false && temp_min_weight < min_weight[i]) {
                min_weight[i] = temp_min_weight;
                prev_vex[i] = min_weight_index;
            }
        }
    }
    for (int i = 0; i < graph.vex_num; i++) {
        std::cout << "[景点" << graph.vex[vex_index] << "到景点" << graph.vex[i] << "最短距离为：" << min_weight[i] << "]" << std::endl;
    }
}

//Floyd算法
void ShortestPathByFloyd(AdjMat graph, char begin_vex, char end_vex) {
    int begin_vex_index = SrchVexIndex(graph, begin_vex);
    int end_vex_index = SrchVexIndex(graph, end_vex);
    int prev_vex[graph.vex_num][graph.vex_num]; //prev_vex[i][j] 为 vex[i] 到 vex[j] 的最短路径所经历的全部顶点中， vex[j] 前驱顶点
    int min_weight[graph.vex_num][graph.vex_num]; //vex[i] 到 vex[j] 最小权值(最短路径长度)
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = 0; j < graph.vex_num; j++) {
            min_weight[i][j] = graph.edge[i][j];
            //判断 vex[i] 和 vex[j] 是否为邻接点
            if (min_weight[i][j] < INT_MAX) {
                prev_vex[i][j] = i;
            }
            else {
                prev_vex[i][j] = -1;
            }
        }
    }
    for (int temp_index = 0; temp_index < graph.vex_num; temp_index++) {
        for (int i = 0; i < graph.vex_num; i++) {
            for (int j = 0; j < graph.vex_num; j++) {
                int temp_min_weight = INT_MAX;
                if (min_weight[i][temp_index] == INT_MAX || min_weight[temp_index][j] == INT_MAX) {
                    temp_min_weight = INT_MAX;
                }
                else {
                    temp_min_weight = min_weight[i][temp_index] + min_weight[temp_index][j];
                }
                if (temp_min_weight < min_weight[i][j]) {
                    min_weight[i][j] = temp_min_weight;
                    prev_vex[i][j] = prev_vex[temp_index][j];
                }
            }
        }
    }
    std::cout << "[景点" << begin_vex << "到景点" << end_vex << "最短距离为：" << min_weight[begin_vex_index][end_vex_index] << "]" << std::endl;
}