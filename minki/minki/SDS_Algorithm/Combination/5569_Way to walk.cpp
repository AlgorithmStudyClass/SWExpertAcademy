/*
	5569 출근 경로
	https://www.acmicpc.net/problem/5569
*/

#include <iostream>
#include <vector>

using namespace std;

#define res 100000
int W, H;
int dp[101][101][4];

int main()
{
	scanf("%d %d", &W, &H);

	for (int i = 2; i <= W; i++) dp[i][1][1] = 1; //계속 우측
	for (int i = 2; i <= H; i++) dp[1][i][3] = 1; //계속 위쪽
	for (int i = 2; i <= W; i++) {
		for (int j = 2; j <= H; j++) {
			dp[i][j][0] = dp[i - 1][j][3]; // 위쪽가다 우측
			dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % res;//계속 우측
			dp[i][j][2] = dp[i][j - 1][1]; //우측가다 위쪽
			dp[i][j][3] = (dp[i][j - 1][3] + dp[i][j - 1][2]) % res;//계속 위쪽
		}
	}

	printf("%d\n", (dp[W][H][0] + dp[W][H][1] + dp[W][H][2] + dp[W][H][3]) % res);


	return 0;
}