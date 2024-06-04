#include "bellman.h"

class BellmanFord;
class TestStudy;

void BellmanFord::BF(int graph[20][20], int num, char Start, int *Value, int *Previous){
     //*Explain: this function returns ONLY 1 step of BF function
     /*write function to calculate BF step by step */
     static int step = 1;
     if(step == 1){
          for(int i = 0; i < num; i++){
                    Value[i] = MAX;
                    Previous[i] = -1;
               }
               Value[Start - 'A'] = 0;
               Previous[Start - 'A'] = -1;
               for(int i = 0; i < num; i++){
                    if(graph[Start - 'A'][i] != MAX && graph[Start - 'A'][i] != 0){
                         Value[i] = graph[Start - 'A'][i];
                         Previous[i] = Start - 'A';
                    }
               }
               step++;
     }
     else{
          for(int i = 0; i < num; i++){
               for(int j = 0; j < num; j++){
                    if(Value[i] + graph[i][j] < Value[j] && graph[i][j] != MAX && graph[i][j] != 0 && Value[i] != MAX){
                         Value[j] = Value[i] + graph[i][j];
                         Previous[j] = i;
                    }
               }
          }
     }
};

void BellmanFord::BFF(int graph[20][20], int num, char Start, int *Value, int *Previous){
     //*Explain: this function returns last step of above BF function
     if(num <=0 || num>20) return;
     for(int i = 0; i < num; i++){
          Value[i] = MAX;
          Previous[i] = -1;
     }    
     Value[Start - 'A'] = 0; 
     for(int k = 0; k < num - 1; k++){
          for(int i = 0; i < num; i++){
               for(int j = 0; j < num; j++){
                    if(Value[i] + graph[i][j] < Value[j] && graph[i][j] != MAX && graph[i][j] != 0 && Value[i] != MAX){
                         Value[j] = Value[i] + graph[i][j];
                         Previous[j] = i;
                    }
               }
          }
     }
     for(int i = 0; i < num; i++){
          for(int j = 0; j < num; j++){
               if(Value[i] + graph[i][j] < Value[j]){
                    Value[j] = -MAX;
               }
          }
     }
};

string BellmanFord::BF_Path(int graph[20][20], int num, char Start, char Goal){
     //*Explain: this function returns the shortest path from Start to Goal
     int Value[20];
     int Previous[20];
     BFF(graph, num, Start, Value, Previous);
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

//! Fix BF function

int main(){
     int graph[20][20] = {
          {0, 10, 15, 20, 30},
          {10, 0, 35, 25, 15},
          {15, 35, 0, 30, 20},
          {20, 25, 30, 0, 10},
          {30, 15, 20, 10, 0}
     };
     BellmanFord bf;
     int Value[20];
     int Previous[20];
     bf.BF(graph, 5, 'A', Value, Previous);
     for(int i = 0; i < 5; i++){
          cout<<"Step"<<": "<<Value[i]<<" "<<Previous[i]<<endl;
     }
}