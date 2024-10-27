#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;

int A[MAX][MAX];
int sodinh;
int E1[MAX], E2[MAX], wE[MAX], nE=0; //Lưu cạnh
int T1[MAX], T2[MAX], wT[MAX], nT=0; //Lưu đỉnh
//Kiểm tra phần tử có tồn tại trong mảng không
int tonTai(int d, int D[], int nD){
    for(int i=0; i<nD; i++){ //Nếu trong mảng D, có tồn tại D[i]=d
        if(D[i]==d){
            cout << D[i] <<  " " << endl;
            return 1; //Tồn tại d
        }
    }
    return 0; //Không tồn tại d
}
//Xuất giá trị cây khung tối tiểu
void output(){
    int tong=0;
    for(int i=0; i<nT; i++){ //Tổng các đỉnh của Cây khung, không tạo thành chu trình
        cout << "(" << T1[i] << "," << T2[i] << ")=" << wT[i] << " ";
        tong += wT[i]; //Tổng
    }
    cout << endl;
    cout << "Tong cay khung toi tieu: " << tong << endl;
}

void taoE(){
    for(int i=0; i<sodinh; i++){
        for(int j=0; j<sodinh; j++){
            if(A[i][j]!=0){ //Chưa được duyệt
                E1[nE] = i; //Đỉnh đầu tiên của cạnh
                E2[nE] = j; //Đỉnh thứ hai của cạnh
                wE[nE] = A[i][j]; //Trọng số cạnh
                A[i][j] = A[j][i] = 0; //Đánh dấu đã duyệt
                nE++; //Tăng giá trị để đánh dấu tìm thấy cạnh mới
            }
        }
    }
}
//Sắp xếp theo E, cơ số wE tăng dần
void sapxepE(){
    for(int i=0; i<nE-1; i++){
        for(int j=i+1; j<nE; j++){
            if(wE[i]>wE[j]){ //Sắp xếp cơ số tăng
                swap(wE[i], wE[j]);
                swap(E1[i], E1[j]);
                swap(E2[i], E2[j]);
            }
        }
    }
    for(int i=0; i<nE; i++){
        cout << E1[i] << " " << E2[i] << " " << wE[i] << endl;
    }
}
//Thuật toán Kruskal
void kruskal(){
    for(int i=0; i<nE; i++){
        if ((tonTai(E1[i], T1, nT)==1 && tonTai(E2[i], T2, nT)==1)){
            
            continue;
        } 
        if ((tonTai(E1[i], T2, nT)==1 && tonTai(E2[i], T1, nT)==1)){
            continue;
        }
        T1[nT]=E1[i];
        T2[nT]=E2[i];
        wT[nT]=wE[i];
        nT++;
        if(nT == sodinh-1){
            break;
        }
    }
}

int main(){
    cout << "Nhap so dinh: \n";
    cin >> sodinh;
    cout << "Nhap ma tran ke: \n";
    for(int i=0; i<sodinh; i++){
        for(int j=0; j<sodinh; j++){
            // cout << "A[" << i  << "][" << j << "]=";
            cin >> A[i][j];
        }
    }
    cout << endl;
    for(int i=0; i<sodinh; i++){
        for(int j=0; j<sodinh; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    taoE();
    sapxepE();
    kruskal();
    output();
    system("pause");
    return 0;
}