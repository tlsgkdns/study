#include <iostream>
#include <queue>
using namespace std;

const int ALP = 26;
int N, Q;
string S;
class Tri
{
public:
	Tri* child[ALP];
	Tri* fail;
	bool nodeEnd;
	Tri()
	{
		for (int i = 0; i < ALP; i++) child[i] = NULL;
		fail = NULL;
		nodeEnd = false;
	}
	~Tri()
	{
		for (int i = 0; i < ALP; i++)
			if (child[i] != NULL)
				delete child[i];
		delete fail;
	}

	void insert(string& str, int idx)
	{
		if (str.size() == idx)
		{
			nodeEnd = true;
			return;
		}
		int next = str[idx] - 'a';

		if (child[next] == NULL)
			child[next] = new Tri();

		child[next]->insert(str, idx + 1);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	Tri* root = new Tri();
	root->fail = root;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		root->insert(S, 0);
	}
	queue<Tri*> q;
	q.push(root);
	while (!q.empty())
	{
		Tri* now = q.front();
		q.pop();
		for (int i = 0; i < ALP; i++)
		{
			Tri* nxt = now->child[i];
			if (!nxt) continue;
			if (now == root) nxt->fail = root;
			else
			{
				Tri* tmp = now->fail;
				while (tmp != root && !tmp->child[i])
					tmp = tmp->fail;
				if (tmp->child[i]) tmp = tmp->child[i];
				nxt->fail = tmp;
			}
			if (nxt->fail->nodeEnd) nxt->nodeEnd = true;
			q.push(nxt);
		}
	}
	cin >> Q;
	while (Q--)
	{
		cin >> S;
		Tri* here = root;
		bool ans = false;
		for (int i = 0; i < S.size(); i++)
		{
			int there = S[i] - 'a';
			while (here != root && !here->child[there])
				here = here->fail;
			if (here->child[there])
				here = here->child[there];
			if (here->nodeEnd)
			{
				ans = true;
				break;
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}

// https://www.acmicpc.net/problem/9250