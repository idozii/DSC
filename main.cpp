#include "bellman.h"
#include "tsm.h"

using namespace std;

class TestStudy{
    public:
        TestStudy() = default;

        static void tc_01(){
            int Graph[20][20] = {
                {0, 34, 58, 99, 61, 21, 57, 63, 9, 65, 28, 75, 8, 79, 61, 64},
                {68, 0, 79, 11, 60, 42, 96, 26, 92, 98, 50, 1, 61, 62, 96, 83},
                {64, 97, 0, 6, 62, 57, 27, 85, 86, 37, 49, 14, 78, 23, 93, 4},
                {88, 27, 83, 0, 65, 53, 92, 61, 80, 49, 24, 29, 50, 85, 58, 12},
                {33, 88, 8, 39, 0, 16, 31, 67, 0, 16, 3, 16, 97, 47, 39, 56},
                {18, 93, 83, 67, 24, 0, 35, 58, 51, 81, 7, 75, 10, 57, 25, 68},
                {35, 24, 55, 9, 63, 71, 0, 40, 29, 38, 23, 99, 54, 86, 12, 59},
                {41, 30, 52, 90, 97, 76, 25, 0, 55, 93, 5, 62, 33, 82, 85, 24},
                {15, 20, 48, 37, 29, 10, 74, 36, 0, 6, 11, 25, 71, 31, 77, 83},
                {91, 18, 12, 42, 74, 76, 84, 65, 30, 0, 42, 37, 58, 75, 18, 8},
                {99, 0, 95, 12, 3, 91, 89, 77, 93, 95, 0, 55, 84, 66, 86, 60},
                {14, 42, 44, 27, 84, 18, 69, 33, 83, 65, 75, 0, 19, 22, 15, 4},
                {97, 13, 71, 92, 92, 74, 82, 81, 16, 74, 75, 71, 0, 57, 6, 23},
                {83, 21, 65, 27, 14, 15, 11, 83, 14, 94, 47, 90, 80, 0, 35, 4},
                {50, 31, 85, 20, 22, 76, 94, 70, 56, 9, 9, 98, 47, 66, 0, 70},
                {70, 15, 91, 0, 42, 71, 15, 53, 53, 30, 12, 66, 86, 92, 0, 0}
            };
            BellmanFord bf;
            int Value[20];
            int Previous[20];
            for(int i = 0; i<20; i++){
                for(int j = 0; j<20; j++){
                    bf.BF(Graph, 20, 'A', Value, Previous);
                    cout<<Graph[i][j]<<" ";
                }
            }
        }

        static void tc_02(){
            int Graph[20][20] = {
                {0, 34, 58, 99, 61, 21, 57, 63, 9, 65, 28, 75, 8, 79, 61, 64},
                {68, 0, 79, 11, 60, 42, 96, 26, 92, 98, 50, 1, 61, 62, 96, 83},
                {64, 97, 0, 6, 62, 57, 27, 85, 86, 37, 49, 14, 78, 23, 93, 4},
                {88, 27, 83, 0, 65, 53, 92, 61, 80, 49, 24, 29, 50, 85, 58, 12},
                {33, 88, 8, 39, 0, 16, 31, 67, 0, 16, 3, 16, 97, 47, 39, 56},
                {18, 93, 83, 67, 24, 0, 35, 58, 51, 81, 7, 75, 10, 57, 25, 68},
                {35, 24, 55, 9, 63, 71, 0, 40, 29, 38, 23, 99, 54, 86, 12, 59},
                {41, 30, 52, 90, 97, 76, 25, 0, 55, 93, 5, 62, 33, 82, 85, 24},
                {15, 20, 48, 37, 29, 10, 74, 36, 0, 6, 11, 25, 71, 31, 77, 83},
                {91, 18, 12, 42, 74, 76, 84, 65, 30, 0, 42, 37, 58, 75, 18, 8},
                {99, 0, 95, 12, 3, 91, 89, 77, 93, 95, 0, 55, 84, 66, 86, 60},
                {14, 42, 44, 27, 84, 18, 69, 33, 83, 65, 75, 0, 19, 22, 15, 4},
                {97, 13, 71, 92, 92, 74, 82, 81, 16, 74, 75, 71, 0, 57, 6, 23},
                {83, 21, 65, 27, 14, 15, 11, 83, 14, 94, 47, 90, 80, 0, 35, 4},
                {50, 31, 85, 20, 22, 76, 94, 70, 56, 9, 9, 98, 47, 66, 0, 70},
                {70, 15, 91, 0, 42, 71, 15, 53, 53, 30, 12, 66, 86, 92, 0, 0}
            };
            BellmanFord bf;
            int Value[20];
            int Previous[20];
            cout<<bf.BF_Path(Graph, 20, 'A', 'B')<<endl;
        }

        static void tc_03(){
            int Graph[20][20] = {
                {0, 34, 58, 99, 61, 21, 57, 63, 9, 65, 28, 75, 8, 79, 61, 64},
                {68, 0, 79, 11, 60, 42, 96, 26, 92, 98, 50, 1, 61, 62, 96, 83},
                {64, 97, 0, 6, 62, 57, 27, 85, 86, 37, 49, 14, 78, 23, 93, 4},
                {88, 27, 83, 0, 65, 53, 92, 61, 80, 49, 24, 29, 50, 85, 58, 12},
                {33, 88, 8, 39, 0, 16, 31, 67, 0, 16, 3, 16, 97, 47, 39, 56},
                {18, 93, 83, 67, 24, 0, 35, 58, 51, 81, 7, 75, 10, 57, 25, 68},
                {35, 24, 55, 9, 63, 71, 0, 40, 29, 38, 23, 99, 54, 86, 12, 59},
                {41, 30, 52, 90, 97, 76, 25, 0, 55, 93, 5, 62, 33, 82, 85, 24},
                {15, 20, 48, 37, 29, 10, 74, 36, 0, 6, 11, 25, 71, 31, 77, 83},
                {91, 18, 12, 42, 74, 76, 84, 65, 30, 0, 42, 37, 58, 75, 18, 8},
                {99, 0, 95, 12, 3, 91, 89, 77, 93, 95, 0, 55, 84, 66, 86, 60},
                {14, 42, 44, 27, 84, 18, 69, 33, 83, 65, 75, 0, 19, 22, 15, 4},
                {97, 13, 71, 92, 92, 74, 82, 81, 16, 74, 75, 71, 0, 57, 6, 23},
                {83, 21, 65, 27, 14, 15, 11, 83, 14, 94, 47, 90, 80, 0, 35, 4},
                {50, 31, 85, 20, 22, 76, 94, 70, 56, 9, 9, 98, 47, 66, 0, 70},
                {70, 15, 91, 0, 42, 71, 15, 53, 53, 30, 12, 66, 86, 92, 0, 0}
            };
            TSP tsp;
            cout<<tsp.Traveling(Graph, 20, 'A')<<endl;
        }
};

int main(int argc, const char* argv[]){
    //TestStudy::tc_01();
    //TestStudy::tc_02();
    //TestStudy::tc_03();
    return 0;
}