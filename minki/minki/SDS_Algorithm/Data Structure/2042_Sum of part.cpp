/*
	2042 구간 합 구하기
	https://www.acmicpc.net/problem/2042
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_V 1000000
typedef long long int lld;

lld tree[MAX_V * 4];
int N, M, K;

int init() {//트리 초기
	for (int i = 0; i < 4 * N; i++)
		tree[i] = 0;
	//처음으로 N보다 큰 2의 제곱수 구하기
	int ret = 1;
	while (ret < N)
		ret *= 2;

	return ret;
}

void modify(int node, lld delta) {
	int cur = node;
	while (cur > 0) {
		tree[cur] += delta; //트리의 데이터를 갱신
		cur /= 2; //부모 노드로 이동
	}
}

lld sum(int start, int end) {
	lld sum = 0;
	while (start <= end) { //left root right
		if (start % 2 == 1)sum += tree[start]; //left
		if (end % 2 == 0)sum += tree[end]; //right
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}
	return sum;
}

int main() {
	int a, b;
	lld c;
	scanf("%d %d %d", &N, &M, &K);

	int Nidx = init();

	//인덱스 트리의 리프 노드에 데이터 입력
	for (int i = 0; i < N; i++)
		scanf("%lld", &tree[Nidx + i]);

	//트리 구성
	for (int i = Nidx - 1; i > 0; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	for (int i = 0; i < M + K; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) //modify
			modify(Nidx + b - 1, c - tree[Nidx + b - 1]);
		else if (a == 2) //sum
			printf("%lld\n", sum(Nidx + b - 1, Nidx + c - 1));
	}

	return 0;
}