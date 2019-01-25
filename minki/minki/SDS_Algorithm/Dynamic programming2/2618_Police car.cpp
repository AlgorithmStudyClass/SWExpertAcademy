/*
	2618 경찰차
	https://www.acmicpc.net/problem/2618
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_N 1001
#define INF (1<<31)-1

int N, W;					// 도로의 개수, 사건의 개수
int dp[MAX_N][MAX_N];		// row,col 경찰차 1,2 이 마지막으로 처리한 사건 
int car[MAX_N];				//
pair<int, int> acci[MAX_N];	// 사건의 위치

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int func(int x, int y) { // 1,2 처리한 사건의 번호
	if (x == W || y == W)
		return 0;

	int &ret = dp[x][y];
	if (ret != -1)
		return ret;

	int a, b;					// 1,2가 처리할 경우 이동 거리
	int next = max(x, y) + 1;	// 다음 칸 이동

	if (x)
		a = func(next, y) + dist(acci[next], acci[x]);
	else
		a = func(next, y) + dist(acci[next], { 1, 1 }); // 경찰차 1이 1,1에 있으므로

	if (y)
		b = func(x,next) + dist(acci[next], acci[y]);
	else
		b = func(x,next) + dist(acci[next], { N, N }); // 경찰차 2이 N,N에 있으므로

	return ret = min(a, b);
}	 

void solve(int x, int y) {
	if (x == W || y == W)
		return ;

	int a, b;
	int next = max(x, y) + 1; // 다음 칸 이동

	if (x)
		a = func(next, y) + dist(acci[next], acci[x]);
	else
		a = func(next, y) + dist(acci[next], { 1, 1 });

	if (y)
		b = func(x, next) + dist(acci[next], acci[y]);
	else
		b = func(x, next) + dist(acci[next], { N, N });

	if (a < b) { // 1이 이동거리가 더 작으므로
		car[next] = 1;
		solve(next, y);
	}
	else {
		car[next] = 2;
		solve(x, next);
	}
}

int main()
{
	scanf("%d %d", &N, &W);
	for (int i = 1; i <= W; i++) {
		scanf("%d %d", &acci[i].first, &acci[i].second);
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n",func(0, 0));

	solve(0, 0);
	for (int i = 1; i <= W; i++)
		printf("%d\n", car[i]);

	return 0;
}