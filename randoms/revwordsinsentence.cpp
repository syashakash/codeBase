# include <cstdio>
# include <cstdlib>

using namespace std;

void reverse(char *a, int start, int end)
{
	for(char temp; start < end; start++, end--) {
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
	}
}

void reverseWordsInSentence(char *a)
{
	int wdSt, wdEnd;
	int length;
	for(length = 0; a[length] != '\0'; length++);
	reverse(a, 0, length - 1);
	for(wdSt = wdEnd = 0; wdEnd < length; wdEnd++) {
		if(a[wdEnd] != ' ') {
			wdSt = wdEnd;
			while(wdEnd < length && a[wdEnd] != ' ') {
				wdEnd++;
			}
			wdEnd--;
			reverse(a, wdSt, wdEnd);
		}
	}
}

int main()
{
	char *a = (char*)malloc(1000 * sizeof(char));
	scanf("%[^\n]s",a);
	reverseWordsInSentence(a);
	printf("%s\n", a);
	return 0;
}