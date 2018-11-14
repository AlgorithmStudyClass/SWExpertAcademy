/*
2056. 연월일 달력
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QLkdKAz4DFAUq&categoryId=AV5QLkdKAz4DFAUq&categoryType=CODE

< input >
5
22220228
20150002
01010101
20140230
11111111

< output >
#1 2222/02/28
#2 -1
#3 0101/01/01
#4 -1
#5 1111/11/11
 
*/
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int main() {

	string monthArr[12] = { "01" , "02" , "03" , "04" , "05" , "06" , "07" , "08" , "09" , "10" , "11" , "12" } ;
	int maxDayArr[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 } ;

	int size = 0 ;
	scanf("%d" , &size ) ;

	int i = 0 ;
	while( i < size ) {

		char tmpDate[8]  = "" ;
		scanf("%s" , tmpDate ) ;

		string dateString = string( tmpDate ) ;

		string year = dateString.substr( 0 , 4 ) ;
		string month = dateString.substr( 4 , 2 ) ;
		string tmpDay = dateString.substr( 6 ) ;
		int day = atoi( tmpDay.c_str() ) ;


		int index = -1 ;
		for( int j = 0 ; j < 12 ; j++ ) {
			if( monthArr[j] == month ) {
				index = j ;
				break ;
			}
		}


		if( index != -1 ) {

			if( day >= 1 && day <= maxDayArr[ index ] ) {
				printf( "#%d %s/%s/%s\n" , ( i + 1 ) , year.c_str() , month.c_str() , tmpDay.c_str() ) ;
			} else
				printf( "#%d %d\n" , ( i + 1 ) , -1 ) ;
		} else
			printf( "#%d %d\n" , ( i + 1 ) , -1 ) ;

		i++ ;
	}

	return 0 ;
}


