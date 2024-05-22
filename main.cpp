#include <bellman.h>
#include <tsm.h>

void tc_01(){
    // Test case 01
    int graph[20][20] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int vertices = 4;
    char Start = 'A';
    int Value[20];
    int Previous[20];
    for(int i = 0; i < vertices; i++){
        Value[i] = __INT_MAX__;
        Previous[i] = -1;
    }
    Value[Start - 'A'] = 0;
    BellmanFord bf;
    bf.BF(graph, vertices, Start, Value, Previous);
    std::string path = bf.BF_Path(graph, vertices, Start, 'D');
    std::cout << path << std::endl;
    assert(path == "ABCD");
};
void tc_02(){
    // write other test case
    
};
void tc_03(){
    // write another test case
};

class TestStudy{
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
    //TestStudy::tc_01();
    //TestStudy::tc_02();
    //TestStudy::tc_03();
    return 0;
}