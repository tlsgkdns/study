#include <iostream>
#include <algorithm>

using namespace std;
string N;
int s = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	sort(N.begin(), N.end(), greater<char>());
	for (int i = 0; i < (int)N.size(); i++)
		s += (N[i] - '0');
	if (N.back() != '0' || s % 3 > 0) cout << -1 << '\n';
	else cout << N << '\n';
}

// https://www.acmicpc.net/problem/10610