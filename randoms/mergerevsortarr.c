#include <stdio.h>
#include <stdlib.h>

void reverse(int *a, int n)
{
	int i;
	for(i = 0; i < n / 2; i++) {
		int t = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = t;
	}
}

int main() {
	//code
	int t;
	scanf("%d", &t);
	while(t--) {
	    int n1, n2;
	    scanf("%d%d", &n1, &n2);
	    int *a1 = (int*)malloc(n1 * sizeof(int));
	    int *a2 = (int*)malloc(n2 * sizeof(int));
	    int i;
	    for(i = 0; i < n1; i++) scanf("%d", &a1[i]);
	    for(i = 0; i < n2; i++) scanf("%d", &a2[i]);
	    int j, k;
	    i = j = k = 0;
        int *ans = (int*)malloc((n1 + n2) * sizeof(int));
        while(i < n1 - 1 && a1[i] == a1[i + 1]) i++;
        if(a1[i] < a1[i + 1]) reverse(a1, n1);
        while(j < n2 - 1 && a2[j] == a2[j + 1]) j++;
        if(a2[j] < a2[j + 1]) reverse(a2, n2);
        i = j = 0;
	    
	    while(i < n1 && i < n2) {
	        if(a1[i] > a2[j]) {
	            ans[k++] = a1[i++];
	        } else {
	            ans[k++] = a2[j++];
	        }
 	    }
 	    while(i < n1) {
 	        ans[k++] = a1[i++];
 	    }
 	    while(j < n2) {
 	        ans[k++] = a2[j++];
 	    }
	    for(k = 0;  k < n1 + n2; k++) {
	        printf("%d ", ans[k]);
	    }
	    printf("\n");
	}
	return 0;
}