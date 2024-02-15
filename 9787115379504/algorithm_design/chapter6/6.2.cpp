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
    VexNode vex_list[100];
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
//创建无向无权图
void CrtUndirectedUnweightedGraph(AdjacencyList & graph) {
    cout << "vex_num and edge_num: ";
    cin >> graph.vex_num >> graph.edge_num;
    //最多有 n(n - 1) / 2 条边
    if (graph.edge_num > graph.vex_num * (graph.vex_num - 1) / 2) {
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
        begin_edge_node->adj_vex_index = end_vex_index;
        begin_edge_node->next = graph.vex_list[begin_vex_index].first;
        graph.vex_list[begin_vex_index].first = begin_edge_node;
        EdgeNode * end_edge_node = new EdgeNode;
        end_edge_node->adj_vex_index = begin_vex_index;
        end_edge_node->next = graph.vex_list[end_vex_index].first;
        graph.vex_list[end_vex_index].first = end_edge_node;
    }
}
//深度优先搜索邻接表
void DepthFirstSearchAdjacencyList(AdjacencyList graph, int srch_index, bool visit[]) {
    visit[srch_index] = true;
    stack<int> stk = {};
    stk.push(srch_index);
    cout << graph.vex_list[srch_index].vex << " ";
    while (stk.empty() == false) {
        int top_index = stk.top();
        EdgeNode * adj_vex_node = graph.vex_list[top_index].first;
        while (adj_vex_node != nullptr && visit[adj_vex_node->adj_vex_index] == true) {
            adj_vex_node = adj_vex_node->next;
        }
        if (adj_vex_node != nullptr) {
            stk.push(adj_vex_node->adj_vex_index);
            cout << graph.vex_list[adj_vex_node->adj_vex_index].vex << " ";
            visit[adj_vex_node->adj_vex_index] = true;
        }
        else {
            stk.pop();
        }
    }
}
//深度优先搜索无向无权图
void DepthFirstSearchUndirectedUnweightedGraph(AdjacencyList graph, char srch_vex) {
    int srch_index = SrchVexIndex(graph, srch_vex);
    bool visit[srch_index];
    for (int i = 0; i < graph.vex_num; i++) {
        visit[i] = false;
    }
    for (int i = 0; i < graph.vex_num; i++) {
        if (visit[srch_index] == false) {
            DepthFirstSearchAdjacencyList(graph, srch_index, visit);
        }
    }
}
int main() {
    AdjacencyList graph = {};
    CrtUndirectedUnweightedGraph(graph);
    DepthFirstSearchUndirectedUnweightedGraph(graph, graph.vex_list[0].vex);
    return 0;
}
#if 0
/*
8 9
a b c d e f g h
ab ac bd be cf cg dh eh fg
      a
   /     \
  b       c
 / \    /   \
d   e  f ——— g
 \ /
  h
*/
#endif