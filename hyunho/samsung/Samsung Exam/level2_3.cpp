#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

int main() {

   int testSize = 0;
   scanf("%d", &testSize);

   int T = 0;
   while (T++ < testSize) {

      int N = 0;
      scanf("%d", &N);

      vector<vector<int>> vec;
      int x, y;

      for (int i = 0; i < N; i++) {
         vec.push_back(vector<int>());
         scanf("%d %d", &x, &y);
         vec[i].push_back(x);
         vec[i].push_back(y);
         vec[i].push_back(1);
         vec[i].push_back(i + 1);
      }

      for (int i = 0; i < N; i++) {
         if (vec[i][2] == 0)
            continue;
         else {
            for (int j = 0; j < N; j++) {
               if (vec[j][2] == 0 || i == j)
                  continue;
               else {
                  if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1])
                     vec[j][2] = 0;
                  else if (vec[i][0] == vec[j][0]) {
                     if (vec[i][1] < vec[j][1])
                        vec[j][2] = 0;
                  }

                  if (vec[i][1] == vec[j][1]) {
                     if (vec[i][0] < vec[j][0])
                        vec[j][2] = 0;
                  }
               }
            }
         }
      }

      sort(vec.begin(), vec.end());


      printf("#%d ", T);
      for (int i = 0; i < N; i++) {
         if (vec[i][2] == 1) {
            printf("%d ", vec[i][3]);
         }
      }
      cout << endl;

      for (int i = 0; i < N; i++)
         vec[i].clear();
      vec.clear();
   }
   return 0;
}