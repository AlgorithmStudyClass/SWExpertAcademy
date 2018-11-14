/*
1284. 수도 요금 경쟁
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV189xUaI8UCFAZN&categoryId=AV189xUaI8UCFAZN&categoryType=CODE

< input >
2
9 100 20 3 10
8 300 100 10 250
 

< output >
#1 90
#2 1800
 
 
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

		int P , Q , R , S , W = 0 ;
		scanf("%d" , &P ) ;
		scanf("%d" , &Q ) ;
		scanf("%d" , &R ) ;
		scanf("%d" , &S ) ;
		scanf("%d" , &W ) ;

		int A , B = 0 ;

		A = W * P ;

		if( W <= R )	// 기본요금
			B = Q ;
		else
			B = Q + ( ( W - R ) * S ) ;

		int result = 0 ;
		if( A > B )
			result = B ;
		else
			result = A ;

		printf("#%d %d\n" , ( i + 1 ) , result ) ;

		i++ ;
	}

	return 0 ;

}













