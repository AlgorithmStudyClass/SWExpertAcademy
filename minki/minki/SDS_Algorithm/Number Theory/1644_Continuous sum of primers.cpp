/*
	1644 소수의 연속합
	https://www.acmicpc.net/problem/1644
*/

#include <iostream>

using namespace std;

#define MAX_N 4000001

bool check[MAX_N];
int prime[MAX_N];

int main() {
	int n, prime_cnt = 0;

	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		check[i] = true;

	for (int i = 2; i <= n; i++)
	{
		if (!check[i])
			continue;

		prime[prime_cnt++] = i;
		for (int j = 2; i*j <= n; j++)
			check[i*j] = false;
	}
	//투 포인터
	int left, right, ans, sum;
	sum = left = right = ans = 0;

	// prime_cnt 개의 소수 중 연속하여 더하였을 때 합이 N이 되는 경우 2 포인터로 구하기 
	while (left <= right && right<prime_cnt)
	{
		// sum 이 N 미만이면 누적하여 더하기 
		while (right<prime_cnt && sum < n)
			sum += prime[right++];

		// 모든 소수를 다썼으나 sum이 N보다 작으면 종료 
		if (sum < n) break;

		// sum 이 N 초과면 누적하여 빼기 
		while (left<right && sum > n) sum -= prime[left++];

		// sum 이 N 이면 답 갱신, sum 에서 누적하여 빼기 
		if (sum == n)
		{
			ans++;
			sum -= prime[left++];
		}
	}

	printf("%d\n", ans);

	return 0;
}
