/*
11062. 카드게임
https://www.acmicpc.net/problem/11062

dp ( top - down 방식 )
*/

#include<iostream>
#include<cstring>
using namespace std ;

int testSize ;
int N ;
int list[1001] ;
int D[1001][1001] ;

int max_func( int a , int b ) {
	return ( a > b ) ? a : b ;
}

int min_func( int a , int b ) {
	return ( a > b ) ? b : a ;
}

int solve( int l , int r ) { 

	if( l > r )
		return 0 ;

	if( D[l][r] != 0 )
		return D[l][r] ;

	if( ( N - ( l-r ) ) % 2 == 1 )
		D[l][r] =  max_func( solve( l+1 , r ) + list[l] , solve( l , r-1 ) + list[r] ) ;
	else
		D[l][r] = min_func( solve( l+1 , r ) , solve( l , r-1 ) ) ;

	return D[l][r] ;
}


int main() {

	scanf("%d" , &testSize ) ;

	int T = 0 ;
	while( T++ < testSize ) {

		scanf("%d" , &N ) ;
		for( int i = 1 ; i <= N ; i++ )
			scanf("%d" , &list[i] ) ;

		printf("%d\n" , solve( 1 , N ) ) ;

		memset( D , 0 , sizeof( D ) ) ;
	}
	return 0 ;
}



