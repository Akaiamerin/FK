#include <iostream>
#include <climits>
using namespace std;
// #define ADJACENCY_MATRIX_BY_PRIM //基于邻接矩阵的无向有权图的 Prim 算法
// #define ADJACENCY_LIST_BY_PRIM //基于邻接表的无向有权图的 Prim 算法
#define ADJACENCY_MATRIX_BY_KRUSKAL //基于邻接矩阵的无向有权图的 Kruskal 算法
#ifdef ADJACENCY_MATRIX_BY_PRIM
struct WeightSet {
    int adj_vex_index; //边终点的下标
    int weight; //权值
};
struct AdjacencyMatrix {
    int vex_num; //顶点数量
    int edge_num; //边数量
    char vex[100]; //顶点元素
    int edge[100][100]; //边权值
};
//查找集合中顶点之间的最小权值下标
int SrchMinWeightIndex(WeightSet weight_set[], int size) {
    int min_weight = INT_MAX;
    int min_weight_index = -1;
    for (int i = 0; i < size; i++) {
        if (weight_set[i].weight != 0 && weight_set[i].weight < min_weight) {
            min_weight = weight_set[i].weight;
            min_weight_index = i;
        }
    }
    return min_weight_index;
}
//查找顶点下标
int SrchVexIndex(AdjacencyMatrix graph, char srch_vex) {
    for (int i = 0; i < graph.vex_num; i++) {
        if (graph.vex[i] == srch_vex) {
            return i;
        }
    }
    return -1;
}
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
//Prim 算法
void MinimumSpanningTreeByPrim(AdjacencyMatrix graph, char vex) {
    WeightSet weight_set[graph.vex_num];
    int vex_index = SrchVexIndex(graph, vex);
    //初始化集合
    for (int i = 0; i < graph.vex_num; i++) {
        weight_set[i].adj_vex_index = vex_index;
        weight_set[i].weight = graph.edge[vex_index][i];
    }
    weight_set[vex_index].weight = 0; //起始点加入集合（自己到自己的权值为 0）
    for (int i = 0; i < graph.vex_num - 1; i++) {
        int min_weight_index = SrchMinWeightIndex(weight_set, graph.vex_num); //选取最小权值边
        int min_weight_adj_vex_index = weight_set[min_weight_index].adj_vex_index; //最小权值边的邻接点
        cout << graph.vex[min_weight_adj_vex_index] << "->" << graph.vex[min_weight_index] << " ";
        weight_set[min_weight_index].weight = 0; //将该边加入集合
        //更新集合
        for (int j = 0; j < graph.vex_num; j++) {
            if (graph.edge[min_weight_index][j] < weight_set[j].weight) {
                weight_set[j].weight = graph.edge[min_weight_index][j];
                weight_set[j].adj_vex_index = min_weight_index;
            }
        }
    }
}
#endif
#ifdef ADJACENCY_LIST_BY_PRIM
struct WeightSet {
    int adj_vex_index; //边终点的下标
    int weight; //权值
};
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
//查找集合中顶点之间的最小权值下标
int SrchMinWeightIndex(WeightSet weight_set[], int size) {
    int min_weight = INT_MAX;
    int min_weight_index = -1;
    for (int i = 0; i < size; i++) {
        if (weight_set[i].weight != 0 && weight_set[i].weight < min_weight) {
            min_weight = weight_set[i].weight;
            min_weight_index = i;
        }
    }
    return min_weight_index;
}
//查找顶点下标
int SrchVexIndex(AdjacencyList graph, char srch_vex) {
    for (int i = 0; i < graph.vex_num; i++) {
        if (graph.vex_list[i].vex == srch_vex) {
            return i;
        }
    }
    return -1;
}
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
//Prim 算法
void MinimumSpanningTreeByPrim(AdjacencyList graph, char vex) {
    WeightSet weight_set[graph.vex_num];
    int vex_index = SrchVexIndex(graph, vex);
    //初始化集合
    for (int i = 0; i < graph.vex_num; i++) {
        weight_set[i].adj_vex_index = vex_index;
        weight_set[i].weight = INT_MAX;
    }
    weight_set[vex_index].weight = 0; //起始点加入集合（自己到自己的权值为 0）
    //遍历该点的表，将其权值加入集合
    for (EdgeNode * i = graph.vex_list[vex_index].first; i != nullptr; i = i->next) {
        weight_set[i->adj_vex_index].weight = i->weight;
    }
    for (int i = 0; i < graph.vex_num - 1; i++) {
        int min_weight_index = SrchMinWeightIndex(weight_set, graph.vex_num); //选取最小权值边
        int min_weight_adj_vex_index = weight_set[min_weight_index].adj_vex_index; //最小权值边的邻接点
        cout << graph.vex_list[min_weight_adj_vex_index].vex << "->" << graph.vex_list[min_weight_index].vex << " ";
        weight_set[min_weight_index].weight = 0; //将该边加入集合
        //更新集合
        for (EdgeNode * j = graph.vex_list[min_weight_index].first; j != nullptr; j = j->next) {
            if (j->weight < weight_set[j->adj_vex_index].weight) {
                weight_set[j->adj_vex_index].adj_vex_index = min_weight_index;
                weight_set[j->adj_vex_index].weight = j->weight;
            }
        }
    }
}
#endif
#ifdef ADJACENCY_MATRIX_BY_KRUSKAL
struct EdgeSet {
    int begin; //边起点
    int end; //边终点
    int weight; //边权值
};
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
//Kruskal 算法
void MinimumSpanningTreeByKruskal(AdjacencyMatrix graph, char vex) {
    EdgeSet edge_set[graph.edge_num];
    EdgeSet * edge_set_ptr = edge_set;
    //初始化集合
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = i + 1; j < graph.vex_num; j++) {
            if (graph.edge[i][j] < INT_MAX) {
                edge_set_ptr->begin = i;
                edge_set_ptr->end = j;
                edge_set_ptr->weight = graph.edge[i][j];
                edge_set_ptr++;
            }
        }
    }
    //对权值进行冒泡排序
    for (int i = 0; i < graph.edge_num - 1; i++) {
        for (int j = 0; j < graph.edge_num - 1 - i; j++) {
            if (edge_set[j].weight > edge_set[j + 1].weight) {
                EdgeSet temp = edge_set[j];
                edge_set[j] = edge_set[j + 1];
                edge_set[j + 1] = temp;
            }
        }
    }
    int connect[graph.vex_num]; //连通依赖点的集合，connect[a] = b（a 必有一条到 b 的路径）
    //初始化当前连通分量为自己
    for (int i = 0; i < graph.vex_num; i++) {
        connect[i] = i;
    }
    for (int i = 0; i < graph.edge_num; i++) {
        int begin_vex = edge_set[i].begin;
        int end_vex = edge_set[i].end;
        int connect_begin_vex = connect[begin_vex];
        int connect_end_vex = connect[end_vex];
        if (connect_begin_vex != connect_end_vex) {
            cout << graph.vex[begin_vex] << "->" << graph.vex[end_vex] << " ";
            for (int j = 0; j < graph.vex_num; j++) {
                if (connect[j] == connect_end_vex) {
                    connect[j] = connect_begin_vex; //如果顶点 j 依赖于 connect_end_vex 的连通分量，那么连接之后所有顶点都依赖于 connect_begin_vex 的连通分量
                }
            }
        }
    }
}
#endif
int main() {
    #ifdef ADJACENCY_MATRIX_BY_PRIM
    AdjacencyMatrix graph = {};
    CrtUndirectedWeightedGraph(graph);
    MinimumSpanningTreeByPrim(graph, graph.vex[0]);
    #endif
    #ifdef ADJACENCY_LIST_BY_PRIM
    AdjacencyList graph = {};
    CrtUndirectedWeightedGraph(graph);
    MinimumSpanningTreeByPrim(graph, graph.vex_list[0].vex);
    #endif
    #ifdef ADJACENCY_MATRIX_BY_KRUSKAL
    AdjacencyMatrix graph = {};
    CrtUndirectedWeightedGraph(graph);
    MinimumSpanningTreeByKruskal(graph, graph.vex[0]);
    #endif
    return 0;
}
#if 0
/*
6 10
a b c d e f
ab6 ac1 ad5 bc5 be3 cd5 ce6 cf4 df2 ef6
    a
 /  |  \
b — c — d
 \ / \ /
  e — f
*/
#endif