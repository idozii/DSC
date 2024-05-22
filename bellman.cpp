#include "bellman.h"

class BellmanFord;
class TestStudy;

void BellmanFord::BF(int graph[20][20], int vertices, char Start, int Value[20], int Previous[20]){
     for(int i = 0; i < vertices; i++){
          if(graph[Start][i] != 0){
               if(Value[i] > Value[Start] + graph[Start][i]){
                    Value[i] = Value[Start] + graph[Start][i];
                    Previous[i] = Start;
               }
          }
     }
};

std::string BellmanFord::BF_Path(int graph[20][20], int vertices, char Start, char Goal){
     int Value[20];
     int Previous[20];
     for(int i = 0; i < vertices; i++){
          Value[i] = __INT_MAX__;
          Previous[i] = -1;
     }
     Value[Start - 'A'] = 0;
     for(int i = 0; i < vertices - 1; i++){
          for(int j = 0; j < vertices; j++){
               BF(graph, vertices, j, Value, Previous);
          }
     }
     std::string path = "";
     int current = Goal - 'A';
     while(current != Start - 'A'){
          path = path + " " + (char)(current + 'A');
          current = Previous[current];
     }
     path = Start + path;
     return path;
};