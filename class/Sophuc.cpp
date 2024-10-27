#include <iostream>
using namespace std;

class SoPhuc{
    private: 
        int thuc, ao;
    public:
        SoPhuc(int thuc, int ao){
            this->thuc = thuc;
            this->ao = ao;
        }
        SoPhuc operator + (SoPhuc khac){
            this->thuc += khac.thuc;
            this->ao +=khac.ao;
            return SoPhuc(this->thuc, this->ao);
        }
        void in(){
            cout << thuc;
            if(ao < 0 ) cout << ao << "j\n";
            else cout << "+" << ao << "j\n";
        }
};

int main(){
    SoPhuc x(3, 5); 
    x.in();
    SoPhuc y(2, -7);
    y.in();
    SoPhuc z = x+y;
    z.in();
    system("pause");
    return 0;
}