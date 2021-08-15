#include <iostream>
#include <vector>
using namespace std;

int N, M, T;
int nrR[4] = { 0, 0, -1, 1 };
int nrC[4] = { 1, -1, 0, 0 };
class Disk
{
private:
	vector<vector<int>> disk;
	int R = 0, C = 0;
public:
	Disk(int n, int m)
	{
		disk.resize(n, vector<int>(m));
		R = n; C = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> disk[i][j];
	}
	pair<float, float> getDiskInfo()
	{
		float s = 0, cnt = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
			{
				if (disk[i][j] == -1) continue;
				s += disk[i][j];
				cnt++;
			}
		return make_pair(s, cnt);
	}
	void rotateClockwise(int num)
	{
		int t1 = disk[num][0], t2;
		for (int i = 1; i < C; i++)
		{
			t2 = disk[num][i];
			disk[num][i] = t1;
			t1 = t2;
		}
		disk[num][0] = t1;
	}
	void rotateAntiClockwise(int num)
	{
		int t1 = disk[num].back(), t2;
		for (int i = C - 1; i >= 0; i--)
		{
			t2 = disk[num][i];
			disk[num][i] = t1;
			t1 = t2;
		}
		disk[num][M - 1] = t1;
	}
	void rotateDisk(int x, int d, int k)
	{
		for (int num = x; num <= R; num += x)
		{
			if (d == 0)
			{
				for (int i = 0; i < k; i++)
					rotateClockwise(num - 1);
			}
			else
			{
				for (int i = 0; i < k; i++)
					rotateAntiClockwise(num - 1);
			}
		}
	}
	void adjustDiskNum()
	{
		pair<float, float> info = getDiskInfo();
		double avg = info.first / info.second;
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
			{
				if (disk[r][c] == -1) continue;
				if (disk[r][c] > avg) disk[r][c]--;
				else if (disk[r][c] < avg) disk[r][c]++;
			}
	}
	void checkDisk()
	{
		bool erased = false;
		vector<vector<bool>> v(R, vector<bool>(C, false));
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
			{
				if (disk[r][c] == -1) continue;
				for (int i = 0; i < 4; i++)
				{
					int nr = nrR[i] + r;
					int nc = nrC[i] + c;
					if (nr < 0 || nr >= N) continue;
					if (nc < 0) nc = C - 1;
					else if (nc >= C) nc = 0;
					if (disk[nr][nc] == -1) continue;
					if (disk[r][c] == disk[nr][nc])
					{
						v[r][c] = true;
						v[nr][nc] = true;
					}
				}
			}
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				if (v[r][c])
				{
					erased = true;
					disk[r][c] = -1;
				}
		if (!erased) adjustDiskNum();
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T;
	Disk* ds = new Disk(N, M);
	int x, d, k;
	for (int i = 0; i < T; i++)
	{
		cin >> x >> d >> k;
		ds->rotateDisk(x, d, k);
		ds->checkDisk();
	}
	cout << (int)ds->getDiskInfo().first << '\n';
}
// https://www.acmicpc.net/problem/17822