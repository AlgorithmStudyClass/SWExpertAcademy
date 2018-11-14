/*
1984. 중간 평균값 구하기
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pw_-KAdcDFAUq&categoryId=AV5Pw_-KAdcDFAUq&categoryType=CODE

< input >
3      
3 17 1 39 8 41 2 32 99 2 
22 8 5 123 7 2 63 7 3 46 
6 63 2 3 58 76 21 33 8 1   
   
 
 

< output >
#1 18
#2 20
#3 24
 
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std ;

int main() {

	int testSize = 0 ;
	scanf("%d" , &testSize ) ;

	int T = 0 ;
	while( T < testSize ) {

		int arr[10] ;
		for( int i = 0 ; i < 10 ; i++ )
			scanf("%d" , &arr[i] ) ;

		sort( arr , arr + 10 ) ;

		int sum = 0 ;
		for( int i = 1 ; i < 9 ; i++ )
			sum += arr[i] ;

		double result = double( sum / 8.0 ) ;

		printf("#%d %0.f\n" , ( T + 1 ) , result ) ;

		T++ ;
	}

	return 0 ;
}
























