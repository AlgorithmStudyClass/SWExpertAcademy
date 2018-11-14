/*
2050. 알파벳을 숫자로 변환
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QLGxKAzQDFAUq&categoryId=AV5QLGxKAzQDFAUq&categoryType=CODE

< input >
ABCDEFGHIJKLMNOPQRSTUVWXYZ

< output >
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
 
*/
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int main() {

	char inputText[201] ;
	scanf("%s" , inputText ) ;

	 string inputString = string( inputText ) ;
	 int size = inputString.length() ;

	 for( int i = 0 ; i < size ; i++ ) {
	 	printf( "%d " , ( inputText[i] - 64 )  ) ; 
	 }

	 printf( "\n" ) ;

	return 0 ;
}


