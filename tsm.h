#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<fstream>

using namespace std;

class TSP;
class TestStudy;

class TSP {
     friend class TestStudy;

protected:
     const static int MAX = 1000000;
     
public:
     string Traveling(int given_Graph[20][20], int total_City, char init_City);
};