#include<iostream>
#include <vector>
#include <queue>
#include<string>

using namespace std;

int car1[1001];
int car2[51];
int car3[51];

int main(void) {
	int n,m,t,line=1,ans=0,len;
	bool flag;
	scanf("%d", &t);
	while (t > 0) {
		//입력
		scanf("%d %d", &n,&m);
		
		len = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d", &car2[i]);
			if (car2[i] > 0)
				len += car2[i];
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &car1[i]);
		}

		ans = 0;
		for (int i = 0; i < n; i++) {
			flag = true;
			memcpy(car3, car2, m*sizeof(int));
			for (int j = 0; j < len; j++) {
				if (car3[car1[i + j] - 1] > 0) {
					car3[car1[i + j] - 1]--;
				}
				else{
					flag = false;
					break;
				}
			}
			if (flag) {
				ans = i+1;
				break;
			}
		}

		//출력
		printf("#%d %d\n", line++, ans);
		t--;
	}
	return 0;
}

