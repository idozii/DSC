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
     void tsm(int graph[20][20], int vertices, char Start, int Value[20], int Previous[20]);
     std::string Travelling(int graph[20][20], int num, char Start);
};