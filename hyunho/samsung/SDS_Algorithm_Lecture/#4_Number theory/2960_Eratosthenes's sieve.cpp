/*
2960. 에라토스테네스의 체
https://www.acmicpc.net/problem/2960

에라토스테네스의 체
*/

#include<iostream>
using namespace std ;

int N , K ;
int primeNumArr[1001] ;
int ans ;

int main() {

	scanf("%d %d" , &N , &K ) ;

	for( int i = 2 ; i <= N ; i++ )
		primeNumArr[i] = 1 ;

	int cnt = 0 ;
	for( int i = 2 ; i <= N ; i++ ) {

		if( primeNumArr[i] ) {
			for( int j = 1 ; j <= N / i ; j++ ) {

				if( primeNumArr[i*j] == 1 ) {
					primeNumArr[i*j] = 0 ;
					cnt++ ;
					if( cnt == K ) {
						ans = i*j ;
						break ;
					}
				}
			}
		}

		if( ans != 0 ) break ;
	}

	printf("%d\n" , ans ) ;

	return 0 ;
}












