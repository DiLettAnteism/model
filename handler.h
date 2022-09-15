#ifndef HANDLER_H
#define HANDLER_H

#include "fraction.h"
#include <vector>
using std::vector;

void print(const vector<vector<fraction>> &table, int row, int col, const vector<int> &XB, char var0, char var1);
fraction handler1(vector<vector<fraction>> &table, int m, int n, vector<int> &XB, char var0, char var1);
fraction handler2(vector<vector<fraction>> &table, int m, int n, vector<int> &XB, char var0, char var1);

#endif