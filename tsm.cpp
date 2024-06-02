#include "tsm.h"

class TSM;
class TestStudy;

string TSM::Traveling(int graph[20][20], int num, char Start){
     const static int MAX = 1000000;
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

int main(){
     //*Test case 1
     cout<<"Test case 1"<<endl;
     TSM tsm;
     int graph[20][20] = {
          {0, 1, 15, 6},
          {2, 0, 7, 3},
          {9, 6, 0, 12},
          {10, 4, 8, 0}
     };
     string result = tsm.Traveling(graph, 4, 'B');
     cout<<result<<endl;

     //*Test case 2
     cout<<"Test case 2"<<endl;
     TSM tsm1;
     int graph1[20][20] = {
            {0, 3, 13, 9, 7},
            {3, 0, 6, 12, 10},
            {13, 6, 0, 9, 6},
            {9, 12, 9, 0, 8},
            {7, 10, 6, 8, 0}
     };
     string result1 = tsm1.Traveling(graph1, 5, 'C');
     cout<<result1<<endl;


     //*Test case 3
     cout<<"Test case 3"<<endl;
     TSM tsm2;
     int graph2[20][20] = {
          {0, 1, 3},
          {1, 0, 2},
          {3, 2, 0}
     };
     string result2 = tsm2.Traveling(graph2, 3, 'B');
     cout<<result2<<endl;

     //*Test case 4
     cout<<"Test case 4"<<endl;
     TSM tsm3;
     int graph3[20][20] = {
          {0, 1, 2, 3},
          {1, 0, 4, 5},
          {2, 4, 0, 6},
          {3, 5, 6, 0}
     };
     string result3 = tsm3.Traveling(graph3, 4, 'A');
     cout<<result3<<endl;

     //*Test case 5
     cout<<"Test case 5"<<endl;
     TSM tsm4;
     int graph4[20][20] = {
          {0, 1, 2, 3, 4},
          {1, 0, 5, 6, 7},
          {2, 5, 0, 8, 9},
          {3, 6, 8, 0, 10},
          {4, 7, 9, 10, 0}
     };
     string result4 = tsm4.Traveling(graph4, 5, 'D');
     cout<<result4<<endl;

     //*Test case 6
     cout<<"Test case 6"<<endl;
     TSM tsm5;
     int graph5[20][20] = {
          {0, 1, 2, 3, 4, 5},
          {1, 0, 6, 7, 8, 9},
          {2, 6, 0, 10, 11, 12},
          {3, 7, 10, 0, 13, 14},
          {4, 8, 11, 13, 0, 15},
          {5, 9, 12, 14, 15, 0}
     };
     string result5 = tsm5.Traveling(graph5, 6, 'A');
     cout<<result5<<endl;
};