#include <iostream>
#include <string>

using namespace std;

string P, C, S = "";
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	getline(cin, P); getline(cin, C);
	while (S.size() < P.size())
		S += C;
	for (int i = 0; i < P.size(); i++)
	{
		if (P[i] == ' ') continue;
		if (P[i] > S[i])
			P[i] = P[i] - S[i] - 1 + 'a';
		else
			P[i] = 25 + P[i] - S[i] + 'a';
	}
	cout << P << '\n';
}

// https://www.acmicpc.net/problem/1718