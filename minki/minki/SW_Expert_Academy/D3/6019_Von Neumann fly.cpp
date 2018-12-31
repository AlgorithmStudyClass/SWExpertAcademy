/*
	6019. 기차 사이의 파리 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWajaTmaZw4DFAWM&categoryId=AWajaTmaZw4DFAWM&categoryType=CODE
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int D, A, B, F;

double func() {
	return (D/(double)(A + B) * F);
}

int main() {
	int t, line = 1;
	scanf("%d", &t);
	while (t > 0) {
		//입력
		scanf("%d %d %d %d", &D,&A,&B,&F);

		//출력
		printf("#%d %f\n", line++, func());
		t--;
	}
	return 0;
}