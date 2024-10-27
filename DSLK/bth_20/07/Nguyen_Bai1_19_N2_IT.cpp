#include <iostream>
#include <fstream>
using namespace std;

// Khai bao cau truc node
struct Node {
	int data;
	Node* next;
};

// Khai bao cau truc stack
struct Stack {
	Node* head;
};

// Kiem tra Stack co rong hay khong
bool isEmpty_Nguyen_Bai1_19_N2_IT(Stack s) {
	return s.head == NULL;
}

// Tao Node
Node* createNode_Nguyen_Bai1_19_N2_IT(int data) {
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = data;
	p->next = NULL;
	return p;
}

// Them mot phan tu vao stack
void push_Nguyen_Bai1_19_N2_IT(Stack& s, int data) {
	// Tao Node moi
	Node* p = createNode_Nguyen_Bai1_19_N2_IT(data);
	if (isEmpty_Nguyen_Bai1_19_N2_IT(s)) {
		s.head = p;
	}
	else {
		p->next = s.head;
		s.head = p;
	}
}

// Xoa phan tu dau stack
void pop_Nguyen_Bai1_19_N2_IT(Stack& s) {
	// Neu stack rong thi khong xoa
	if (s.head == NULL) {
		cout << "Stack rong, khong the xoa.\n";
		return;
	}
	else {
		// Dung bien tmp de luu dia chi Node hien tai
		Node* tmp = s.head;
		s.head = s.head->next;
		delete tmp; // Giai phong bo nho
		cout << "Da xoa phan tu khoi Stack.\n";
	}
}

// Xem phan tu dau tien trong stack
void top_Nguyen_Bai1_19_N2_IT(Stack s) {
	if (s.head == NULL) {
		cout << "Stack rong.\n";
	}
	else {
		cout << "Phan tu dau tien trong Stack: " << s.head->data << endl;
	}
}
//Duyet
void output_Nguyen_Bai1_19_N2_IT(Stack s) {
	Node* tmp = s.head;
	cout << "Stack: ";
	while (tmp != NULL) {
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}
//Doc file
void docFile_Nguyen_Bai1_19_N2_IT(Stack &s) {
	ifstream inFile("docFile_Nguyen_Bai1_19_N2_IT.txt");
	int z, idx;
	inFile >> idx;
	for (int i = 0; i < idx; i++) {
		inFile >> z;
		push_Nguyen_Bai1_19_N2_IT(s, z);
	}
	cout << "Doc file thanh cong\n";
	inFile.close();
}
//Ghi file
void ghiFile_Nguyen_Bai1_19_N2_IT(Stack &s){
    ofstream outFile("docFile_Nguyen_Bai1_19_N2_IT.txt");
    int n; cout << "Nhap so phan tu: \n";
    cin >> n;
    outFile << n << endl;
    for(int i=0; i<n; i++){
        int x = rand()%50;
        outFile << x << " ";
    }
    cout << "Ghi file thanh cong!\n";
}
//Chuyen thap phan sang nhi phan
void decToBin_Nguyen_Bai1_19_N2_IT(Stack &s, int x) {
	while (x) {
		push_Nguyen_Bai1_19_N2_IT(s, x % 2);
		x /= 2;
	}
	output_Nguyen_Bai1_19_N2_IT(s);
}
void menu_Nguyen_Bai1_19_N2_IT() {
	cout << "============ MENU ============" << endl;
	cout << "1. Them phan tu vao Stack" << endl;
	cout << "2. Xoa phan tu khoi Stack" << endl;
	cout << "3. Xem phan tu dau tien trong Stack" << endl;
	cout << "4. Duyet Stack" << endl;
	cout << "5. Phan tu dau Stack" << endl;
	cout << "6. Doc file" << endl;
	cout << "7. Chuyen thap phan sang nhi phan" << endl;
    cout << "8. Ghi file" << endl;
	cout << "0. Thoat" << endl;
	cout << "=============================" << endl;
}

int main() {
	Stack s;
	s.head = NULL;
	int choice;

	do {
		menu_Nguyen_Bai1_19_N2_IT();
		cout << "Xin nhap lua chon: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "- Them phan tu vao Stack -" << endl;
			int x;
			cout << "Nhap phan tu can them: ";
			cin >> x;
			push_Nguyen_Bai1_19_N2_IT(s, x);
			break;
		case 2:
			cout << "- Xoa phan tu khoi Stack -" << endl;
			pop_Nguyen_Bai1_19_N2_IT(s);
			break;
		case 3:
			cout << "- Xem phan tu dau tien trong Stack -" << endl;
			top_Nguyen_Bai1_19_N2_IT(s);
			break;
		case 4:
			cout << "- Duyet Stack -" << endl;
			output_Nguyen_Bai1_19_N2_IT(s);
			break;
		case 5:
			cout << "-Phan tu dau Stack-" << endl;
			top_Nguyen_Bai1_19_N2_IT(s);
			break;
		case 6: 
			cout << "-Doc file-\n";
			docFile_Nguyen_Bai1_19_N2_IT(s);
			break;
		case 7: 
			Stack st;
			st.head = NULL;
			cout << "-Chuyen thap phan sang nhi phan-\n";
			int xx; cout << "Nhap so can chuyen: \n";
			cin >> xx;
			decToBin_Nguyen_Bai1_19_N2_IT(st, xx);
			break;
        case 8:
            cout << "-Ghi file-\n";
            ghiFile_Nguyen_Bai1_19_N2_IT(s);
			break;
		case 0:
			cout << "- Cam on da su dung chuong trinh -" << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long nhap lai.\n";
		}
	} while (choice != 0);

	system("pause");
	return 0;
}