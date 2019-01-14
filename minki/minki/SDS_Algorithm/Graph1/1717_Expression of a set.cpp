/*
	1717 집합의 표현
	https://www.acmicpc.net/problem/1717
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1000000

int N, M;
int root[MAX_N + 1];

int find(int node) {
	if (root[node] == node) 
		return node;
	else
		return root[node] = find(root[node]);//log급 최상위 부모와 자식 연결
		//return find(root[node] -> n급 부모 자식만 연결
}

//하나의 루트 노드를 다른 하나의 루트 노드의 자식 노드로 넣어 두 트리를 합친다
void union_func(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	root[pb] = pa;
	//root[pa] = pb; 도 가능 단지 취향 차이
}

int main() {
	int check, a, b;

	scanf("%d %d", &N, &M);
	//초기 설정
	//모두 루트 노드로 봐 자기 번호를 저장
	for (int i = 0; i <= N; i++)
		root[i] = i;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &check, &a, &b);
		if (check == 0)
			union_func(a, b);
		else if (check == 1) {
			if (find(root[a]) == find(root[b]))
				puts("YES");
			else
				puts("NO");
		}
	}

	return 0;
}