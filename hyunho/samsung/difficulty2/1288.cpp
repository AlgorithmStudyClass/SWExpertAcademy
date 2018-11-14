/*
1288. 새로운 불면증 치료법
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18_yw6I9MCFAZN&categoryId=AV18_yw6I9MCFAZN&categoryType=CODE

< input >
5
1
2
11
1295
1692
 

< output >
#1 10
#2 90
#3 110
#4 6475
#5 5076
 
 
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

	int totalNum = 0 ;
	scanf("%d" , &totalNum ) ;

	int i = 0 ;
	while( i < totalNum ) { 

		int numArr[10] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 } ;
		vector<int> answerVec( numArr , numArr + 10 ) ;
		vector<int> resultVec ;

		int num , tempNum = 0 ;
		scanf("%d" , &num ) ;

		while( true ) {

			sort( resultVec.begin(), resultVec.end() );
			if( answerVec == resultVec )
				break ;

			tempNum += num ;

			string stringNum = to_string( tempNum ) ;
			int size = stringNum.length() ;
			char *charNum = new char[ stringNum.length() + 1 ] ;
			strcpy( charNum , stringNum.c_str() ) ;

			for( int j = 0 ; j < size ; j++ ) {

				vector<int>::iterator iter;
				iter = find(resultVec.begin(), resultVec.end(), ( charNum[j] - 48 ) );
				if (iter == resultVec.end())
    				resultVec.push_back( charNum[j] - 48) ;
			}
		}

		printf("#%d %d\n" , ( i + 1 ) , tempNum ) ;

		i++ ;
	}

	return 0 ;
}











