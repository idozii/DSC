#include "bellman.h"

class BellmanFord;
class TestStudy;

const static int MAX = 999;

void BellmanFord::BF(int graph[20][20], int num, char Start, int *Value, int *Previous){
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
                    if(graph[i][j] != 0 && Value[i] != MAX && Value[i] + graph[i][j] < Value[j]){
                         Value[j] = Value[i] + graph[i][j];
                         Previous[j] = i;
                    }
               }
          }
     }

     //TODO: Check circuit of negative weight
     for(int i = 0; i < num; i++){
          for(int j = 0; j < num; j++){
               if(graph[i][j] != 0 && Value[i] != MAX && Value[i] + graph[i][j] < Value[j]){
                    cout << "Contains circuit of negative weight" << endl;
                    return;
               }
          }
     }
};

string BellmanFord::BF_Path(int graph[20][20], int num, char Start, char Goal){
     //TODO: Initialize the value and previous arrays
     int Value[20];
     int Previous[20];
     for(int i = 0; i < num; i++){
          Value[i] = MAX;
          Previous[i] = -1;
     }
     Value[Start - 'A'] = 0;

     //TODO: Call the Bellman Ford algorithm
     BF(graph, num, Start, Value, Previous);

     //TODO: Get the path
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
     //* Test case 1
     cout<<"Test case 1"<<endl;
     int graph[20][20] = {
         {0, 10, 15, 20},
         {10, 0, 35, 25},
         {15, 35, 0, 30},
         {20, 25, 30, 0}
     };
     BellmanFord bf;
     cout << bf.BF_Path(graph, 4, 'A', 'D') << endl;

     //* Test case 2
     cout<<"Test case 2"<<endl;
     int graph1[20][20] = {
        {0, 3, 13, 9, 7},
        {3, 0, 6, 12, 10},
        {13, 6, 0, 9, 6},
        {9, 12, 9, 0, 8},
        {7, 10, 6, 8, 0}
     };
     BellmanFord bf1;
     cout << bf1.BF_Path(graph1, 5, 'A', 'C') << endl;

     //* Test case 3
     cout<<"Test case 3"<<endl;
     int graph2[20][20] = {
          {0, 1, 2},
          {1, 0, 3},
          {2, 3, 0}
     };
     BellmanFord bf2;
     cout << bf2.BF_Path(graph2, 3, 'A', 'C') << endl;
     return 0;
}