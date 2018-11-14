/*
4751. 다솔이의 다이아몬드 장식
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWSNw5jKzwMDFAUr&categoryId=AWSNw5jKzwMDFAUr&categoryType=CODE
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
    while( T++ < testSize ) {

        char text[51] = "" ;
        scanf("%s" , &text ) ;

        string str1 = "" ;
        string str2 = "" ;
        string str3 ="" ;
        for( int i = 0 ; i < strlen( text ) ; i++ ) {

            if( i == 0 )
                str1.append( "..#" ) ;
            else
                str1.append( "...#" ) ;
            
            str2.append( ".#.#" ) ;
            str3.append( "#." ) ; str3 += text[i] ; str3.append( "." ) ;
        }
        str1.append( ".." ) ;
        str2.append( "." ) ;
        str3.append( "#" ) ;


        printf("%s\n" , str1.c_str() ) ;
        printf("%s\n" , str2.c_str() ) ;
        printf("%s\n" , str3.c_str() ) ;
        printf("%s\n" , str2.c_str() ) ;
        printf("%s\n" , str1.c_str() ) ;
    }
    return 0 ;
}






















