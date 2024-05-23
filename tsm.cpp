#include "tsm.h"

class TSM;
class TestStudy;


string TSM::Traveling(int graph[20][20], int num, char Start){
     int Value[20];
     int Previous[20];
     for(int i = 0; i < num; i++){
          Value[i] = __INT_MAX__;
          Previous[i] = -1;
     }
     Value[Start - 'A'] = 0;

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

     string path = "";
     int temp = 0;
     for(int i = 1; i < num; i++){
          if(Value[i] < Value[temp]){
               temp = i;
          }
     }
     path = Start;
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
     int vertices = 12;
     char Start = 'A';
     TSM tsm;
     string path = tsm.Traveling(graph, vertices, Start);
     cout << path << endl;
     return 0;
}