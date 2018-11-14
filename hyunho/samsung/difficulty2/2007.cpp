/*
2007. 패턴 마디의 길이
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P1kNKAl8DFAUq&categoryId=AV5P1kNKAl8DFAUq&categoryType=CODE

< input >
3       
KOREAKOREAKOREAKOREAKOREAKOREA
SAMSUNGSAMSUNGSAMSUNGSAMSUNGSA
GALAXYGALAXYGALAXYGALAXYGALAXY       
 
 

< output >
#1 5
#2 7
#3 6
 
 
 
 
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
	cin >> totalNum ;

	int i = 0 ;
	while( i < totalNum ) {

		string str ;
		cin >> str ;

		char *charStr = new char[ str.length() + 1 ] ;
		strcpy( charStr , str.c_str() ) ;

		int result = 0 ;
		for( int x = 0 , y = 1 ; y < str.length() ; y++ ) {

			if( charStr[x] == charStr[y] ) {

				if( x == 0 ) 	//	처음
					result = y ;

				x++ ;

			} else {
				result = 0 ;
				x = 0 ;
			}
		}

		cout << "#" << ( i + 1 ) << " " << result << endl ;
		i++ ;
	}

	return 0 ;
}
























