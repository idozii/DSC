#include "tsm.h"

string TSM::Travelling(std::vector<std::vector<int>>& graph, int num, char Start) {
     /*write function Traveling() to calculate the shortest
way to go over all the vertices in the graph and go back to the starting vertex.*/
     std::vector<std::vector<int>> Value(1, std::vector<int>(num, INT_MAX));
     std::vector<std::vector<int>> Previous(1, std::vector<int>(num, -1));
     Value[0][Start - 'A'] = 0;
     for(int i = 0; i < num - 1; i++){
          BellF::BF(graph, num, Start - 'A', Value, Previous);
     }
     std::string path = "";
     int current = Start - 'A';
     std::vector<int> visited(num, 0);
     visited[current] = 1;
     int min = INT_MAX;
     int next = -1;
     for(int i = 0; i < num; i++){
          if(visited[i] == 0 && graph[current][i] != 0 && Value[0][i] < min){
               min = Value[0][i];
               next = i;
          }
     }
     while(next != -1){
          visited[next] = 1;
          path = path + (char)(next + 'A');
          current = next;
          min = INT_MAX;
          next = -1;
          for(int i = 0; i < num; i++){
               if(visited[i] == 0 && graph[current][i] != 0 && Value[0][i] < min){
                    min = Value[0][i];
                    next = i;
               }
          }
     }
     path = Start + path;
     return path;
};
     