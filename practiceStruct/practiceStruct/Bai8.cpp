#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct MaTran {
	int row;
	int col;
	int **matrix;
};

void initMaTran(MaTran &mt) {
	mt.matrix = new int*[mt.row];
	for (int i = 0; i < mt.row; i++) {
		mt.matrix[i] = new int[mt.col];
		for (int j = 0; j < mt.col; j++) {
			mt.matrix[i][j] = rand() % 100;
		}
	}
}

void xuatMaTran(MaTran mt) {
	for (int i = 0; i < mt.row; i++) {
		for (int j = 0; j < mt.col; j++) {
			cout << mt.matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

bool isDoiXung(int num) {
	int tmp = num, rev_num=0;
	while (tmp != 0) {
		rev_num += rev_num*10 + tmp % 10;
		tmp /= 10;
	}
	return rev_num == num;
}

int tongDoiXung(MaTran mt) {
	int tong = 0;
	for (int i = 0; i < mt.row; i++) {
		for (int j = 0; j < mt.col; j++) {
			if (isDoiXung(mt.matrix[i][j])) {
				tong += mt.matrix[i][j];
			}
		}
	}
	return tong;
}
int main() {
	srand(time(nullptr));
	MaTran mt;
	cout << "Nhap so dong: ";
	cin >> mt.row;
	cout << "Nhap so cot: ";
	cin >> mt.col;

	initMaTran(mt);
	xuatMaTran(mt);

	cout << "Tong doi xung: " << tongDoiXung(mt) << endl;

	for (int i = 0; i < mt.row; i++) {
		delete[] mt.matrix[i];
	}
	delete[] mt.matrix;
	system("pause");
	return 0;
}