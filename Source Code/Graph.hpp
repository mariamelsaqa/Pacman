//
//  Graph.hpp
//  PacmanFinal
//
//  Created by Mariam Elsaqa on 5/18/20.
//  Copyright © 2020 None. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include<vector>
#include<set>
#include<string>
#include<iostream>
#include <utility>
#include <stack>
#include <queue>
#include <limits.h>
#include <stdio.h>
#include <list>

using namespace std;

class Graph
{
    int numVertices;
    vector<vector<int>> adjLists;
    bool* visited;
    
public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    bool BFS(int startVertex,int dest,  int pred[], int dist[]);
    void printDist(int source, int dest);
    void plainBFS(int startVertex);
};


#endif /* Graph_hpp */
