/*
	7579 앱
	https://www.acmicpc.net/problem/7579
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_M 10001

int N, M;
int C[101], W[101], sum;
int dp[101][MAX_M], dp2[MAX_M];//C의 비용으로 확보할 수 있는 최대 비용

int max(int a, int b) {
	return (a < b) ? b : a;
}
int min(int a, int b) {
	return (a < b) ? a : b;
}

int knapsack1() {
	int i, w, ans = 10001;

	// max( D[i-1][c-cost[i] + me[i] , D[i-1][C])
	// D[i-1][C]

	for (i = 0; i <= N; i++)
	{
		for (w = 0; w <= sum; w++)
		{
			if (i == 0 || w == 0)
				dp[i][w] = 0;
			else if (C[i - 1] <= w)
				dp[i][w] = max(dp[i - 1][w - C[i - 1]] + W[i - 1], dp[i - 1][w]);
			else if (C[i - 1] > w)
				dp[i][w] = dp[i - 1][w];

			if (dp[i][w] >= M)
				ans = min(ans, w);
		}
	}

	return ans;
}

int knapsack2() {
	int w, ans;

	for (int i = 0; i <= N; i++){
		for (int j = sum; j >= C[i]; j--) {
			dp2[j] = max(dp2[j], dp2[j - C[i]] + W[i]);
		}
	}

	for (ans = 0; ans < sum && dp2[ans] < M; ans++);

	return ans;
}
int main()
{
	int temp;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) 
		scanf("%d", &W[i]);

	sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &C[i]);
		sum += C[i];
	}

	//printf("%d\n", knapsack1());
	printf("%d\n", knapsack2());

	return 0;
}