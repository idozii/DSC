#include "tsm.h"

class TSP;
class TestStudy;

string TSP::Traveling(int given_Graph[20][20], int total_City, char init_City){
     //*Explain: this function returns the shortest possible route to solve TSP problem
     //! INITIALIZATION
     int Ticket[1 << total_City][total_City];
     int previousCity[1 << total_City][total_City];
     for(int i = 0; i < (1 << total_City); i++){
          for(int j = 0; j < total_City; j++){
               Ticket[i][j] = MAX;
               previousCity[i][j] = -1;
          }
     }
     Ticket[1 << (init_City - 'A')][init_City - 'A'] = 0;

     //! ITERATION CALCULATION
     for(int i = 0; i < (1 << total_City); i++){
          for(int j = 0; j < total_City; j++){
               if(i & (1 << j)){
                    for(int k = 0; k < total_City; k++){
                         if(i & (1 << k)){
                              if(Ticket[i ^ (1 << j)][k] + given_Graph[k][j] < Ticket[i][j]){
                                   Ticket[i][j] = Ticket[i ^ (1 << j)][k] + given_Graph[k][j]; 
                                   previousCity[i][j] = k; 
                              }
                         }
                    }
               }
          }
     }

     //! FINDING THE SHORTEST ROUTE
     int min_Ticket = MAX;
     int min_Position = -1;
     for(int i = 0; i < total_City; i++){
          if(i != init_City - 'A' && Ticket[(1 << total_City) - 1][i] + given_Graph[i][init_City - 'A'] < min_Ticket){
               min_Ticket = Ticket[(1 << total_City) - 1][i] + given_Graph[i][init_City - 'A'];
               min_Position = i;
          }
     }

     //! PRINTING RESULT
     string result = "";
     int temp = (1 << total_City) - 1; 
     int temp_Position = min_Position; 
     while(temp_Position != -1){
          if(result != ""){
               result = " " + result;
          }
          result = char(temp_Position + 'A') + result;
          int temp2 = temp_Position;
          temp_Position = previousCity[temp][temp_Position];
          temp ^= (1 << temp2);
     }
     result = result + " " + init_City;
     return result;
};