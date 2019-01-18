/*
2098. 외판원 순회
https://www.acmicpc.net/problem/2098

< TSP >
BackTracking
DP
Bit
*/

#include<iostream>
using namespace std ;
#define INF (int)1e9

int N ;
int list[17][17] ;
int D[17][( 1 << 16 )] ;

int min_func( int a , int b ) {
	return ( a > b ) ? b : a ;
}

int tsp( int cur , int s ) {

	if( s == ( 1 << N ) - 1 ) {
		
		if( list[cur][0] == 0 )	//	길 없음
			return INF ;
		else
			return list[cur][0] ;
	}

	if( D[cur][s] != INF )
		return D[cur][s] ;

	for( int i = 0 ; i < N ; i++ ) {

		if( ( s & (1 << i) ) == 0 && list[cur][i] != 0  )
			D[cur][s] = min_func( D[cur][s] , tsp( i , ( s | ( 1 << i ) ) ) + list[cur][i] ) ;
	}

	return D[cur][s] ;
}

int main() { 

	scanf("%d" , &N ) ;

	for( int i = 0 ; i < N ; i++ ) {
		for( int j = 0 ; j < N ; j++ )
			scanf("%d" , &list[i][j] ) ;
	}

	for( int i = 0 ; i < N ; i++ ) {
		for( int j = 0 ; j < ( 1 << N ) ; j++ )
			D[i][j] = INF ;
	}

	printf("%d\n" , tsp( 0 , 1 ) ) ;

	return 0 ;
}




