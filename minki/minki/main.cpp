/*
	3233. 정삼각형 분할 놀이 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWAe5G8afT0DFAUw&categoryId=AWAe5G8afT0DFAUw&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <cstring>
#include <numeric>
#include <sstream>

using namespace std;

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, index;
	bool flag;
	vector<int> vec, temp_vec;
	string str, temp_str;
	vector<string> str_vec, ans_vec;

	cin >> t;

	while (t > 0) {
		int a, b;
		
		//입력
		scanf("%d %d", &a, &b);

		long long int n = a/b;

		//출력
		printf("#%d %lld", line++,n * n);
		printf("\n");
		t--;
	}

	return 0;
}