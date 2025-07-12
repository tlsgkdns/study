#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char c;
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> c;
		if (c == '#') break;
		getline(cin, S);
		transform(S.begin(), S.end(), S.begin(), [](auto c) {return std::tolower(c); });
		int ans = 0;
		for (int i = 0; i < S.size(); i++)
			ans += (S[i] == c);
		cout << c << " " << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/2386