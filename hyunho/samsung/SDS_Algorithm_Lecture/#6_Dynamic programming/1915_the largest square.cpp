/*
1915. 가장 큰 정사각형
https://www.acmicpc.net/problem/1915

dp
*/

// #include<iostream>
// using namespace std ;

// int n , m ;
// int D[1001][1001] ;
// int list[1001][1001] ;
// int ans ;

// int min( int a , int b ) {
// 	return ( a > b )? b : a ;
// }

// int max( int a , int b ) {
// 	return ( a > b )? a : b ;
// }

// int main() {

// 	scanf("%d %d" , &n , &m ) ;

// 	string strNum ;
// 	for( int i = 1 ; i <= n ; i++ ) {

// 		cin >> strNum ;
// 		for( int j = 1 ; j <= strNum.length() ; j++ )
// 			list[i][j] = strNum[j-1] - '0' ;
// 	}

// 	for( int i = 0 ; i <= n ; i++ )
// 		D[i][0] = 0 ;
// 	for( int j = 0 ; j <= m ; j++ )
// 		D[0][j] = 0 ;


// 	for( int i = 1 ; i <= n ; i++ ) {
// 		for( int j = 1 ; j <= m ; j++ ) {

// 			if( list[i][j] == 0 )
// 				D[i][j] = 0 ;
// 			else {

// 				D[i][j] = min( D[i-1][j-1] , min( D[i-1][j] , D[i][j-1] ) ) + 1 ;
// 				ans = max( D[i][j] , ans ) ;
// 			}
// 		}
// 	}

// 	printf("%d\n" , ans * ans ) ;
// 	return 0 ;
// }






#include<iostream>
using namespace std ;

int n , m ;
int list[1001][1001] ;
int D[1001][1001] ;
int ans ;

int min_func( int a , int b ) {
	return ( a > b )? b : a ;
}

int max_func( int a , int b ) {
	return ( a > b )? a : b ;
}

int main() {

	scanf("%d %d" , &n , &m ) ;

	char str[1002] ;
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%s" , str ) ;
		for( int j = 1 ; j <= m ; j++ )
			list[i][j] = str[j-1] - '0' ;
	}

	for( int i = 1 ; i <= n ; i++ ) {
		for( int j = 1 ; j <= m ; j++ ) {

			if( list[i][j] != 0 ) {
				D[i][j] = min_func( D[i-1][j-1] , min_func( D[i-1][j] , D[i][j-1] ) ) + 1 ;
				ans = max_func( ans , D[i][j] ) ;
			}
		}
	}

	printf("%d\n" , ans * ans ) ;
	return 0 ;
}










































