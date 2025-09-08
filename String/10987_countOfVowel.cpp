#include <iostream>


using namespace std;
string W;
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> W;
	for (int i = 0; i < W.size(); i++)
		ans += (W[i] == 'a' || W[i] == 'e' || W[i] == 'u' || W[i] == 'o' || W[i] == 'i');
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10987