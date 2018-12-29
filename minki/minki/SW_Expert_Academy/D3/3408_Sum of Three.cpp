/*
	3408. 세가지 합 구하기 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWEbPukqySUDFAWs&categoryId=AWEbPukqySUDFAWs&categoryType=CODE&&&
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

long long int N;

long long int func1() {
	long long sum = (1+N)*N/2;
	/*
		for (int i = 1; i <= N; i++)
			sum += i;
	*/
	
	return sum;
}

long long int func2() {
	long long sum = N*N;
	/*
		for (int i = 1; i <= N; i++)
			sum += i * 2 -1;
	*/
	return sum;
}

long long int func3() {
	long long int sum = N*(N+1);
	/*
		for (int i = 1; i <= N; i++)
			sum += i * 2;
	*/
	return sum;
}

int main() {
	int t, line = 1;
	scanf("%d", &t);
	while (t > 0) {
		//입력
		scanf("%d", &N);

		//출력
		printf("#%d %lld %lld %lld\n", line++, func1(), func2(), func3());
		t--;
	}
	return 0;
}