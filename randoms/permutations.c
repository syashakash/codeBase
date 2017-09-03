# include <stdio.h>
# include <stdlib.h>

void permutations(int depth, int length, char *original, int *used, char *ans)
{
	if(depth == length) {
		printf("%s\n", ans);
	} else {
		int i;
		for(i = 0; i < length; i++) {
			if(!used[i]) {
				used[i] = 1;
				ans[depth] = original[i];
				permutations(depth + 1, length, original, used, ans);
				used[i] = 0;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	char *original = (char*)malloc(1000 * sizeof(char));
	scanf("%s", original);
	char *ans = (char*)malloc(1000 * sizeof(char));
	int l;
	for(l = 0; original[l] != '\0'; l++);
	int *used = (int*)calloc(l, sizeof(int));
	permutations(0, l, original, used, ans);
	return 0;
}