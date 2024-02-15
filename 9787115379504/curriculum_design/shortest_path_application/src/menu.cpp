#include <sstream>
#include <iostream>
#include "menu.h"
#include "utils.h"
#include "adj_mat.h"
#include "shortest_path.h"

//创建图
void CrtGraph(AdjMat & graph, std::vector<std::string> vec) {
    int vex_num = 0;
    int edge_num = 0;
    std::istringstream iss(vec[0]);
    iss >> vex_num >> edge_num;
    for (int i = 1; i < vec.size(); i++) {
        if (i <= vex_num) {
            InsVex(graph, vec[i][0]);
        }
        else {
            iss.clear();
            iss.str(vec[i]);
            char begin_vex = {};
            char end_vex = {};
            int weight = 0;
            iss >> begin_vex >> end_vex >> weight;
            InsEdge(graph, begin_vex, end_vex, weight);
        }
    }
}

//获取图的信息，用于写入文件
std::vector<std::string> GetGraphInfo(AdjMat & graph) {
    std::vector<std::string> vec = {};
    vec.push_back(std::to_string(graph.vex_num) + " " + std::to_string(graph.edge_num));
    for (int i = 0; i < graph.vex_num; i++) {
        vec.push_back(std::string(sizeof(graph.vex[i]), graph.vex[i]));
    }
    for (int i = 0; i < graph.vex_num; i++) {
        for (int j = i; j < graph.vex_num; j++) {
            if (graph.edge[i][j] > 0 && graph.edge[i][j] < INT_MAX) {
                vec.push_back(std::string(sizeof(graph.vex[i]), graph.vex[i]) + " " + std::string(sizeof(graph.vex[j]), graph.vex[j]) + " " + std::to_string(graph.edge[i][j]));
            }
        }
    }
    return vec;
}

//菜单
void Menu() {
    std::vector<std::string> read_vec = {};
    ReadFile(FILE_PATH, read_vec);
    AdjMat graph = InitAdjMat(graph);
    CrtGraph(graph, read_vec);
    while (true) {
        OutputAdjMat(graph);
        std::cout << "+—————————————————+" << std::endl;
        std::cout << "|1. 增加景点      |" << std::endl;
        std::cout << "|2. 删除景点      |" << std::endl;
        std::cout << "|3. 增加路径      |" << std::endl;
        std::cout << "|4. 删除路径      |" << std::endl;
        std::cout << "|5. 景点信息查询  |" << std::endl;
        std::cout << "|6. 问路查询      |" << std::endl;
        std::cout << "|7. 退出          |" << std::endl;
        std::cout << "+—————————————————+" << std::endl;
        int opt = 0;
        std::cin >> opt;
        if (opt == 1) {
            system("cls");
            std::cout << "请输入待增加景点的名称：";
            char input_vex = {};
            std::cin >> input_vex;
            if (InsVex(graph, input_vex) == false) {
                std::cout << "增加景点失败" << std::endl;
            }
            system("pause");
            system("cls");
        }
        else if (opt == 2) {
            system("cls");
            std::cout << "请输入待删除景点的名称：";
            char input_vex = {};
            std::cin >> input_vex;
            if (DelVex(graph, input_vex) == false) {
                std::cout << "删除景点失败" << std::endl;
            }
            system("pause");
            system("cls");
        }
        else if (opt == 3) {
            system("cls");
            std::cout << "请输入待增加路径的信息（起点 终点 距离）：";
            char input_beign_vex = {};
            char input_end_vex = {};
            int input_weight = 0;
            std::cin >> input_beign_vex >> input_end_vex >> input_weight;
            if (InsEdge(graph, input_beign_vex, input_end_vex, input_weight) == false) {
                std::cout << "增加路径失败" << std::endl;
            }
            system("pause");
            system("cls");
        }
        else if (opt == 4) {
            system("cls");
            std::cout << "请输入待删除路径的信息（起点 终点）：";
            char input_beign_vex = {};
            char input_end_vex = {};
            std::cin >> input_beign_vex >> input_end_vex;
            if (DelEdge(graph, input_beign_vex, input_end_vex) == false) {
                std::cout << "删除路径失败" << std::endl;
            }
            system("pause");
            system("cls");
        }
        else if (opt == 5) {
            system("cls");
            std::cout << "请输入待查询景点：";
            char input_vex = {};
            std::cin >> input_vex;
            if (SrchVexIndex(graph, input_vex) == -1) {
                std::cout << "无该景点信息" << std::endl;
            }
            else {
                ShortestPathByDijkstra(graph, input_vex);
            }
            system("pause");
            system("cls");
        }
        else if (opt == 6) {
            system("cls");
            std::cout << "请输入起点和终点：";
            char input_beign_vex = {};
            char input_end_vex = {};
            std::cin >> input_beign_vex >> input_end_vex;
            if (SrchVexIndex(graph, input_beign_vex) == -1 || SrchVexIndex(graph, input_end_vex) == -1) {
                std::cout << "无该路径信息" << std::endl;
            }
            else {
                ShortestPathByFloyd(graph, input_beign_vex, input_end_vex);
            }
            system("pause");
            system("cls");
        }
        else if (opt == 7) {
            system("cls");
            break;
        }
        else {
            system("cls");
            std::cin.clear();
            std::cin.sync();
        }
    }
    std::vector<std::string> write_vec = GetGraphInfo(graph);
    WriteFile(FILE_PATH, write_vec);
}