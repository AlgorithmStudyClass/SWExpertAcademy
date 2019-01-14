/*
	1753 최단경로
	https://www.acmicpc.net/problem/1753
*/
#include <iostream>
#include <queue>

using namespace std;

//pq는 원래 max heap
struct Info {
	int node, cost;
	Info(int n, int c) {
		node = n;
		cost = c;
	}
	bool operator<(const Info & ref)const{
		return cost > ref.cost;
	}
	//첫 번째 const 최적화하려고 값을 안 바꾸려고 함
	//두 번째 const 자기 자신도 바뀌면 안되니깐 
	// &를 쓰므로 원래 있는 녀석을 씀 성능적으로 좋아짐 값을 copy할 필요가 없으니
};
struct comp {
	bool operator()(const Info &a, const Info &b) {
		return a.cost > b.cost;
	}
};

int main() {
	//priority_queue <Info, vector<Info>, comp > pq;
	priority_queue<Info>pq;
	for (int i = 1; i <= 10; i++)pq.push({ i, i });
	while (!pq.empty()) {
		Info cur = pq.top();
		pq.pop();
		printf("%d %d\n", cur.node, cur.cost);
	}
	return 0;
}