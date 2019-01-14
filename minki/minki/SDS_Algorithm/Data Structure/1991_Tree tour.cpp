/*
	1991 트리 순회
	https://www.acmicpc.net/problem/1991
*/

#include <iostream>
#include <string>

using namespace std;

struct info {
	char value;
	int parent, left, right;
};

info arr[26];

void preOrder(int node) {
	printf("%c", arr[node].value);
	if (arr[node].left > -1)preOrder(arr[node].left);
	if (arr[node].right > -1)preOrder(arr[node].right);
}

void inOrder(int node) {
	if (arr[node].left > -1)inOrder(arr[node].left);
	printf("%c", arr[node].value);
	if (arr[node].right > -1)inOrder(arr[node].right);
}

void postOrder(int node) {
	if (arr[node].left > -1)postOrder(arr[node].left);
	if (arr[node].right > -1)postOrder(arr[node].right);
	printf("%c", arr[node].value);
}

int main() {
	int N;
	char p, l, r;
	string str, temp;
	scanf("%d", &N);
	cin.ignore(256, '\n');

	//초기화
	for (int i = 0; i < 26; i++) {
		arr[i].value = i + 'A';
		arr[i].parent = arr[i].left = arr[i].right = -1;
	}

	for (int i = 0; i < N; i++) {
		getline(cin, str);
		p = str[0];
		l = str[2];
		r = str[4];
		if (l != '.') {
			arr[p - 'A'].left = l - 'A';
			arr[l - 'A'].parent = p - 'A';
		}
		if (r != '.') {
			arr[p - 'A'].right = r - 'A';
			arr[r - 'A'].parent = p - 'A';
		}
	}

	preOrder(0); printf("\n");
	inOrder(0); printf("\n");
	postOrder(0); printf("\n");
	
	return 0;
}