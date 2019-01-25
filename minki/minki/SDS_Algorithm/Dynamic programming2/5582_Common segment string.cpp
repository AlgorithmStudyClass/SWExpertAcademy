/*
	5582 공통 부분 문자열
	https://www.acmicpc.net/problem/5582
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N 4001

int N, len1, len2;
int dp[MAX_N][MAX_N];
string str1, str2;

int max(int a, int b) {
	return (a < b) ? b : a;
}

int lcs() {
	int ans = 0;

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	return ans;
}

int main()
{
	cin >> str1;
	cin >> str2;

	len1 = str1.length();
	len2 = str2.length();

	printf("%d\n", lcs());

	return 0;
}