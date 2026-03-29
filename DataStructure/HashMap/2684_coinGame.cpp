#include <iostream>
#include <unordered_map>

using namespace std;

int P;
string S, a[8] = { "TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> P;
	while (P--)
	{
		unordered_map<string, int> d;
		cin >> S;
		for (int i = 0; i < S.size() - 2; i++)
		{
			string s = string(S.begin() + i, S.begin() + i + 3);
			d[s]++;
		}
		for (int i = 0; i < 8; i++) cout << d[a[i]] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2684