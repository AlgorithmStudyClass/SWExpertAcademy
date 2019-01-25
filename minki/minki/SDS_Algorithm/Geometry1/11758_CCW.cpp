/*
	11758 CCW
	https://www.acmicpc.net/problem/11758
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int x[3], y[3];

// a*b = |a||b|sin(theta)
int ccw() {
	int ans = (x[0] * y[1] + x[1] * y[2] + x[2] * y[0] - y[0] * x[1] - y[1] * x[2] - y[2] * x[0]);
	if (ans > 0)//counter clockwise
		return 1;
	else if (ans < 0) //clockwise
		return -1;
	else // parallel
		return 0;
}

int main()
{
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	printf("%d\n", ccw());
}