/*
1974. 스도쿠 검증
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Psz16AYEDFAUq&categoryId=AV5Psz16AYEDFAUq&categoryType=CODE

< input >
1
7 3 6 4 2 9 5 8 1
5 8 9 1 6 7 3 2 4
2 1 4 5 8 3 6 9 7
8 4 7 9 3 6 1 5 2
1 5 3 8 4 2 9 7 6
9 6 2 7 5 1 8 4 3
4 2 1 3 9 8 7 6 5
3 9 5 6 7 4 2 1 8
6 7 8 2 1 5 4 3 9
 
 

< output >
#1 1
 
 
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int a[9][9];
double ch[10];
 
int search() {
    int num;
    //가로검사
    for (int i = 0; i < 9; i++) {
        memset(ch, false, sizeof(ch));
        for (int j = 0; j < 9; j++) {
            num = a[i][j];
            if (ch[num]) {
                return 0;
            }
            else {
                ch[num] = true;
            }
        }
    }
    //세로검사
    for (int j = 0; j < 9; j++) {
        memset(ch, false, sizeof(ch));
        for (int i = 0; i < 9; i++) {
            num = a[i][j];
            if (ch[num]) {
                return 0;
            }
            else {
                ch[num] = true;
            }
        }
    }
    //사각형 검사
    for (int stx = 0; stx < 9; stx += 3) {
        for (int sty = 0; sty < 9; sty += 3) {
            memset(ch, false, sizeof(ch));
            for (int i = stx; i < stx + 2; i++) {
                for (int j = sty; j < sty + 2; j++) {
                    num = a[i][j];
                    if (ch[num]) {
                        return 0;
                    }
                    else {
                        ch[num] = true;
                    }
                }
            }
        }
    }
    return 1;
}
 
 
int main()
{   
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        printf("#%d %d\n", t, search());
    }
    return 0;
}











