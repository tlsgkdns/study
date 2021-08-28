#include <iostream>
#include <vector>
using namespace std;

char puz[3][3];
string words[6];
bool filled = false;
void brute(vector<bool>& sel, int r)
{
	if (filled) return;
	if (r == 3)
	{
		vector<bool> p(3, false);
		int cnt = 0;
		for (int i = 0; i < 6; i++)
		{
			if (sel[i]) continue;
			for (int j = 0; j < 3; j++)
			{
				string cmp = "";
				for (int w = 0; w < 3; w++)
					cmp.push_back(puz[w][j]);
				if (!p[j] && cmp == words[i])
				{
					p[j] = true; cnt++;
					break;
				}
			}
			filled = (cnt == 3);
		}
		return;
	}
	for (int w = 0; w < 6; w++)
	{
		if (sel[w] || filled) continue;
		for (int c = 0; c < 3; c++)
			puz[r][c] = words[w][c];
		sel[w] = true;
		brute(sel, r + 1);
		sel[w] = false;
	}
}
int main()
{
	for (int i = 0; i < 6; i++)
		cin >> words[i];
	vector<bool> s(6, false);
	brute(s, 0);
	if (!filled)
		cout << 0 << '\n';
	else
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << puz[i][j];
			cout << '\n';
		}
}

// https://www.acmicpc.net/problem/2784