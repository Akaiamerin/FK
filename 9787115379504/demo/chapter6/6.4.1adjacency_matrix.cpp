#include <iostream>
#include <climits>
using namespace std;
// #define UNDIRECTED_UNWEIGHTED_GRAPH //无向无权图
// #define UNDIRECTED_WEIGHTED_GRAPH //无向有权图
// #define DIRECTED_UNWEIGHTED_GRAPH //有向无权图
// #define DIRECTED_WEIGHTED_GRAPH //有向有权图
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
#ifdef UNDIRECTED_UNWEIGHTED_GRAPH
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
//遍历无向无权图
void TraverseUndirectedUnweightedGraph(AdjacencyMatrix graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = 0; j < graph.vex_num; j++) {
            cout << graph.edge[i][j] << " ";
        }
        cout << endl;
    }
}
#endif
#ifdef UNDIRECTED_WEIGHTED_GRAPH
//创建无向有权图
void CrtUndirectedWeightedGraph(AdjacencyMatrix & graph) {
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
            graph.edge[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < graph.edge_num; i++) {
        cout << "begin_vex[" << i << "] end_vex[" << i << "] weight[" << i << "]: ";
        char begin_vex = {};
        char end_vex = {};
        int weight = 0;
        cin >> begin_vex >> end_vex >> weight;
        int begin_vex_index = SrchVexIndex(graph, begin_vex);
        int end_vex_index = SrchVexIndex(graph, end_vex);
        graph.edge[begin_vex_index][end_vex_index] = weight;
        graph.edge[end_vex_index][begin_vex_index] = weight;
    }
}
//遍历无向有权图
void TraverseUndirectedWeightedGraph(AdjacencyMatrix graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = 0; j < graph.vex_num; j++) {
            if (graph.edge[i][j] == INT_MAX) {
                cout << "∞ ";
            }
            else {
                cout << graph.edge[i][j] << " ";
            }
        }
        cout << endl;
    }
}
#endif
#ifdef DIRECTED_UNWEIGHTED_GRAPH
//创建有向无权图
void CrtDirectedUnweightedGraph(AdjacencyMatrix & graph) {
    cout << "vex_num and edge_num: ";
    cin >> graph.vex_num >> graph.edge_num;
    //最多有 n(n - 1) 条边
    if (graph.edge_num > graph.vex_num * (graph.vex_num - 1)) {
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
    }
}
//遍历有向无权图
void TraverseDirectedUnweightedGraph(AdjacencyMatrix graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = 0; j < graph.vex_num; j++) {
            cout << graph.edge[i][j] << " ";
        }
        cout << endl;
    }
}
#endif
#ifdef DIRECTED_WEIGHTED_GRAPH
//创建有向有权图
void CrtDirectedWeightedGraph(AdjacencyMatrix & graph) {
    cout << "vex_num and edge_num: ";
    cin >> graph.vex_num >> graph.edge_num;
    //最多有 n(n - 1) 条边
    if (graph.edge_num > graph.vex_num * (graph.vex_num - 1)) {
        return;
    }
    for (int i = 0; i < graph.vex_num; i++) {
        cout << "vex[" << i << "]: ";
        cin >> graph.vex[i];
    }
    //初始化邻接矩阵
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = 0; j < graph.vex_num; j++) {
            graph.edge[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < graph.edge_num; i++) {
        cout << "begin_vex[" << i << "] end_vex[" << i << "] weight[" << i << "]: ";
        char begin_vex = {};
        char end_vex = {};
        int weight = INT_MAX;
        cin >> begin_vex >> end_vex >> weight;
        int begin_vex_index = SrchVexIndex(graph, begin_vex);
        int end_vex_index = SrchVexIndex(graph, end_vex);
        graph.edge[begin_vex_index][end_vex_index] = weight;
    }
}
//遍历有向有权图
void TraverseDirectedWeightedGraph(AdjacencyMatrix graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = 0; j < graph.vex_num; j++) {
            if (graph.edge[i][j] == INT_MAX) {
                cout << "∞ ";
            }
            else {
                cout << graph.edge[i][j] << " ";
            }
        }
        cout << endl;
    }
}
#endif
int main() {
    AdjacencyMatrix graph = {};
    #ifdef UNDIRECTED_UNWEIGHTED_GRAPH
    CrtUndirectedUnweightedGraph(graph);
    TraverseUndirectedUnweightedGraph(graph);
    #endif
    #ifdef UNDIRECTED_WEIGHTED_GRAPH
    CrtUndirectedWeightedGraph(graph);
    TraverseUndirectedWeightedGraph(graph);
    #endif
    #ifdef DIRECTED_UNWEIGHTED_GRAPH
    CrtDirectedUnweightedGraph(graph);
    TraverseDirectedUnweightedGraph(graph);
    #endif
    #ifdef DIRECTED_WEIGHTED_GRAPH
    CrtDirectedWeightedGraph(graph);
    TraverseDirectedWeightedGraph(graph);
    #endif
    return 0;
}