#include <iostream>

using namespace std;

string S1, S2, a1, a2, a3, a4, a5;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S1;
	cin >> S2;
	a1 = a2 = a3 = a4 = a5 = S1;
	for (int i = 0; i < S1.size(); i++)
	{
		a1[i] = (S1[i] == S2[i] && S1[i] == '1') + '0';
		a2[i] = (S1[i] == '1' || S2[i] == '1') + '0';
		a3[i] = ((S1[i] == '1') + (S2[i] == '1') == 1) + '0';
		a4[i] = !(S1[i] == '1') + '0';
		a5[i] = !(S2[i] == '1') + '0';
	}
	cout << a1 << '\n' << a2 << '\n' << a3 << '\n' << a4 << '\n' << a5 << '\n';
}

// https://www.acmicpc.net/problem/12813