# include <iostream>
# include <vector>

using namespace std;

void combinations(int *a, vector<vector<int> > &ans, int v, int depth, int n, int k)
{
	if(depth >= k) {
		vector<int> a1;
		for(int  i = 0; i < k; i++) {
			a1.push_back(a[i]);
		}
		ans.push_back(a1);
		return;
	}

	for(int i = v; i <= n - k + depth + 1; i++) {
		a[depth] = i;
		combinations(a, ans, i + 1, depth + 1, n, k);
	}
} 

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cout << endl;
		cin >> n >> k;
		int *a = new int[k];
		vector<vector<int> > ans;
		combinations(a, ans, 1, 0, n, k);
		for(vector<int> v : ans) {
			cout << "[ ";
			for(int k : v) {
				cout << k << " "; 
			}
			cout << "]";
		}
		cout << endl;
	}
	return 0;
}