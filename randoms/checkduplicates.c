# include <stdlib.h>
# include <stdio.h>

int checkDuplicates(int *A, int n)
{
	int i;
	for(i = 0; i < n; i++) {
		int k = A[i] > 0 ? A[i] : -1 * A[i];
		if(A[k] >= 0) {
			A[k] = -1 * A[k];
		} else {
			return k;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int *A = (int*)malloc(n * sizeof(int));
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	printf("%d\n", checkDuplicates(A, n));
	return 0;
}