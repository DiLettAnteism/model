#ifndef INPUT_H
#define INPUT_H

#include "fraction.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

extern ifstream file_in;

int to_int(const string &s, int &idx, int r);
fraction to_fraction(const string &s, int &idx, int r);
void read_C(bool &dir, char &var0, char &var1, vector<fraction> &C);
void read_A(int &m, int &n, vector<vector<fraction>> &A, vector<fraction> &b);

#endif