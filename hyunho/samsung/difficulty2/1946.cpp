/*
1946. 간단한 압축 풀기
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Psz16AYEDFAUq&categoryId=AV5Psz16AYEDFAUq&categoryType=CODE

< input >
1
3
A 10
B 7
C 5           
 
 
 

< output >
#1
AAAAAAAAAA
BBBBBBBCCC
CC
 
 
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
    scanf("%d" , &totalNum ) ;

    int i = 0 ;
    while( i < totalNum ) {

        int num = 0 ;
        scanf("%d" , &num ) ;

        char ch[num] ;
        int cntArr[num] ;

        for( int j = 0 ; j < num ; j++ ) {
            cin >> ch[j] ;
            scanf( "%d" , &cntArr[j] ) ;
        }

        vector<char> result ;

        for( int j = 0 ; j < num ; j++ ) {
            for( int k = 0 ; k < cntArr[j] ; k++ ) {
                result.push_back( ch[j] ) ;
            }
        }

        cout << "#" << ( i + 1 ) << " " << endl ;
        for( int j = 0 ; j < result.size() ; j++ ) {

            if( j % 10 == 0 && j != 0 )
                cout << endl ;

            cout << result[j] ;
        }
        cout << endl ;

        i++ ;
    }

    return 0 ;
}










