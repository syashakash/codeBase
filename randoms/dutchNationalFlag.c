# include <stdio.h>
# include <stdlib.h>

void swap(int *a, int *b)
{
	*a ^= *b ^= *a ^= *b;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int *A = (int*)malloc(n * sizeof(int));
	int i;
	for(i = 0; i < n; i++) scanf("%d", &A[i]);
	int l = 0, r = n - 1;
	while(l < r) {
		while(l < r && A[l] % 2 == 0) {
			l++;
		}
		while(l < r && A[r] % 2 == 1) {
			r--;
		}
		while(l < r) {
			swap(&A[l], &A[r]);
			l++; r--;
		}
	}
	for(i = 0; i < n; i++) printf("%d ", A[i]);
	printf("\n");
	return 0;
}