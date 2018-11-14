/*
 1215. [S/W 문제해결 기본] 3일차 - 회문1
 https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14QpAaAAwCFAYi&categoryId=AV14QpAaAAwCFAYi&categoryType=CODE#
 */

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;


bool check( char arr[8][8] , int n1 , int n2 , int n3 , int n4 ) {

    char charA[8] = "";
    char charB[8] = "";

    int index = 0 ;
    for( int i = n2 ; i <= n4 ; i++) {

    	 charA[index++] = arr[n1][i] ;
    }
 
    for( int i = 0 ; i < n4 - n2 + 1 ; i++ )
        charB[i] = charA[ ( n4 - n2 ) - i ] ;
    
    if( strcmp( charA , charB ) == 0  )
        return true ;
    else
        return false ;
}


int main() {
    
    int testSize = 10 ;
    
    int T = 0 ;
    while( T < testSize ) {
        
        int size = 0 ;
        scanf("%d" , &size ) ;
        
        char arr[8][8] ;
        for( int i = 0 ; i < 8 ; i++ )
            for( int j = 0 ; j < 8 ; j++ )
                cin >> arr[i][j] ;

        char arr2[8][8] ;
        for( int j = 0 ; j < 8 ; j++ )
            for( int i = 0 ; i < 8 ; i++ )
                arr2[i][j] = arr[j][i] ;
        
        int cnt = 0 ;
        for( int i = 0 ; i < 8 ; i++ ) {
            for( int j = 0 ; j < ( 8 - size ) + 1 ; j++ ) {
                
                int y = j + size - 1 ;
                if( arr[i][j] == arr[i][y]) {
                    if( check( arr, i , j , i , y ) ) {
                    	//	[i][j]  ~ [i][y]
                        cnt++ ;
                    }
                }
            }
        }

        for( int i = 0 ; i < 8 ; i++ ) {
            for( int j = 0 ; j < ( 8 - size ) + 1 ; j++ ) {
                
                int y = j + size - 1 ;
                if( arr2[i][j] == arr2[i][y]) {
                    if( check( arr2, i , j , i , y ) ) {
                    	//	[i][j]  ~ [i][y]
                        cnt++ ;
                    }
                }
            }
        }
        
        cout << "#" << ( T + 1 ) << " " << cnt << endl ;
        
        T++ ;
    }
  
  	return 0 ;
}
























