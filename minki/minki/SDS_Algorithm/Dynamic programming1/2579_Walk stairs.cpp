/*
	2579 계단 오르기
	https://www.acmicpc.net/problem/2579
*/

#include <iostream>
#include <vector>

using namespace std;

int N, arr[301];
int dp[3][301];//row 연속으로 밟은 갯수 - 1 col 현 위치

int max(int a, int b) {
	return (a < b) ? b : a;
}

int main()
{	
	bool flag = true;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	// d[0][j] = max(d[0][j-2],d[1][j-2]) + arr[j]
	// d[1][j] = d[0][j-1] + arr[j]

	dp[1][1] = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[1][i] = max(dp[1][i-2],dp[2][i-2]) + arr[i];
		dp[2][i] = dp[1][i-1] + arr[i];
	}

	printf("%d\n", max(dp[0][N], dp[1][N]));

	return 0;
}