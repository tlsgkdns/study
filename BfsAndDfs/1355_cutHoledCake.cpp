#include <iostream>

using namespace std;

int LC, LH, H, V, h, v;

class Node
{
	int sy, sx, ey, ex;
	int L, cut;
	Node* l; Node* r;
public:
	Node(int sy, int sx, int ey, int ex)
	{
		l = NULL; r = NULL;
		this->sx = sx; this->sy = sy;
		this->ex = ex; this->ey = ey;
		cut = -1; L = -1;
	}
	bool isLeaf()
	{
		return cut < 0;
	}
	void cutCake(bool hor, int n)
	{
		if (isLeaf())
		{
			cut = hor;
			L = n;
			if (hor)
			{
				l = new Node(sy, sx, n, ex);
				r = new Node(n, sx, ey, ex);
			}
			else
			{
				l = new Node(sy, sx, ey, n);
				r = new Node(sy, n, ey, ex);
			}
		}
		else
		{
			if (hor == cut)
			{
				if (n < L) l->cutCake(hor, n);
				else if (n > L) r->cutCake(hor, n);
			}
			else
			{
				l->cutCake(hor, n);
				r->cutCake(hor, n);
			}
		}
	}
	int count()
	{
		if (isLeaf())
		{
			if (ey <= LH && ex <= LH && sy >= -LH && sx >= -LH) return 0;
			if ((sx >= -LH && ex <= LH && sy < -LH && ey > LH)
				|| (sy >= -LH && ey <= LH && sx < -LH && ex > LH)) return 2;
			return 1;
		}
		return l->count() + r->count();
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> LC >> LH;
	Node* node = new Node(-LC, -LC, LC, LC);
	cin >> H;
	while (H--)
	{
		cin >> h;
		node->cutCake(true, h);
	}
	cin >> V;
	while (V--)
	{
		cin >> v;
		node->cutCake(false, v);
	}
	cout << node->count() << '\n';
}

// https://www.acmicpc.net/problem/1355