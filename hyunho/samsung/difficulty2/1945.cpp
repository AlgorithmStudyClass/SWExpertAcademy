/*
1945. 간단한 소인수분해 
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pl0Q6ANQDFAUq&categoryId=AV5Pl0Q6ANQDFAUq&categoryType=CODE&&&

< input >
10  
6791400
1646400
1425600
8575
185625
6480
1185408
6561
25
330750

< output >
#1 3 2 2 3 1
#2 6 1 2 3 0
#3 6 4 2 0 1
#4 0 0 2 3 0
#5 0 3 4 0 1
#6 4 4 1 0 0
#7 7 3 0 3 0
#8 0 8 0 0 0
#9 0 0 2 0 0
#10 1 3 3 2 0
 
 
*/
#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
using namespace std ;

int main() {

	int inputNum = 0 ;
	scanf("%d" , &inputNum ) ;

	int arr[5] = { 2 , 3 , 5 , 7 , 11 } ;
	vector<int> prime( arr , arr + 5 ) ;

	int i = 0 ;
	while( i < inputNum ) {

		int num = 0 ;
		scanf("%d" , &num ) ;

		int cntArr[5] = { 0 } ;

		while( num != 1 ) {

			if( num % 2 == 0 ) {
				cntArr[0]++ ;
				num /= 2 ;
			}
			if( num % 3 == 0 ) {
				cntArr[1]++ ;
				num /= 3 ;
			}
			if( num % 5 == 0 ) {
				cntArr[2]++ ;
				num /= 5 ;
			}
			if( num % 7 == 0 ) {
				cntArr[3]++ ;
				num /= 7 ;
			}
			if( num % 11 == 0 ) {
				cntArr[4]++ ;
				num /= 11 ;
			}
		}


		printf("#%d " , ( i + 1 ) ) ;

		for( int j = 0 ; j < 5 ; j++ )
			printf("%d " , cntArr[j] ) ;

		printf("\n") ;

		i++ ;
	}

	return 0 ;

}













