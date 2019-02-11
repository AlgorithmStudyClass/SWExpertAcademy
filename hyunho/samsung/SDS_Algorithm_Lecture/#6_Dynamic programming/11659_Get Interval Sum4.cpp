/*
11659. 구간의 합4
https://www.acmicpc.net/problem/11659

dp( index tree )
*/

// #include<iostream>
// using namespace std ;

// int N , M ;
// int tree[100000 * 4] ;
// int a , b ;

// int initTree() {

// 	for( int i = 0 ; i < N * 4 ; i++ )
// 		tree[i] = 0 ;

// 	int ret = 1 ;

// 	while( ret < N )
// 		ret *= 2 ;

// 	ret-- ;
// 	return ret ;
// }

// int sum( int s , int e ) {

// 	int ret = 0 ;
// 	while( s <= e ) {

// 		if( s % 2 == 1 )
// 			ret += tree[s] ;
// 		if( e % 2 == 0 )
// 			ret += tree[e] ;

// 		s = ( s + 1 ) / 2 ;
// 		e = ( e - 1 ) / 2 ;
// 	}

// 	return ret ;
// }

// int main() {

// 	scanf("%d %d" , &N , &M ) ;

// 	int idx = initTree() ;

// 	for( int i = 1 ; i <= N ; i++ )
// 		scanf("%d" , &tree[idx+i] ) ;

// 	for( int i = idx ; i >= 0 ; i-- )
// 		tree[i] = tree[i*2] + tree[i*2+1] ;

// 	for( int i = 0 ; i < M ; i++ ) {

// 		scanf("%d %d" , &a , &b ) ;
// 		printf("%d\n" , sum( idx + a , idx + b ) ) ;
// 	}

// 	return 0 ;

// }


#include<iostream>
using namespace std ;

int N , M ;
int indexTree[ 100000 * 4 ] ;
int ans ;

int main() {

	scanf("%d %d" , &N , &M ) ;

	int tidx = 1 ;
	while( tidx < N )
		tidx *= 2 ;

	for( int i = tidx ; i < tidx + N ; i++ )
		scanf("%d" , &indexTree[i] ) ;

	for( int i = tidx - 1 ; i >= 1 ; i-- )
		indexTree[i] = indexTree[i*2] + indexTree[i*2 + 1] ;

	for( int i = 0 , a , b ; i < M ; i++ ) {

		scanf("%d %d" , &a , &b ) ;

		int s = a + tidx - 1 ;
		int e = b + tidx - 1 ;

		ans = 0 ;
		while( s <= e ) {

			if( s % 2 == 1 )
				ans += indexTree[s] ;

			if( e % 2 == 0 )
				ans += indexTree[e] ;

			s = ( s + 1 ) / 2 ;
			e = ( e - 1 ) / 2 ;
		}
		printf("%d\n" , ans ) ;
	}
	return 0 ;
}

































