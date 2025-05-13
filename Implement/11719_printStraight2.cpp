#include <iostream>
#include <string>

using namespace std;
string ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		getline(cin, ans);
		if (cin.eof()) break;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/11719