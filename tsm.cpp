#include "tsm.h"

class TSM;
class TestStudy;

string TSM::Traveling(int graph[20][20], int num, char Start){
     int Value[1 << num][num];
     int previousCity[1 << num][num];
     for(int i = 0; i < (1 << num); i++){
          for(int j = 0; j < num; j++){
               Value[i][j] = MAX;
               previousCity[i][j] = -1;
          }
     }
     Value[1 << (Start - 'A')][Start - 'A'] = 0;
     for(int i = 0; i < (1 << num); i++){
          for(int j = 0; j < num; j++){
               if(i & (1 << j)){
                    for(int k = 0; k < num; k++){
                         if(i & (1 << k)){
                              if(Value[i ^ (1 << j)][k] + graph[k][j] < Value[i][j]){
                                   Value[i][j] = Value[i ^ (1 << j)][k] + graph[k][j]; 
                                   previousCity[i][j] = k; 
                              }
                         }
                    }
               }
          }
     }
     int min = MAX;
     int min_index = -1;
     for(int i = 0; i < num; i++){
          if(i != Start - 'A' && Value[(1 << num) - 1][i] + graph[i][Start - 'A'] < min){
               min = Value[(1 << num) - 1][i] + graph[i][Start - 'A'];
               min_index = i;
          }
     }

     string result = "";
     int temp = (1 << num) - 1; 
     int temp_index = min_index; 
     while(temp_index != -1){
          if(result != ""){
               result = " " + result;
          }
          result = char(temp_index + 'A') + result;
          int temp2 = temp_index;
          temp_index = previousCity[temp][temp_index];
          temp ^= (1 << temp2);
     }
     result = result + " " + Start;
     return result;
};