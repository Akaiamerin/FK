#include <iostream>
using namespace std;
// #define ADJACENCYMATRIX //邻接矩阵
// #define ADJACENCYLIST //邻接表
#ifdef ADJACENCYMATRIX
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
//增加一个顶点
void InsVex(AdjacencyMatrix & graph, char ins_vex) {
    if (graph.vex_num >= 100) {
        return;
    }
    if (SrchVexIndex(graph, ins_vex) != -1) {
        return;
    }
    graph.vex[graph.vex_num] = ins_vex;
    graph.vex_num++;
}
//删除顶点及其相关的边
void DelVex(AdjacencyMatrix & graph, char del_vex) {
    int del_vex_index = SrchVexIndex(graph, del_vex);
    int last_vex_index = graph.vex_num - 1;
    if (del_vex_index == -1) {
        return;
    }
    swap(graph.vex[del_vex_index], graph.vex[last_vex_index]);
    for (int i = 0; i < graph.vex_num; i++) {
        swap(graph.edge[del_vex_index][i], graph.edge[last_vex_index][i]);
    }
    for (int i = 0; i < graph.vex_num; i++) {
        swap(graph.edge[i][del_vex_index], graph.edge[i][last_vex_index]);
    }
    graph.vex_num--;
}
//增加一条边
void InsEdge(AdjacencyMatrix & graph, char begin_vex, char end_vex) {
    int begin_vex_index = SrchVexIndex(graph, begin_vex);
    int end_vex_index = SrchVexIndex(graph, end_vex);
    if (begin_vex_index != -1 && end_vex_index != -1) {
        graph.edge[begin_vex_index][end_vex_index] = 1;
        graph.edge[end_vex_index][begin_vex_index] = 1;
    }
    graph.edge_num++;
}
//删除一条边
void DelEdge(AdjacencyMatrix & graph, char begin_vex, char end_vex) {
    int begin_vex_index = SrchVexIndex(graph, begin_vex);
    int end_vex_index = SrchVexIndex(graph, end_vex);
    if (begin_vex_index != -1 && end_vex_index != -1) {
        graph.edge[begin_vex_index][end_vex_index] = 0;
        graph.edge[end_vex_index][begin_vex_index] = 0;
    }
    graph.edge_num--;
}
//遍历
void Traverse(AdjacencyMatrix graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        cout << graph.vex[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = 0; j < graph.vex_num; j++) {
            cout << graph.edge[i][j] << " ";
        }
        cout << endl;
    }
}
#endif
#ifdef ADJACENCYLIST
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
//增加一个顶点
void InsVex(AdjacencyList & graph, char ins_vex) {
    if (graph.vex_num >= 100) {
        return;
    }
    if (SrchVexIndex(graph, ins_vex) != -1) {
        return;
    }
    graph.vex_list[graph.vex_num].vex = ins_vex;
    graph.vex_list[graph.vex_num].first = nullptr;
    graph.vex_num++;
}
//删除顶点及其相关的边
void DelVex(AdjacencyList & graph, char del_vex) {
    int del_vex_index = SrchVexIndex(graph, del_vex);
    for (int i = 0; i < graph.vex_num; i++) {
        EdgeNode * edge_node = graph.vex_list[i].first;
        if (edge_node != nullptr && edge_node->adj_vex_index == del_vex_index) {
            graph.vex_list[i].first = edge_node->next;
            delete edge_node;
            edge_node = nullptr;
        }
        else {
            while (edge_node != nullptr) {
                if (edge_node->next != nullptr && edge_node->next->adj_vex_index == del_vex_index) {
                    EdgeNode * del_edge_node = edge_node->next;
                    edge_node->next = edge_node->next->next;
                    delete del_edge_node;
                    del_edge_node = nullptr;
                    break;
                }
                else {
                    edge_node = edge_node->next;
                }
            }
        }
    }
    EdgeNode * edge_node = graph.vex_list[del_vex_index].first;
    graph.vex_list[del_vex_index].first = nullptr;
    while (edge_node != nullptr) {
        EdgeNode * del_edge_node = edge_node;
        edge_node = edge_node->next;
        delete del_edge_node;
        del_edge_node = nullptr;
    }
    graph.vex_list[del_vex_index] = graph.vex_list[graph.vex_num - 1];
    graph.vex_num--;
}
//增加一条边
void InsEdge(AdjacencyList & graph, char begin_vex, char end_vex) {
    int begin_vex_index = SrchVexIndex(graph, begin_vex);
    int end_vex_index = SrchVexIndex(graph, end_vex);
    EdgeNode * begin_vex_node = new EdgeNode;
    begin_vex_node->adj_vex_index = end_vex_index;
    begin_vex_node->next = graph.vex_list[begin_vex_index].first;
    graph.vex_list[begin_vex_index].first = begin_vex_node;
    EdgeNode * end_vex_node = new EdgeNode;
    end_vex_node->adj_vex_index = begin_vex_index;
    end_vex_node->next = graph.vex_list[end_vex_index].first;
    graph.vex_list[end_vex_index].first = end_vex_node;
    graph.edge_num++;
}
//删除一条边
void DelEdge(AdjacencyList & graph, char begin_vex, char end_vex) {
    int begin_vex_index = SrchVexIndex(graph, begin_vex);
    int end_vex_index = SrchVexIndex(graph, end_vex);
    EdgeNode * begin_vex_node = graph.vex_list[begin_vex_index].first;
    EdgeNode * end_vex_node = graph.vex_list[end_vex_index].first;
    if (begin_vex_node != nullptr && begin_vex_node->adj_vex_index == end_vex_index) {
        graph.vex_list[begin_vex_index].first = begin_vex_node->next;
        delete begin_vex_node;
        begin_vex_node = nullptr;
    }
    else {
        while (begin_vex_node != nullptr) {
            if (begin_vex_node->next != nullptr && begin_vex_node->next->adj_vex_index == end_vex_index) {
                EdgeNode * del_edge_node = begin_vex_node->next;
                begin_vex_node->next = begin_vex_node->next->next;
                delete del_edge_node;
                del_edge_node = nullptr;
                break;
            }
            else {
                begin_vex_node = begin_vex_node->next;
            }
        }
    }
    if (end_vex_node != nullptr && end_vex_node->adj_vex_index == begin_vex_index) {
        graph.vex_list[end_vex_index].first = end_vex_node->next;
        delete end_vex_node;
        end_vex_node = nullptr;
    }
    else {
        while (end_vex_node != nullptr) {
            if (end_vex_node->next != nullptr && end_vex_node->next->adj_vex_index == begin_vex_index) {
                EdgeNode * del_edge_node = end_vex_node->next;
                end_vex_node->next = end_vex_node->next->next;
                delete del_edge_node;
                del_edge_node = nullptr;
                break;
            }
            else {
                end_vex_node = end_vex_node->next;
            }
        }
    }
    graph.edge_num--;
}
//遍历
void Traverse(AdjacencyList graph) {
    for (int i = 0; i < graph.vex_num; i++) {
        for (EdgeNode * j = graph.vex_list[i].first; j != nullptr; j = j->next) {
            cout << "[" << graph.vex_list[i].vex << "->" << graph.vex_list[j->adj_vex_index].vex << "] ";
        }
        cout << endl;
    }
}
#endif
int main() {

    return 0;
}