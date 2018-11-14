/*
1976. 시각 덧셈
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PttaaAZIDFAUq&categoryId=AV5PttaaAZIDFAUq&categoryType=CODE

< input >
3 
3 17 1 39
8 22 5 10
6 53 2 12       

< output >
#1 4 56
#2 1 32
#3 9 5
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() { 

	int totalNum = 0 ;
	scanf("%d" , &totalNum ) ;

	int i = 0 ;
	while( i < totalNum ) {

		int hourArr[2] = { 0 } ;
		int minArr[2] = { 0 } ; 
		for( int j = 0 ; j < 2 ; j++ ) {
			scanf("%d" , &hourArr[j] ) ;
			scanf("%d" , &minArr[j] ) ;
		}

		int sumHour = 0 ;
		int sumMin = 0 ;
		for( int j = 0 ; j < 2 ; j++ ) {
			sumHour += hourArr[j] ;
			sumMin += minArr[j] ;
		}

		int share = 0 , rest = 0 ;
		if( sumMin >= 60 ) {
			sumHour += sumMin / 60 ;
			sumMin = sumMin % 60 ;
		}

		if( sumHour >= 13 )
			sumHour = ( sumHour % 13 ) + 1 ;

		printf("#%d %d %d\n" , ( i + 1 ) , sumHour , sumMin ) ;

		i++ ;
	}
	return 0 ;
}
























