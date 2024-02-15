#include <iostream>
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
        begin_edge_node->adj_vex_index = end_vex_index;
        begin_edge_node->next = graph.vex_list[begin_vex_index].first;
        graph.vex_list[begin_vex_index].first = begin_edge_node;
    }
}
bool exist_path = false;
char end_path_vex = {};
void DepthFirstSearchAdjacencyList(AdjacencyList graph, int srch_index, bool visit[]) {
    if (visit[srch_index] == true) {
        return;
    }
    if (graph.vex_list[srch_index].vex == end_path_vex) {
        for (int i = 0; i < graph.vex_num; i++) {
            visit[i] = true;
            exist_path = true;
            return;
        }
    }
    for (EdgeNode * i = graph.vex_list[srch_index].first; i != nullptr; i = i->next) {
        if (visit[i->adj_vex_index] == true) {
            continue;
        }
        DepthFirstSearchAdjacencyList(graph, i->adj_vex_index, visit);
    }
}
bool IsExistPath(AdjacencyList graph, char begin_vex, char end_vex) {
    exist_path = false;
    bool visit[graph.vex_num];
    for (int i = 0; i < graph.vex_num; i++) {
        visit[i] = false;
    }
    int begin_vex_index = SrchVexIndex(graph, begin_vex);
    int end_vex_index = SrchVexIndex(graph, end_vex);
    end_path_vex = end_vex;
    DepthFirstSearchAdjacencyList(graph, begin_vex_index, visit);
    return exist_path;
}
int main() {
    AdjacencyList graph = {};
    CrtDirectedUnweightedGraph(graph);
    cout << IsExistPath(graph, 'a', 'h') << endl;
    cout << IsExistPath(graph, 'h', 'a') << endl;
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