/*
	5356. 의석이의 세로로 말해요 -D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWVWgkP6sQ0DFAUO&categoryId=AWVWgkP6sQ0DFAUO&categoryType=CODE
*/

#include <iostream>
#include <vector>   
#include <algorithm> 
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, index, q, l, r;
	vector<int> vec, temp_vec;
	string str, temp_str;
	vector<string> str_vec, ans_vec;

	cin >> t;

	while (t > 0) {
		//입력
		for (int i = 0; i < 5; i++) {
			cin >> temp_str;
			str_vec.push_back(temp_str);
			vec.push_back(str_vec[i].length());
		}

		str.clear();
		sort(vec.begin(), vec.end(),greater<int>());

		for (int i = 0; i < vec[0]; i++) {
			for (int j = 0; j < 5; j++)
				if(i < str_vec[j].length())
					str.push_back(str_vec[j][i]);
		}

		//출력
		cout << "#" << line++ << " " << str;
		cout << endl;

		str_vec.clear();
		vec.clear();
		t--;
	}
	return 0;
}