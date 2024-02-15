#include <iostream>
#include <stack>
using namespace std;
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
    cout << "vex_num and edge_num: ";
    cin >> graph.vex_num >> graph.edge_num;
    //最多有 n(n - 1) 条边
    if (graph.edge_num > graph.vex_num * (graph.vex_num - 1)) {
        return;
    }
    for (int i = 0; i < graph.vex_num; i++) {
        cout << "vex[" << i << "]: ";
        cin >> graph.vex_list[i].vex;
        graph.vex_list[i].first = nullptr;
    }
    for (int i = 0; i < graph.edge_num; i++) {
        cout << "begin_vex[" << i << "] end_vex[" << i << "] weight[" << i << "]: ";
        char begin_vex = {};
        char end_vex = {};
        int weight = 0;
        cin >> begin_vex >> end_vex >> weight;
        int begin_vex_index = SrchVexIndex(graph, begin_vex);
        int end_vex_index = SrchVexIndex(graph, end_vex);
        EdgeNode * begin_edge_node = new EdgeNode;
        begin_edge_node->adj_vex_index = end_vex_index;
        begin_edge_node->next = graph.vex_list[begin_vex_index].first;
        begin_edge_node->weight = weight;
        graph.vex_list[begin_vex_index].first = begin_edge_node;
    }
}
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
    stack<int> stk = {};
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
//关键路径
void CriticalPath(AdjacencyList graph) {
    int * topological_sort_arr = TopologicalSort(graph);
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
    for (int i = 0; i < graph.vex_num; i++) {
        for (EdgeNode * j = graph.vex_list[i].first; j != nullptr; j = j->next) {
            int earliest_begin = earliest_vex[i]; //最早发生时间为该点前驱结点的最早发生时间
            int latest_begin = latest_vex[j->adj_vex_index] - j->weight; //最晚发生时间为该点前驱结点最晚发生时间减去权值
            if (earliest_begin == latest_begin) {
                cout << graph.vex_list[i].vex << "->" << graph.vex_list[j->adj_vex_index].vex << " ";
            }
        }
    }
    delete[] topological_sort_arr;
    topological_sort_arr = nullptr;
}
int main() {
    AdjacencyList graph = {};
    CrtDirectedWeightedGraph(graph);
    CriticalPath(graph);
    return 0;
}
#if 0
/*
9 11
a b c d e f g h i
ab6 ac4 ad5 be1 ce1 df2 eg9 eh7 fh4 gi2 hi4
    b       g
 ↗   ↘ ↗   ↘
a       e      i
↓↘   ↗ ↘   ↗
↓   c       h
 ↘       ↗
    d → f
*/
#endif