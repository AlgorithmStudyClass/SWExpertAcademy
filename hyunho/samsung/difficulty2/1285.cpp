/*
1285. 아름이의 돌 던지기 
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18-stqI8oCFAZN&categoryId=AV18-stqI8oCFAZN&categoryType=CODE

< input >
2
2
-100 100
3
-5 -1 3     
 
 

< output >
#1 100 2
#2 1 1
 
 
 
 
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

		int size = 0 ;
		scanf("%d" , &size ) ;

		int arr[size] ;
		for( int j = 0 ; j < size ; j++ )
			scanf("%d" , &arr[j] ) ;

		int gapArr[size] ;
		int minValue = 1000000 ;
		for( int j = 0 ; j < size ; j++ ) {
			gapArr[j] = abs( arr[j] - 0 ) ;
			minValue = min( minValue , gapArr[j] ) ;
		}

		int cnt = 0 ;
		for( int j = 0 ; j < size ; j++ ) {
			if( minValue == gapArr[j] )
				cnt++ ;
		}

		printf("#%d %d %d\n" , ( i + 1 ) , minValue , cnt ) ;
		i++ ;
	}

	return 0 ;
}
























