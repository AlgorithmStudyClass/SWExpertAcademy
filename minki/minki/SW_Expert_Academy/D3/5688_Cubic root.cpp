/*
	5688. 세제곱근을 찾아라 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXVyCaKugQDFAUo&categoryId=AWXVyCaKugQDFAUo&categoryType=CODE
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t, line = 1;
	long long int triple, n ,answer;
	scanf("%d", &t);
	while (0 < t--) {
		scanf("%lld", &n);
		answer = 1;
		//sol1
		/*while (1) {
			triple = answer * answer * answer;
			if (triple == n)
				break;
			else if (triple > n) {
				answer = -1;
				break;
			}
			answer++;
		}
		*/
		//sol2
		long long int l = 1, r = 1e6, mid, dab = -1;//1e6 = 10^6
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (mid * mid * mid == n) { dab = mid; break; }
            else if (mid * mid * mid > n) r = mid - 1;
            else l = mid + 1;
        }
		
		printf("#%d %d\n", line++, dab);
	}

	return 0;
}