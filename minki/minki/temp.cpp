#include <stdio.h>

int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}
int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
int main()
{
	int tc;
	int move, i, a[101], u, d, temp;
	for (tc = 0; tc < 10; tc++)
	{
		scanf("%d", &move);
		for (i = 1; i <= 100; i++)
			a[i] = 0;
		for (i = 0; i < 100; i++)
		{
			scanf("%d", &temp);
			a[temp]++;
		}
		for (i = 99; i > 0; i--)
			a[i] += a[i + 1];
		u = 100, d = 1;
		for (;;)
		{
			temp = min(min(a[u], 100 - a[d]), move);
			a[u] -= temp;
			a[d] += temp;
			move -= temp;
			if (a[u] == 0)
				u--;
			if (a[d] == 100)
				d++;
			if (d >= u || move == 0)
				break;
		}


		printf("#%d %d\n", tc + 1, u - d + 1);
	}
	return 0;
}