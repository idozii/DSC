#include "bellman.h"

class BellmanFord;
class TestStudy;

void BellmanFord::BF(int graph[20][20], int num, char Start, int *Value, int *Previous){
     //TODO: Initialize the value and previous arrays
     for(int i = 0; i < num; i++){
          Value[i] = __INT_MAX__;
          Previous[i] = -1;
     }    
     Value[Start - 'A'] = 0; 
     
     //TODO: Iteration for all vertices
     for(int k = 0; k < num - 1; k++){
          for(int i = 0; i < num; i++){
               for(int j = 0; j < num; j++){
                    if(graph[i][j] != 0 && Value[i] != __INT_MAX__ && Value[i] + graph[i][j] < Value[j]){
                         Value[j] = Value[i] + graph[i][j];
                         Previous[j] = i;
                    }
               }
          }
     }

     //TODO: Check for negative weight cycles
     for(int i = 0; i < num; i++){
          for(int j = 0; j < num; j++){
               if(graph[i][j] != 0 && Value[i] != __INT_MAX__ && Value[i] + graph[i][j] < Value[j]){
                    cout << "Graph contains a negative-weight cycle" << endl;
                    return;
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
     BF(graph, num, Start, Value, Previous);
     std::string path = "";
     int temp = Goal - 'A';
     while(temp != -1){
          if(path != ""){
               path = " " + path;
          }
          path = char(temp + 'A') + path;
          temp = Previous[temp];
     }
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
     int num = 4;
     char Start = 'A';
     int Value[20];
     int Previous[20];
     for(int i = 0; i < num; i++){
          Value[i] = __INT_MAX__;
          Previous[i] = -1;
     }
     Value[Start - 'A'] = 0;
     BellmanFord bf;
     bf.BF(graph, num, Start, Value, Previous);
     std::string path = bf.BF_Path(graph, num, Start, 'D');
     std::cout << path << std::endl;
     return 0;
}