/*
2618. 경찰차
https://www.acmicpc.net/problem/2618

dp
*/

#include<iostream>
using namespace std ;

struct Col {

	int x , y ;
} ;

int N , W ;
Col list[1001] ;
int D[1001][1001] ;
int P[1001] ;

int max_func( int a , int b ) {
	return ( a > b )? a : b ;
}

int distance( int x , int next ) {

	int fromX = list[x].x ;
	int fromY = list[x].y ;

	int toX = list[next].x ;
	int toY = list[next].y ;

	return abs( toX - fromX ) + abs( toY - fromY ) ;
}

int func( int x , int y ) {

	if( x == W || y == W )
		return 0 ;

	if( D[x][y] != 0 )
		return D[x][y] ;

	int next = max_func( x , y ) + 1 ;
	int next1 , next2 ;

	if( x == 0 )
		next1 = func( next , y ) + ( ( list[next].x - 1 ) + ( list[next].y - 1 ) ) ;
	else
		next1 = func( next , y ) + distance( x , next ) ;

	if( y == 0 )
		next2 = func( x , next ) + ( ( N - list[next].x ) + ( N - list[next].y ) ) ;
	else
		next2 = func( x , next ) + distance( y , next ) ;


	if( next1 < next2 ) {
		D[x][y] = next1 ;
		P[next] = 1 ;
	} else {
		D[x][y] = next2 ;
		P[next] = 2 ;
	}

	return D[x][y] ;
}

int main() {

	scanf("%d" , &N ) ;
	scanf("%d" , &W ) ;

	for( int i = 1 ; i <= W ; i++ )
		scanf("%d %d" , &list[i].x , &list[i].y ) ;

	printf("%d\n" , func( 0 , 0 ) ) ;

	for( int i = 1 ; i <= W ; i++ ) 
		printf("%d\n" , P[i] ) ;

	return 0 ;
}









