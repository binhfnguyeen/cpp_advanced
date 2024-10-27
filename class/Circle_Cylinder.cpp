#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
class Circle{
    private: 
        double radius;
        string color;
    public: 
        Circle(double radius, string color){
            this->radius = radius;
            this->color = color;
        }
        double getRadius(){
            return this->radius;
        }
        string getColor(){
            return this->color;
        }
};
class Cylinder : public Circle{
    private:
        double height;
    public:
        Cylinder(double radius, string color, double height) : Circle(radius, color){
            this->height = height;
        }
        double getVolume(){
            return 3.14*Circle::getRadius()*Circle::getRadius()*height;
        }
        void in(){
            cout << "Color : " << Circle::getColor() << endl;
            cout << "Height : " << fixed << setprecision(2) << this->height << endl;
            cout << "Radius : " << fixed << setprecision(2) << Circle::getRadius() << endl;
            cout << "Volume : " << fixed << setprecision(2) << getVolume() << endl; 
            cout << "-------------------\n";
        }
};
bool cmp(Cylinder a, Cylinder b){
    if(a.getVolume()!=b.getVolume()){
        return a.getVolume() > b.getVolume();
    }
    return a.getColor() < b.getColor();
}
int main(){
    int n; cin >> n;
    vector <Cylinder> v;
    for(int i=0; i<n; i++){
        string color; double r, h;
        cin >> color >> r >> h;
        v.push_back(Cylinder(r, color, h));
    }
    sort(v.begin(), v.end(), cmp);
    for(Cylinder x: v){
        x.in();
    }
    system("pause");
    return 0;
}