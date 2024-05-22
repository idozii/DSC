#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>

class BellF { 

public:
     void BF(std::vector<std::vector<int>>& graph, int vertices, char Start, std::vector<std::vector<int>>& Value, std::vector<std::vector<int>>& Previous);
     string BF_Path(std::vector<std::vector<int>>& graph, int vertices, char Start, char Goal);
};