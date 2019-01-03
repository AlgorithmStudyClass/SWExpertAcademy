/*
	4615. 재미있는 오셀로 게임 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWQmA4uK8ygDFAXj&categoryId=AWQmA4uK8ygDFAXj&categoryType=CODE
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int arr[8][8];
//방향 저장 배열 (우 좌 상 하 대각선 4개)
int dx[8] = { 0,0,1,-1,1,1,-1,-1};
int dy[8] = { 1,-1,0,0,1,-1,1,-1};

void init()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			arr[i][j] = 0;
}

void func(int x, int y,int value)
{
	//8방향 체크
	for (int d = 0; d < 8; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		bool chk = false;

		//상하좌우 범위 내에 있고 빈 공간이 아니면
		while (nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] != 0)
		{
			if (arr[nx][ny] == value)
			{
				chk = true;
				break;
			}
			nx += dx[d];
			ny += dy[d];
		}

		//같은 값을 찾는다면 계속 값을 바꿔줌
		while (chk)
		{
			if (nx == x && ny == y)
				break;
	
			arr[nx][ny] = value;
			nx -= dx[d];
			ny -= dy[d];
		}
	}
}

int main() {
	int t, line = 1;
	scanf("%d", &t);
	while (t > 0) {
		//입력
		scanf("%d %d", &n, &m);

		//초기화
		init();
		arr[n / 2][n / 2] = arr[n / 2 - 1][n / 2 - 1] = 2;
		arr[n / 2][n / 2 - 1] = arr[n / 2 - 1][n / 2] = 1;
		
		int x, y, value;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &x, &y, &value);
			arr[x-1][y-1] = value;
			func(x - 1, y - 1,value);
		}

		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1)
					ans1++;
				else if (arr[i][j] == 2)
					ans2++;
			}

		//출력
		printf("#%d %d %d\n", line++, ans1, ans2);
		t--;
	}
	return 0;
}