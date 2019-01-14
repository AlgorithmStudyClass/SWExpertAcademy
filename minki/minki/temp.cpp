/*
2504 괄호의 값
https://www.acmicpc.net/problem/2504
*/

#include <iostream>
#include <cstring>

#define small 2
#define big   3

using namespace std;

int main() {
	int top = 0, len, answer = 0, sum = 0, depth = 0, max = -1;
	char input[35], stack[35], ch;
	bool flag = true; // 괄호가 올바른지 검사
	int check1 = 0, check2 = 0; // 값을 곱해야하는지 더해야하는지 검사
	scanf("%s", input);
	len = strlen(input);

	for (int i = 0; i < len; i++) {
		ch = input[i];
		if (ch == '(') {
			stack[top++] = ch;
			check1++;
		}
		else if (ch == '[') {
			stack[top++] = ch;
			check2++;
		}
		else if (ch == ')') {
			if (stack[--top] != '(') {
				flag = false;
				break;
			}

			if (top != 0) {
				sum += small;
			}
			else {
				answer *= small;
			}

			if (top == 0) {
				answer += sum;
				sum = 0;
				depth = 0;
			}
		}
		else if (ch == ']') {
			if (stack[--top] != '[') {
				flag = false;
				break;
			}

			if (check1 == check2)
				sum *= small;
			else {
				sum += small;
				check2++;
			}

			if (top == 0) {
				answer += sum;
				sum = 0;
			}
		}
	}


	if (flag)
		printf("%d\n", answer);
	else
		printf("0\n");

	return 0;
}
/*
6416 트리인가
https://www.acmicpc.net/problem/6416
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_V 100001

struct edge {
	int u, v;
};
int degree[MAX_V], visit[MAX_V];
vector <int> adj[MAX_V];
map<int, int> Vmap;

int main() {
	int u, v, k = 1;

	while (1) {
		int vnum = 0;
		Vmap.clear();
		scanf("%d %d", &u, &v);
		if (u == 0 && v == 0) {
			//트리 하나 끝
			break;
		}
		else if (u == -1 && v == -1)
			break;
		if (Vmap.find(u) == Vmap.end()) {

		}
	}

	return 0;
}
