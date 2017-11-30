#include <iostream>
#include <string>

using namespace std;

char ch[250][250];
int M, N;

int Ffunc(int x, int y, char color);

int main()
{
	char head;			//¸Ç ¾Õ¿¡ ¾ËÆÄºª
	char tail;			//¹Ù²Ü »ö±ò(?)
	string name;		//¾ËÆÄºª SÀÏ ¶§ ÆÄÀÏ ÀÌ¸§
	int x1, x2, y1, y2;
	
	while(true)
	{
		cin >> head;

		switch (head)
		{
		case 'I':
			cin >> M >> N;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					ch[i][j] = 'O';
				}
			}

			break;

		case 'X':
			return 0;

			break;

		case 'S':
			cin >> name;
			cout << name << endl;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					cout << ch[i][j];
				}
				cout << endl;
			}

			break;

		case 'L':
			cin >> x1 >> y1 >> tail;

			ch[y1 - 1][x1 - 1] = tail;

			break;

		case 'C':
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					ch[i][j] = 'O';
				}
			}

			break;

		case 'V':
			cin >> x1 >> y1 >> y2 >> tail;

			for (int i = y1; i < y2 + 1; i++)
			{
				ch[i - 1][x1 - 1] = tail;
			}

			break;

		case 'H':
			cin >> x1 >> x2 >> y1 >> tail;

			for (int i = x1; i < x2 + 1; i++)
			{
				ch[y1 - 1][i - 1] = tail;
			}

			break;

		case 'K':
			cin >> x1 >> y1 >> x2 >> y2 >> tail;

			for (int i = y1; i < y2 + 1; i++)
			{
				ch[i - 1][x1 - 1] = tail;
				ch[i - 1][x2 - 1] = tail;
			}

			for (int i = x1; i < x2 + 1; i++)
			{
				ch[y1 - 1][i - 1] = tail;
				ch[y2 - 1][i - 1] = tail;
			}

			break;

		case 'F':
			cin >> x1 >> y1 >> tail;

			Ffunc(x1, y1, tail);

			break;
		}
	}
	
	return 0;
}

int Ffunc(int x, int y, char color)
{
	if (color == ch[y - 1][x - 1])
	{
		return 0;
	}

	char beforeColor;
	beforeColor = ch[y - 1][x - 1];

	ch[y - 1][x - 1] = color;

	if (x >= 0 && y >= 0 && x <= M && y <= N)
	{
		if (ch[y - 2][x] == beforeColor)
		{
			Ffunc(x + 1, y - 1, color);
		}

		if (ch[y - 2][x - 1] == beforeColor)
		{
			Ffunc(x, y - 1, color);
		}

		if (ch[y - 2][x - 2] == beforeColor)
		{
			Ffunc(x - 1, y - 1, color);
		}

		if (ch[y - 1][x] == beforeColor)
		{
			Ffunc(x + 1, y, color);
		}

		if (ch[y - 1][x - 2] == beforeColor)
		{
			Ffunc(x - 1, y, color);
		}

		if (ch[y][x] == beforeColor)
		{
			Ffunc(x + 1, y + 1, color);
		}

		if (ch[y][x - 1] == beforeColor)
		{
			Ffunc(x, y + 1, color);
		}

		if (ch[y][x - 2] == beforeColor)
		{
			Ffunc(x - 1, y + 1, color);
		}
	}

	return 0;
}