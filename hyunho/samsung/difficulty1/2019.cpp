/*
2019. 더블더블 
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QDEX6AqwDFAUq&categoryId=AV5QDEX6AqwDFAUq&categoryType=CODE

< input >
8

< output >
1 2 4 8 16 32 64 128 256

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

	int inputNum = 0 ;
	scanf("%d" , &inputNum ) ;

	int tmpNum = 1 ;

	int i = 0 ;
	while( i <= inputNum ) {

		printf("%d " , tmpNum ) ;

		tmpNum *= 2 ;

		i++ ;
	}
	printf("\n") ;
	return 0 ;
}


