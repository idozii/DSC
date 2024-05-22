#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cassert>

class BellmanFord;
class TestStudy;

class BellmanFord { 

public:
     void BF(int graph[20][20], int vertices, char Start, int Value[20], int Previous[20]);
     std::string BF_Path(int graph[20][20], int vertices, char Start, char Goal);
};