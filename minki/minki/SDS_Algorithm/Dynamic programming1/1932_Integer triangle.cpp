/*
	1932 정수 삼각형
	https://www.acmicpc.net/problem/1932
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[501][501], dp[501];

int max(int a, int b) {
	return (a < b) ? b : a;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
			scanf("%d", &arr[i][j]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j >= 0; j--) {
			dp[j] = max(dp[j-1],dp[j]) + arr[i][j];
		}
	}


	int ans = -1;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);

	return 0;
}