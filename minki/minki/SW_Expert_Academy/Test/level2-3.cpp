#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX_NUM 200001

vector<vector<int>> vec;
int check[MAX_NUM];

void func(int n) {
	int x, y;

	sort(vec.begin(), vec.end());

	x = vec[0][0];
	y = vec[0][1];
	check[0] = 1;

	for (int i = 0; i < n - 1; i++) {
		if (x < vec[i + 1][0] && y > vec[i + 1][1]) {
			x = vec[i + 1][0];
			y = vec[i + 1][1];
			check[i] = 1;
		}
	}
}

int main() {

	int t, line = 1, n;
	scanf("%d", &t);

	while (t > 0) {
		scanf("%d", &n);

		int x, y;

		for (int i = 0; i < n; i++) {
			vec.push_back(vector<int>());
			scanf("%d %d", &x, &y);
			vec[i].push_back(x);
			vec[i].push_back(y);
			vec[i].push_back(i + 1);
			check[i] = 0;
		}

		func(n);

		printf("#%d ", line++);
		for (int i = 0; i < n; i++)
			if (check[i])
				printf("%d ", vec[i][2]);
		printf("\n");

		for (int i = 0; i < n; i++)
			vec[i].clear();
		vec.clear();
		t--;
	}

	return 0;
}