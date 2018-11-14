/*
1959. 두 개의 숫자열
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpoFaAS4DFAUq&categoryId=AV5PpoFaAS4DFAUq&categoryType=CODE

< input >
10
3 5
1 5 3
3 6 -7 5 4
7 6
6 0 5 5 -1 1 6
-4 1 8 7 -9 3
5 15
-8 4 6 -9 -1
-1 1 0 -2 10 10 0 2 5 2 10 7 -9 7 -8
11 20
3 -8 4 0 -1 -4 8 3 7 -3 1
3 10 0 1 10 0 -8 -6 9 -7 -1 1 -1 4 10 6 0 -8 -5 0
11 16
-6 0 -1 7 5 -1 -3 0 -9 8 4
0 -6 1 1 8 -8 0 -7 4 -7 -8 -2 1 4 0 -10
3 16
8 9 0
-4 9 -7 -1 -8 3 1 -6 -8 5 2 -7 -9 -10 8 9
11 3
3 -4 -7 7 -2 5 5 0 -2 -8 4
-1 1 3
14 6
-9 9 0 -7 8 10 7 -3 2 3 0 0 0 -2
8 1 -9 3 0 -7
17 10
-6 -1 -4 2 -5 1 -10 -9 8 -9 -6 1 10 0 -5 -8 1
7 6 2 7 -8 4 8 10 -2 9
11 9
8 6 -2 0 0 5 10 2 -10 -8 -10
10 -9 -7 -1 0 8 0 10 3


< output >
#1 30
#2 63
#3 140
#4 181
#5 63
#6 58
#7 22
#8 120
#9 96
#10 70

 
 
*/
#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

	int inputNum = 0 ;
	scanf("%d" , &inputNum ) ;

	int i = 0 ;
	while( i < inputNum ) {

		int size1 , size2 = 0 ;
		scanf("%d" , &size1 ) ;
		scanf("%d" , &size2 ) ;

		vector<int> A ;
		vector<int> B ;

		for( int j = 0 ; j < size1 ; j++ ) {
			int numA = 0 ;
			scanf("%d" , &numA ) ;
			A.push_back( numA ) ;
		}

		for( int j = 0 ; j <size2 ; j++ ) {
			int numB = 0 ;
			scanf("%d" , &numB ) ;
			B.push_back( numB ) ;
		}

		int maxSize = max( size1 , size2 ) ;
		int minSize = min( size1 , size2 ) ;
		int gap = maxSize - minSize + 1 ;

		int flag = -1 ;
		if( size1 < size2 )
			flag = 0 ;
		else
			flag = 1 ;

		int startIndex = 0 ;
		int endIndex = minSize ;
		vector<int> result ;
		for( int j = 0 ; j < gap ; j++ ) {	//	2번

			int sum = 0 ;
			for( int k = startIndex ; k < endIndex ; k++ ) {	//	4
				int tempResult = A[k] * B[k] ;
				sum += tempResult ;
			}
			result.push_back( sum ) ;

			if( flag == 0 )
				A.insert( A.begin() , 1 , 0 ) ;
			else
				B.insert( B.begin() , 1 , 0 ) ;

			startIndex++ ;
			endIndex++ ;
		}

		int maxResult = *max_element( result.begin() , result.end() ) ;

		printf( "#%d %d\n" , ( i + 1 ) , maxResult ) ;

		i++ ;
	}

	return 0 ;
}













