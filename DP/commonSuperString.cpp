# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>
# include <cstring>

using namespace std;

void index(int **dp, vector<int> &indexA, vector<int> &indexB, string A, string B, int sizeA, int sizeB)
{
	indexA.clear();
	indexB.clear();

	if(sizeA == 0 || sizeB == 0) return;

	if(A[sizeA - 1] == B[sizeB - 1]) {
		index(dp, indexA, indexB, A, B, sizeA - 1, sizeB - 1);
		indexA.push_back(sizeA - 1);
		indexB.push_back(sizeB - 1);
	} else if(dp[sizeA - 1][sizeB] > dp[sizeA][sizeB - 1]) {
		index(dp, indexA, indexB, A, B, sizeA - 1, sizeB);
	} else {
		index(dp, indexA, indexB, A, B, sizeA, sizeB - 1);
	}
}

string combine(string A, string B)
{
	int sizeA = A.length();
	int sizeB = B.length();
	int **dp = new int*[sizeA + 1];
	for(int i = 0; i <= sizeA; i++) {
		dp[i] = new int[sizeB + 1];
	} 
	int k = 0;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= sizeA; i++) {
        for(int j = 1; j <= sizeB; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    string ans = "";
    int lcs = dp[sizeA][sizeB];
    vector<int> indexA, indexB;
    index(dp, indexA, indexB, A, B, sizeA, sizeB);
    int i, j = i = k;
    while (k < lcs) {
        while (i < sizeA && i < indexA[k]) {
            ans += A[i++];
        }
 
        while (j < sizeB && j < indexB[k]) {
            ans += B[j++];
        }
        ans = ans + A[indexA[k]];
        k++;
        i++;
        j++;
    }
    while (i < sizeA) {
        ans += A[i++];
    }
    while (j < sizeB) {
        ans += B[j++];
    }
}

int main(int argc, char const *argv[])
{
	string A, B;
	cin >> A >> B;
	cout << combine(A, B);
	return 0;
}