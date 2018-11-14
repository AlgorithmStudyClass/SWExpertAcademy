/*
1926. 간단한 369게임
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PTeo6AHUDFAUq&categoryId=AV5PTeo6AHUDFAUq&categoryType=CODE

< input >
10    
 
 

< output >
1 2 - 4 5 - 7 8 - 10
 
 
 
 
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

void func( int n ) {

	string tmpString = to_string( n ) ;
	char *charNum = new char[ tmpString.length() + 1 ] ;
	strcpy( charNum , tmpString.c_str() ) ;

	int cnt = 0 ;
	for( int i = 0 ; i < strlen( charNum ) ; i++ ) {

		if( charNum[i] == '3' || charNum[i] == '6' || charNum[i] == '9' )
			cnt++ ;
	}

	if( cnt == 0 )
		printf( "%d " , n ) ;
	else {
		for( int i = 0 ; i < cnt ; i++ ) {
			printf( "-" ) ;
		}
		printf( " " ) ;
	}
}

int main() { 

	int inputNum = 0 ;
	scanf("%d" , &inputNum ) ;

	for( int i = 1 ; i <= inputNum ; i++ )
		func( i ) ;
	printf( "\n" ) ;

	return 0 ;
}
























