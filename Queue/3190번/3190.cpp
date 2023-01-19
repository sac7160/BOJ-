#include <iostream>
#include <queue>

using namespace std;

class position
{
public:
	position(int x, int y) { this->x = x; this->y = y; }
	int x;
	int y;
};

class change_direction
{
public:
	int sec;
	char c;
};

int main()
{
	int dx[4] = { 0, 1,0, -1};
	int dy[4] = { 1, 0,-1,0};

	int n;
	cin >> n;

	int board[101][101];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) board[i][j] = 0;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;	//사과 위치 1로 표현
	}

	int l;
	cin >> l;

	queue <change_direction> changes;
	change_direction tmp;

	for (int i = 0; i < l; i++)
	{
		cin >> tmp.sec >> tmp.c;
		changes.push(tmp);
	}

	queue<position> snake;	//뱀의 위치
	snake.push(position(1, 1));
	board[1][1] = 2;	//보드 상 뱀 위치 2로 표현
	int ans = 0;

	tmp = changes.front();
	changes.pop();

	int direction = 0;

	position current_pos = snake.front();
	while (ans < 10000 + n)
	{

		current_pos.x += dx[direction];
		current_pos.y += dy[direction];


		if (current_pos.x == 0 || current_pos.y == 0 || current_pos.y > n || current_pos.x > n) break;
		else if (board[current_pos.x][current_pos.y] == 2) break;
		//종료조건

		if (board[current_pos.x][current_pos.y] == 0)
		{
			board[snake.front().x][snake.front().y] = 0;
			board[current_pos.x][current_pos.y] = 2;
			snake.pop();
			snake.push(current_pos);
		}
		else if (board[current_pos.x][current_pos.y] == 1)
		{
			board[current_pos.x][current_pos.y] = 2;
			snake.push(current_pos);
		}

		ans++;
		if (tmp.sec == ans)
		{
			if (tmp.c == 'L')
			{
				direction--;
				if (direction < 0) direction = 3;
			}
			else if (tmp.c == 'D')
			{
				direction++;
				if (direction > 3) direction = 0;
			}
			if (changes.size() != 0) {
				tmp = changes.front();
				changes.pop();
			}

		}
	}

	cout << ans+1;
}
