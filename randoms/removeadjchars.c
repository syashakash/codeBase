# include <stdio.h>
# include <stdlib.h>

void removeAdj(char *str)
{
	int i, j;
	j = 0;
	i = 1;
	int l;
	for(l = 0; str[l] != '\0'; l++);
	while(i <= l) {
		while(j >= 0 && str[j] == str[i]) {
			i++;
			j--;
		}
		str[++j] = str[i++];
	}
}

int main()
{
	char *a = (char*)malloc(1000 * sizeof(char));
	scanf("%s",a);
	removeAdj(a);
	printf("%s\n", a);
	return 0;
}