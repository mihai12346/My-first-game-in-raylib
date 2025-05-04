
#include <iostream>
void tab(char tab1[3][3]) {
	for (int i = 0; i < 3; i++) {
		std::cout  << "---------";
		std::cout << std::endl;
		for (int j = 0; j < 3; j++) {
			std::cout << "|";
			std::cout  << tab1[i][j] << "|";
		}
			std::cout << std::endl;
	}
	std::cout << "---------";
	std::cout << std::endl;                      
}
bool winner(char tab1[3][3], bool win) {
	do {                         
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 3; i++) {
				if (tab1[j][0] == 'X' && tab1[j][1] == 'X' && tab1[j][2] == 'X'  || tab1[j][0] == 'O' && tab1[j][1] == 'O' && tab1[j][2] == 'O') {
					win = true;
					return true;
				}
				else if (tab1[0][i] == 'X' && tab1[1][i] == 'X' && tab1[2][i] == 'X' || tab1[0][i] == 'O' && tab1[1][i] == 'O' && tab1[2][i] == 'O')
				{
					win = true;
					return true;
				}
				if (tab1[0][0] == 'X' && tab1[1][1] == 'X' && tab1[2][2] == 'X' || tab1[0][0] == 'O' && tab1[1][1] == 'O' && tab1[2][2] == 'O'|| tab1[0][2] == 'X' && tab1[1][1] == 'X' && tab1[2][0] == 'X' || tab1[0][2] == 'O' && tab1[1][1] == 'O' && tab1[2][0] == 'O')
				{

					win = true;
					return true;
				}
			}
				
		}
	} while (win == true);
	return false;



}
void ver(char tab1[3][3], int coordonate1, int coordonate2) {
	bool win = false;
		char confirm='2';
	do {
		input1:
		std::cin >> coordonate1;
		std::cin >> coordonate2;
		if (coordonate1 == 0 || coordonate1 == 1 ||coordonate1 ==2  ||coordonate2== 0 || coordonate2 == 1 || coordonate2 == 2) {
			if (tab1[coordonate1][coordonate2] != 'O') {
				tab1[coordonate1][coordonate2] = 'X';
				tab(tab1);
			}
			else {
				std::cout << "Nu "<<"\n";
				goto input1;
			}
		}
		else {
			std::cout << "nu e bine\n";
			goto input1;
		}
		input2:
		std::cin >> coordonate1;
		std::cin >> coordonate2;
		if (coordonate1 == 0 || coordonate1 == 1 || coordonate1 == 2 || coordonate2 == 0 || coordonate2 == 1 || coordonate2 == 2) {
			if (tab1[coordonate1][coordonate2] != 'X') {
				tab1[coordonate1][coordonate2] = 'O';
				tab(tab1);
			}
			else {
				std::cout << "Nu\n ";
				goto input2;
			}
		}
		else {
			std::cout << "nu e bine\n";
			goto input2;
		}
		if (winner(tab1, win) == true) {
			std::cout << "Jocul s-a terminat";
		
			std::cin >> confirm;

		}
	} while (confirm =='Y' || confirm == 'y');
}

int main()
{
	char tab1[3][3]{
		{'1','1','1'},
		{'2','2','2'},
		{'3','3','3'}
	};
	int coordonate1 = 2;
	int coordonate2 = 2;
	tab(tab1);
	std::cout << std::endl;
	ver(tab1, coordonate1, coordonate2);
	return 0;
}


