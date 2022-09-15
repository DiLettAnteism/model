#include "handler.h"
#include <iostream>
using std::cout;

void print(const vector<vector<fraction>> &table, int row, int col, const vector<int> &XB, char var0, char var1) {
	cout << "\t\t\t";
	for (int i = 1; i <= col; ++i) {
		cout << table[0][i] << "\t";
	}
	cout << "\n";
	cout << "\t\tb\t";
	for (int i = 1; i <= col; ++i) {
		cout << var1 << i << "\t";
	}
	cout << "\n";
	for (int i = 1; i <= row; ++i) {
		cout << table[0][XB[i]] << "\t";
		cout << var1 << XB[i] << "\t";
		for (int j = 0; j <= col; ++j) {
			cout << table[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

fraction handler1(vector<vector<fraction>> &table, int m, int n, vector<int> &XB, char var0, char var1) {
	fraction min_col_ele(0);
	int min_col = 1;
	for (int i = 1; i <= n + m; ++i) { // 列
		fraction temp(table[0][i]);
		for (int j = 1; j <= m; ++j) { // 行
			temp = temp - table[0][XB[j]] * table[j][i];
		}
		if (temp < min_col_ele) {
			min_col_ele = temp;
			min_col = i;
		}
	}
	if (min_col_ele == fraction(0)) {
		fraction ret(0);
		for (int i = 1; i <= m; ++i) {
			ret = ret + table[i][0] * table[0][XB[i]];
		}
		return ret;
	}
	fraction min_row_ele(100000);
	int min_row = 1;
	for (int i = 1; i <= m; ++i) {
		if (table[i][min_col] <= fraction(0)) continue;
		fraction temp = table[i][0] / table[i][min_col];
		if (temp < min_row_ele) {
			min_row_ele = temp;
			min_row = i;
		}
	}
	if (table[min_row][min_col] != fraction(1)) {
		fraction temp = table[min_row][min_col];
		for (int i = 0; i <= n + m; ++i) {
			table[min_row][i] = table[min_row][i] / temp;
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (i == min_row) continue;
		if (table[i][min_col] == fraction(0)) continue;
		fraction temp = table[i][min_col];
		for (int j = 0; j <= n + m; ++j) {
			table[i][j] = table[i][j] - temp * table[min_row][j];
		}
	}
	XB[min_row] = min_col;
	print(table, m, n + m, XB, var0, var1);
	return handler1(table, m, n, XB, var0, var1);
}

fraction handler2(vector<vector<fraction>> &table, int m, int n, vector<int> &XB, char var0, char var1) {
	fraction max_col_ele(0);
	int max_col = 1;
	for (int i = 1; i <= n; ++i) { // 列
		fraction temp(table[0][i]);
		for (int j = 1; j <= m; ++j) { // 行
			temp = temp - table[0][XB[j]] * table[j][i];
		}
		if (temp > max_col_ele) {
			max_col_ele = temp;
			max_col = i;
		}
	}
	if (max_col_ele == fraction(0)) {
		fraction ret(0);
		for (int i = 1; i <= m; ++i) {
			ret = ret + table[i][0] * table[0][XB[i]];
		}
		return ret;
	}
	fraction min_row_ele(100000);
	int min_row = 1;
	for (int i = 1; i <= m; ++i) {
		if (table[i][max_col] <= fraction(0)) continue;
		fraction temp = table[i][0] / table[i][max_col];
		if (temp < min_row_ele) {
			min_row_ele = temp;
			min_row = i;
		}
	}
	if (table[min_row][max_col] != fraction(1)) {
		fraction temp = table[min_row][max_col];
		for (int i = 0; i <= n; ++i) {
			table[min_row][i] = table[min_row][i] / temp;
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (i == min_row) continue;
		if (table[i][max_col] == fraction(0)) continue;
		fraction temp = table[i][max_col];
		for (int j = 0; j <= n; ++j) {
			table[i][j] = table[i][j] - temp * table[min_row][j];
		}
	}
	XB[min_row] = max_col;
	print(table, m, n, XB, var0, var1);
	return handler2(table, m, n, XB, var0, var1);
}