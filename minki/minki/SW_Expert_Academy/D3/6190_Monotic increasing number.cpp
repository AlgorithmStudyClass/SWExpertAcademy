/*
	6190. 정곤이의 단조 증가하는 수 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWcPjEuKAFgDFAU4&categoryId=AWcPjEuKAFgDFAU4&categoryType=CODE
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N;

bool monotonic_func(int num) {
	int q, r, cur;
	cur = 9;
	for (q = num; q>0; q /= 10) {
		r = q % 10;
		if (r > cur) return false;
		if (r < cur) cur = r;
	}
	return true;
}

int main() {
	int t, line = 1;
	scanf("%d", &t);
	while (t > 0) {
		//입력
		scanf("%d", &N);
		int cnt = 0, temp, ans;
		vector<int> vec;
		bool flag = false;

		for (int i = 0; i < N; i++) {
			scanf("%d", &temp);
			if (temp % 10 != 0)
				vec.push_back(temp);
		}

		ans = -1;
		sort(vec.rbegin(), vec.rend());

		for (int i = 0; i < vec.size(); i++) {
			for (int j = i + 1; j < vec.size(); j++) {
				temp = vec[i] * vec[j];
				if (monotonic_func(temp)) {
					if (ans < temp) {
						ans = temp;
						break;
					}
				}
			}
		}

		//출력
		printf("#%d %d\n", line++, ans);
		t--;
	}
	return 0;
}