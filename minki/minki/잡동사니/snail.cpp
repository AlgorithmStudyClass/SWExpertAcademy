#include <iostream> // cin ��� ���� �ʿ� 
#include <vector>	// vector ��� ���� �ʿ�  
#include <algorithm> // sort ��� ���� �ʿ� 
#include <string>
#include <numeric>

using namespace std;

//������
int main()
{
	int n, cnt = 1, temp;
	int arr[100][100];

	//n�� 2���� ������ ũ��
	scanf("%d", &n);

	//	�ð�	123
	//			894
	//			765

	//	����
	//	n = 5
	//  5 4 4 3
	//  3 2 2 1
	//  1

	for (int i = 0; i < (n / 2) + 1; i++) {
		for (int j = i; j < n - i; j++)  // ���� ->������
			arr[i][j] = cnt++;
		for (int j = i + 1; j < n - i; j++)  // ��   -> �Ʒ�
			arr[j][n - i - 1] = cnt++;
		for (int j = i + 1; j < n - i; j++)  // ������->����
			arr[n - i - 1][n - j - 1] = cnt++;
		for (int j = i + 1; j < n - i - 1; j++)  // �Ʒ� -> ��
			arr[n - j - 1][i] = cnt++;
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			printf("%5d", arr[i][j]);
		}
		puts("");
	}
	puts("");

	//	�ݽð�	187
	//			296
	//			345

	cnt = 1;

	for (int i = 0; i < (n / 2) + 1; i++) {
		for (int j = i; j < n - i; j++)  // ��   -> �Ʒ�
			arr[j][i] = cnt++;
		for (int j = i + 1; j < n - i; j++)  // ���� ->������
			arr[n - i - 1][j] = cnt++;
		for (int j = i + 1; j < n - i; j++)  // �Ʒ� -> ��
			arr[n - j - 1][n - i - 1] = cnt++;
		for (int j = i + 1; j < n - i - 1; j++)  // ������->����
			arr[i][n - j - 1] = cnt++;
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			printf("%5d", arr[i][j]);
		}
		puts("");
	}
}