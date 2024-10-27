#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

struct SanPham {
	char id[10];
	string ten;
	double donGia;
	int soLuong;
};

void nhapDSSanPham(SanPham sp[], int bufferSize) {
	for (int i = 0; i < bufferSize; i++) {
		cout << "ID san pham: ";
		cin.getline(sp[i].id, 10);
		cout << "Ten san pham: ";
		getline(cin, sp[i].ten);
		cout << "Don gia: ";
		cin >> sp[i].donGia;
		cout << "So luong: ";
		cin >> sp[i].soLuong;
		cin.ignore();
		cout << endl;
	}
}

void xuatDSSanPham(SanPham sp[], int bufferSize) {
	for (int i = 0; i < bufferSize; i++) {
		cout << "ID: " << sp[i].id << endl;
		cout << "Ten: " << sp[i].ten << endl;
		cout << "Don gia: " << sp[i].donGia << endl;
		cout << "So luong: " << sp[i].soLuong << endl;
		cout << endl;
	}
}

void suaThongTin(SanPham sp[], int bufferSize) {
	char idSua[10];
	cout << "Nhap san pham can sua thong tin (id): ";
	cin.getline(idSua, 10);
	for (int i = 0; i < bufferSize; i++) {
		if (strcmp(idSua, sp[i].id) == 0) {
			cout << "ID (1): " << sp[i].id << endl;
			cout << "Ten (2): " << sp[i].ten << endl;
			cout << "Don gia (3): " << sp[i].donGia << endl;
			cout << "So luong (4): " << sp[i].soLuong << endl;
			cout << endl;

			int choice;
			do {
				cout << "Nhap thong tin sua (1-4, 0 thoat!): ";
				cin >> choice;
				cin.ignore();
				switch (choice)
				{
				case 1: {
					char newId[10];
					cout << "Nhap id moi: ";
					cin.getline(newId, 10);
					strcpy(sp[i].id, newId);
					break;
				}
				case 2: {
					string newTen;
					cout << "Nhap ten moi: ";
					getline(cin, newTen);
					sp[i].ten = newTen;
					break;
				}
				case 3: {
					int newDonGia;
					cout << "Nhap don gia moi: ";
					cin >> newDonGia;
					sp[i].donGia = newDonGia;
					break;
				}
				case 4: {
					int newSoLuong;
					cout << "Nhap so luong moi: ";
					cin >> newSoLuong;
					sp[i].soLuong = newSoLuong;
					break;
				}
				}
			} while(choice!=0);
		}
	}
}

void xoaThongTin(SanPham sp[], int &bufferSize) {
	char xoaID[10];
	cout << "Nhap san pham can xoa (id): ";
	cin.getline(xoaID, 10);

	for (int i = 0; i < bufferSize; i++) {
		if (strcmp(sp[i].id, xoaID)==0) {
			for (int j = i; j < bufferSize - 1; j++) {
				sp[j] = sp[j + 1];
			}
			bufferSize--;
			cout << "Da xoa san pham: " << xoaID << endl;
			return;
		}
	}
	cout << "Khong tim thay san pham: " << xoaID << endl;
}
int main() {
	SanPham sp[2];
	int buffsz = 2;
	nhapDSSanPham(sp, buffsz);
	xuatDSSanPham(sp, buffsz);

	suaThongTin(sp, buffsz);
	xuatDSSanPham(sp, buffsz);

	xoaThongTin(sp, buffsz);
	xuatDSSanPham(sp, buffsz);
	system("pause");
	return 0;
}