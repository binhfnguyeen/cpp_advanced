#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next;
};

void init(Node *&head) {
	head = NULL;
}

Node *createNode(int x) {
	Node *p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}

void themDau(Node *&head, int x) {
	Node *p = createNode(x);
	p->next = head;
	head = p;
}
void themSau(Node *&head, int x) {
	Node *p = createNode(x);
	if (head == NULL) {
		head = p;
		return;
	}
	else {
		Node *cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = p;
	}
}

void xoaALL(Node *&head) {
	while (head != NULL) {
		Node *p = head;
		head = p->next;
		p->next = NULL;
		delete p;
	}
}

void output(Node *head) {
	Node *p = head;
	while (p->next != NULL) {
		cout << p->value << "\t";
		p = p->next;
	}
	cout << endl;
}

Node *Tim(Node *head, int v) {
	Node *q = head;
	while (q != NULL && q->value != v) {
		q = q->next;
	}
	return q;
}
int main() {
	Node *head;
	init(head);
	cout << "Them dau: \n";
	themDau(head, 77);
	themDau(head, 88);
	themDau(head, 99);
	themDau(head, 5);
	themDau(head, 10);
	themDau(head, 15);
	output(head);
	cout << "Xoa het" << endl;
	xoaALL(head);
	cout << "Them cuoi: \n";
	themSau(head, 15);
	themSau(head, 10);
	themSau(head, 5);
	themSau(head, 99);
	themSau(head, 88);
	themSau(head, 77);
	output(head);
	if (Tim(head, 108)) {
		cout << "Tim thay " << 108 << " trong danh sach\n";
	}
	else {
		cout << "Ko tim thay " << 108 << " trong danh sach\n";
	}
	if (Tim(head, 77)) {
		cout << "Tim thay " << 77 << " trong danh sach\n";
	}
	else {
		cout << "Ko tim thay " << 77 << " trong danh sach\n";
	}
	system("pause");
	return 0;
}