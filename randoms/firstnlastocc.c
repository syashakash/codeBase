#include <stdio.h>
#include <stdlib.h>

int firstOcc(int *a, int n, int x)
{
    int l, h, mid;
    int index = -1;
    l = 0, h = n - 1;
    while(l <= h) {
        mid = l + (h - l) / 2;
        if(a[mid] == x) {
            h = mid - 1;
            index = mid;
        } else if(a[mid] < x) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return index;
}

int lastOcc(int *a, int n, int x)
{
    int l, h, mid;
    int index = -1;
    l = 0, h = n - 1;
    while(l <= h) {
        mid = l + (h - l) / 2;
        if(a[mid] == x) {
            l = mid + 1;
            index = mid;
        } else if(a[mid] < x) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return index;
}
int main() {
	//code
	int t;
	scanf("%d", &t);
	while(t--) {
	    int n;
	    scanf("%d", &n);
	    int *a = (int*)malloc(n * sizeof(int));
	    int i;
	    for(i = 0; i < n; i++) {
	        scanf("%d", &a[i]);
	    }
	    int x;
	    scanf("%d", &x);
	    int l = firstOcc(a, n, x);
	    int h = lastOcc(a, n, x);
	    if(l != -1 || h != -1)
	        printf("%d %d\n", l, h);
	    else printf("-1\n");
	}
	return 0;
}