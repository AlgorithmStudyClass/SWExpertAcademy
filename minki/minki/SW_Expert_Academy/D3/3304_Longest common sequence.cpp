/*
	3304. 최장 공통 부분 수열 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWBOHEx66kIDFAWr&categoryId=AWBOHEx66kIDFAWr&categoryType=CODE
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

string x, y;
int dp[1001][1001];

int func() {
	// if xi = yj  -> dp[i-1][j-1] + 1
	// if xi != yj -> max(dp[i-1][j],dp[i][j-1])
	int xlen = x.length(), ylen = y.length();

	for (int i = 1; i <= xlen; i++) {
		for (int j = 1; j <= ylen; j++) {
			if (x[i - 1] == y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[xlen][ylen];
}

int main() {
	int t, line = 1;
	scanf("%d", &t);
	while (t > 0) {
		//입력
		cin >> x >> y;

		//출력
		printf("#%d %d\n", line++, func());
		t--;
	}
	return 0;
}