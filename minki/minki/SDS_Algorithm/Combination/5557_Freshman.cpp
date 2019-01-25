/*
	5557 1학년
	https://www.acmicpc.net/problem/5557
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vec;
long long int dp[101][21];

void func() {
	dp[0][vec[0]] = 1;
	//dp[i][j] = dp[i-1][j-vec[i]] + dp[i-1][j+vec[i]]
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j + vec[i] < 21) dp[i][j + vec[i]] += dp[i - 1][j];
			if (j - vec[i] >= 0) dp[i][j - vec[i]] += dp[i - 1][j];
		}
	}
}

int main()
{
	scanf("%d", &N);
	int temp;
	for (int i = 0; i<N; i++)
	{
		scanf("%d", &temp);
		vec.push_back(temp);
		for (int j = 0; j<21; j++)
			dp[i][j] = 0;
	}

	func();

	printf("%lld\n", dp[N - 2][vec[N - 1]]);
	return 0;
}