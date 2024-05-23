#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cassert>

using namespace std;

class BellmanFord;
class TestStudy;

class BellmanFord { 
     friend class TestStudy;

public:
     void BF(int graph[20][20], int vertices, char Start, int Value[20], int Previous[20]);
     string BF_Path(int graph[20][20], int vertices, char Start, char Goal);
};