/*
	10828 스택
	https://www.acmicpc.net/problem/10828
*/

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 10001

int Top = -1;
int Stack[MAX];

int main() {
	int N,num,temp;
	char ch[7];
	
	scanf("%d", &N);

	for(int i = 0;i<N;i++){
		scanf("%s", ch);

		if (strcmp(ch, "push") == 0) {
			scanf("%d", &num);
			Stack[++Top] = num;
		}
		else if (strcmp(ch, "pop") == 0) {
			if (Top >= 0) {
				temp = Stack[Top--];
				printf("%d\n", temp);
			}
			else
				printf("-1\n");
		}
		else if (strcmp(ch, "size") == 0) {
			printf("%d\n", Top + 1);
		}
		else if (strcmp(ch, "empty") == 0) {
			if (Top >= 0) 
				printf("%d\n", 0);
			else
				printf("1\n");
		}
		else if (strcmp(ch, "top") == 0) {
			if (Top >= 0)
				printf("%d\n", Stack[Top]);
			else
				printf("-1\n");
		}
	}


	return 0;
}