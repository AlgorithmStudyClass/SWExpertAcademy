/*
	11062 카드게임
	https://www.acmicpc.net/problem/11062
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 1001
int dp[MAX_N][MAX_N];
int arr[MAX_N], N;

int max(int a, int b) {
	return (a < b) ? b : a;
}
int min(int a, int b) {
	return (a < b) ? a : b;
}

int solve(int left, int right) {// solve(i,j)는 i~j까지의 카드만 남았을 때, "지금 상황에서" 내가 먹을 수 있는 최대의 점수
	int &ret = dp[left][right];
	if (ret != 0)
		return ret;
	
	int order = N + right - left;

	if (left == right) {
		if (order & 1) // 근우 
			return ret = arr[left];
		else //명우
			return ret = 0;
	}

	if (order & 1) // 근우
		ret = max(solve(left+1,right) + arr[left], solve(left, right - 1) + arr[right]);
	else //명우
		ret = min(solve(left + 1, right), solve(left, right - 1));

	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		for (int i = 0; i < N; i++) {
			memset(dp[i], 0, sizeof(int) * N);
		}

		printf("%d\n", solve(0, N - 1));
	}

	return 0;
}