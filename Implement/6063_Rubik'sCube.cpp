#include <iostream>
#include <vector>
using namespace std;

char topSide[3][3], leftSide[3][3],
frontSide[3][3], rightSide[3][3],
backSide[3][3], bottomSide[3][3];

void rotateSide(char side[3][3])
{
	char tmp[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tmp[i][j] = side[j][2 - i];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			side[i][j] = tmp[i][j];
}
void rotateTop()
{
	char tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = backSide[0][i];
	for (int i = 0; i < 3; i++) backSide[0][i] = leftSide[0][i];
	for (int i = 0; i < 3; i++) leftSide[0][i] = frontSide[0][i];
	for (int i = 0; i < 3; i++) frontSide[0][i] = rightSide[0][i];
	for (int i = 0; i < 3; i++) rightSide[0][i] = tmp[i];
	for (int i = 0; i < 3; i++) rotateSide(topSide);
}
void rotateBottom()
{
	char tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = backSide[2][i];
	for (int i = 0; i < 3; i++) backSide[2][i] = leftSide[2][i];
	for (int i = 0; i < 3; i++) leftSide[2][i] = frontSide[2][i];
	for (int i = 0; i < 3; i++) frontSide[2][i] = rightSide[2][i];
	for (int i = 0; i < 3; i++) rightSide[2][i] = tmp[i];
	rotateSide(bottomSide);
}

void rotateLeft()
{
	char tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = backSide[2 - i][2];
	for (int i = 0; i < 3; i++) backSide[i][2] = bottomSide[2 - i][0];
	for (int i = 0; i < 3; i++) bottomSide[i][0] = frontSide[i][0];
	for (int i = 0; i < 3; i++) frontSide[i][0] = topSide[i][0];
	for (int i = 0; i < 3; i++) topSide[i][0] = tmp[i];
	for (int i = 0; i < 3; i++) rotateSide(leftSide);
}

void rotateRight()
{
	char tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = backSide[2 - i][0];
	for (int i = 0; i < 3; i++) backSide[i][0] = bottomSide[2 - i][2];
	for (int i = 0; i < 3; i++) bottomSide[i][2] = frontSide[i][2];
	for (int i = 0; i < 3; i++) frontSide[i][2] = topSide[i][2];
	for (int i = 0; i < 3; i++) topSide[i][2] = tmp[i];
	rotateSide(rightSide);
}

void rotateFront()
{
	char tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = bottomSide[0][i];
	for (int i = 0; i < 3; i++) bottomSide[0][i] = rightSide[2 - i][0];
	for (int i = 0; i < 3; i++) rightSide[i][0] = topSide[2][i];
	for (int i = 0; i < 3; i++) topSide[2][2 - i] = leftSide[i][2];
	for (int i = 0; i < 3; i++) leftSide[i][2] = tmp[i];
	for (int i = 0; i < 3; i++) rotateSide(frontSide);
}
void rotateBack()
{
	char tmp[3];
	for (int i = 0; i < 3; i++) tmp[i] = bottomSide[2][i];
	for (int i = 0; i < 3; i++) bottomSide[2][i] = rightSide[2 - i][2];
	for (int i = 0; i < 3; i++) rightSide[i][2] = topSide[0][i];
	for (int i = 0; i < 3; i++) topSide[0][2 - i] = leftSide[i][0];
	for (int i = 0; i < 3; i++) leftSide[i][0] = tmp[i];
	rotateSide(backSide);
}
void printCube(int num)
{
	cout << "Scenario #" << num << ":\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << "  ";
		for (int j = 0; j < 3; j++)
			cout << topSide[i][j] << " ";
		cout << '\n';
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << leftSide[i][j] << " ";
		for (int j = 0; j < 3; j++)
			cout << frontSide[i][j] << " ";
		for (int j = 0; j < 3; j++)
			cout << rightSide[i][j] << " ";
		for (int j = 0; j < 3; j++)
			cout << backSide[i][j] << " ";
		cout << '\n';
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << "  ";
		for (int j = 0; j < 3; j++)
			cout << bottomSide[i][j] << " ";
		cout << '\n';
	}
	cout << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int M;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cin >> topSide[i][j];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cin >> leftSide[i][j];
			for (int j = 0; j < 3; j++)
				cin >> frontSide[i][j];
			for (int j = 0; j < 3; j++)
				cin >> rightSide[i][j];
			for (int j = 0; j < 3; j++)
				cin >> backSide[i][j];
		}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cin >> bottomSide[i][j];
		cin >> M; int dir, sd;
		for (int m = 0; m < M; m++)
		{
			cin >> sd >> dir;
			switch (sd)
			{
			case 0:
				if (dir == 1) rotateLeft();
				else for (int i = 0; i < 3; i++) rotateLeft();
				break;
			case 1:
				if (dir == 1) rotateFront();
				else for (int i = 0; i < 3; i++) rotateFront();
				break;
			case 2:
				if (dir == 1) for (int i = 0; i < 3; i++) rotateRight();
				else rotateRight();
				break;
			case 3:
				if (dir == 1) for (int i = 0; i < 3; i++) rotateBack();
				else rotateBack();
				break;
			case 4:
				if (dir == 1) rotateTop();
				else for (int i = 0; i < 3; i++) rotateTop();
				break;
			default:
				if (dir == 1) for (int i = 0; i < 3; i++) rotateBottom();
				else  rotateBottom();
				break;
			}
		}
		printCube(t + 1);
	}
}