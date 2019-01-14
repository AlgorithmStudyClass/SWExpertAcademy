/*
	1753 최단경로
	https://www.acmicpc.net/problem/1753
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_V 20001
#define MAX_E 300001
#define INF (1<<31) -1

struct Info { // priority queue에 넣을 정보
	int v; // 방문한 노드
	int w; // 노드까지의 거리
	Info(int node, int cost) {
		v = node;
		w = cost;
	}
	// c++ pq의 경우 default가 max heap
	bool operator<(const Info & ref)const{
		return w > ref.w;
	}
};
vector<Info> path[MAX_V];
int dist[MAX_V];
priority_queue<Info>pq;// 방문한 정점 중 최단거리가 가장 까까운 정점 정보를 위해 priority queue 생성 
int V, E, S;

int main() {
	int u, v, w;
	scanf("%d %d", &V, &E);
	scanf("%d", &S);
	for (int i = 1; i <= V; i++) {
		path[i].clear();
		dist[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		//인접 리스트 생성
		path[u].push_back({ v,w });
	}

	dist[S] = 0;// 시작 정점까지의 최단거리는 0
	pq.push({ S,0 });//시작 정점 정보 추가
	while(!pq.empty()){	
		int node = pq.top().v;
		int cost = pq.top().w;
		pq.pop();
		if (dist[node] != cost)continue; // 중복되는 간선 cutting
		for (Info next : path[node]) {
			//최단거리가 확정된 정점으로 연결되는 새로운 정점
			//혹은 기존 거리보다 더 빠르게 갈 수 있는 정점을 추가
			int temp = dist[node] + next.w;
			if (dist[next.v] > temp && temp > 0) {
				dist[next.v] = temp;
				pq.push({ next.v,dist[next.v] });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i]!= INF)
			printf("%d\n", dist[i]);
		else
			puts("INF");
	}

	return 0;
}