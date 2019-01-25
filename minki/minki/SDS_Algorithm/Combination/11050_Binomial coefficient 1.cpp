/*
	11050 이항계수1
	https://www.acmicpc.net/problem/11050
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 11

int n, k;
long long ans;
int dp[MAX_N][MAX_N];

int main(void) {
	scanf("%d %d", &n, &k);
	//dp[n][k] = dp[n-1][k-1] + dp[n-1][k];
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	printf("%d\n", dp[n][k]);

	return 0;
}