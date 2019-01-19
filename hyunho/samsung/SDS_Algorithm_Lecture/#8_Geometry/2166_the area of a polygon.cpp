/*
2166. 다각형의 면적
https://www.acmicpc.net/problem/2166

기하
면적( ccw 랑 완전 다른거 2차원 )
*/

#include<iostream>
#include<cmath>

using namespace std ;

struct Col {

	double x , y ;
} ;

int N ;
Col list[10001] ;

double func( double baseX , double baseY , Col col1 , Col col2 ) {

	// // cout << baseX << " , " << baseY << endl ;
	// // printf("%d %d\n" , col1.x , col1.y ) ;
	// // printf("%d %d\n" , col2.x , col2.y ) ;
	// // cout << endl ;

	// col1.x - baseX ;
	// col1.y - baseY ;

	// col2.x - baseX ;
	// col2.y - baseY ;

	return ( ( col1.x - baseX ) * ( col2.y - baseY ) - ( col1.y - baseY ) * ( col2.x - baseX ) ) / 2 ; 
}

int main() {

	scanf("%d" , &N ) ;

	for( int i = 0 ; i < N ; i++ )
		scanf("%lf %lf" , &list[i].x , &list[i].y ) ;

	double ans = 0 ;
	for( int i = 0 ; i < N ; i++ )
		ans += func( list[0].x , list[0].y  ,  list[i] , list[ (i+1) % N ] ) ;

	printf("%.1lf\n" , fabs(ans) ) ;
	return 0 ;
}















