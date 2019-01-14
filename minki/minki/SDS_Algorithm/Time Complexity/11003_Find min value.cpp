/*
	11003 �ּڰ� ã��
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
		// deque �ּҸ�ŭ �־���ϴ� �տ� �� ����
		if (!deq.empty() && i - L + 1 >= 0 && deq.front().idx < i - L + 1)
			deq.pop_front();
		// deque �ڿ��� temp���� ū �� �� ����
		while (!deq.empty() && deq.back().num > temp)
			deq.pop_back();
		// �� ���� ������ temp �߰�
		deq.push_back({ temp,i });
		// ���� �迭�� �߰�
		// ���� �� ���
		// printf("%d ",deq.front().num);
		answer += sprintf(&ans[answer], "%d ", deq.front().num);
	}

	//1���� ���
	printf("%s\n", ans);

	return 0;
}