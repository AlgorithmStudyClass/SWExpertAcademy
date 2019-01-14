/*
	3955 캔디분배
	https://www.acmicpc.net/problem/3955
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
struct St {
	ll x, ans;
};

ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, (a%b));

	/*while (a != b) {
	if (a > b)
	a = a - b;
	else
	b = b - a;
	}*/
}

St euclid(ll a, ll b) {
	ll s[3], t[3], r[3], q;
	s[0] = t[1] = t[2] = 1;
	s[1] = t[0] = s[2] = 0;
	r[0] = a;
	r[1] = b;
	r[2] = b;//b가 1일경우 꼬여서 초기 설정 필요 그래서 t[2],s[2]도 설정
	while (r[2]>1) {
		q = r[0] / r[1];
		r[2] = r[0] % r[1];
		s[2] = s[0] - q * s[1];
		t[2] = t[0] - q * t[1];
		for (int i = 0; i <= 1; i++) {
			s[i] = s[i + 1];
			t[i] = t[i + 1];
			r[i] = r[i + 1];
		}
	}
	return { s[2], t[2] };
}

int main() {
	ll a, b;
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%lld %lld", &a, &b);

		if (gcd(a, b) != 1)
			puts("IMPOSSIBLE");
		else {
			St st = euclid(a, b);
			//printf("%d %d\n", st.x, st.ans);
			while (st.ans <= 0 || st.x >= 0) {
				st.ans += a;
				st.x -= b;
			}
			if (st.ans > 1000000000L) puts("IMPOSSIBLE");
			else printf("%lld\n", st.ans);
		}
	}

	return 0;
}
