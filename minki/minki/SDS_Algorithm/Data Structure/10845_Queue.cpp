/*
	10845 큐
	https://www.acmicpc.net/problem/10845
*/

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 10000

int front=0,rear=0;
int Queue[MAX];

int main() {
	int N,num,temp;
	char ch[7];
	
	scanf("%d", &N);

	for(int i = 0;i<N;i++){
		scanf("%s", ch);

		if (strcmp(ch, "push") == 0) {
			scanf("%d", &num);
			if ((rear+1) % MAX == front)
				printf("Queue is full!\n");
			else
				Queue[rear++] = num;
		}
		else if (strcmp(ch, "pop") == 0) {
			if (front != rear) {
				temp = Queue[front++];
				printf("%d\n", temp);
				if (front == MAX)
					front = 0;
			}
			else
				printf("-1\n");
		}
		else if (strcmp(ch, "size") == 0) {
			printf("%d\n", rear - front);
		}
		else if (strcmp(ch, "empty") == 0) {
			if (front!=rear) 
				printf("%d\n", 0);
			else
				printf("1\n");
		}
		else if (strcmp(ch, "front") == 0) {
			if (front!=rear)
				printf("%d\n", Queue[front]);
			else
				printf("-1\n");
		}
		else if (strcmp(ch, "back") == 0) {
			if (front != rear)
				printf("%d\n", Queue[rear - 1]);
			else
				printf("-1\n");
		}
	}


	return 0;
}