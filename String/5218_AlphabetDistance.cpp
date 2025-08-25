#include <iostream>

using namespace std;
int N;
string S1, S2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> S1 >> S2;
		cout << "Distances: ";
		for (int i = 0; i < S1.size(); i++)
		{
			if (S2[i] < S1[i]) cout << (S2[i] - S1[i] + 26) << " ";
			else cout << S2[i] - S1[i] << " ";
		}
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/5218