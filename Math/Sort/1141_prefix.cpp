#include <iostream>
#include <algorithm>

using namespace std;

int N, s = 0;
string X[51];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i];
	sort(X, X + N);
	for (int i = 0; i < N - 1; i++)
	{
		if (X[i].size() <= X[i + 1].size() && X[i] == string(X[i + 1].begin(), X[i + 1].begin() + X[i].size()))
			++s;
	}
	cout << N - s << '\n';
}

// https://solved.ac/contribute/1141