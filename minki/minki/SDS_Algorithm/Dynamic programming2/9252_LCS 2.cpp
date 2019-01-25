/*
	9252 LCS 2
	https://www.acmicpc.net/problem/9252
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_N 1001

int N, len1, len2;
int dp[MAX_N][MAX_N];
string str1, str2, ans_str;
char c[1001];

int max(int a, int b) {
	return (a < b) ? b : a;
}

int lcs() {
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[len1][len2];
}

void print_lcs() {
	ans_str = "";
	int i = len1, j = len2;
	while (i > 0 && j > 0) {
		if (str1[i - 1] == str2[j - 1]) {
			ans_str += str1[i - 1];
			i--;
			j--;
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1])
				i--;
			else
				j--;
		}
	}
	for (int k = ans_str.size() - 1; k >= 0; k--)
		printf("%c", ans_str[k]);
	puts("");
}

int main()
{
	cin >> str1;
	cin >> str2;

	len1 = str1.length();
	len2 = str2.length();

	printf("%d\n", lcs());
	print_lcs();

	return 0;
}