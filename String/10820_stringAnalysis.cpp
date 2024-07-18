#include <iostream>
#include <string>

using namespace std;

string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		getline(cin, S);
		if (cin.eof()) break;
		int small = 0, big = 0, num = 0, blank = 0;
		for (int i = 0; i < S.size(); i++)
		{
			small += (S[i] >= 'a' && S[i] <= 'z');
			big += (S[i] >= 'A' && S[i] <= 'Z');
			num += (S[i] >= '0' && S[i] <= '9');
			blank += (S[i] == ' ');
		}
		cout << small << " " << big << " " << num << " " << blank << '\n';
	}
}

// https://www.acmicpc.net/problem/10820