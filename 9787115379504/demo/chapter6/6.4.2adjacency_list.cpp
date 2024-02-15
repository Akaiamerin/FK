#include <iostream>
#include <climits>
using namespace std;
// #define UNDIRECTED_UNWEIGHTED_GRAPH //无向无权图
// #define UNDIRECTED_WEIGHTED_GRAPH //无向有权图
// #define DIRECTED_UNWEIGHTED_GRAPH //有向无权图
// #define DIRECTED_WEIGHTED_GRAPH //有向有权图
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
#ifdef UNDIRECTED_UNWEIGHTED_GRAPH
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
//遍历无向无权图
void TraverseUndirectedUnweightedGraph(AdjacencyList graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        for (EdgeNode * j = graph.vex_list[i].first; j != nullptr; j = j->next) {
            cout << "[" << graph.vex_list[i].vex << "->" << graph.vex_list[j->adj_vex_index].vex << "] ";
        }
        cout << endl;
    }
}
#endif
#ifdef UNDIRECTED_WEIGHTED_GRAPH
//创建无向有权图
void CrtUndirectedWeightedGraph(AdjacencyList & graph) {
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
        EdgeNode * end_edge_node = new EdgeNode;
        end_edge_node->adj_vex_index = begin_vex_index;

        end_edge_node->next = graph.vex_list[end_vex_index].first;
        end_edge_node->weight = weight;
        graph.vex_list[end_vex_index].first = end_edge_node;
    }
}
//遍历无向有权图
void TraverseUndirectedWeightedGraph(AdjacencyList graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        for (EdgeNode * j = graph.vex_list[i].first; j != nullptr; j = j->next) {
            cout << "[" << graph.vex_list[i].vex << "->" << graph.vex_list[j->adj_vex_index].vex << " " << j->weight << "] ";
        }
        cout << endl;
    }
}
#endif
#ifdef DIRECTED_UNWEIGHTED_GRAPH
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
//遍历有向无权图
void TraverseDirectedUnweightedGraph(AdjacencyList graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        for (EdgeNode * j = graph.vex_list[i].first; j != nullptr; j = j->next) {
            cout << "[" << graph.vex_list[i].vex << "->" << graph.vex_list[j->adj_vex_index].vex << "] ";
        }
        cout << endl;
    }
}
#endif
#ifdef DIRECTED_WEIGHTED_GRAPH
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
//遍历有向有权图
void TraverseDirectedWeightedGraph(AdjacencyList graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        for (EdgeNode * j = graph.vex_list[i].first; j != nullptr; j = j->next) {
            cout << "[" << graph.vex_list[i].vex << "->" << graph.vex_list[j->adj_vex_index].vex << " " << j->weight << "] ";
        }
        cout << endl;
    }
}
#endif
int main() {
    AdjacencyList graph = {};
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