/*
	5601. [Professional] 쥬스 나누기 -D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXGAylqcdYDFAUo&categoryId=AWXGAylqcdYDFAUo&categoryType=CODE
*/

#include <iostream>
#include <vector>   
#include <algorithm> 
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

void func(int n) {
	for (int i = 0; i < n; i++)
		cout << "1/" << n << " ";
}

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, index, arr[7];
	vector<int> vec, temp_vec;
	string str, temp_str;
	vector<string> str_vec, ans_vec;

	cin >> t;

	while (t > 0) {
		//입력
		scanf("%d", &n);
		//출력
		cout << "#" << line++ << " ";
		func(n);
		cout << endl;
		t--;
	}
	return 0;
}