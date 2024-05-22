#include <bellman.h>
#include <tsm.h>

int main() {
    std::vector<std::vector<int>> graph = {{0, 1, 0, 0, 0, 0, 0, 0, 0},
                                           {1, 0, 1, 0, 0, 0, 0, 0, 0},
                                           {0, 1, 0, 1, 0, 0, 0, 0, 0},
                                           {0, 0, 1, 0, 1, 0, 0, 0, 0},
                                           {0, 0, 0, 1, 0, 1, 0, 0, 0},
                                           {0, 0, 0, 0, 1, 0, 1, 0, 0},
                                           {0, 0, 0, 0, 0, 1, 0, 1, 0},
                                           {0, 0, 0, 0, 0, 0, 1, 0, 1},
                                           {0, 0, 0, 0, 0, 0, 0, 1, 0}};
    BellF bf;
    TSM tsm;
    std::cout << bf.BF_Path(graph, 9, 'A', 'I') << std::endl;
    std::cout << tsm.Travelling(graph, 9, 'A') << std::endl;
    return 0;
}