#include "bellman.h"

class BellmanFord;
class TestStudy;

void BellmanFord::BF(int graph[20][20], int num, char Start, int *Value, int *Previous){
     for(int i = 0; i < num; i++){
          if(graph[Start][i] != 0){
               if(Value[i] > Value[Start] + graph[Start][i]){
                    Value[i] = Value[Start] + graph[Start][i];
                    Previous[i] = Start;
               }
          }
     }
};

string BellmanFord::BF_Path(int graph[20][20], int num, char Start, char Goal){
     int Value[20];
     int Previous[20];
     for(int i = 0; i < num; i++){
          Value[i] = __INT_MAX__;
          Previous[i] = -1;
     }
     Value[Start - 'A'] = 0;
     for(int i = 0; i < num - 1; i++){
          for(int j = 0; j < num; j++){
               BF(graph, num, j, Value, Previous);
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
     // Test case 01
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
     return 0;
}