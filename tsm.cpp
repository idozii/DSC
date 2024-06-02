#include "tsm.h"

class TSM;
class TestStudy;

string TSM::Traveling(int graph[20][20], int num, char Start){
     const static int MAX = 999;
     int dp[1 << num][num]; //* dp[i][j] means the minimum cost to visit all cities in i and end at city j
     int path[1 << num][num]; //* path[i][j] means the previous city of city j in the path of i
     for(int i = 0; i < (1 << num); i++){
          for(int j = 0; j < num; j++){
               dp[i][j] = MAX; //* set up the init cost to MAX
               path[i][j] = -1; //* set up the init path to -1
          }
     }
     dp[1 << (Start - 'A')][Start - 'A'] = 0; //* set up the init cost to 0
     for(int i = 0; i < (1 << num); i++){
          for(int j = 0; j < num; j++){
               if(i & (1 << j)){ //* if city j is in the path of i
                    for(int k = 0; k < num; k++){
                         if(i & (1 << k)){ //* if city k is in the path of i
                              if(dp[i ^ (1 << j)][k] + graph[k][j] < dp[i][j]){ //* if the cost to visit city k and then city j is less than the cost to visit city j
                                   dp[i][j] = dp[i ^ (1 << j)][k] + graph[k][j]; //* update the cost
                                   path[i][j] = k; //* update the path
                              }
                         }
                    }
               }
          }
     }
     int min = MAX; //* find the minimum cost to visit all cities
     int min_index = -1; //* find the city to start
     for(int i = 0; i < num; i++){
          if(i != Start - 'A'){
               if(dp[(1 << num) - 1][i] + graph[i][Start - 'A'] < min){ //* if the cost to visit all cities and back to the start city is less than min
                    min = dp[(1 << num) - 1][i] + graph[i][Start - 'A']; //* update the min cost
                    min_index = i; //* update the city to start
               }
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
          temp_index = path[temp][temp_index]; //* find the previous city of city temp_index in the path of temp
          temp ^= (1 << temp2); //* remove the city from the path
     }
     return result + " " + to_string(min);  
};

int main(){
     //*Test case 1
     cout<<"Test case 1"<<endl;
     TSM tsm;
     int graph[20][20] = {
          {0, 10, 15, 20, 30},
          {10, 5, 30, 25, 15},
          {15, 35, 15, 25, 20},
          {20, 25, 30, 20, 5},
          {30, 15, 20, 10, 0}
     };
     string result = tsm.Traveling(graph, 5, 'B');
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