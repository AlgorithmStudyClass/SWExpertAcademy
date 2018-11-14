/*
1983. 조교의 성적 매기기
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PwGK6AcIDFAUq&categoryId=AV5PwGK6AcIDFAUq&categoryType=CODE

< input >
1
10 2
87 59 88
99 94 78
94 86 86
99 100 99
69 76 70
76 89 96
98 95 96
74 69 60
98 84 67
85 84 91   
 
 

< output >
#1 A-
 
 
 
 
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

string func( double *arr  , int n1 , int n2 ) {

	double findScore = 0 ;
	for( int i = 0 ; i < n1 ; i++ ) {

		int exam1 = 0 , exam2 = 0 , quiz = 0 ;
		scanf("%d%d%d" , &exam1 , &exam2 , &quiz ) ;

		double totalScore = exam1 * 0.35 + exam2 * 0.45 + quiz * 0.2 ;
		arr[i] = totalScore ;

		if( i == n2 - 1 )
			findScore = totalScore ;
	}
	sort( arr , arr + n1 , greater<double>() ) ;

	int findIndex = 0 ;
	for( int i = 0 ; i < n1 ; i++ ) {

		if( arr[i] == findScore )
			findIndex = i ;
	}

	int equalSize = n1 / 10 ;
	string grade[10] = { "A+" , "A0" , "A-" , "B+" , "B0" , "B-" , "C+" , "C0" , "C-" , "D0" } ;
	string *resultGrade = new string[n1] ;

	int cnt = 0 ;
	for( int x = 0 , i = 0 ; i < n1 ; i++ ) {

		if( cnt == equalSize ) {
			cnt = 0 ;
			x++ ;
		}
		resultGrade[i] = grade[x] ;
		cnt++ ;
	}

	return resultGrade[findIndex] ;
}

int main() {

	int testSize = 0 ;
	scanf("%d" , &testSize ) ;

	int T = 0 ;
	while( T < testSize ) {

		int N = 0 , K = 0 ;
		scanf("%d%d" , &N ,&K ) ;

		double *arr = new double[ N ] ;

		string result = func( arr , N , K ) ;

		printf("#%d %s\n" , ( T + 1 ) , result.c_str() ) ;
		
		T++ ;
	}

	return 0 ;
}
























