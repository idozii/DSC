#include "tsm.h"

class TSM;
class TestStudy;

//TODO: Greedy algorithm
string TSM::Traveling(int graph[20][20], int num, char Start){
     const static int MAX = 999;
     if (Start < 'A' || Start >= 'A' + num) {
        return "Invalid start city";
     }
     vector<bool> visited(num, false);
     int start = Start - 'A';
     visited[start] = true;

     string path = "";
     path += Start;
     path += " ";

     int totalCost = 0;
     for (int count = 0; count < num - 1; count++) {
          int nearestCity = -1;
          int min = MAX;
          for (int i = 0; i < num; i++) {
               if (!visited[i] && graph[start][i] < min) {
                    min = graph[start][i];
                    nearestCity = i;
               }
          }
          if (nearestCity == -1) {
               return "No path found";
          }
          visited[nearestCity] = true;
          totalCost += min;
          start = nearestCity;
          path += char(nearestCity + 'A');
          path += " ";
     }
     totalCost += graph[start][Start - 'A'];
     path += Start;
     path += " ";
     return path + to_string(totalCost);
};

int main(){
     //*Test case 1
     cout<<"Test case 1"<<endl;
     TSM tsm;
     int graph[20][20] = {
          {0, 10, 15, 20, 30},
          {10, 0, 35, 25, 15},
          {15, 35, 0, 30, 20},
          {20, 25, 30, 0, 10},
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