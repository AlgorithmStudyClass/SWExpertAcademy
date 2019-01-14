/*
11266 ������
https://www.acmicpc.net/problem/11266
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_V 10001

vector<int> graph[MAX_V]; //���� ���� �׷���
int visit[MAX_V], cut[MAX_V], ans[MAX_V]; //�湮�� ����, ��������x
int order;
int V, E;

int min(int a, int b) { return a < b ? a : b; }

int dfs(int node, int p) {
	if (visit[node] != 0)return visit[node];

	visit[node] = ++order; // �湮 ���� ����
	int minlow = visit[node]; //���� �湮������ ���� ���

	int child = 0;
	int sz = graph[node].size();
	for (int i = 0, n; i < sz; i++) {
		n = graph[node][i];
		if (n == p) continue; //�θ� ����� ��� skip

		if (visit[n] != 0) //����� ��尡 �̹� �湮�ߴ� �����
			minlow = min(minlow, visit[n]);
		else // ó�� �湮�ϴ� �����
		{
			child++;
			int low = dfs(n, node); // ����� ���� Ž�� �� ���� �湮�ߴ� ��� �� ���� �湮 ������ ���� ���� �޾ƿ���
									// ���� ��尡 root�� �ƴϰ�, �ڽ� ���� Ž�� ���� �� ���� ��� �湮 ������ ���ų� ���� ��尡 ���ٸ� ���� ���� ������
			if (p != -1 && low >= visit[node])
				cut[node] = 1;
			minlow = min(minlow, visit[n]);
		}
	}

	//root ����� �ڽ��� �� üũ, edge size�� üũ�ϸ� �ȵ�
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
		//�湮�������� ��� dfsŽ��
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
