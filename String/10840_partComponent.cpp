#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
using ll = long long;
string S1, S2;
int ans = 0;

ll code[26] = { 1146512365, 1893210001, 2424126, 311123689, 434212389, 1379023125, 489123122, 659232112, 2301773, 1231223673,
				42323892, 83321891, 143121728, 2356782, 1634121452, 96578234471, 232567773, 104203120, 9178932216, 1832412122
				,2311112312, 711177853, 87234562315, 4112341265235, 7611123218, 654222141 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S1; cin >> S2;

	for (int l = 1; l <= min(S1.size(), S2.size()); l++)
	{
		unordered_map<ll, bool> um;
		ll H = 0;
		for (int i = 0; i < l; i++) H += code[S1[i] - 'a'];
		um.insert({ H, false });
		for (int i = 1; i + l <= S1.size(); i++)
		{
			H -= code[S1[i - 1] - 'a'];
			H += code[S1[i + l - 1] - 'a'];
			um.insert({ H, true });
		}
		H = 0;
		for (int i = 0; i < l; i++) H += code[S2[i] - 'a'];
		if (um.count(H)) ans = l;
		for (int i = 1; i + l <= S2.size(); i++)
		{
			H -= code[S2[i - 1] - 'a'];
			H += code[S2[i + l - 1] - 'a'];
			if (um.count(H) > 0)
			{
				ans = l;
				break;
			}
		}
	}

	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10840