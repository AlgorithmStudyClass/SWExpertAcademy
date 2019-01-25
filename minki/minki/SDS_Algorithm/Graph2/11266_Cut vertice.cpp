/*
	11266 단절점
	https://www.acmicpc.net/problem/11266
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_V 10001

vector<int> graph[MAX_V]; //무향 연결 그래프
int cut[MAX_V]; //단절 여부
int visit[MAX_V]; //방문한 순서
int number;
int ans[MAX_V];
int V, E;

int min(int a, int b) {
	return (a<b) ? a : b;
}
int dfs(int v, int p) // v:방문한 노드, p:부모 노드(-1인 경우 root)
{
	if (visit[v] != 0) return visit[v];

	visit[v] = ++number; // 방문 순서 저장
	int minLow = visit[v]; // 연결된 점을 방문하며 기존 방문했던 노드 중 가장 방문순서가 빠른 순서 저장

	int child = 0; // 연결된 자식의 수
	int sz = graph[v].size();
	for (int i = 0, n; i<sz; i++) {
		n = graph[v][i];
		if (n == p) continue; // 부모 노드의 경우 skip

		if (visit[n] != 0)  // 연결된 노드가 이미 방문했던 노드라면
		{
			// minLow 갱신
			minLow = min(minLow, visit[n]);
		}
		else // 처음 방문하는 노드라면
		{
			child++; // 자식의 수 갱신
			int low = dfs(n, v); // 연결된 노드로 탐색 후 기존 방문했던 노드 중 가장 방문 순서가 빠른 순서 받아오기
								 // 현재 노드가 root가 아니고, 자식 노드로 탐색 했을 때 현재 노드 방문순서와 같거나 빠른 노드가 없다면 현재노드는 단절점
			if (p != -1 && low >= visit[v]) cut[v] = 1;

			// minLow 갱신
			minLow = min(minLow, low);
		}
	}

	// root 노드라면 자식의 수 체크, edge size로 체크하면 안됨
	if (p == -1 && child > 1)  cut[v] = 1;

	return minLow;
}
int main()
{
	scanf("%d %d", &V, &E);
	for (int i = 0; i <= V; i++)
	{
		graph[i].clear();
		visit[i] = 0;
		cut[i] = 0;
	}

	int a, b;
	for (int i = 1; i <= E; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	number = 0;
	for (int i = 1; i <= V; i++) {
		if (visit[i] != 0) continue;
		// 방문 하지 않은 노드 dfs 탐색
		dfs(i, -1);
	}

	int cutVCnt = 0;
	for (int i = 1; i <= V; i++) {
		if (cut[i]) {
			ans[cutVCnt++] = i;
		}
	}

	printf("%d\n", cutVCnt);
	for (int i = 0; i<cutVCnt; i++)printf("%d ", ans[i]);
	printf("\n");
}