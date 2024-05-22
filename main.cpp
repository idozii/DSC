#include <bellman.h>
#include <tsm.h>

void tc_01(){
    // Test case 01
    std::vector<std::vector<int>> graph = {{0, 1, 0, 0, 0, 0, 0, 0, 0},
                                           {1, 0, 1, 0, 0, 0, 0, 0, 0},
                                           {0, 1, 0, 1, 0, 0, 0, 0, 0},
                                           {0, 0, 1, 0, 1, 0, 0, 0, 0},
                                           {0, 0, 0, 1, 0, 1, 0, 0, 0},
                                           {0, 0, 0, 0, 1, 0, 1, 0, 0},
                                           {0, 0, 0, 0, 0, 1, 0, 1, 0},
                                           {0, 0, 0, 0, 0, 0, 1, 0, 1},
                                           {0, 0, 0, 0, 0, 0, 0, 1, 0}};
    BellmanFord bf;
    TSM tsm;
    std::cout << bf.BF_Path(graph, 9, 'A', 'I') << std::endl;
    std::cout << tsm.Travelling(graph, 9, 'A') << std::endl;
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