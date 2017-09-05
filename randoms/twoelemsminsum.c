# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

void swap(int *a, int *b)
{
	*a = (*a + *b) - (*b = *a);
}

int partition(int a[], int l, int h)
{
	int i, j;
	i = j  = l;
	for(i = l; i < h; i++) {
		if(a[i] < a[h]) {
			swap(&a[i], &a[j]);
			j++;
		}
	}
	swap(&a[j], &a[h]);
	return j;	
}

void quickSort(int a[], int l, int h)
{
	if(l >= h) return;
	int p = partition(a, l,  h);
	quickSort(a, l, p - 1);
	quickSort(a, p + 1, h);
}

int getMinSum(int *A, int n)
{
	quickSort(A, 0, n - 1);
	int i = 0, j = n - 1, temp, positiveClosest = INT_MAX, negativeClosest = INT_MIN;
	while(i < j) {
		temp = A[i] + A[j];
		if(temp > 0) {
			positiveClosest = positiveClosest < temp ? positiveClosest : temp;
			j--;
		} else if(temp < 0) {
			negativeClosest = negativeClosest > temp ? negativeClosest : temp;
			i++;
		} else {
			printf("Closest Sum : %d\n", A[i] + A[j]);
		}
	}
	return (negativeClosest > 0 ? negativeClosest : -negativeClosest) > positiveClosest ? positiveClosest : negativeClosest; 
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
	printf("%d\n", getMinSum(A, n));
	return 0;
}