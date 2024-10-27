#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct TichCuc {
	string keyWord[100];
	int frequency;
	int size;

	void initWord(const string word[], int wordSize) {
		size = min(wordSize, 100);
		for (int i = 0; i < size; i++) {
			keyWord[i] = word[i];
		}
		frequency = 0;
	}
};

struct TieuCuc
{
	string keyWord[100];
	int frequency;
	int size;

	void initWord(const string word[], int wordSize) {
		size = min(wordSize, 100);
		for (int i = 0; i < size; i++) {
			keyWord[i] = word[i];
		}
		frequency = 0;
	}
};

void tinhTanSuat(const string data[], int dataSize, TichCuc &tichCuc, TieuCuc &tieuCuc) {
	tichCuc.frequency = 0;
	tieuCuc.frequency = 0;
	for (int i = 0; i < dataSize; i++) {
		for (int j = 0; j < tichCuc.size; j++) {
			if (data[i] == tichCuc.keyWord[j]) {
				tichCuc.frequency++;
				break;
			}
		}
		for (int j = 0; j < tieuCuc.size; j++) {
			if (data[i] == tieuCuc.keyWord[j]) {
				tieuCuc.frequency++;
				break;
			}
		}
	}
}

string danhGia(const TichCuc &tichCuc, const TieuCuc &tieuCuc) {
	double freTichCuc = (double)tichCuc.frequency / (tichCuc.frequency + tieuCuc.frequency) * 100;
	double freTieuCuc = (double)tieuCuc.frequency / (tieuCuc.frequency + tichCuc.frequency) * 100;
	if (freTichCuc > 60 && freTieuCuc < 60) {
		return "Tich cuc";
	}
	if (freTieuCuc > 60 && freTichCuc < 60) {
		return "Tieu cuc";
	}
	return "Trung lap";
}
int main() {
	string data[] = { "positive_word1", "positive_word2", "negative_word1", "negative_word2" };
	int dataSize = sizeof(data) / sizeof(data[0]);
	string pos[] = { "positive_word1", "positive_word2" };
	int posSize = sizeof(pos) / sizeof(pos[0]);
	string neg[] = { "negative_word1" };
	int negSize = sizeof(neg) / sizeof(neg[0]);
	TichCuc tichCuc;
	TieuCuc tieuCuc;
	tichCuc.initWord(pos, posSize);
	tieuCuc.initWord(neg, negSize);
	tinhTanSuat(data, dataSize, tichCuc, tieuCuc);
	cout << "Danh gia: " << danhGia(tichCuc, tieuCuc) << endl;
	system("pause");
	return 0;
}