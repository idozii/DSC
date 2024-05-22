#include<unordered_set>
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cassert>

class TSM;
class TestStudy;

class TSM {

public:
     void tsm(std::vector<std::vector<int>>& graph, int vertices, char Start, std::vector<std::vector<int>>& Value, std::vector<std::vector<int>>& Previous);
     std::string Travelling(std::vector<std::vector<int>>& graph, int num, char Start);
};