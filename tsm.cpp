#include "tsm.h"

class TSM;
class TestStudy;

static int MAX = 999;

//TODO: Greedy algorithm
string TSM::Traveling(int graph[20][20], int num, char Start){
     if (Start < 'A' || Start >= 'A' + num) {
        return "Invalid start city";
     }
     vector<bool> visited(num, false);
     int start = Start - 'A';
     visited[start] = true;

     string path = "";
     path += Start;
     path += " ";

     for (int count = 0; count < num - 1; count++) {
          int nearestCity = -1;
          int min = MAX;
          for (int i = 0; i < num; i++) {
               if (!visited[i] && graph[start][i] && (nearestCity == -1 || graph[start][i] < min)) {
                    min = graph[start][i];
                    nearestCity = i;
               }
          }
          if (nearestCity == -1) {
               return "No path found";
          }
          visited[nearestCity] = true;
          start = nearestCity;
          path += char(nearestCity + 'A');
          path += " ";
     }
     return path;
};

int pathlength(int graph[20][20], int num, string path){
    int length = 0;
    for(int i = 0; i < num - 1; i++){
        length += graph[path[i] - 'A'][path[i + 1] - 'A'];
    }
    length += graph[path[num - 1] - 'A'][path[0] - 'A'];
    return length;
};

int main(){
     //TODO: Test case 01: A B D C
     TSM tsm;
     int graph[20][20] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
     };
     string result = tsm.Traveling(graph, 4, 'A');
     cout<<result<<endl;

     //TODO: Test case 02: C B E D A
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


     //TODO: Test case 03: B A C
     TSM tsm2;
     int graph2[20][20] = {
          {0, 1, 2},
          {1, 0, 3},
          {2, 3, 0}
     };
     string result2 = tsm2.Traveling(graph2, 3, 'B');
     cout<<result2<<endl;
     return 0;
};