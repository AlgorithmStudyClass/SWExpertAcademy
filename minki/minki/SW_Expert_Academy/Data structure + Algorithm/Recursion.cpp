/*
	재귀는 수학이나 컴퓨터 과학 등에서 자신을 정의할 때 자기 자신을 재참조하는 방법을 뜻한다. 
	주로 이 방법은 함수에 적용한 재귀 함수(Recursion Function)의 형태로 많이 사용된다.
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

long long factorial(int num) {
	if (num == 0)
		return 1;
	else
		return factorial(num - 1) * num;
}

int main()
{
	int test_case;
	int T;
	int num;
	long long value;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &num);
		value = factorial(num);
		printf("#%d %d! = %lld\n", test_case, num, value);
	}

	return 0;
}