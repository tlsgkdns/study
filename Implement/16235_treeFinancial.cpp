#include <iostream>
#include <vector>
#include <algorithm>

int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { 0, 1, -1, 1, -1, 0, 1, -1 };

struct Tree
{
	int age;
	int alive;

	Tree(int a)
	{
		age = a;
		alive = true;
	}
	bool operator<(const Tree& t)
	{
		if (age < t.age) return true;
		else return false;
	}
};
using namespace std;
using treeList = vector<Tree>;
int n, m, k, tr, tc, ta;
vector<vector<int>> adding;
struct Ground
{
	vector<vector<int>> food;
	vector<vector<treeList>> trees;
	int size = 0;
	int numOfTree = 0;
	Ground(int n)
	{
		size = n;
		food.resize(n, vector<int>(n, 5));
		trees.resize(n, vector<treeList>(n));
	}
	void plant(int r, int c, int age)
	{
		trees[r - 1][c - 1].push_back(Tree(age));
		numOfTree++;
	}
	void spring()
	{
		for (int r = 0; r < size; r++)
			for (int c = 0; c < size; c++)
			{
				sort(trees[r][c].begin(), trees[r][c].end());
				for (Tree& t : trees[r][c])
					if (food[r][c] >= t.age)
					{
						food[r][c] -= t.age;
						t.age++;
					}
					else
						t.alive = false;
			}
	}

	void summer()
	{
		for (int r = 0; r < size; r++)
			for (int c = 0; c < size; c++)
			{
				auto it = trees[r][c].begin();
				while (it != trees[r][c].end())
				{
					if (!((*it).alive))
					{
						food[r][c] += (((*it).age) / 2);
						numOfTree--;
						it = trees[r][c].erase(it);
					}
					else
						it++;
				}
			}
	}
	void autumn()
	{
		for (int r = 0; r < size; r++)
			for (int c = 0; c < size; c++)
				for (Tree t : trees[r][c])
					if (t.age % 5 == 0)
						for (int i = 0; i < 8; i++)
						{
							int newR = r + dy[i];
							int newC = c + dx[i];
							if (newR < 0 || newC < 0 || newR == size || newC == size) continue;
							trees[newR][newC].push_back(Tree(1));
							numOfTree++;
						}
	}
	void winter()
	{
		for (int r = 0; r < size; r++)
			for (int c = 0; c < size; c++)
				food[r][c] += adding[r][c];
	}
	void yearPass(int year)
	{
		for (int i = 0; i < year; i++)
		{
			spring();
			summer();
			autumn();
			winter();
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	adding.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adding[i][j];
	Ground g(n);
	for (int i = 0; i < m; i++)
	{
		cin >> tr >> tc >> ta;
		g.plant(tr, tc, ta);
	}
	g.yearPass(k);
	cout << g.numOfTree << '\n';
}

// https://www.acmicpc.net/problem/16235