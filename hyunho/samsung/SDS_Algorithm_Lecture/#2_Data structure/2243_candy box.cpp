/*
2243. 사탕 상자
https://www.acmicpc.net/problem/2243

index tree => sum tree 
사탕의 개수를 이용해서 풀이
*/

#include<iostream>
using namespace std ;

int N ;
int Nidx ;
int indexTree[1000000*4] ;

void update( int idx , int value ) {

	while( idx >= 1 ) {

		indexTree[idx] += value ;
		idx /= 2 ;
	}
}

int getNum( int b ) {

	int cur = 1 ;
	while( cur < Nidx ) {

		if( indexTree[cur*2] >= b )
			cur *= 2 ;
		else {
			b -= indexTree[cur*2] ;
			cur = cur * 2 + 1 ;
		}
	}
	update( cur , -1 ) ;
	return cur - Nidx + 1 ;
}

int main() {

	scanf("%d" , &N ) ;

	Nidx = 1 ;
	while( Nidx < 1000000 )
		Nidx *= 2 ;

	for( int i = 0 ; i < N ; i++ ) {

		int a , b , c ;
		scanf("%d" , &a ) ;

		if( a == 1 ) {	//	꺼낼때

			scanf("%d" , &b ) ;
			printf("%d\n" , getNum( b ) ) ;
		} else {	//	넣을때

			scanf("%d %d" , &b , &c ) ;
			update( Nidx + b - 1 , c ) ;
		}
	}
	return 0 ;
}











