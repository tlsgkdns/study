#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;
int S;
string L;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	cin.ignore();
	while (S--)
	{
		int c = 0, v = 0;
		getline(cin, L);
		for_each(L.begin(), L.end(), [](auto& c) {c = tolower(c); });
		for (int i = 0; i < L.size(); i++)
		{
			if (L[i] == ' ') continue;
			if (L[i] == 'u' || L[i] == 'o' || L[i] == 'i' || L[i] == 'a' || L[i] == 'e')
				++v;
			else
				++c;
		}
		cout << c << " " << v << '\n';
	}
}

// https://www.acmicpc.net/problem/11319