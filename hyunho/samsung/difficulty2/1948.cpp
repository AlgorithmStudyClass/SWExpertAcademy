/*
1948. 날짜 계산기
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PnnU6AOsDFAUq&categoryId=AV5PnnU6AOsDFAUq&categoryType=CODE

< input >
3 
3 1 3 31
5 5 8 15
7 17 12 24  
 
 

< output >
#1 31
#2 103
#3 161
 
 
 
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std ;

int main() {

	int maxDayArr[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 } ;

	int totalNum = 0 ;
	scanf("%d" , &totalNum ) ;

	int i = 0 ;
	while( i < totalNum ) {

		int Amonth , Adate = 0 ;
		int Bmonth , Bdate = 0 ;

		scanf("%d" , &Amonth ) ;
		scanf("%d" , &Adate ) ;
		scanf("%d" , &Bmonth ) ;
		scanf("%d" , &Bdate ) ;

		int resultDate = 0 ;
		if( Amonth == Bmonth )
			resultDate = Bdate - Adate + 1 ;
		else {

			resultDate += maxDayArr[ Amonth - 1 ] - Adate ;
			Amonth++ ;
			while( Amonth < Bmonth ) {

				resultDate += maxDayArr[ Amonth - 1 ] ;
				Amonth++ ;
			}
			resultDate += Bdate + 1 ;
		}

		printf("#%d %d\n", ( i + 1 ) , resultDate ) ;

		i++ ;
	}

	return 0 ;
}













