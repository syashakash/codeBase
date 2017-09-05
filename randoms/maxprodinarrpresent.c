# include <stdio.h>
# include <stdlib.h>

void swap(int *a, int *b)
{
	if(*a == *b) return;
		*a = *a + *b;
	*b = *a - *b;
	
	*a = *a - *b;
	// *a = (*a + *b) - (*b = *a);
	// *a ^= *b ^= *a ^= *b;
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

int binsearch(int *a, int n, int x)
{
    int l = 0, h = n - 1, mid;
    while(l <= h) {
        mid = l + (h - l) / 2;
        if(a[mid] == x) return mid;
        else if(a[mid] < x) {
            l = mid + 1;
        } else {
            h = mid - 1; 
        }
    }
    return -1;
}

int main() {
	//code
	int t;
	scanf("%d", &t);
	while(t--) {
	    int n;
	    scanf("%d", &n);
	    int i, j;
	    int a[n];
	    for(i = 0; i < n; i++) {
	        scanf("%d", &a[i]);
	    }
	    quickSort(a, 0, n - 1);
	    for(i = 0; i < n; i++) printf("%d ", a[i]);
	    printf("\n");
	    int p;
	    int max = 0;
	    for(i = 0; i < n - 1; i++) {
	        for(j = i + 1; j < n; j++) {
	            p = a[i] * a[j];
	            if(binsearch(a, n, p) != -1) {
	                max = max < p ? p : max;
	            }
	        } 
	    }
	    printf("%d\n", max > 0 ? max : -1);
	    
	}
	return 0;
}