#include <iostream>
using namespace std;
// #define DEPTH_FIRST_SEARCH_ADJACENCY_MATRIX //深度优先搜索邻接矩阵
// #define DEPTH_FIRST_SEARCH_ADJACENCY_LIST //深度优先搜索邻接表
#ifdef DEPTH_FIRST_SEARCH_ADJACENCY_MATRIX
struct AdjacencyMatrix {
    int vex_num; //顶点数量
    int edge_num; //边数量
    char vex[100]; //顶点元素
    int edge[100][100]; //边权值
};
//查找顶点下标
int SrchVexIndex(AdjacencyMatrix graph, char srch_vex) {
    for (int i = 0; i < graph.vex_num; i++) {
        if (graph.vex[i] == srch_vex) {
            return i;
        }
    }
    return -1;
}
//创建无向无权图
void CrtUndirectedUnweightedGraph(AdjacencyMatrix & graph) {
    cout << "vex_num and edge_num: ";
    cin >> graph.vex_num >> graph.edge_num;
    //最多有 n(n - 1) / 2 条边
    if (graph.edge_num > graph.vex_num * (graph.vex_num - 1) / 2) {
        return;
    }
    for (int i = 0; i < graph.vex_num; i++) {
        cout << "vex[" << i << "]: ";
        cin >> graph.vex[i];
    }
    //初始化邻接矩阵
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = 0; j < graph.vex_num; j++) {
            graph.edge[i][j] = 0;
        }
    }
    for (int i = 0; i < graph.edge_num; i++) {
        cout << "begin_vex[" << i << "] end_vex[" << i << "]: ";
        char begin_vex = {};
        char end_vex = {};
        cin >> begin_vex >> end_vex;
        int begin_vex_index = SrchVexIndex(graph, begin_vex);
        int end_vex_index = SrchVexIndex(graph, end_vex);
        graph.edge[begin_vex_index][end_vex_index] = 1;
        graph.edge[end_vex_index][begin_vex_index] = 1;
    }
}
//深度优先搜索邻接矩阵
void DepthFirstSearchAdjacencyMatrix(AdjacencyMatrix graph, int srch_index, bool visit[]) {
    cout << graph.vex[srch_index] << " ";
    visit[srch_index] = true;
    for (int i = 0; i < graph.vex_num; i++) {
        if (graph.edge[srch_index][i] != 0 && visit[i] == false) {
            DepthFirstSearchAdjacencyMatrix(graph, i, visit);
        }
    }
}
//深度优先搜索无向无权图
void DepthFirstSearchUndirectedUnweightedGraph(AdjacencyMatrix graph, char srch_vex) {
    bool visit[graph.vex_num];
    for (int i = 0; i < graph.vex_num; i++) {
        visit[i] = false;
    }
    int srch_index = SrchVexIndex(graph, srch_vex);
    DepthFirstSearchAdjacencyMatrix(graph, srch_index, visit);
}
#endif
#ifdef DEPTH_FIRST_SEARCH_ADJACENCY_LIST
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
    cout << graph.vex_list[srch_index].vex << " ";
    visit[srch_index] = true;
    for (EdgeNode * i = graph.vex_list[srch_index].first; i != nullptr; i = i->next) {
        int j = i->adj_vex_index;
        if (visit[j] == false) {
            DepthFirstSearchAdjacencyList(graph, j, visit);
        }
    }
}
//深度优先搜索无向无权图
void DepthFirstSearchUndirectedUnweightedGraph(AdjacencyList graph, char srch_vex) {
    bool visit[graph.vex_num];
    for (int i = 0; i < graph.vex_num; i++) {
        visit[i] = false;
    }
    int srch_index = SrchVexIndex(graph, srch_vex);
    DepthFirstSearchAdjacencyList(graph, srch_index, visit);
}
#endif
int main() {
    #ifdef DEPTH_FIRST_SEARCH_ADJACENCY_MATRIX
    AdjacencyMatrix graph = {};
    CrtUndirectedUnweightedGraph(graph);
    DepthFirstSearchUndirectedUnweightedGraph(graph, graph.vex[0]);
    #endif
    #ifdef DEPTH_FIRST_SEARCH_ADJACENCY_LIST
    AdjacencyList graph = {};
    CrtUndirectedUnweightedGraph(graph);
    DepthFirstSearchUndirectedUnweightedGraph(graph, graph.vex_list[0].vex);
    #endif
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