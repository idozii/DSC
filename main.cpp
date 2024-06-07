#include "bellman.h"
#include "tsm.h"

using namespace std;

class TestStudy{
    public:
        TestStudy() = default;

        static void tc_01(){
            int Graph[20][20] = {
                {0, 10, 15, 20},
                {10, 0, 35, 25},
                {15, 35, 0, 30},
                {20, 25, 30, 0}
            };
            BellmanFord bf;
            int Value[20];
            int Previous[20];
            bf.BF(Graph, 4, 'A', Value, Previous);
        }

        static void tc_02(){
            int Graph[20][20] = {
                {0, 10, 15, 20},
                {10, 0, 35, 25},
                {15, 35, 0, 30},
                {20, 25, 30, 0}
            };
            BellmanFord bf;
            int Value[20];
            int Previous[20];
            bf.BF_Path(Graph, 4, 'A', 'D');
        }

        static void tc_03(){
            int Graph[20][20] = {
                {0, 10, 15, 20},
                {10, 0, 35, 25},
                {15, 35, 0, 30},
                {20, 25, 30, 0}
            };
            TSP tsp;
            tsp.Traveling(Graph, 4, 'A');
        }
};

int main(int argc, const char* argv[]){
    //TestStudy::tc_01();
    //TestStudy::tc_02();
    TestStudy::tc_03();
    return 0;
}