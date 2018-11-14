/*
1936. 1대1 가위바위보
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PjKXKALcDFAUq&categoryId=AV5PjKXKALcDFAUq&categoryType=CODE

< input >
3 2

< output >
A

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

	int inputNumArr[2] = { 0 } ;
	for( int i = 0 ; i < 2 ; i++ )
		scanf("%d" , &inputNumArr[i] ) ;

	int flag = 0 ;

	if( inputNumArr[0] == 1 ) {
		if( inputNumArr[1] == 3 )
			flag = 1 ;
	} else if( inputNumArr[0] == 2 ) {
		if( inputNumArr[1] == 1 )
			flag = 1 ;
	} else {
		if( inputNumArr[1] == 2 )
			flag = 1 ;
	}

	if( flag == 0 )
		printf("%c\n" , 'B' ) ;
	else
		printf("%c\n" , 'A' ) ;

	return 0 ;
}


