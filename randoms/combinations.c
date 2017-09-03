# include <stdio.h>
# include <stdlib.h>

void combinations(int depth, char *original, int start, int length, char *ans)
{
	int i;
	for(i = start; i < length; i++) {
		ans[depth] = original[i];
		ans[depth + 1] = '\0';
		printf("%s\n", ans);
		if(i < length - 1) {
			combinations(depth + 1, original, start + 1, length, ans);
		}
	}
}

int main(int argc, char const *argv[])
{
	char *original = (char*)malloc(1000 * sizeof(char));
	scanf("%s", original);
	char *ans = (char*)malloc(1000 * sizeof(char));
	int length;
	for(length = 0; original[length] != '\0'; length++);
	combinations(0, original, 0, length, ans);
	return 0;
}