/*
1954. 달팽이 숫자
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PobmqAPoDFAUq&categoryId=AV5PobmqAPoDFAUq&categoryType=CODE

< input >
2    
3   
4             
 
 

< output >
#1
1 2 3
8 9 4
7 6 5
#2
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7
 
 
 
 
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

	int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	int i = 0 ;
	while( i < totalNum ) { 

		int num = 0 ;
		scanf("%d" , &num ) ;

		int arr[10][10] = { 0 }  ;
        int curRow = 0, curCol = 0, curDir = 0;
 
        for (int i = 1; i <= num * num; i++){
            int nextRow = curRow + direction[curDir][0];
            int nextCol = curCol + direction[curDir][1];
 
            arr[curRow][curCol] = i;
             
            if (nextRow < 0 || nextRow >= num || nextCol < 0 || nextCol >= num || arr[nextRow][nextCol] != 0) {
                curDir = (curDir + 1) % 4;
                curRow += direction[curDir][0];
                curCol += direction[curDir][1];
            }
            else {
                curRow = nextRow;
                curCol = nextCol;
            }
 
		}

		printf("#%d\n" , ( i + 1 ) ) ;
		for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++)
                printf("%d ", arr[i][j]);
            printf("\n");
        }

		i++ ;
	}

	return 0 ;
}











