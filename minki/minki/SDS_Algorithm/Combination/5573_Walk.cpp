/*
	5573 산책
	https://www.acmicpc.net/problem/5573
*/

#include <iostream>
#include <vector>

using namespace std;

int H, W, N;
int arr[1001][1001]; // 경로
int dp[1001][1001];  // 각 경로를 몇번 거칠지 계산

int main()
{
	scanf("%d %d %d", &H, &W, &N);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = N - 1; // N-1번만 바꿔도 알 수 있으니
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (dp[i][j] == 0) continue;

			dp[i][j + 1] += dp[i][j] / 2;
			dp[i + 1][j] += dp[i][j] / 2;

			if (dp[i][j] % 2 == 1) {
				if (arr[i][j] == 1)//우측
					dp[i][j + 1]++;
				else
					dp[i + 1][j]++;
			}

			arr[i][j] = (arr[i][j] + dp[i][j]) % 2;
		}
	}

	int x = 0, y = 0;
	while (x < H && y < W) {
		if (arr[x][y] == 1)//우측
			y++;
		else
			x++;
	}

	printf("%d %d\n", x + 1, y + 1);

	return 0;
}