/*
1986. 지그재그 숫자
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PxmBqAe8DFAUq&categoryId=AV5PxmBqAe8DFAUq&categoryType=CODE

< input >
2
5
6
 

< output >
#1 3
#2 -3
 
 
 
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std ;

int main() {

	int totalNum = 0 ;
	scanf("%d" , &totalNum ) ;

	int i = 0 ;
	while( i < totalNum ) {

		int num = 0 ;
		scanf("%d" , &num ) ;

		int sum = 0 ;
		for( int j = 0 ; j <= num ; j++ ) {

			if( j % 2 == 0 )	//	짝수
				sum -= j ;
			else				//	홀수
				sum += j ;
		}

		printf("#%d %d\n" , ( i + 1 ) , sum ) ;

		i++ ;
	}

	return 0 ;

}













