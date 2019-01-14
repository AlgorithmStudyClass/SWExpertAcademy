/*
11266 단절점
https://www.acmicpc.net/problem/11266
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_V 10001

vector<int> graph[MAX_V]; //무향 연결 그래프
int visit[MAX_V], cut[MAX_V], ans[MAX_V]; //방문한 순서, 단절여부x
int order;
int V, E;

int min(int a, int b) { return a < b ? a : b; }

int dfs(int node, int p) {
	if (visit[node] != 0)return visit[node];

	visit[node] = ++order; // 방문 순서 저장
	int minlow = visit[node]; //가장 방문순서가 빠른 노드

	int child = 0;
	int sz = graph[node].size();
	for (int i = 0, n; i < sz; i++) {
		n = graph[node][i];
		if (n == p) continue; //부모 노드의 경우 skip

		if (visit[n] != 0) //연결된 노드가 이미 방문했던 노드라면
			minlow = min(minlow, visit[n]);
		else // 처음 방문하는 노드라면
		{
			child++;
			int low = dfs(n, node); // 연결된 노드로 탐색 후 기존 방문했던 노드 중 가장 방문 순서가 빠른 순서 받아오기
									// 현재 노드가 root가 아니고, 자식 노드로 탐색 했을 때 현재 노드 방문 순서와 같거나 빠른 노드가 없다면 현재 노드는 단절점
			if (p != -1 && low >= visit[node])
				cut[node] = 1;
			minlow = min(minlow, visit[n]);
		}
	}

	//root 노드라면 자식의 수 체크, edge size로 체크하면 안됨
	if (p == -1 && child > 1)
		cut[node] = 1;
	return minlow;
}

int main() {
	scanf("%d %d", &V, &E);
	int v, u;
	for (int i = 0; i <= V; i++) {
		graph[i].clear();
		visit[i] = 0;
		cut[i] = 0;
	}
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &v, &u);
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	order = 0;
	for (int i = 1; i <= V; i++) {
		if (visit[i] != 0)continue;
		//방문하지않은 노드 dfs탐색
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

	return 0;
}
