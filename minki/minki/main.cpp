#include<stdio.h>

int main(void) {
	FILE *fp;
	char mne[10], op[10], data[10];
	int n;

	fp = fopen("a.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s", op);
	}
	return 0;
}