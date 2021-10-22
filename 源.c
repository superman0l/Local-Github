#include <stdio.h>
char A[100], B[100];
int A1[100];
int n,m;
void mul(int i,int j) {
	if (j == 1) {
		A[0] = '1';
		for (int i = 1; i < 100; i++) {
			A[i] = '0';
		}
	}
	if (j <= i) {
		int k;
		for (k = 0; k < 99; k++) {
			A1[k] = (A[k] - '0') * j;
		}
		for (k = 0; k < 99; k++) {
			A[k] = A1[k] % 10 + '0';
			A1[k + 1] += A1[k] / 10;
		}
		mul(i, j + 1);
	}

}
void plus(char A[], char B[]) {
	for (int i = 0; i <100; i++) {
		B[i] += A[i] - '0';
	}
	for (int k = 0; k < 99; k++) {
		n = B[k] - '0';
		B[k] = n % 10 + '0';
		B[k + 1] += n / 10;
	}
	
}
int main() {
	for (int i = 0; i < 100; i++) {
		B[i] = '0';
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		mul(i, 1);
		plus(A, B);
	}
	int i;
	for (i = 99; B[i] == '0'; i--);
	for (; i >= 0; i--)
		printf("%c", B[i]);
return 0;
}
