#include "bellman.h"

class BellmanFord;
class TestStudy;

void BellmanFord::BF(int graph[20][20], int vertices, char Start, int Value[20], int Previous[20]){
     for(int i = 0; i < vertices; i++){
          if(graph[Start][i] != 0 && graph[Start][i]!=__INT_MAX__){
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

int main(){
     int graph[20][20] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
     };
     int vertices = 4;
     char Start = 'A';
     int Value[20];
     int Previous[20];
     for(int i = 0; i < vertices; i++){
         Value[i] = __INT_MAX__;
         Previous[i] = -1;
     }
     Value[Start - 'A'] = 0;
     BellmanFord bf;
     bf.BF(graph, vertices, Start, Value, Previous);
     std::string path = bf.BF_Path(graph, vertices, Start, 'D');
     std::cout << path << std::endl;
}