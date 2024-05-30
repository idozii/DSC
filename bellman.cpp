#include "bellman.h"

class BellmanFord;
class TestStudy;

const static int MAX = 999;


void BellmanFord::BF(int graph[20][20], int num, char Start, int *Value, int *Previous){
     //*Explain: this function returns ONLY 1 step of BF function
     for(int i = 0; i < num; i++){
          Value[i] = MAX;
          Previous[i] = -1;
     }
     Value[Start - 'A'] = 0;
     
     if(graph[Start - 'A'][0] == 0){
          //TODO: Check the shortest path
          for(int i = 0; i < num; i++){
               if(graph[Start - 'A'][i] != MAX){
                    Value[i] = graph[Start - 'A'][i];
                    Previous[i] = Start - 'A';
               }
          }
     } else {
          //TODO: Iteration steps:
          for(int i = 0; i<num; i++){
               for(int j = 0; j<num; j++){
                    if(Value[i] + graph[i][j] < Value[j] && graph[i][j] != MAX && Value[i] != MAX){
                         Value[j] = Value[i] + graph[i][j];
                         Previous[j] = i;
                    }
               }
          }
     }
};

void BellmanFord::BFF(int graph[20][20], int num, char Start, int *Value, int *Previous){
     //*Explain: this function returns last step of above BF function
     if(num <=0){
          return;
     }
     for(int i = 0; i < num; i++){
          Value[i] = MAX;
          Previous[i] = -1;
     }    
     Value[Start - 'A'] = 0; 
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