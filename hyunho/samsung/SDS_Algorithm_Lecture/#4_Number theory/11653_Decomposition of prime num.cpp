/*
11653. 소인수 분해
https://www.acmicpc.net/problem/11653

에라토스테네스의 체를 이용한 문제
*/

#include<iostream>
using namespace std ;

int N ;
int isPrime[10000001] ;
int prime[10000001] ;

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

	for( int i = 0 ; i < index ; i++ ) {

		while( N % prime[i] == 0 ) {
			printf("%d\n" , prime[i] ) ;
			N /= prime[i] ;
		}
	}

	return 0 ;
}




