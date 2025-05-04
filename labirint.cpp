#include <iostream>
void maze(char maze1[5][5]) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					std::cout << maze1[i][j];
				}
			std::cout<<"\n";
			}
}
bool cango(bool go, char maze1[5][5], int x, int y,char simbol) {
	switch (simbol) {
	case ('w'):
		if (maze1[y - 1][x] != '0') {
			return true;
		}else{ std::cout << "ho,ho,ho,no" << std::endl; }
		break;
	case('d'):
		if (maze1[y][x + 1] != '0') {
			return true;
		}
		else {
			std::cout << "ho,ho,ho,no" << std::endl;
		}
break;
	}
	return false;
}
void ver1(char maze1[5][5], char simbol) {
	bool go = true;
	int x = 1;
	int y = 4;
	while (true) {
			std::cin >> simbol;
			
			switch (simbol) {

			case ('w'):
				if (cango(go, maze1, x, y, simbol) == true) {
					y -= 1;
					maze1[y][x] = 's';
				}

				maze(maze1);

				break;
			case('d'):
				if (cango(go, maze1, x, y, simbol) == true) {
					x += 1;
					maze1[y][x] = 's';
					maze(maze1);
				}
break;
			}
			}
}
int main()
{
	char simbol='g';
	char maze1[5][5]{

		{'0','0','0','0','1'},
		{'0','0','1','1','1'},
		{'0','0','1','0','0'},
		{'0','1','1','0','0'},
		{'0','s','0','0','0'}
};
	maze(maze1);
	std::cout << "\n";
	ver1(maze1, simbol);
	return 0;
}
