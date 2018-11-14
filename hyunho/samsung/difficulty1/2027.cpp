/*
2027. 대각선 출력하기
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QFuZ6As0DFAUq&categoryId=AV5QFuZ6As0DFAUq&categoryType=CODE&&&

< output >
#++++
+#+++
++#++
+++#+
++++#

*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int main() {

	char text[6] = "#++++" ;
	int i = 0 ;
	while( i < 5 ) {

		printf("%s\n" , text ) ;

		char tmpText[6] = "" ;
		strcpy ( tmpText , text ) ;

		char tmpChar = tmpText[4] ;

		for( int j = 0 ; j < 4 ; j++ ) {
			text[ j + 1 ] = tmpText[ j ] ;
		}
		text[0] = tmpChar ;

		i++ ;
	}

	return 0 ;
}


