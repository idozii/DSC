#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cassert>
#include<vector>

using namespace std;

class TSM;
class TestStudy;

class TSM {
     friend class TestStudy;

public:
     const static int MAX = 999;
     string Traveling(int graph[20][20], int num, char Start);
};