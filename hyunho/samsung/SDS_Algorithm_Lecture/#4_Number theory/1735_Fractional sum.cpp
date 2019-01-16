/*
1735. 분수 합
https://www.acmicpc.net/problem/1735

유클리드 호제법
*/

#include<iostream>
using namespace std ;

int gcd( int a , int b ) {
	return ( b ) ? gcd( b , a % b ) : a ;
}

int main() {

	int a , b , c , d ;
	scanf( "%d %d" , &a , &b ) ;
	scanf( "%d %d" , &c , &d ) ;

	int wantA , wantB ;
	wantA = a * d + c * b ;
	wantB = b * d ;

	int result = gcd( wantA , wantB ) ;

	printf( "%d %d\n" , wantA / result , wantB / result ) ;
	return 0 ;
}





