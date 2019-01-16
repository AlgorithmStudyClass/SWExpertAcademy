/*
6588. 골드바흐의 추측
https://www.acmicpc.net/problem/6588

에라토스테네스의 체를 이용한 문제
*/

#include<iostream>
using namespace std ;

int N ;
int isPrime[1000001] ;
int prime[1000001] ;

int main() {

	for( int i = 2 ; i <= 1000001 ; i++ )
		isPrime[i] = 1 ;

	int index = 0 ;
	for( int i = 2 ; i <= 1000001 ; i++ ) {			//	소수를 적어서 가지고 있으려면 N 번 다 돌려야함

		if( isPrime[i] ) {
			prime[index++] = i ;
			for( int j = i ; j <= 1000001 / i ; j++ ) {

				isPrime[i*j] = 0 ;
			}
		}
	}

	while( true ) {

		scanf("%d" , &N ) ;
		if( N == 0 ) break ;

		for( int i = 0 ; i < index ; i++ ) {

			if( isPrime[ N - prime[i] ] ) {
				printf("%d = %d + %d\n" , N , prime[i] , N - prime[i] ) ;
				break ;
			}
		}
	}

	return 0 ;
}












