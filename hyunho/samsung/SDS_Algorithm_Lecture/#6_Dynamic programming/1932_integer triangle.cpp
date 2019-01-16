/*
1932. 정수 삼각형
https://www.acmicpc.net/problem/1932

dp
*/

#include<iostream>
using namespace std ;

int n ;
int D[501][501] ;
int list[501][501] ;
int ans ;

int max( int a , int b ) {
	return ( a > b )? a : b ;
}

int main() {

	scanf("%d" , &n ) ;

	for( int i = 0 ; i < n ; i++ )
		D[i][0] = 0 ;

	for( int i = 0 ; i < n ; i++ ) {
		for( int j = 1 ; j <= i + 1 ; j++ )
			scanf("%d" , &list[i][j] ) ;
	}

	D[0][1] = list[0][1] ;
	for( int i = 1 ; i < n ; i++ ) {
		for( int j = 1 ; j <= i + 1 ; j++ ) {
			D[i][j] = max( D[i-1][j-1] , D[i-1][j] ) + list[i][j] ;

			if( i == n - 1 )
				ans = max( D[i][j] , ans ) ;
		}
	}

	printf("%d\n" , ans ) ;
	return 0 ;
}


















