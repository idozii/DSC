#include "bellman.h"

class BellmanFord;
class TestStudy;

const static int MAX = 999;

void BF(int graph[20][20], int num, char Start, int *Value, int *Previous){
     //TODO: Initialization steps:
     for(int i = 0; i < num; i++){
          Value[i] = MAX;
          Previous[i] = -1;
     }    
     Value[Start - 'A'] = 0; 
     
     //TODO: Iteration steps:
     for(int k = 0; k < num - 1; k++){
          for(int i = 0; i < num; i++){
               for(int j = 0; j < num; j++){
                    if(Value[i] + graph[i][j] < Value[j]){
                         Value[j] = Value[i] + graph[i][j];
                         Previous[j] = i;
                    }
               }
          }
     }

     //TODO: Check circuit of negative weight
     for(int i = 0; i < num; i++){
          for(int j = 0; j < num; j++){
               if(Value[i] + graph[i][j] < Value[j]){
                    cout << "Contains circuit of negative weight" << endl;
                    return;
               }
          }
     }
};

string BellmanFord::BF_Path(int graph[20][20], int num, char Start, char Goal){
     //TODO: Initialization steps:
     int Value[20];
     int Previous[20];
     for(int i = 0; i < num; i++){
          Value[i] = MAX;
          Previous[i] = -1;
     }
     Value[Start - 'A'] = 0;

     //TODO: Bellman Ford algorithm
     BF(graph, num, Start, Value, Previous);

     //TODO: Path
     string path = "";
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
     int graph[20][20] = {
          {0, 6, 5, 5, MAX, MAX, MAX, MAX, MAX, MAX},
          {MAX, 0, MAX, MAX, -1, MAX, MAX, MAX, MAX, MAX},
          {MAX, -2, 0, MAX, 1, MAX, MAX, MAX, MAX, MAX},
          {MAX, MAX, -2, 0, MAX, MAX, MAX, MAX, MAX, MAX},
          {MAX, MAX, MAX, MAX, 0, -1, MAX, MAX, MAX, MAX},
          {MAX, MAX, MAX, MAX, MAX, 0, -1, MAX, MAX, MAX},
          {MAX, MAX, MAX, MAX, MAX, MAX, 0, 1, MAX, MAX},
          {MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0, 1, MAX},
          {MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0, 1},
          {MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0}
     };
     BellmanFord bf;
     cout << bf.BF_Path(graph, 10, 'A', 'J') << endl;
     return 0;
}