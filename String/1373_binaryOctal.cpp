#include <iostream>

using namespace std;
string B, ans = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> B;
	while (B.size() % 3 > 0)
		B = '0' + B;
	for (int i = 0; i < B.size(); i += 3)
	{
		string tmp = string(B.begin() + i, B.begin() + i + 3);
		int n = 0, b = 1;
		for (int j = 2, b = 1; j >= 0; j--, b *= 2)
			if (tmp[j] == '1')
				n += b;
		ans.push_back(n + '0');
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1373