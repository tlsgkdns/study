#include <iostream>

using namespace std;

string H, N;
int ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> H;
	cin >> N;
	for (int i = 0; i <= H.size() - N.size(); i++)
		ans += string(H.begin() + i, H.begin() + i + N.size()) == N;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/12780