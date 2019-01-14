/*
	11404 플로이드
	https://www.acmicpc.net/problem/11404
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_V 101
#define INF 100000001
int dist[MAX_V][MAX_V];
int min(int a, int b) { return a < b ? a : b; }

int main() {
	int u, v, w, n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}
		
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		dist[u][v] = min(dist[u][v], w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}