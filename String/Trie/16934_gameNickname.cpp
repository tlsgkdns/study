#include <iostream>

using namespace std;

const int ALP = 26;
int N;
string S;
class Tri
{
public:
	Tri* child[ALP];
	int endWord;
	Tri()
	{
		for (int i = 0; i < ALP; i++) child[i] = NULL;
		endWord = 0;
	}
	~Tri()
	{
		for (int i = 0; i < ALP; i++)
			if (child[i] != NULL)
				delete child[i];
	}

	void insert(string& str, int idx, bool f)
	{
		if (str.size() == idx)
		{
			++endWord;
			if (f)
			{
				if (endWord > 1) cout << str << endWord << '\n';
				else cout << str << '\n';
			}
			return;
		}
		int next = str[idx] - 'a';

		if (child[next] == NULL)
		{
			if (f) cout << string(str.begin(), str.begin() + idx + 1) << '\n';
			f = false;
			child[next] = new Tri();
		}
		child[next]->insert(str, idx + 1, f);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	Tri* root = new Tri();
	while (N--)
	{
		cin >> S;
		root->insert(S, 0, true);
	}
}

// https://www.acmicpc.net/problem/16934