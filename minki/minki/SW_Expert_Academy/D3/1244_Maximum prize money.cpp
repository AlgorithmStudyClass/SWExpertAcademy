/*
	1244. 최대 상금 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD&categoryId=AV15Khn6AN0CFAYD&categoryType=CODE
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int K, MAX;
string str;

int str_to_int(string str) {
	int ans = 0, len = str.length(), ten = 1;
	for (int i = len - 1; i >= 0; i--) {
		ans += (str[i] - '0') * ten;
		ten *= 10;
	}
	return ans;
}

void func(int cnt, int now) {
	if (cnt == K) {
		MAX = max(MAX, stoi(str));//stoi도 가능
		return;
	}

	for (int i = now; i < str.length(); i++) {
		for (int j = i; j < str.length(); j++) {
			if (i!=j && str[i] <= str[j]) {
				swap(str[i], str[j]);
				func(cnt + 1, i);
				swap(str[i], str[j]);
			}
		}
	}
}

int main() {
	int t, line = 1;
	scanf("%d", &t);
	while (t > 0) {
		//입력
		cin >> str >> K;

		MAX = 0;
		func(0, 0);

		//출력
		printf("#%d %d\n", line++, MAX);
		t--;
	}
	return 0;
}