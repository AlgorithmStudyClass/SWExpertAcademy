/*
5569. 출근 경로
https://www.acmicpc.net/problem/5569

dp	4차원배열
*/

#include<iostream>
using namespace std ;

int w , h ;
int D[2][2][101][101] ;

int main() {

	scanf("%d %d" , &w , &h ) ;

	for( int i = 1 ; i <= w ; i++ )
		D[0][0][i][1] = 1 ;
	for( int j = 1 ; j <= h ; j++ )
		D[1][0][1][j] = 1 ;

	for( int i = 2 ; i <= w ; i++ ) {
		for( int j = 2 ; j <= h ; j++ ) {

			D[0][0][i][j] += D[0][0][i-1][j] ;
			D[0][0][i][j] += D[0][1][i-1][j] ;

			D[0][1][i][j] += D[1][0][i-1][j] ;

			D[1][0][i][j] += D[1][0][i][j-1] ;
			D[1][0][i][j] += D[1][1][i][j-1] ;

			D[1][1][i][j] += D[0][0][i][j-1] ;

			D[0][0][i][j] %= 100000 ;
			D[0][1][i][j] %= 100000 ;
			D[1][0][i][j] %= 100000 ;
			D[1][1][i][j] %= 100000 ;
		}
	}

	int ans = ( D[0][0][w][h] + D[0][1][w][h] + D[1][0][w][h] + D[1][1][w][h] ) % 100000 ;
	printf("%d\n" , ans ) ;
	return 0 ;
}














