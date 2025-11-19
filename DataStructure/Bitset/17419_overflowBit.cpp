#include <iostream>

using namespace std;
int N, ans = 0;
string K;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	cin >> K;
	for (int i = 0; i < K.size(); i++)
		ans += (K[i] == '1');
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17419