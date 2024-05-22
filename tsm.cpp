#include "tsm.h"

class TSM;
class TestStudy;

void TSM::tsm(std::vector<std::vector<int>>& graph, int vertices, char Start, std::vector<std::vector<int>>& Value, std::vector<std::vector<int>>& Previous){
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

std::string TSM::Travelling(std::vector<std::vector<int>>& graph, int num, char Start) {
     std::vector<std::vector<int>> Value(1, std::vector<int>(num, INT_MAX));
     std::vector<std::vector<int>> Previous(1, std::vector<int>(num, -1));
     Value[0][Start - 'A'] = 0;
     for(int i = 0; i < num - 1; i++){
          tsm(graph, num, Start - 'A', Value, Previous);
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
     