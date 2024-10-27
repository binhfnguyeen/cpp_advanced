#include "PhanSo.h"

int PhanSo::getTuso() {
	return tuso;
}

int PhanSo::getMauso() {
	return mauso;
}

void PhanSo::setTuso(int a) {
	this->tuso = a;
}

void PhanSo::setMauso(int b) {
	this->mauso = b;
}

PhanSo PhanSo::tichPhanSo(PhanSo ps1, PhanSo ps2) {
	PhanSo *kq;
	kq->tuso = ps1.tuso*ps2.tuso;
	kq->mauso = ps2.mauso*ps2.mauso;
	kq->reduce();
	return *kq;
}
int main() {
	PhanSo ps1, ps2, kq;
	ps1.setTuso(1);
	ps1.setMauso(2);
	ps2.setTuso(1);
	ps2.setMauso(2);
	kq = kq.tichPhanSo(ps1, ps2);
	kq.hienThi();
	system("pause");
	return 0;
}