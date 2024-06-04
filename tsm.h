#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cassert>
#include<fstream>
#include<vector>

using namespace std;

class TSM;
class TestStudy;

class TSM {
     friend class TestStudy;

protected:
     const static int MAX = 1000000;
     
public:
     string Traveling(int graph[20][20], int num, char Start);
};