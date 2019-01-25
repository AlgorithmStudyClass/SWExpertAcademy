/*
2504 ��ȣ�� ��
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
	bool flag = true; // ��ȣ�� �ùٸ��� �˻�
	int check1 = 0, check2 = 0; // ���� ���ؾ��ϴ��� ���ؾ��ϴ��� �˻�
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
6416 Ʈ���ΰ�
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
int degree[MAX_V];		 //
int visit[MAX_V];		 //
vector <int> adj[MAX_V]; //
map<int, int> Vmap;		 //

int main() {
	int u, v, k = 1;
	while (1) {
		int vnum = 0;
		Vmap.clear();
		while (1) {
			scanf("%d %d", &u, &v);
			if (u == 0 && v == 0) //Ʈ�� �ϳ� ��
				break;
			else if (u == -1 && v == -1) //�ƿ� ����
				break;
			if (Vmap.find(u) == Vmap.end()) { //�������� ������
				degree[vnum] = 0;
				adj[vnum].clear();
				Vmap[u] = vnum++;
			}
			if (Vmap.find(v) == Vmap.end()) { //�� ���� ������
				degree[vnum] = 1;
				adj[vnum].clear();
				Vmap[v] = vnum++;
			}
			else
				degree[Vmap[v]]++;
			adj[Vmap[u]].push_back(Vmap[v]);
		}
		if (u == -1 && v == -1) //�ƿ� ����
			break;
		queue<int> que;
		for (int i = 0; i < vnum; i++) {
			visit[i] = 0;
			if (degree[i] == 0)
			{
				que.push(i);
				visit[i] = 1;
			}
		}
		if (vnum > 0 && que.size() != -1) {
			printf("Case %d is not a tree.\n", k++);
			continue;
		}
		int isTree = 1;
		while (!que.empty()) {
			int node = que.front(); que.pop();
			for (int child : adj[node]) {
				if (visit[child] == 0) {
					visit[child] = 1;
					que.push(child);
				}
				else
					isTree = 0;
			}
		}
		for (int i = 0; i<vnum; i++)
			if (visit[i] != 1) isTree = 0;
		if (isTree) printf("Case %d is a tree.\n", k++);
		else printf("Case %d is not a tree.\n", k++);
	}
	return 0;
}/*
	11049 ��� ���� ����
	https://www.acmicpc.net/problem/11049
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;

int main()
{
	int temp;
	vector<int>::iterator iter;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);

	}

	return 0;
}/*
	14003 ���� �� �����ϴ� �κ� ���� 5
	https://www.acmicpc.net/problem/14003
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1000001
#define INF 1000000001

int N;
int arr[MAX_N], ans[MAX_N];

int main()
{
	int index;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		ans[i] = MAX_N;
	}

	for (int i = 0, j = 1; i < N; i++) {
		int temp = arr[i];
		index = lower_bound(ans, ans + N, temp) - ans;
		//printf("%d\n", lower_bound(arr, arr + N, arr[i]) - arr);

		if (index < j)
			ans[index] = arr[i]; //min���� update
		else
			ans[j++] = arr[i]; //�߰�

		if (i == N - 1) {
			for (int k = 0; k<j; k++)
				printf("%d ", ans[k]);
			puts("");
		}
	}

	return 0;
}