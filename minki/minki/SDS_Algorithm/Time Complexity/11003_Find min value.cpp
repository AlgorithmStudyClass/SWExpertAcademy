/*
	11003 최솟값 찾기
	https://www.acmicpc.net/problem/11003
*/

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

struct info {
	int num, idx;
};

char ans[12 * 5000000 + 1];

int main() {
	int N, L, answer, temp;
	deque<info> deq;
	answer = 0;

	scanf("%d %d", &N, &L);
	for (int i = 0, temp; i < N; i++) {
		scanf("%d", &temp);
		// deque 주소만큼 있어야하니 앞에 거 제거
		if (!deq.empty() && i - L + 1 >= 0 && deq.front().idx < i - L + 1)
			deq.pop_front();
		// deque 뒤에서 temp보다 큰 거 다 제거
		while (!deq.empty() && deq.back().num > temp)
			deq.pop_back();
		// 다 제거 했으니 temp 추가
		deq.push_back({ temp,i });
		// 정답 배열에 추가
		// 여러 번 출력
		// printf("%d ",deq.front().num);
		answer += sprintf(&ans[answer], "%d ", deq.front().num);
	}

	//1번에 출력
	printf("%s\n", ans);

	return 0;
}