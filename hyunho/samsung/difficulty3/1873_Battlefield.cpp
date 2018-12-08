/*
1873. 상호의 배틀필드  D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LyE7KD2ADFAXc&categoryId=AV5LyE7KD2ADFAXc&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std ;

void bang( string *info , int index1 , int index2 , char way , int H , int W ) {

    switch( way ) {

        case 'L' : {
            for( int j = index2 ; j >= 0 ; j-- ) {
                if( info[index1][j] == '*' ) {
                    info[index1][j] = '.' ; break ;
                } else if( info[index1][j] == '#' ) {
                    break ;
                }
            }
            break ;
        }
        case 'U' : {
            for( int i = index1 ; i >= 0 ; i-- ) {
                if( info[i][index2] == '*' ) {
                    info[i][index2] = '.' ; break ;
                } else if( info[i][index2] == '#' ) {
                    break ;
                }
            }
            break ;
        }
        case 'R' : {
            for( int j = index2 ; j < W ; j++ ) {
                if( info[index1][j] == '*' ) {
                    info[index1][j] = '.' ; break ;
                } else if( info[index1][j] == '#' ) {
                    break ;
                }
            }
            break ;
        }
        case 'D' : {
            for( int i = index1 ; i < H ; i++ ) {
                if( info[i][index2] == '*' ) {
                    info[i][index2] = '.' ; break ;
                } else if( info[i][index2] == '#' ) {
                    break ;
                }
            }
            break ;
        }
        default :
            break ;
    }

}

void changeInputStr( string &inputStr ) {

    for( int i = 0 ; i < inputStr.length() ; i++ ) {

        if( inputStr[i] == 'U' || inputStr[i] == 'D' || inputStr[i] == 'L' || inputStr[i] == 'R' || inputStr[i] == 'S' ) {
            inputStr[i] = '=' ;
            break ;
        }
    }
}

char getWay( string *info , int index1 , int index2 ) {

    char ch = info[index1][index2] ;

    switch( ch ) {

        case '<' :
            return 'L' ;
        case '^' :
            return 'U' ;
        case '>' :
            return 'R' ;
        case 'v' :
            return 'D' ;
        default :
            break ;
    }
    return '\0' ;
}

char getInputStr( string &inputStr ) {

    for( int i = 0 ; i < inputStr.length() ; i++ ) {

        if( inputStr[i] == 'U' || inputStr[i] == 'D' || inputStr[i] == 'L' || inputStr[i] == 'R' || inputStr[i] == 'S' )
            return inputStr[i] ;
        else
            continue ;
    }
    return '\0' ;
}

int getCurrent( string *info , int H , int W ) {

    for( int i = 0 ; i < H ; i++ ) {
        for( int j = 0 ; j < W ; j++ ) {

            if( info[i][j] == '^' || info[i][j] == '<' || info[i][j] == '>' || info[i][j] == 'v' )
                return i ;
        }
    }
    return 0 ;
}

int getCurrent2( string *info , int H , int W ) {

    for( int i = 0 ; i < H ; i++ ) {
        for( int j = 0 ; j < W ; j++ ) {

            if( info[i][j] == '^' || info[i][j] == '<' || info[i][j] == '>' || info[i][j] == 'v' )
                return j ;
        }
    }
    return 0 ;
}

bool check( string &inputStr ) {

    for( int i = 0 ; i < inputStr.length() ; i++ ) {

        if( inputStr[i] == 'U' || inputStr[i] == 'D' || inputStr[i] == 'L' || inputStr[i] == 'R' || inputStr[i] == 'S' )
            return true ;
        else
            continue ;
    }
    return false ;
}

void game( string *info , string &inputStr , int H , int W ) {

    while( check( inputStr ) ) {

        int index1 = getCurrent( info , H , W ) ;
        int index2 = getCurrent2( info , H , W ) ;
        char way = getWay( info , index1 , index2 ) ;
        char currentInput = getInputStr( inputStr ) ;

        switch( currentInput ) {

            case 'U' : {
                info[index1][index2] = '^' ;
                if( index1 - 1 >= 0 ) {

                    if( info[index1-1][index2] == '.' ) {
                        info[index1-1][index2] = '^' ;
                        info[index1][index2] = '.' ;
                    }
                }
                break ;
            }
            case 'D' : {
                info[index1][index2] = 'v' ;
                if( index1 + 1 < H ) {

                    if( info[index1+1][index2] == '.' ) {
                        info[index1+1][index2] = 'v' ;
                        info[index1][index2] = '.' ;
                    }
                }
                break ;
            }
            case 'L' : {
                info[index1][index2] = '<' ;
                if( index2 - 1 >= 0 ) {

                    if( info[index1][index2-1] == '.' ) {
                        info[index1][index2-1] = '<' ;
                        info[index1][index2] = '.' ;
                    }
                }
                break ;
            }
            case 'R' : {
                info[index1][index2] = '>' ;
                if( index2 + 1 < W ) {

                    if( info[index1][index2+1] == '.' ) {
                        info[index1][index2+1] = '>' ;
                        info[index1][index2] = '.' ;
                    }
                }
                break ;
            }
            case 'S' : {
                bang( info , index1 , index2 , way , H , W ) ;
                break ;
            }
            default :
                break ;
        }
        changeInputStr( inputStr ) ;
    }
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int H = 0 , W = 0 ;
        scanf("%d %d" , &H , &W ) ;

        string *info = new string[ H ] ;
        for( int i = 0 ; i < H ; i++ )
            cin >> info[i] ;

        int inputSize = 0 ;
        scanf("%d" , &inputSize ) ;
        string inputStr = "" ;
        cin >> inputStr ;

        game( info , inputStr , H , W ) ;

        printf("#%d " , T ) ;
        for( int i = 0 ; i < H ; i++ ) {
            for( int j = 0 ; j < W ; j++ )
                printf("%c" , info[i][j] ) ;
            printf("\n" ) ;
        }
        delete []info ;
    }
    return 0 ;
}







