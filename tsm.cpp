#include "tsm.h"

class TSM;
class TestStudy;

void TSM::tsm(int graph[20][20], int num, char Start, int *Value, int *Previous){
     for(int i = 0; i < num; i++){
          if(graph[Start][i] != 0){
               if(Value[i] > Value[Start] + graph[Start][i]){
                    Value[i] = Value[Start] + graph[Start][i];
                    Previous[i] = Start;
               }
          }
     }
};

string TSM::Travelling(int graph[20][20], int num, char Start) {
/*Print the shortest path over all the vertices and return to the starting vertex.*/
     int Value[20];
     int Previous[20];
     for(int i = 0; i < num; i++){
          Value[i] = __INT_MAX__;
          Previous[i] = -1;
     }
     Value[Start] = 0;
     for(int i = 0; i < num - 1; i++){
          for(int j = 0; j < num; j++){
               tsm(graph, num, j, Value, Previous);
          }
     }
     std::string path = "";
     int temp = Start;
     while(temp != -1){
          path = char(temp + 'A') + path;
          temp = Previous[temp];
     }
     return path;
};
     