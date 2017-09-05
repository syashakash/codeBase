# include <stdio.h>
# include <stdlib.h>
# define max(a, b) (a > b ? a : b)

int maxSumRec(int *A, int left, int right)
{
	int maxLeftBorderSum = 0, maxRightBorderSum = 0, leftBorderSum = 0,	rightBorderSum = 0;
	int mid = left + (right - left) / 2;
	
	if(left == right) return A[left] > 0 ? A[left] : 0;

	int maxLeftSum = maxSumRec(A, left, mid);
	int maxRightSum = maxSumRec(A, mid + 1, right);

	int i;
	for(i = mid; i >= left; i--) {
		leftBorderSum += A[i];
		maxLeftBorderSum = maxLeftBorderSum > leftBorderSum ? maxLeftBorderSum : leftBorderSum;
	}

	for(i = mid + 1; i <= right; i++) {
		rightBorderSum += A[i];
		maxRightBorderSum = maxRightBorderSum > rightBorderSum ? maxRightBorderSum : rightBorderSum;
	} 

	return max(maxLeftBorderSum + maxRightBorderSum, max(maxLeftSum, maxRightSum));
}

int maxSubsequenceSum(int *A, int n)
{
	return n > 0 ? maxSumRec(A, 0, n - 1) : 0;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int *A = (int*)malloc(n * sizeof(int));
	int i;
	for(i = 0; i < n; i++) scanf("%d", &A[i]);
	printf("%d\n", maxSubsequenceSum(A, n));
	return 0;
}