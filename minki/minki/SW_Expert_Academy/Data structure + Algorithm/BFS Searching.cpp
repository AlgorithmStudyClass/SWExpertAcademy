/*
	너비 우선 탐색은 맹목적 탐색방법의 하나로 
	시작 정점을 방문한 후 시작 정점에 인접한 모든 정점들을 우선 방문하는 방법이다.
*/

#include <stdio.h>

#define MAX_VERTEX 30

int num;
int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];
int queue[MAX_VERTEX];
int rear, front;

void breadthFirstSearch(int v) {
	int i;
	visit[v] = 1;
	printf("%d ", v);
	queue[rear++] = v;
	while (front < rear) {
		v = queue[front++];
		for (i = 1; i <= num; i++) {
			if (map[v][i] == 1 && !visit[i]) {
				visit[i] = 1;
				printf("%d ", i);
				queue[rear++] = i;
			}
		}
	}
}

int main()
{
	int T;
	int test_case;
	int i, j;
	int start;
	int v1;
	int v2;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		for (i = 0; i < MAX_VERTEX; i++)
		{
			for (j = 0; j < MAX_VERTEX; j++)
			{
				map[i][j] = 0;
			}
			visit[i] = 0;
			queue[i] = 0;
		}
		front = 0;
		rear = 0;

		scanf("%d %d", &num, &start);

		while (true)
		{
			scanf("%d %d", &v1, &v2);
			if (v1 == -1 && v2 == -1)
				break;
			
			map[v1][v2] = map[v2][v1] = 1;
		}

		printf("#%d ", test_case);
		breadthFirstSearch(start);
		printf("\n");
	}

	return 0;
}