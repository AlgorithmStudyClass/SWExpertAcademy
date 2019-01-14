/*
	DFS
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_V 100001

int N, M;
vector<int> adj[MAX_V];
int visit_num; 
int visit[MAX_V];

void dfs(int node) {
	//visit_num을 파라미터로 들고다니기 애매함
	//자식의 방문한 제대로 counting이 이루어 지지 않음
	visit[node] = ++visit_num;
	//visit[node] = vnum + 1;
	//용도가 다르다 위에껀 방문한 순서 밑에껀 depth

	for (int i = 0; i < adj[node].size(); i++) {
		int nnode = adj[node][i];
		if (visit[nnode] == 0) {//자식과 부모가 확장
			dfs(nnode);
			//difs(nnode,visit[node]);
		}
		else {//방문했던 노드를 어떻게 하겠다
			;
		}
	}
	//out[node] = visit_num;
}

int main()
{
	//초기화
	for (int i = 1; i < MAX_V; i++) {
		adj[i].clear();
		visit[i] = 0;
	}
	visit_num = 0;

	dfs(1);

	return 0;
}