/*
6439. ccw
https://www.acmicpc.net/problem/6439

기하
*/

#include<iostream>
using namespace std ;

struct Col {

	int x , y ;
} ;

int testSize ;
Col line[2] ;
Col rectangular[4] ;
int xstart , ystart , xend , yend , xleft , ytop , xright , ybottom ;

int max_func( int a , int b ) {
	return ( a > b )? a : b ;
}

int min_func( int a , int b ) {
	return ( a > b )? b : a ;
}

int ccw( Col A , Col B , Col C ) {

	// A.x , A.y
	// B.x , B.y
	// C.x , C.y

	return ( A.x*B.y + B.x*C.y + C.x*A.y ) - ( B.x*A.y + C.x*B.y + A.x*C.y ) ;
}

bool isCCW( Col A , Col B , Col C , Col D ) {	//	true -> 교차 한다 

	int first = ccw( A , B , C ) ;
	int second = ccw( A , B , D ) ;
	int third = ccw( C , D , A ) ;
	int fourth = ccw( C , D , B ) ;

	if( first*second <= 0 && third*fourth <= 0 ) {	//	교차높음

		if( first*second == 0 && third*fourth == 0 ) {
			if( A.x == B.x && A.x == C.x && A.x == D.x ) {
				if( max_func( A.y , B.y ) < min_func( C.y , D.y ) )
					return false ;
			} else {	//	x로 비교
				if( max_func( A.x , B.x ) < min_func( C.x , D.x ) )
					return false ;
			}
		} else
			return true ;
	} else
		return false ;	//	교차 x

	return true ;
}



int main() {

	scanf("%d" , &testSize ) ;

	int T = 0 ;
	while( T++ < testSize ) {

		scanf("%d %d %d %d %d %d %d %d" , &xstart , &ystart , &xend , &yend , &xleft , &ytop , &xright , &ybottom ) ;

		line[0].x = xstart ; line[0].y = ystart ;
		line[1].x = xend ; line[1].y = yend ;

		rectangular[0].x = xleft ; rectangular[0].y = ytop ;
		rectangular[1].x = xright ; rectangular[1].y = ybottom ;
		rectangular[2].x = xleft ; rectangular[2].y = ybottom ;
		rectangular[3].x = xright ; rectangular[3].y = ytop ;

		int flag = 0 ;
		for( int i = 0 ; i < 4 ; i++ ) {

			// printf( "%d %d , %d %d\n" , rectangular[i].x , rectangular[i].y , rectangular[ (i+1) % 4 ].x , rectangular[ (i+1) % 4 ].y ) ;

			if( i <= 1 ) {
				if( isCCW( line[0] , line[1] , rectangular[0] , rectangular[ (i+2) ]  ) )  {

					// printf("%d %d , %d %d , %d %d , %d %d\n" , line[0].x , line[0].y , line[1].x , line[1].y , rectangular[i].x , rectangular[i].y , rectangular[ (i+1) % 4 ].x , rectangular[ (i+1) % 4 ].y ) ;
					flag = 1 ;
					break ;
				}
			} else {
				if( isCCW( line[0] , line[1] , rectangular[1] , rectangular[ i ]  ) )  {

					// printf("%d %d , %d %d , %d %d , %d %d\n" , line[0].x , line[0].y , line[1].x , line[1].y , rectangular[i].x , rectangular[i].y , rectangular[ (i+1) % 4 ].x , rectangular[ (i+1) % 4 ].y ) ;
					flag = 1 ;
					break ;
				}
			}
		}

		int lineMinX , lineMinY , lineMaxX , lineMaxY ;
		lineMinX = lineMinY = 10000000 ;
		lineMaxX = lineMaxY = -1 ; 

		int rentangleMinX , rentangleMinY , rentangleMaxX , rentangleMaxY ;
		rentangleMinX = rentangleMinY = 10000000 ;
		rentangleMaxX = rentangleMaxY = -1 ; 

		for( int i = 0 ; i < 2 ; i++ ) {

			if( i < 2 ) {

				lineMinX = min_func( lineMinX , line[i].x ) ;
				lineMinY = min_func( lineMinY , line[i].y ) ;
				lineMaxX = max_func( lineMaxX , line[i].x ) ;
				lineMaxY = max_func( lineMaxY , line[i].y ) ;
			}

			rentangleMinX = min_func( rentangleMinX , rectangular[i].x ) ;
			rentangleMinY = min_func( rentangleMinY , rectangular[i].y ) ;
			rentangleMaxX = max_func( rentangleMaxX , rectangular[i].x ) ;
			rentangleMaxY = max_func( rentangleMaxY , rectangular[i].y ) ;
		}

		if( rentangleMinX < lineMinX && rentangleMinY < lineMinY && lineMaxX < rentangleMaxX && lineMaxY < rentangleMaxY )
			flag = 1 ;



		if( flag == 1 )
			printf("T\n" ) ;	//	교차
		else
			printf("F\n" ) ;	//	교차 x

	}
	return 0 ;
}







