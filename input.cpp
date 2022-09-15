#include "input.h"

ifstream file_in("test.txt", ios::in);

int to_int(const string &s, int &idx, int r) { // [idx, r]
	int ret = 0;
	int sign = 1;
	int flag = 0; // flag == 0 :无符号
				  // flag == -1:前面为负号
				  // flag == 1 :前面为正号
	if (s[idx] == '-') {
		flag = -1;
		sign = -1;
		++idx;
	} else if (s[idx] == '+') {
		flag = 1;
		++idx;
	}
	while (idx <= r && s[idx] >= '0' && s[idx] <= '9') {
		ret = ret * 10 + s[idx] - '0';
		++idx;
	}
	if (flag == 0) {
		return ret;
	} else {
		if (ret == 0) ret = 1;
		return sign * ret;
	}
}

fraction to_fraction(const string &s, int &idx, int r) { // [idx, r]
	int numerator = to_int(s, idx, r);
	int denominator;
	if (idx > r || s[idx] != '/') {
		denominator = 1;
	} else {
		++idx;
		denominator = to_int(s, idx, r);
	}
	return fraction(numerator, denominator);
}

void read_C(bool &dir, char &var0, char &var1, vector<fraction> &C) {
	string s;

	// 判断是max还是min，若是max，则dir == true，否则dir == false
	file_in >> s;
	dir = (s == "max");

	// var0
	file_in >> s;
	var0 = s[0];

	// var1
	for (char c : s) {
		if (c != var0 && c >= 'a' && c <= 'z') {
			var1 = c;
			break;
		}
	}

	// C
	int r = s.size() - 1;
	int i = 2;
	while (i <= r) {
		fraction fra = to_fraction(s, i, r);
		if (fra == 0) {
			fra = fraction(1);
		}
		++i;
		int index = to_int(s, i, r);
		C[index] = fra;
	}
}

void read_A(int &m, int &n, vector<vector<fraction>> &A, vector<fraction> &b) {
	string s;
	while (file_in >> s) {
		++m;
		int i = 0;
		int r = s.size() - 1;
		while (i <= r) {
			fraction fra = to_fraction(s, i, r);
			if (fra == 0) fra = fraction(1);
			++i;
			int index = to_int(s, i, r);
			n = max(n, index);
			A[index][m] = fra;

			if (s[i] == '=') break;
		}
		++i;

		b[m] = to_fraction(s, i, r);
	}
}