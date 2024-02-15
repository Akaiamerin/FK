#include <iostream>
#include <climits>
using namespace std;
// #define ADJACENCY_MATRIX_BY_DIJKSTRA //基于邻接矩阵的无向有权图的 Dijkstra 算法
// #define ADJACENCY_MATRIX_BY_FLOYD //基于邻接矩阵的无向有权图的 Floyd 算法
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
//创建无向有权图例
void CrtUndirectedWeightedGraphExample(AdjacencyMatrix & graph) {
    graph.vex_num = 6;
    graph.edge_num = 8;
    char vex[graph.vex_num] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int edge[graph.vex_num][graph.vex_num] = {
        {0, INT_MAX, 10, INT_MAX, 30, 100},
        {INT_MAX, 0, 5, INT_MAX, INT_MAX, INT_MAX},
        {10, 5, 0, 50, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 50, 0, 20, 10},
        {30, INT_MAX, INT_MAX, 20, 0, 60},
        {100, INT_MAX, INT_MAX, 10, 60, 0}
    };
    for (int i = 0; i < graph.vex_num; i++) {
        graph.vex[i] = vex[i];
        for (int j = 0; j < graph.vex_num; j++) {
            graph.edge[i][j] = edge[i][j];
        }
    }
}
#ifdef ADJACENCY_MATRIX_BY_DIJKSTRA
//Dijkstra 算法
void UndirectedWeightedGraphByDijkstra(AdjacencyMatrix graph, char vex) {
    int vex_index = SrchVexIndex(graph, vex);
    int prev_vex[graph.vex_num]; //prev_vex[i] 为起点到 vex[i] 的最短路径所经历的全部顶点中， vex[i] 前驱顶点
    int min_weight[graph.vex_num]; //起点到 vex[i] 最小权值(最短路径长度)
    //初始化
    for (int i = 0; i < graph.vex_num; i++) {
        min_weight[i] = graph.edge[vex_index][i];
    }
    min_weight[vex_index] = 0; //初始化自己
    bool shortest_path_tag[graph.vex_num]; //是否找到起点到 vex[i] 的最短路径
    for (int i = 0; i < graph.vex_num; i++) {
        shortest_path_tag[i] = false;
    }
    shortest_path_tag[vex_index] = true;
    for (int i = 0; i < graph.vex_num - 1; i++) {
        int cur_min_weight = INT_MAX;
        int min_weight_index = -1; //查找在未获取最短路径的点中距离顶点最近的点
        for (int j = 0; j < graph.vex_num; j++) {
            if (shortest_path_tag[j] == false && min_weight[j] < cur_min_weight) {
                cur_min_weight = min_weight[j];
                min_weight_index = j;
            }
        }
        shortest_path_tag[min_weight_index] = true;
        //更新
        for (int i = 0; i < graph.vex_num; i++) {
            int temp_min_weight = INT_MAX;
            if (graph.edge[min_weight_index][i] < INT_MAX) {
                temp_min_weight = cur_min_weight + graph.edge[min_weight_index][i];
            }
            if (shortest_path_tag[i] == false && temp_min_weight < min_weight[i]) {
                min_weight[i] = temp_min_weight;
                prev_vex[i] = min_weight_index;
            }
        }
    }
    for (int i = 0; i < graph.vex_num; i++) {
        cout << "[" << graph.vex[vex_index] << "->" << graph.vex[i] << " " << min_weight[i] << "] ";
    }
}
#endif
#ifdef ADJACENCY_MATRIX_BY_FLOYD
//Floyd 算法
void UndirectedWeightedGraphByFloyd(AdjacencyMatrix graph, char begin_vex, char end_vex) {
    int begin_vex_index = SrchVexIndex(graph, begin_vex);
    int end_vex_index = SrchVexIndex(graph, end_vex);
    int prev_vex[graph.vex_num][graph.vex_num]; //prev_vex[i][j] 为 vex[i] 到 vex[j] 的最短路径所经历的全部顶点中， vex[j] 前驱顶点
    int min_weight[graph.vex_num][graph.vex_num]; //vex[i] 到 vex[j] 最小权值(最短路径长度)
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = 0; j < graph.vex_num; j++) {
            min_weight[i][j] = graph.edge[i][j];
            //判断 vex[i] 和 vex[j] 是否为邻接点
            if (min_weight[i][j] < INT_MAX) {
                prev_vex[i][j] = i;
            }
            else {
                prev_vex[i][j] = -1;
            }
        }
    }
    for (int k = 0; k < graph.vex_num; k++) {
        for (int i = 0; i < graph.vex_num; i++) {
            for (int j = 0; j < graph.vex_num; j++) {
                int temp_min_weight = INT_MAX;
                if (min_weight[i][k] == INT_MAX || min_weight[k][j] == INT_MAX) {
                    continue;
                }
                else {
                    temp_min_weight = min_weight[i][k] + min_weight[k][j];
                }
                if (temp_min_weight < min_weight[i][j]) {
                    min_weight[i][j] = temp_min_weight;
                    prev_vex[i][j] = prev_vex[k][j];
                }
            }
        }
    }
    cout << "[" << begin_vex << "->" << end_vex << " " << min_weight[begin_vex_index][end_vex_index] << "] ";
}
#endif
int main() {
    AdjacencyMatrix graph = {};
    CrtUndirectedWeightedGraphExample(graph);
    #ifdef ADJACENCY_MATRIX_BY_DIJKSTRA
    UndirectedWeightedGraphByDijkstra(graph, graph.vex[0]);
    #endif
    #ifdef ADJACENCY_MATRIX_BY_FLOYD
    for (int i = 0; i < graph.vex_num; i++) {
        UndirectedWeightedGraphByFloyd(graph, graph.vex[0], graph.vex[i]);
        cout << " ";
    }
    #endif
    return 0;
}
#if 0
/*
ac10 ae30 af100 bc5 cd50 df10 ed20 ef60
     a ————— e
     | \   / |
     |   f   |
     |     \ |
b —— c ————— d
    a   b   c   d   e   f
a   0   ∞  10   ∞  30 100
b   ∞   0   5   ∞   ∞   ∞
c  10   5   0  50   ∞   ∞
d  ∞    ∞  50   0  20  10
e  30   ∞   ∞  20   0  60
f 100   ∞   ∞  10  60   0
*/
#endif