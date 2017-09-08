# include <iostream>
# include <vector>

using namespace std;

int countJumps(vector<int> A, int n, int x, int y)
{
	int jumps = 0;
	for(int i = 0; i < n; i++) {
		while(A[i] > x) {
			A[i] = A[i] - (x - y);
			jumps++;
		}
		jumps++;
	}	
	return jumps;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i =0 ; i < n; i++) {
		cin >> A[i];
	}
	int x, y;
	cin >> x >> y;
	cout << countJumps(A, n, x, y) << endl;
	return 0;
}