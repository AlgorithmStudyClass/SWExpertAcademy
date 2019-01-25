/*
	1915 가장 큰 정사각형
	https://www.acmicpc.net/problem/1915
*/

#include <iostream>

using namespace std;

int N, M, arr[1001][1001], dp[1001][1001];

int min(int a, int b, int c) {
	if (a < b)
		return (a < c) ? a : c;
	else
		return (b < c) ? b : c;
}

int main()
{
	scanf("%d %d", &N, &M);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("\n%1d", &arr[i][j]);
			if (arr[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
				ans = ans < dp[i][j] ? dp[i][j] : ans;
			}
			else
				dp[i][j] = 0;
		}
	}

	printf("%d\n", ans*ans);

	return 0;
}