#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cassert>

using namespace std;

class TSM;
class TestStudy;

class TSM {
     friend class TestStudy;

public:
     void tsm(int graph[20][20], int num, char Start, int *Value, int *Previous);
     string Travelling(int graph[20][20], int num, char Start);
};