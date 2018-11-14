/*
2001. 파리 퇴치
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PzOCKAigDFAUq&categoryId=AV5PzOCKAigDFAUq&categoryType=CODE

< input >
2
5 2
1 3 3 6 7
8 13 9 12 8
4 16 11 12 6
2 4 1 23 2
9 13 4 7 3
6 3
29 21 26 9 5 8
21 19 8 0 21 19
9 24 2 11 4 24
19 29 1 0 21 19
10 29 6 18 4 3
29 11 15 3 3 29  
 
 

< output >
#1 49
#2 159
 
 
 
 
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

		int N = 0 , M = 0 ;
		scanf("%d %d" , &N , &M ) ;

		int arr[15][15] = { 0 } ;
		for( int j = 0 ; j < N ; j++ )
			for( int k = 0 ; k < N ; k++ )
				scanf("%d" , &arr[j][k] ) ;

		vector<int> vecSum ;
		int maxValue = 0 ;

		for( int j = 0 ; j <= N - M ; j++ ) {
			for( int k = 0 ; k <= N - M ; k++ ) {

				int sum = 0 ;
				for( int a = j ; a < j + M ; a++ ) {
					for( int b = k ; b < k + M ; b++ )
						sum += arr[a][b] ;
				}
				maxValue = max( maxValue , sum ) ;
			}
		}
		
		printf("#%d %d\n" , ( i + 1 ) , maxValue ) ;
		i++ ;
	}

	return 0 ;
}
























