/*
1859. 백만 장자 프로젝트
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE&&&

< input >
3
3
10 7 6
3
3 5 9
5
1 1 3 1 2


< output >
#1 0
#2 10
#3 5
 
 
 
 
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() { 

	int testSize = 0 ;
	scanf("%d" , &testSize ) ;

	int T = 0 ;
	while( T < testSize ) {

		int size = 0 ;
		scanf("%d" , &size ) ;

		vector<int> vecNum ;
		for( int i = 0 ; i < size ; i++ ) {
			int tmp = 0 ;
			scanf("%d" , &tmp ) ;
			vecNum.push_back( tmp ) ;
		}

		vector<long long int> vecLongLong ;

		while( !vecNum.empty() ) {

			int index = 0 ;
			int max = vecNum[0] ;
			for( int i = 0 ; i < vecNum.size() ; i++ ) {

				if( max < vecNum[i] ) {
					index = i ;
					max = vecNum[i] ;
				}
			}

			long long int sum = 0 ;
			for( int i = 0 ; i <= index ; i++ ) {

				if( i == index ) {
					vecNum.erase( vecNum.begin() , vecNum.begin() + ( i + 1 ) ) ;
					break ;
				}
				sum += ( max - vecNum[i] ) ;
			}
			vecLongLong.push_back( sum ) ;
		}

		long long int resultSum = 0 ;
		for( int i = 0 ; i < vecLongLong.size() ; i++ )
			resultSum += vecLongLong[i] ;

		printf("#%d %lld\n" , ( T + 1 ) , resultSum ) ;

		T++ ;
	}

	return 0 ;
}
























