//
//  Graph.cpp
//  PacmanFinal
//
//  Created by Mariam Elsaqa on 5/18/20.
//  Copyright © 2020 None. All rights reserved.
//

#include "Graph.hpp"
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists.resize(vertices);
}

void Graph::addEdge(int src, int dest)
{
    
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::plainBFS(int startVertex)
{
    
    visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
        visited[i] = false;
    
    list<int> queue;
    
    visited[startVertex] = true;
    queue.push_back(startVertex);
    
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop_front();
        
        for(auto i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if(!visited[adjVertex])
            {
                
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

bool Graph::BFS(int startVertex, int dest, int pred[], int dist[] )
{   list<int> queue;
    visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
    {  visited[i] = false;
        dist[i]= INT_MAX;
        pred[i]=-1;
    }
    
    
    
    visited[startVertex] = true;
    dist[startVertex] = 0;
    queue.push_back(startVertex);
    
    
    while(!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " \n";
        queue.pop_front();
       
        for(int i = 0; i < adjLists[currVertex].size(); i++)
        {
          
            if(!visited[adjLists[currVertex][i]])
            {
                
                visited[adjLists[currVertex][i]] = true;
                dist[(adjLists[currVertex][i])] = dist[currVertex] +1;
                pred[adjLists[currVertex][i]] = currVertex;
                queue.push_back(adjLists[currVertex][i]);
                
                if (adjLists[currVertex][i] == dest) {
                    return true;
                }
            }
        }
       
    } return false;
}
void Graph::printDist(int source, int dest){
    int pred[numVertices], dist[numVertices];
    cout << "predd: " << pred[0];
    if (BFS(source, dest, pred, dist) == false) {
        cout <<"nope";
        return;
    }
    
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    cout << "predd: " << pred[1];
    while(pred[crawl] != -1){
        path.push_back(pred[crawl]);
        crawl=pred[crawl];
    }
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    
}

