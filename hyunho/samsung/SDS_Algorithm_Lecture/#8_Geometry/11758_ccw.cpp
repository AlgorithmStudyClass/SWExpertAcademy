/*
11758. ccw
https://www.acmicpc.net/problem/11758

기하
ccw
*/

#include<iostream>
using namespace std ;

struct col {
	int x , y ;
} ;

col list[3] ;

int main() {

	for( int i = 0 ; i < 3 ; i++ )
		scanf("%d %d" , &list[i].x , &list[i].y ) ;

	int ans = 0 ;
	int idx = 0 ;
	while( idx < 3 ) {

		ans += ( ( list[idx].x * list[ ( idx+1 ) % 3 ].y ) - ( list[ ( idx+1 ) % 3 ].x * list[idx].y ) ) ;

		idx++ ;
	}

	if( ans > 0 )
		printf("1\n" ) ;
	else if( ans == 0 )
		printf("0\n" ) ;
	else
		printf("-1\n" ) ;

	// printf("%d\n" , ans ) ;

	return 0 ;
}






