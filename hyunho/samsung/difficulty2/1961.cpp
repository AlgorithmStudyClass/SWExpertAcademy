/*
1961. 숫자 배열 회전
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pq-OKAVYDFAUq&categoryId=AV5Pq-OKAVYDFAUq&categoryType=CODE

< input >
2
3
1 2 3
4 5 6
7 8 9
6
6 9 4 7 0 5
8 9 9 2 6 5
6 8 5 4 9 8
2 2 7 7 8 4
7 5 1 9 7 9
8 9 3 9 7 6     

< output >
#1
741 987 369
852 654 258
963 321 147
#2
872686 679398 558496
952899 979157 069877
317594 487722 724799
997427 894586 495713
778960 562998 998259
694855 507496 686278
 
 
 
 
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

		int N = 0 ;
		scanf("%d" , &N ) ;

		int arr[N][N] ;

		for( int j = 0 ; j < N ; j++ ) {
			for( int k = 0 ; k < N ; k++ ) {
				int num = 0 ;
				scanf("%d" , &num) ;
				arr[j][k] = num ;
			}
		}

		string resultArr[N][3] ;

		int A[N] ;
		int B[N] ;
		int C[N] ;

		for( int j = 0 ; j < N ; j++ ) {

			string tmp ;
			for( int k = N - 1 ; k >= 0 ; k-- )
				tmp.append( to_string(arr[k][j]) ) ;
			resultArr[j][0] = tmp ;
		}

		for( int j = N - 1 ; j >= 0 ; j-- ) {

			string tmp ;
			for( int k = N - 1 ; k >= 0 ; k-- )
				tmp.append( to_string( arr[j][k]) ) ;
			resultArr[ N - ( j + 1 )][1] = tmp ;
		}

		for( int j = N - 1 ; j >= 0 ; j-- ) {

			string tmp ;
			for( int k = 0 ; k < N ; k++ )
				tmp.append( to_string(arr[k][j]) ) ;
			resultArr[ N - ( j + 1 )][2] = tmp ;
		}

		printf("#%d\n" , ( i + 1 ) ) ;
		for( int j = 0 ; j < N ; j++ ) {
			for( int k = 0 ; k < 3 ; k++ )
				printf("%s " , resultArr[j][k].c_str() ) ;
			printf("\n") ;
		}

		i++ ;
	}
	return 0 ;
}









