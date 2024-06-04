#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cassert>
#include<fstream>

using namespace std;

class BellmanFord;
class TestStudy;

class BellmanFord { 
     friend class TestStudy;

protected:
     const static int MAX = 1000000;
     
public:
     void BF(int graph[20][20], int num, char Start, int *Value, int *Previous);
     void BFF(int graph[20][20], int num, char Start, int *Value, int *Previous);
     string BF_Path(int graph[20][20], int num, char Start, char Goal);
};