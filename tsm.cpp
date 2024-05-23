#include "tsm.h"

class TSM;
class TestStudy;

void TSM::tsm(int graph[20][20], int vertices, char Start, int Value[20], int Previous[20]){
     for(int i = 0; i < vertices; i++){
          if(graph[Start][i] != 0){
               if(Value[i] > Value[Start] + graph[Start][i]){
                    Value[i] = Value[Start] + graph[Start][i];
                    Previous[i] = Start;
               }
          }
     }
};

std::string TSM::Travelling(int graph[20][20], int num, char Start) {

};
     