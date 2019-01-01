/*
	3282. 0/1 Knapsack - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWBJAVpqrzQDFAWr&categoryId=AWBJAVpqrzQDFAWr&categoryType=CODE&&&#
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_N 101
#define MAX_K 1001

int V[MAX_N], C[MAX_N], N, K, dp[MAX_N][MAX_K];

void func() {
	int temp;

	//초기화1
	for (int i = 0; i <= K; i++)
		dp[0][i] = 0;

	for (int i = 1; i <= N; i++) {
		//초기화2
		dp[i][0] = 0;
		for (int ww = 1; ww <= K; ww++) {
			if (ww >= V[i]) {
				if((temp=C[i] + dp[i-1][ww-V[i]]) > dp[i-1][ww])
					dp[i][ww] = temp;
				else
					dp[i][ww] = dp[i - 1][ww];
			}
			else
				dp[i][ww] = dp[i-1][ww];
		}
	}
}

int main() {
	int t, line = 1;
	scanf("%d", &t);
	while (t > 0) {
		//입력
		scanf("%d %d", &N,&K);
		for (int i = 1; i <= N; i++)
			scanf("%d %d", &V[i], &C[i]);

		func();

		//출력
		printf("#%d %d\n", line++, dp[N][K]);
		t--;
	}
	return 0;
}