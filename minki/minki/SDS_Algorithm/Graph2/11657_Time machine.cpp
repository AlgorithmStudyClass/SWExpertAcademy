/*
	11657 타임머신
	https://www.acmicpc.net/problem/11657
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_V 501
#define MAX_E 6001
#define INF 500*10000+1
int path[MAX_E][3];
int dist[MAX_V];

int main() {
	int u, v, w, n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &path[i][0], &path[i][1], &path[i][2]);

	dist[1] = 0;
	int cnt = n;
	while(cnt>0) {
		for (int i = 0; i < m; i++) {
			int temp = dist[path[i][0]] + path[i][2];
			if (dist[path[i][0]] != INF && dist[path[i][1]] > temp)
				dist[path[i][1]] = temp;
		}
		cnt--;
	}

	//음수 cycle 확인
	//만약 음수 cycle이 없다면 시작점에서 모든 점으로 가는 최단거리는 갱신되어 있어야 한다
	for (int j = 0; j < m; j++) {
		int temp = dist[path[j][0]] + path[j][2];
		//갱신되면 음수 cycle이 존재
		if (dist[path[j][0]] != INF && dist[path[j][1]] > temp) {
			puts("-1");
			return 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] != INF)
			printf("%d\n", dist[i]);
		else
			puts("-1");
	}

	return 0;
}