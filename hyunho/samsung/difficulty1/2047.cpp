/*
2047. 신문 헤드라인
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QKsLaAy0DFAUq&categoryId=AV5QKsLaAy0DFAUq&categoryType=CODE

< input >
The_headline_is_the_text_indicating_the_nature_of_the_article_below_it.

< output >
THE_HEADLINE_IS_THE_TEXT_INDICATING_THE_NATURE_OF_THE_ARTICLE_BELOW_IT.
 
*/
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int main() {

	char inputText[81] = "" ;
	scanf("%s" , inputText ) ;

	string inputString = string( inputText ) ;
	int size = inputString.length() ;

	for( int i = 0 ; i < size ; i++ ) {

		if( inputText[i] >= 97 && inputText[i] <= 122 ) {
			inputText[i] = char( inputText[i] - ( 'a' - 'A' ) ) ;
		}
	}

	printf("%s\n" , inputText ) ;


	return 0 ;
}


