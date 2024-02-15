#include <iostream>
#include <stack>
using namespace std;
struct EdgeNode {
    int adjacency_vex_index; //边终点的下标
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
    VexNode vex_list[100];
};
//查找顶点下标
int SrchVexIndex(AdjacencyList graph, char seach_vex) {
    for (int i = 0; i < graph.vex_num; i++) {
        if (graph.vex_list[i].vex == seach_vex) {
            return i;
        }
    }
    return -1;
}
//创建有向无权图
void CrtDirectedUnweightedGraph(AdjacencyList & graph) {
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
        cout << "begin_vex[" << i << "] end_vex[" << i << "]: ";
        char begin_vex = {};
        char end_vex = {};
        cin >> begin_vex >> end_vex;
        int begin_vex_index = SrchVexIndex(graph, begin_vex);
        int end_vex_index = SrchVexIndex(graph, end_vex);
        EdgeNode * begin_edge_node = new EdgeNode;
        begin_edge_node->adjacency_vex_index = end_vex_index;
        begin_edge_node->next = graph.vex_list[begin_vex_index].first;
        graph.vex_list[begin_vex_index].first = begin_edge_node;
    }
}
//拓扑排序
void TopologicalSort(AdjacencyList graph) {
    int prev_vex_index[graph.vex_num]; //前驱节点数组
    for (int i = 0; i < graph.vex_num; i++) {
        prev_vex_index[i] = 0;
    }
    for (int i = 0; i < graph.vex_num; i++) {
        //获取前驱结点
        for (EdgeNode * j = graph.vex_list[i].first; j != nullptr; j = j->next) {
            prev_vex_index[j->adjacency_vex_index]++;
        }
    }
    int topological_sort_arr[graph.vex_num]; //拓扑排序结果数组
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
            prev_vex_index[i->adjacency_vex_index]--; //更新该点的邻接点的前驱结点
            if (prev_vex_index[i->adjacency_vex_index] == 0) {
                stk.push(i->adjacency_vex_index); //若该点的邻接点的没有前驱结点，则入栈
            }
        }
    }
    //有环
    if (topological_sort_arr_index < graph.vex_num) {
        return;
    }
    for (int i = 0; i < graph.edge_num; i++) {
        cout << graph.vex_list[topological_sort_arr[i]].vex << " ";
    }
    cout << endl;
}
int main() {
    AdjacencyList graph = {};
    CrtDirectedUnweightedGraph(graph);
    TopologicalSort(graph);
    return 0;
}
#if 0
/*
6 8
a b c d e f
ab ac ad cb ce de fd fe
a —→ b
↓ ↘ ↑
d    c
↑ ↘ ↓
f —→ e
*/
#endif