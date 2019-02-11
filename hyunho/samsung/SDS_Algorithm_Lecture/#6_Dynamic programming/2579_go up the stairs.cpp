/*
2579. 계단 오르기
https://www.acmicpc.net/problem/2579

dp
*/

// #include<iostream>
// using namespace std ;

// int N ;
// int D[2][301] ;
// int list[301] ;
// int ans ;

// int max( int a , int b ) {
// 	return ( a > b )? a : b ;
// }

// int main() {

// 	scanf("%d" , &N ) ;

// 	for( int i = 1 ; i <= N ; i++ )
// 		scanf("%d" , &list[i] ) ;

// 	D[0][1] = list[1] ;
// 	D[1][1] = list[1] ;


// 	for( int i = 2 ; i <= N ; i++ ) {

// 		D[0][i] = max( D[0][i-2] , D[1][i-2] ) + list[i] ;
// 		D[1][i] = D[0][i-1] + list[i] ;

// 		if( i == N )
// 			ans = max( D[0][i] , D[1][i] ) ;
// 	}

// 	printf("%d\n" , ans ) ;
// 	return 0 ;
// }





#include<iostream>
using namespace std ;

int N ;
int list[301] ;
int D[3][301] ;	//	i번 연속 발고 j 번 째에 도달했을 때 최대 값
int ans ;

int max_func( int a , int b ) {
	return ( a > b ) ? a : b ;
}

int main() {

	scanf("%d" , &N ) ;

	for( int i = 1 ; i <= N ; i++ )
		scanf("%d" , &list[i] ) ;

	D[1][1] = list[1] ;
	D[2][1] = list[1] ;

	for( int j = 2 ; j <= N ; j++ ) {

		D[1][j] = max_func( D[1][j-2] , D[2][j-2] ) + list[j] ; 
		D[2][j] = D[1][j-1] + list[j] ;
	}

	ans = max_func( D[1][N] , D[2][N] ) ;
	printf("%d\n" , ans ) ;
	return 0 ;
}








































