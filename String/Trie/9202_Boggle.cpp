#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int W, B;
string word;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int score[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };
char board[4][4];
bool v[4][4];
unordered_map<string, bool> um;
string a2[31];
int a1[31], a3[31];
class Node
{
	Node* alp[26];
	bool term;
public:
	Node()
	{
		term = false;
		memset(alp, 0, sizeof(alp));
	}
	~Node()
	{
		for (int i = 0; i < 26; i++)
			if (alp[i])
				delete alp[i];
	}
	void insert(string& str, int idx)
	{
		if (idx == str.size())
			term = true;
		else
		{
			int cur = str[idx] - 'A';
			if (alp[cur] == NULL) alp[cur] = new Node();
			alp[cur]->insert(str, idx + 1);
		}
	}
	bool find(string& str, int idx)
	{
		if (idx == (int)str.size()) return term;
		int cur = str[idx] - 'A';
		if (alp[cur] == NULL) return NULL;
		return alp[cur]->find(str, idx + 1);
	}
};
Node* node;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < 4 && x < 4;
}
void dfs(string& str, int y, int x, int idx)
{
	if (um.count(str) == 0)
	{
		um[str] = true;
		if (node->find(str, 0))
		{
			if (a2[idx].size() < str.size() || (a2[idx].size() == str.size() && a2[idx] > str))
				a2[idx] = str;
			a1[idx] += score[(int)str.size()];
			a3[idx]++;
		}
	}
	if (str.size() >= 8) return;
	for (int d = 0; d < 8; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || v[ny][nx]) continue;
		v[ny][nx] = true;
		str.push_back(board[ny][nx]);
		dfs(str, ny, nx, idx);
		str.pop_back();
		v[ny][nx] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	node = new Node();
	cin >> W;
	for (int i = 0; i < W; i++)
	{
		cin >> word;
		node->insert(word, 0);
	}
	cin >> B;
	for (int b = 0; b < B; b++)
	{
		um.clear();
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> board[i][j];
		string str = "";
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				v[i][j] = true;
				str.push_back(board[i][j]);
				dfs(str, i, j, b);
				str.pop_back();
				v[i][j] = false;
			}
	}
	for (int i = 0; i < B; i++) cout << a1[i] << " " << a2[i] << " " << a3[i] << '\n';
}

// https://www.acmicpc.net/problem/9202