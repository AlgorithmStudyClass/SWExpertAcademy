/*
	5626 제단
	https://www.acmicpc.net/problem/5626
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define rem 1000000007
typedef long long int lld;

int N, K;
lld dp[2][5005]; //row 그 전 배열 확인하려고 만든 것 그래서 2개 col 재단의 수 / 2
int arr[10001];

//무조건 양옆에 수가 있어야 가운데가 상승 가능
int main()
{
	int ans;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	
	if (arr[1] == -1 || arr[1] == 0)
		dp[0][0] = 1;

	for (int i = 2; i <= N; i++) {
		if (arr[i] == -1) {
			dp[1][0] = (dp[0][0] + dp[0][1]) % rem;
			for (int j = 1; j <= N / 2; j++)
				dp[1][j] = (dp[0][j - 1] + dp[0][j] + dp[0][j + 1]) % rem;
		}
		else if (arr[i] == 0) dp[1][0] = (dp[0][0] + dp[0][1]) % rem;
		else dp[1][arr[i]] = (dp[0][arr[i] - 1] + dp[0][arr[i]] + dp[0][arr[i] + 1]) % rem;

		for (int j = 0; j <= N / 2; j++) {
			dp[0][j] = dp[1][j];
			dp[1][j] = 0;
		}
	}

	printf("%d\n", dp[0][0]);

	return 0;
}