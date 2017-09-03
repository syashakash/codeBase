# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		long long int *a = (long long int*)malloc(n * sizeof(long long int));
		int i;
		for(i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		long long int *psum = (long long int*)malloc(n * sizeof(long long int));
		long long int *ssum = (long long int*)malloc(n * sizeof(long long int));
		psum[0] = a[0];
		ssum[n - 1] = a[n - 1];
		for(i = 1; i < n; i++) {
			psum[i] = psum[i - 1] + a[i];
		}
		for(i = n - 2; i > -1; i--) {
			ssum[i] = ssum[i + 1] + a[i];
		}
		long long int max = LLONG_MAX, ans = -1;
		for(i = n - 1; i >= 0; i--) {
			if(max >= psum[i] + ssum[i]) {
				max = psum[i] + ssum[i];
				ans = i;
			}
		}
		
		printf("%lld\n", ans + 1);
		free(a);
		free(ssum);
		free(psum);
	}
	return 0;
}