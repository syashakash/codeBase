# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

void swap(long long int *a, long long int *b)
{
	long long int t = *a;
	*a = *b;
	*b = t;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		long long int n;
		scanf("%lld", &n);
		long long int *a = (long long int*)malloc(n * sizeof(long long int));
		int i;
		for(i = 0; i < n; i++) {
			a[i] = i + 1;
		}
		for(i = 0; i < n - 1; i +=2 ) {
			swap(&a[i], &a[i + 1]);
		}
		if(n % 2 == 1) {
			swap(&a[i], &a[i - 1]);
		}
		for(i = 0; i < n; i++) {
			printf("%lld ", a[i]);
		}
		printf("\n");
		free(a);
	}
	return 0;
}