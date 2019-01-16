/*
2579. 계단 오르기
https://www.acmicpc.net/problem/2579

dp
*/

#include<iostream>
using namespace std ;

int N ;
int D[2][301] ;
int list[301] ;
int ans ;

int max( int a , int b ) {
	return ( a > b )? a : b ;
}

int main() {

	scanf("%d" , &N ) ;

	for( int i = 1 ; i <= N ; i++ )
		scanf("%d" , &list[i] ) ;

	D[0][1] = list[1] ;
	D[1][1] = list[1] ;


	for( int i = 2 ; i <= N ; i++ ) {

		D[0][i] = max( D[0][i-2] , D[1][i-2] ) + list[i] ;
		D[1][i] = D[0][i-1] + list[i] ;

		if( i == N )
			ans = max( D[0][i] , D[1][i] ) ;
	}

	printf("%d\n" , ans ) ;
	return 0 ;
}











