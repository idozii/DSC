#include "bellman.h"

void BellF::BF(std::vector<std::vector<int>>& graph, int vertices, char Start, std::vector<std::vector<int>>& Value, std::vector<std::vector<int>>& Previous){
    /*Write function BF() to calculate 1 step of Bellman-Ford on an
input graph.*/
     /*Updated Bellman-Ford Value array based on the current Graph.*/
     for(int i = 0; i < vertices; i++){
          for(int j = 0; j < vertices; j++){
               if(graph[i][j] != 0){
                    if(Value[0][j] > Value[0][i] + graph[i][j]){
                         Value[0][j] = Value[0][i] + graph[i][j];
                         Previous[0][j] = i;
                    }
               }
          }
     }
};

string BellF::BF_Path(std::vector<std::vector<int>>& graph, int vertices, char Start, char Goal){
     /*a string containing the shortest path from Start vertex to Goal vertex*/
     /*Write function BF_Path() to return a string containing the Bellman-
Ford path from input start and goal vertices.*/
     std::vector<std::vector<int>> Value(1, std::vector<int>(vertices, INT_MAX));
     std::vector<std::vector<int>> Previous(1, std::vector<int>(vertices, -1));
     Value[0][Start - 'A'] = 0;
     for(int i = 0; i < vertices - 1; i++){
          BF(graph, vertices, Start - 'A', Value, Previous);
     }
     std::string path = "";
     int current = Goal - 'A';
     while(current != Start - 'A'){
          path = (char)(current + 'A') + path;
          current = Previous[0][current];
     }
     path = Start + path;
     return path;
};