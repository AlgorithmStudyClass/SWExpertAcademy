/*
	2098 외판원 순회
	https://www.acmicpc.net/problem/2098
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX_N (1<<16)
#define INF (int)1e9+1

int N, start = 0;
int W[16][16];
int dp[16][MAX_N];

int min(int a, int b) {
	return (a < b) ? a : b;
}

/*
현재 외판원이 current번 마을에 있고, 방문한 마을 집합이 visited일 때
앞으로 남은 모든 마을을 방문하고 0번 마을로 돌아갈 때 드는 최소 비용
*/
int TSP(int cur, int visit) {
	if (visit == (1 << N) - 1)// 모든 마을을 방문한 경우, 현재 마을에서 시작지점으로 갈 수 있으면 해당 비용을 리턴하고 아닐 경우 불가능 값을 리턴한다.
		return W[cur][start] ? W[cur][start] : INF;
	if (dp[cur][visit] != -1)
		return dp[cur][visit];

	dp[cur][visit] = INF;
	// 아직 방문하지 않은 모든 마을을 순회해 봄
	for (int i = 0; i<N; i++) {
		if (visit & (1 << i)) // 방문했으면 재방문 필요가 없으므로
			continue;
		if (W[cur][i] == 0) // 갈 수 없는 경우
			continue;
		dp[cur][visit] = min(dp[cur][visit], TSP(i, visit | (1 << i)) + W[cur][i]); // TSP에는 i번째 마을 방문한걸 송신하고 dp에는 비용 저장
	}

	return dp[cur][visit];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &W[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", TSP(0, 1));

	return 0;
}