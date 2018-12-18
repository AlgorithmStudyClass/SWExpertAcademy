/*
4047. 영준이의 카드 카운팅   D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIsY84KEPMDFAWN&categoryId=AWIsY84KEPMDFAWN&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

bool insert( int **cardArr , int n1 , int tmpNum ) {

    for( int i = 0 ; i < 13 ; i++ ) {

        if( cardArr[n1][i] == tmpNum )
            return false ;

        if( cardArr[n1][i] == -1 ) {
            cardArr[n1][i] = tmpNum ; break ;
        }
    }
    return true ;
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int **cardArr = new int*[4] ;
        for( int i = 0 ; i < 4 ; i++ ) {
            cardArr[i] = new int[13] ;
        }

        for( int i = 0 ; i < 4 ; i++ ) {
            for( int j = 0 ; j < 13 ; j++ )
                cardArr[i][j] = -1 ;
        }

        string tmpStr ;
        cin >> tmpStr ;

        int index = 0 ;
        char card ;
        char cardNum[3] = "" ;
        int flag = 0 ;
        for( int i = 0 ; i < tmpStr.length() ; i++ ) {

            if( i % 3 == 0 )  {

                if( tmpStr[i] == 'S' || tmpStr[i] == 'D' || tmpStr[i] == 'H' || tmpStr[i] == 'C' )
                    card = tmpStr[i] ;
                else {
                    flag = 1 ; break ;
                }
            }
            else {

                if( index == 1 ) {

                    cardNum[index] = tmpStr[i] ;
                    int tmpNum = atoi( cardNum ) - 1 ;
                    index = 0 ;

                    switch( card ) {
                        case 'S' : {
                            if( insert( cardArr , 0 , tmpNum ) ) {
                                continue ;
                            } else {
                                flag = 1 ; break ;
                            }
                            break ;
                        }
                        case 'D' : {
                            if( insert( cardArr , 1 , tmpNum ) ) {
                                continue ;
                            } else {
                                flag = 1 ; break ;
                            }
                            break ;
                        }
                        case 'H' : {
                            if( insert( cardArr , 2 , tmpNum ) ) {
                                continue ;
                            } else {
                                flag = 1 ; break ;
                            }
                            break ;
                        }
                        case 'C' : {
                            if( insert( cardArr , 3 , tmpNum ) ) {
                                continue ;
                            } else {
                                flag = 1 ; break ;
                            }
                            break ;
                        }
                        default : {
                            flag = 1 ;
                            break ;
                        }
                    }
                } else
                    cardNum[index++] = tmpStr[i] ;
            }
        }

        int *cardCnt = new int[4] ;
        for( int i = 0 ; i < 4 ; i++ )
            cardCnt[i] = 0 ;

        for( int i = 0 ; i < 4 ; i++ ) {
            for( int j = 0 ; j < 13 ; j++ ) {

                if( cardArr[i][j] == -1 )
                    cardCnt[i]++ ;
            }
        }

        if( flag == 0 ) {
            printf("#%d " , T ) ;
            for( int i = 0 ; i < 4 ; i++ )
                printf("%d " , cardCnt[i] ) ;
            printf("\n") ;
        } else {
            printf("#%d ERROR\n" , T ) ;
        }

        delete []cardCnt ;
        for( int i = 0 ; i < 4 ; i++ )
            delete []cardArr[i] ;
        delete []cardArr ;
    }
    return 0 ;
}



