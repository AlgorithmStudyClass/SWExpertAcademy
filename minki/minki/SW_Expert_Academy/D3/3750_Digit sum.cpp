/*
	3750. Digit sum - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPiSYKAD0DFAUn&categoryId=AWHPiSYKAD0DFAUn&categoryType=CODE
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

string str;

int func() {
	while (str.length() > 1) {
		int temp = 0;
		for (int i = 0; i < str.length(); i++)
			temp += str[i] - '0';
		str = to_string(temp);
	}

	return str[0] - '0';
}

int main() {
	int line = 1, t;
	char ch[20];
	scanf("%d", &t);
	while (0 < t--) {
		scanf("%s", ch);
		str = ch;
		printf("#%d %d\n", line++, func());
	}

	return 0;
}