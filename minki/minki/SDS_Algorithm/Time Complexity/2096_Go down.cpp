/*
	2096 내려가기
	https://www.acmicpc.net/problem/2096
*/

#include <iostream>

using namespace std;

#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define MAX(a,b)  ((a) > (b) ? (a) : (b))

int min_dp[2][3], max_dp[2][3], arr[3];

int main() {
	int N,num,temp;
	
	scanf("%d", &N);

	for(int i = 0;i<N;i++){
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

		min_dp[(i + 1) % 2][0] = MIN(min_dp[i % 2][0], min_dp[i % 2][1]) + arr[0];
		min_dp[(i + 1) % 2][1] = MIN(min_dp[i % 2][0], MIN(min_dp[i % 2][1], min_dp[i % 2][2])) + arr[1];
		min_dp[(i + 1) % 2][2] = MIN(min_dp[i % 2][1], min_dp[i % 2][2]) + arr[2];

		max_dp[(i + 1) % 2][0] = MAX(max_dp[i % 2][0], max_dp[i % 2][1]) + arr[0];
		max_dp[(i + 1) % 2][1] = MAX(max_dp[i % 2][0], MAX(max_dp[i % 2][1], max_dp[i % 2][2])) + arr[1];
		max_dp[(i + 1) % 2][2] = MAX(max_dp[i % 2][1], max_dp[i % 2][2]) + arr[2];
	}

	printf("%d ", MAX(max_dp[N % 2][0], MAX(max_dp[N % 2][1], max_dp[N % 2][2])));
	printf("%d\n", MIN(min_dp[N%2][0],MIN(min_dp[N % 2][1], min_dp[N % 2][2])));

	return 0;
}