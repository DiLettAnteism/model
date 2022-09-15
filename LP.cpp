#include <iostream>
#include <vector>
#include <string>
#include "fraction.h"
#include "handler.h"
#include "input.h"
using namespace std;

int main() {
	bool dir;
	char var0, var1;
	vector<fraction> C(1000, fraction(0));
	read_C(dir, var0, var1, C);

	int m = 0, n = 0;
	vector<vector<fraction>> A(1000, vector<fraction>(1000, 0));
	vector<fraction> b(1000, fraction(0));
	read_A(m, n, A, b);

	// 生成单纯形表
	vector<vector<fraction>> table(m + 1, vector<fraction>(n + m + 1, fraction(0)));
	for (int i = n + 1; i <= n + m; ++i) {
		table[0][i] = fraction(1);
	}
	for (int i = 1; i <= m; ++i) {
		table[i][0] = b[i];
		for (int j = 1; j <= n; ++j) {
			table[i][j] = A[j][i];
		}
		table[i][n + i] = fraction(1);
	}
	// 基变量
	vector<int> XB(m + 1);
	for (int i = 1; i <= m; ++i) {
		XB[i] = n + i;
	}

	cout << "进入第一阶段" << "\n";
	// 打印第一阶段初始的单纯形表
	print(table, m, n + m, XB, var0, var1);

	fraction res = handler1(table, m, n, XB, var0, var1);
	if (res == fraction(0)) {
		cout << "进入第二阶段" << "\n";
		for (int i = 1; i <= n; ++i) {
			table[0][i] = C[i];
		}
		// 打印第二阶段初始的单纯形表
		print(table, m, n, XB, var0, var1);
		res = handler2(table, m, n, XB, var0, var1);
		cout << var0 << "=" << res << "\n";
		return 0;
	} else {
		cout << "无可行解" << "\n";
		return 0;
	}

	cout << "error" << endl;
	return 0;	
}