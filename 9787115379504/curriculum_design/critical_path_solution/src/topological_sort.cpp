#include <stack>
#include "topological_sort.h"
#include "adjacency_list.h"

//拓扑排序
int * TopologicalSort(AdjacencyList graph) {
    int prev_vex_index[graph.vex_num]; //前驱节点数组
    for (int i = 0; i < graph.vex_num; i++) {
        prev_vex_index[i] = 0;
    }
    //获取前驱结点
    for (int i = 0; i < graph.vex_num; i++) {
        for (EdgeNode * j = graph.vex_list[i].first; j != nullptr; j = j->next) {
            prev_vex_index[j->adj_vex_index]++;
        }
    }
    int * topological_sort_arr = new int[graph.vex_num]; //拓扑排序结果数组
    for (int i = 0; i < graph.vex_num; i++) {
        topological_sort_arr[i] = 0;
    }
    std::stack<int> stk = {};
    for (int i = 0; i < graph.vex_num; i++) {
        if (prev_vex_index[i] == 0) {
            stk.push(i); //没有前驱结点的点入栈
        }
    }
    int topological_sort_arr_index = 0;
    while (stk.empty() == false) {
        int pop_index = stk.top();
        stk.pop();
        topological_sort_arr[topological_sort_arr_index++] = pop_index;

        for (EdgeNode * i = graph.vex_list[pop_index].first; i != nullptr; i = i->next) {
            prev_vex_index[i->adj_vex_index]--; //更新该点的邻接点的前驱结点
            if (prev_vex_index[i->adj_vex_index] == 0) {
                stk.push(i->adj_vex_index); //若该点的邻接点的没有前驱结点，则入栈
            }
        }
    }
    //有环
    if (topological_sort_arr_index < graph.vex_num) {
        delete[] topological_sort_arr;
        topological_sort_arr = nullptr;
    }
    return topological_sort_arr;
}