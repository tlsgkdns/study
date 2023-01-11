#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;
using pii = pair<int, int>;
const unordered_map<string, int> stringToAccessory
= { {"HR", 0}, {"RE", 1}, {"CO", 2}, {"EX", 3}, {"DX", 4}, {"HU", 5}, {"CU", 6} };
enum ItemType // 아이템 박스의 물건 종류
{
	None, Acc, Weapon, Armor
};
enum Accessory // 액세서리 종류
{
	HPRegeneration, Reincarnation, Courage, Experience, Dexterity, Hunter, Cursed
};
enum Result
{
	Continue, PlayerDead, BossDead
};
struct Item // 아이템 정보 클래스
{
private:
	ItemType itemType;
	int num;
public:
	Item(ItemType it, int n)
	{
		itemType = it;
		num = n;
	}
	void setItem(ItemType it, int n)
	{
		itemType = it;
		num = n;
	}
	bool isThisItemType(ItemType it)
	{
		return (itemType == it);
	}
	int getNumber()
	{
		return num;
	}
};
class ItemMap // 아이템 위치 및 정보 클래스
{
	Item* items[101][101];
	int N, M;
public:
	ItemMap(int n, int m)
	{
		N = n; M = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				items[i][j] = new Item(None, 0);
	}
	~ItemMap()
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				delete items[i][j];
	}
	void setItemMap(int r, int c, ItemType it, int n)
	{
		items[r][c]->setItem(it, n);
	}
	Item* getItem(pii pos)
	{
		return items[pos.first][pos.second];
	}
};
class AccessoryManager // 액세서리 관련 클래스
{
private:
	const int MAX = 4;
	bool wear[7]; // enum형인 Accessory로 index
	int accessoryNum;
public:
	AccessoryManager()
	{
		memset(wear, false, sizeof(wear));
		accessoryNum = 0;
	}
	void wearAccesory(Accessory acc)
	{
		if (accessoryNum >= MAX || wear[(int)acc]) return;
		wear[(int)acc] = true;
		++accessoryNum;
	}
	bool isPlayerWearThis(Accessory acc)
	{
		return wear[(int)acc];
	}
	void offAccesory(Accessory acc)
	{
		if (!wear[(int)acc]) return;
		--accessoryNum;
		wear[(int)acc] = false;
	}
};
class PlayerPosition // 플레이어 움직임 관련 클래스
{
private:
	bool wall[101][101];
	int limitY, limitX, posY, posX, initY, initX;
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	bool inRange(int y, int x)
	{
		return ((y >= 0) && (x >= 0) && (y < limitY) && (x < limitX));
	}
	int getIdx(char ch)
	{
		switch (ch)
		{
		case 'U':
			return 0;
		case 'D':
			return 1;
		case 'L':
			return 2;
		}
		return 3;
	}

public:
	PlayerPosition(char(&w)[101][101], int n, int m, int y, int x)
	{
		limitY = n; limitX = m; posY = y; posX = x;
		initY = y, initX = x;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				wall[i][j] = (w[i][j] == '#');
	}
	pair<int, int> getPlayerPos()
	{
		return { posY, posX };
	}
	void playerRevived()
	{
		posY = initY; posX = initX;
	}
	pair<int, int> PlayerMove(char cmd)
	{
		int idx = getIdx(cmd);
		int ny = posY + dy[idx]; int nx = posX + dx[idx];
		if (!inRange(ny, nx) || wall[ny][nx]) return { posY, posX };
		posY = ny; posX = nx;
		return { posY, posX };
	}
};
class Live // 몬스터, 플레이어 중복 회피 기본 클래스
{
protected:
	int attack, defense, health;
	Live(int att, int def, int hp)
	{
		attack = att;
		defense = def;
		health = hp;
	}
public:
	bool isDead()
	{
		return health <= 0;
	}
	bool getDamage(int dmg)
	{
		health = max(health - dmg, 0);
		return health > 0;
	}
	virtual int getDefense()
	{
		return defense;
	}
	virtual int getAttack()
	{
		return attack;
	}
	int getHealth()
	{
		return health;
	}
};
class Player : public Live // 플레이어 클래스
{
private:
	int maxHealth, level, experience, weapon, armor;
	AccessoryManager* accManager;
public:
	Player() : Live(2, 2, 20)
	{
		level = 1; experience = 0;
		weapon = 0, armor = 0;
		maxHealth = 20;
		accManager = new AccessoryManager();
	}
	~Player()
	{
		delete accManager;
	}

	void wearItem(Item* item)
	{
		int num = item->getNumber();
		if (item->isThisItemType(Acc)) accManager->wearAccesory((Accessory)num);
		if (item->isThisItemType(Weapon)) weapon = num;
		if (item->isThisItemType(Armor)) armor = num;
	}
	bool getTrapDamage()
	{
		if (accManager->isPlayerWearThis(Dexterity)) return getDamage(1);
		else return getDamage(5);
	}
	int getAttack() override
	{
		return weapon + attack;
	}
	int getDefense() override
	{
		return armor + defense;
	}
	void printPlayerInfo()
	{
		cout << "LV : " << level << '\n';
		cout << "HP : " << health << "/" << maxHealth << '\n';
		cout << "ATT : " << attack << "+" << weapon << '\n';
		cout << "DEF : " << defense << "+" << armor << '\n';
		cout << "EXP : " << experience << "/" << level * 5 << '\n';
	}
	void levelUp()
	{
		++level;
		experience = 0;
		maxHealth += 5; recoverFull();
		attack += 2; defense += 2;
	}
	void getExperience(int exp)
	{
		experience += ((accManager->isPlayerWearThis(Experience)) ? (1.2 * exp) : (exp));
		if (experience >= 5 * level)
			levelUp();
	}
	void recoverHp(int h)
	{
		health = min(maxHealth, health + h);
	}
	void recoverFull()
	{
		health = maxHealth;
	}
	bool isPlayerWearThis(Accessory acc)
	{
		return accManager->isPlayerWearThis(acc);
	}
	void offAccessory(Accessory acc)
	{
		accManager->offAccesory(acc);
	}
};
class Monster : public Live // 몬스터 클래스
{
private:
	const int Dummy = -1; // 더미 몬스터 처리 관련 const형
	string name;
	int exp;
	bool isBoss;
public:
	Monster() : Live(Dummy, Dummy, Dummy) // 더미 몬스터. 해당 클래스는 몬스터로 취급하지 않음.
	{
		name = "Dummy";
		exp = Dummy; isBoss = false;
	}
	Monster(string& n, int a, int d, int h, int e, bool b) : Live(a, d, h)
	{
		name = n;
		exp = e;
		isBoss = b;
	}
	string getName()
	{
		return name;
	}
	Monster(Monster* mon) : Live(mon->getAttack(), mon->getDefense(), mon->getHealth())
	{
		name = mon->getName();
		exp = mon->getMonsterExp();
		isBoss = mon->isThisMonsterBoss();
	}
	int getMonsterExp()
	{
		return exp;
	}
	bool isThisMonsterBoss()
	{
		return isBoss;
	}
	void setMonsterDead()
	{
		health = 0;
	}
};
class MonsterMap // 몬스터 위치 및 정보 관련 클래스.
{
	Monster* monster[101][101];
	int N, M;
public:
	MonsterMap(int n, int m)
	{
		N = n; M = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				monster[i][j] = new Monster();
	}
	~MonsterMap()
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				delete monster[i][j];
	}
	void setMonster(int r, int c, string name, int att, int def, int hp, int e, bool b)
	{
		monster[r][c] = new Monster(name, att, def, hp, e, b);
	}
	Monster* getMonster(pii pos)
	{
		return monster[pos.first][pos.second];
	}
	void setMonsterDead(pii pos)
	{
		monster[pos.first][pos.second]->setMonsterDead();
	}
};

class Dungeon // 지도 정보와 관련된 클래스
{
private:
	PlayerPosition* playerPos;
	char dungeon[101][101];
	int N, M, initY = 0, initX = 0;
public:
	Dungeon(int n, int m, char(&d)[101][101])
	{
		N = n; M = m;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				dungeon[i][j] = d[i][j];
				if (dungeon[i][j] == '@')
				{
					initY = i;
					initX = j;
					dungeon[i][j] = '.';
				}
			}
		playerPos = new PlayerPosition(d, n, m, initY, initX);
	}

	pii movePlayer(char cmd)
	{
		return playerPos->PlayerMove(cmd);
	}
	pii getPlayerPos()
	{
		return playerPos->getPlayerPos();
	}
	void setPlayerPos()
	{
		pii pos = getPlayerPos();
		dungeon[pos.first][pos.second] = '@';
	}
	void backToFirstPosition()
	{
		playerPos->playerRevived();
	}
	void printDungeon()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cout << dungeon[i][j];
			cout << '\n';
		}
	}
	bool isThereBoss(pii& pos)
	{
		return dungeon[pos.first][pos.second] == 'M';
	}
	bool isThereMonster(pii& pos)
	{
		return (dungeon[pos.first][pos.second] == '&' || isThereBoss(pos));
	}
	bool isThereTrap(pii& pos)
	{
		return (dungeon[pos.first][pos.second] == '^');
	}
	bool isThereBox(pii& pos)
	{
		return (dungeon[pos.first][pos.second] == 'B');
	}
	void setEmpty(pii& pos)
	{
		dungeon[pos.first][pos.second] = '.';
	}
};

class Game // 게임 진행 클래스
{
private:
	const string spikeName = "SPIKE TRAP";
	Player* player;
	MonsterMap* monsterMap;
	ItemMap* itemMap;
	Dungeon* dungeon;
	int turn;
	string command, killedMonster = "";
	Result result;

	void setInput() // input 처리
	{
		result = Continue;
		int N, M, K = 0, R, C, W, A, H, E, L = 0;
		char T;
		string S;
		char D[101][101];
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				cin >> D[i][j];
				if (D[i][j] == '&' || D[i][j] == 'M')
					K++;
				if (D[i][j] == 'B')
					L++;
			}
		dungeon = new Dungeon(N, M, D);
		monsterMap = new MonsterMap(N, M);
		itemMap = new ItemMap(N, M);
		player = new Player();
		cin >> command;
		while (K--)
		{
			cin >> R >> C >> S >> W >> A >> H >> E;
			monsterMap->setMonster(R - 1, C - 1, S, W, A, H, E, (D[R - 1][C - 1] == 'M'));
		}
		while (L--)
		{
			cin >> R >> C >> T;
			if (T == 'W' || T == 'A')
			{
				cin >> N;
				if (T == 'W') itemMap->setItemMap(R - 1, C - 1, Weapon, N);
				else itemMap->setItemMap(R - 1, C - 1, Armor, N);
			}
			else
			{
				cin >> S;
				itemMap->setItemMap(R - 1, C - 1, Acc, stringToAccessory.find(S)->second);
			}
		}
	}
	bool setBattleDamage(Live* live1, Live* live2, int attackRatio) // live1이 live2에게 공격받음.
	{
		return live1->getDamage(max(1, (live2->getAttack() * attackRatio - live1->getDefense())));
	}
	void run()
	{
		for (turn = 0; turn < command.size(); turn++)
		{
			pii npos = dungeon->movePlayer(command[turn]);
			if (dungeon->isThereTrap(npos))
			{
				bool alive = player->getTrapDamage();
				if (!alive)
				{
					if (player->isPlayerWearThis(Reincarnation))
					{
						dungeon->backToFirstPosition();
						player->recoverFull();
						player->offAccessory(Reincarnation);
					}
					else
					{
						result = PlayerDead;
						killedMonster = spikeName;
						break;
					}
				}
			}
			if (dungeon->isThereBox(npos))
			{
				player->wearItem(itemMap->getItem(npos));
				dungeon->setEmpty(npos);
			}
			if (dungeon->isThereMonster(npos))
				battleWithMonster(npos);
			if (result != Continue)
				break;
		}
		if (result != PlayerDead) dungeon->setPlayerPos();
		int t = (result == Continue) ? command.size() : turn + 1;
		printResult(t);
	}
	void battleWithMonster(pii npos)
	{
		Monster* monster = new Monster(monsterMap->getMonster(npos));
		bool firstAttack = true;
		while (true)
		{
			int ratio = 1;
			if (firstAttack && player->isPlayerWearThis(Courage))
			{
				if (player->isPlayerWearThis(Dexterity))
					ratio = 3;
				else
					ratio = 2;
			}
			if (firstAttack && monster->isThisMonsterBoss() && player->isPlayerWearThis(Hunter))
				player->recoverFull();
			if (!setBattleDamage(monster, player, ratio)) // 플레이어가 몬스터 공격
			{
				if (player->isPlayerWearThis(HPRegeneration))
					player->recoverHp(3);
				if (monster->isThisMonsterBoss())
					result = BossDead;
				dungeon->setEmpty(npos);
				monsterMap->setMonsterDead(npos);
				player->getExperience(monster->getMonsterExp());
				break;
			}
			if (firstAttack && monster->isThisMonsterBoss() && player->isPlayerWearThis(Hunter))
			{
				firstAttack = false;
				continue;
			}
			if (!setBattleDamage(player, monster, 1)) // 몬스터가 플레이어 공격
			{
				if (player->isPlayerWearThis(Reincarnation))
				{
					dungeon->backToFirstPosition();
					player->recoverFull();
					player->offAccessory(Reincarnation);
				}
				else
				{
					result = PlayerDead;
					killedMonster = monster->getName();
				}
				break;
			}
		}
	}
	void printResult(int turn)
	{
		dungeon->printDungeon();
		cout << "Passed Turns : " << turn << '\n';
		player->printPlayerInfo();
		if (result == Continue) cout << "Press any key to continue.\n";
		else if (result == PlayerDead) cout << "YOU HAVE BEEN KILLED BY " << killedMonster << "..\n";
		else cout << "YOU WIN!\n";
	}
public:
	Game()
	{
		setInput();
		run();
	}
	~Game()
	{
		delete monsterMap; delete player;
		delete dungeon; delete itemMap;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Game* game = new Game();
	delete game;
}

// https://www.acmicpc.net/problem/17081