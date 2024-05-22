#include "tsm.h"

class TSM;
class TestStudy;

void TSM::tsm(int graph[20][20], int vertices, char Start, int Value[20], int Previous[20]){
     for(int i = 0; i < vertices; i++){
          if(graph[Start][i] != 0){
               if(Value[i] > Value[Start] + graph[Start][i]){
                    Value[i] = Value[Start] + graph[Start][i];
                    Previous[i] = Start;
               }
          }
     }
};

std::string TSM::Travelling(int graph[20][20], int num, char Start) {
     std::vector<std::vector<int>> Value(1, std::vector<int>(num, INT_MAX));
     std::vector<std::vector<int>> Previous(1, std::vector<int>(num, -1));
     Value[0][Start - 'A'] = 0;
     for(int i = 0; i < num - 1; i++){
          for(int j = 0; j < num; j++){
               tsm(graph, num, j, Value[0].data(), Previous[0].data());
          }
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
     