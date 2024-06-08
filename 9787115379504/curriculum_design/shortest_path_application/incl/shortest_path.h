#pragma once

#include "adj_mat.h"

//Dijkstra 算法
void ShortestPathByDijkstra(AdjMat graph, char vex);

//Floyd算法
void ShortestPathByFloyd(AdjMat graph, char begin_vex, char end_vex);