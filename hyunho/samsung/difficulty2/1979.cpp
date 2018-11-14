/*
1979. 어디에 단어가 들어갈 수 있을까
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PuPq6AaQDFAUq&categoryId=AV5PuPq6AaQDFAUq&categoryType=CODE

< input >
1
5 3
0 0 1 1 1
1 1 1 1 0
0 0 1 0 0
0 1 1 1 1
1 1 1 0 1  
 
 

< output >
#1 2
 
 
 
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int arr[16][16] ;
int N = 0 , K = 0 ;

int main() { 

	int totalNum = 0;
	scanf("%d" , &totalNum ) ;

	int i = 0 ;
	while( i < totalNum ) { 

		scanf("%d" , &N ) ;
		scanf("%d" , &K ) ;

		for( int j = 0 ; j < N ; j++ ) {
			for( int k = 0 ; k < N ; k++ )
				scanf("%d" , &arr[j][k] ) ;
		}

		int flag = 0 , cnt = 0 ;
		for( int j = 0 ; j < N ; j++ ) {
			flag = 0 ;
			for( int k = 0 ; k < N ; k++ ) {
				if( arr[j][k] == 1 )
					flag++ ;
				else {
					if( flag == K ) {
						cnt++ ;
					}
					flag = 0 ;
				}
			}
			if( flag == K )
				cnt++ ;
		}

		for( int k = 0 ; k < N ; k++ ) {
			flag = 0 ;
			for( int j = 0 ; j < N ; j++ ) {
				if( arr[j][k] == 1 )
					flag++ ;
				else {
					if( flag == K ) {
						cnt++ ;
					}
					flag = 0 ;
				}
			}
			if( flag == K )
				cnt++ ;
		}

		printf("#%d %d\n" , ( i + 1 ) , cnt ) ;

		i++ ;
	}

	return 0 ;
}




