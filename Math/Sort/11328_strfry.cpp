#include <iostream>
#include <algorithm>

using namespace std;

int N;
string S1, S2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> S1 >> S2;
		sort(S1.begin(), S1.end());
		sort(S2.begin(), S2.end());
		if (S1 == S2) cout << "Possible\n";
		else cout << "Impossible\n";
	}
}

// https://www.acmicpc.net/problem/11328