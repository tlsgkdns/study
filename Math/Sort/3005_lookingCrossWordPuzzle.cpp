#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<string> words;
int R, C;
char P[22][22];
string W = "";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(P, '#', sizeof(P));
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> P[i][j];
	for (int i = 0; i <= R; i++)
		for (int j = 0; j <= C; j++)
			if (P[i][j] == '#')
			{
				if (W.size() >= 2) words.push_back(W);
				W = "";
			}
			else
			{
				W.push_back(P[i][j]);
			}
	for (int j = 0; j <= C; j++)
		for (int i = 0; i <= R; i++)
			if (P[i][j] == '#')
			{
				if (W.size() >= 2) words.push_back(W);
				W = "";
			}
			else
			{
				W.push_back(P[i][j]);
			}
	sort(words.begin(), words.end());
	cout << words[0] << '\n';
}

// https://www.acmicpc.net/problem/3005