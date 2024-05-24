#include <bellman.h>
#include <tsm.h>

void tc_01(){
    // Test case 01
    BellmanFord bf;
    int graph[20][20] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    string result = bf.BF_Path(graph, 4, 'A', 'C');
    cout<<result<<endl;
};
void tc_02(){
    // write test case for travelling function
    TSM tsm;
    int graph[20][20] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    string result = tsm.Traveling(graph, 4, 'A');
    cout<<result<<endl;
};
void tc_03(){
    // write another test case
    BellmanFord bf;
    TSM tsm;
    int graph1[20][20] = {
        {0, 3, 13, 9, 7},
        {3, 0, 6, 12, 10},
        {13, 6, 0, 9, 6},
        {9, 12, 9, 0, 8},
        {7, 10, 6, 8, 0}
    };
    string result = bf.BF_Path(graph1, 5, 'A', 'C');
    cout<<result<<endl;
    string result1 = tsm.Traveling(graph1, 5, 'C');
    cout<<result1<<endl;
};

class TestStudy {
public:

    TestStudy() = default;

    static void tc_01(){
        tc_01();
    }
    static void tc_02(){
        tc_02();
    }
    static void tc_03(){
        tc_03();
    }
};

int main(int argc, char const *argv[]) {
    TestStudy::tc_01();
    //TestStudy::tc_02();
    //TestStudy::tc_03();
    return 0;
}