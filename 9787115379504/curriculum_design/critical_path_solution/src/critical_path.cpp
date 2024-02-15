#include <iostream>
#include "critical_path.h"
#include "topological_sort.h"

//关键路径
void CriticalPath(AdjacencyList graph) {
    int * topological_sort_arr = TopologicalSort(graph);
    if (topological_sort_arr == nullptr) {
        std::cout << "该工程无法顺利进行" << std::endl;
        return;
    }
    int earliest_vex[graph.vex_num]; //earliest_vex[i] 为最早发生时间
    int latest_vex[graph.vex_num]; //latest_vex[i] 为最晚发生时间
    for (int i = 0; i < graph.vex_num; i++) {
        earliest_vex[i] = 0;
        latest_vex[i] = 0;
    }
    //按照拓扑排序遍历各点的邻接点
    for (int i = 0; i < graph.vex_num; i++) {
        int cur_adj_vex_index = topological_sort_arr[i];
        for (EdgeNode * j = graph.vex_list[cur_adj_vex_index].first; j != nullptr; j = j->next) {
            if (earliest_vex[j->adj_vex_index] < earliest_vex[cur_adj_vex_index] + j->weight) {
                earliest_vex[j->adj_vex_index] = earliest_vex[cur_adj_vex_index] + j->weight;
            }
        }
    }
    //把所有点的最晚发生时间初始化为汇点最晚发生时间
    for (int i = 0; i < graph.vex_num; i++) {
        latest_vex[i] = earliest_vex[topological_sort_arr[graph.vex_num - 1]];
    }
    //由汇点从后往前遍历拓扑排序
    for (int i = graph.vex_num - 1; i >= 0; i--) {
        int cur_adj_vex_index = topological_sort_arr[i];
        for (EdgeNode * j = graph.vex_list[cur_adj_vex_index].first; j != nullptr; j = j->next) {
            if (latest_vex[cur_adj_vex_index] > latest_vex[j->adj_vex_index] - j->weight) {
                latest_vex[cur_adj_vex_index] = latest_vex[j->adj_vex_index] - j->weight;
            }
        }
    }
    std::cout << "该工程的关键活动为：" << std::endl;
    for (int i = 0; i < graph.vex_num; i++) {
        for (EdgeNode * j = graph.vex_list[i].first; j != nullptr; j = j->next) {
            int earliest_begin = earliest_vex[i]; //最早发生时间为该点前驱结点的最早发生时间
            int latest_begin = latest_vex[j->adj_vex_index] - j->weight; //最晚发生时间为该点前驱结点最晚发生时间减去权值
            if (earliest_begin == latest_begin) {
                std::cout << graph.vex_list[i].vex << "->" << graph.vex_list[j->adj_vex_index].vex << " ";
            }
        }
    }
    std::cout << std::endl << "活动的起点和终点 最早发生时间 最晚发生时间" << std::endl;
    for (int i = 0; i < graph.vex_num; i++) {
        for (EdgeNode * j = graph.vex_list[i].first; j != nullptr; j = j->next) {
            int earliest_begin = earliest_vex[i]; //最早发生时间为该点前驱结点的最早发生时间
            int latest_begin = latest_vex[j->adj_vex_index] - j->weight; //最晚发生时间为该点前驱结点最晚发生时间减去权值
            std::cout << graph.vex_list[i].vex << "->" << graph.vex_list[j->adj_vex_index].vex << " " << earliest_begin << " " << latest_begin << std::endl;
        }
    }
    delete[] topological_sort_arr;
    topological_sort_arr = nullptr;
}