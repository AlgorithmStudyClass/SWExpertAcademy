/*
1644. 소수의 연속합
https://www.acmicpc.net/problem/1644

에라토스테네스의 체를 이용한 문제
*/

#include<iostream>
using namespace std ;

int N ;
int isPrime[4000001] ;
int prime[4000001] ;
int ans ;

int main() {

	scanf("%d" , &N ) ;

	for( int i = 2 ; i <= N ; i++ )
		isPrime[i] = 1 ;

	int index = 0 ;
	for( int i = 2 ; i <= N ; i++ ) {			//	소수를 적어서 가지고 있으려면 N 번 다 돌려야함

		if( isPrime[i] ) {
			prime[index++] = i ;
			for( int j = i ; j <= N / i ; j++ )
				isPrime[i*j] = 0 ;
		}
	}

	int s , e , sum ;
	s = e = sum = 0 ;

	while( s <= e && e < index ) {

		while( e < index && sum < N )
			sum += prime[e++] ;

		if( sum < N ) break ;

		while( s < e && sum > N )
			sum -= prime[s++] ;

		if( sum == N ) {
			ans++ ;
			sum -= prime[s++] ;
		}
	}

	printf("%d\n" , ans ) ;

	return 0 ;
}




