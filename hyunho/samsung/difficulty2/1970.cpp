/*
1970. 쉬운 거스름돈
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PsIl6AXIDFAUq&categoryId=AV5PsIl6AXIDFAUq&categoryType=CODE

< input >
2 
32850
160   
 

< output >
#1
0 3 0 2 1 3 1 0
#2
0 0 0 0 0 1 1 1
 
 
 
 
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() { 

	int testSize = 0 ;
	scanf("%d" , &testSize ) ;

	int T = 0 ;
	while( T < testSize ) {

		int moneyArr[8] = { 50000 , 10000 , 5000 , 1000 , 500 , 100 , 50 , 10 } ;
		int moneyCnt[8] = { 0 } ;

		int money = 0 ;
		scanf("%d" , &money ) ;

		for( int i = 0 ; i < 8 ; i++ ) {
			moneyCnt[i] = money / moneyArr[i] ;
			money %= moneyArr[i] ;
		}

		printf("#%d\n" , ( T + 1 ) ) ;
		for( int i = 0 ; i < 8 ; i++ )
			printf("%d " , moneyCnt[i] ) ;
		printf( "\n" ) ;

		T++ ;
	}

	return 0 ;
}
























