/*
2748. 피보나치 수 2
https://www.acmicpc.net/problem/2748
*/

// #include<stdio.h>
// using namespace std ;

// int N = 0 ;
// long long int fibo[91] ;

// int main() {

//     scanf("%d" , &N ) ;

//     fibo[1] = 1 , fibo[2] = 1 ;
//     for( int i = 3 ; i <= N ; i++ )
//         fibo[i] = fibo[ i - 1 ] + fibo[ i - 2 ] ;

//     printf("%lld\n" , fibo[N] ) ;

//     return 0 ;
// }

#include<iostream>
using namespace std ;

int N ;
long long int list[91] ;

int main() {

	scanf("%d" , &N ) ;

	list[1] = 1 ;
	list[2] = 1 ;

	for( int i = 3 ; i <= N ; i++ )
		list[i] = list[i-2] + list[i-1] ;

	printf("%lld\n" , list[N] ) ;
	return 0 ;
}


//	재귀 방법
// #include<iostream>
// using namespace std ;

// int N ;
// long long int list[91] ;

// long long int fibo( int num ) {

// 	if( num == 1 || num == 2 )
// 		return 1 ;
// 	else if( list[num] != 0 )
// 		return list[num] ;
// 	else
// 		return fibo( num - 2 ) + fibo( num -1 ) ;
// }

// int main() {

// 	scanf("%d" , &N ) ;

// 	long long int ans = fibo( N ) ;

// 	printf("%lld\n" , ans ) ;
// 	return 0 ;
// }










