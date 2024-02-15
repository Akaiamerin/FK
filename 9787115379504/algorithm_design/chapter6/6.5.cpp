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
bool SrchLengthPath(AdjacencyList graph, int begin_vex_index, int end_vex_index, int length, bool visit[]) {
    if (length < 0) {
        return false;
    }
    if (begin_vex_index == end_vex_index && length == 0) {
        return true;
    }
    visit[begin_vex_index] = true;
    for (EdgeNode * i = graph.vex_list[begin_vex_index].first; i != nullptr; i = i->next) {
        if (visit[i->adj_vex_index] == false && SrchLengthPath(graph, i->adj_vex_index, end_vex_index, length - 1, visit) == true) {
            return true;
        }
    }
    visit[end_vex_index] = false;
    return false;
}
bool IsExistlengthPath(AdjacencyList graph, char begin_vex, char end_vex, int length) {
    bool visit[graph.vex_num];
    for (int i = 0; i < graph.vex_num; i++) {
        visit[i] = false;
    }
    int begin_vex_index = SrchVexIndex(graph, begin_vex);
    int end_vex_index = SrchVexIndex(graph, end_vex);
    return SrchLengthPath(graph, begin_vex_index, end_vex_index, length, visit);
}
int main() {
    AdjacencyList graph = {};
    CrtDirectedUnweightedGraph(graph);
    cout << IsExistlengthPath(graph, 'a', 'h', 3) << endl;
    cout << IsExistlengthPath(graph, 'a', 'h', 4) << endl;
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