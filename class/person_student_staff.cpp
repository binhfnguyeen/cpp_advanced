#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
private: 
    string name, address;
public: 
    Person(string name, string address){
        this->name = name;
        this->address = address;
    }
    void in(){
        cout << "Full name : " << this->name << endl;
        cout << "Address : " << this->address << endl;
    }
    string getName(){
        return name;
    }
};

class Student : public Person{
    private: 
        string program;
        int year;
        double fee;
    public: 
        Student(string name, string address, string program, int year, double fee) : Person(name, address){
            this->program = program;
            this->year = year;
            this->fee = fee;
        }
        void in(){
            cout << "-----------------\n";
            Person::in();
            cout << "Program : " << this->program << endl;
            cout << "Year : " << this->year << endl;
            cout << "Fee : " << this->fee << " $ " << endl;
            
        }
        double getFee(){
            return this->fee;
        }
};

class Staff : public Person{
    private: 
        string school;
        int pay;
    public: 
        Staff(string name, string address, string school, int pay) : Person(name, address){
            this->school = school;
            this->pay = pay;
        }
        void in(){
            cout << "-----------------\n";
            Person::in();
            cout << "School : " << this->school << endl;
            cout << "Pay : " << this->pay << " $\n";
        }
        int getPay(){
            return this->pay;
        }
};
bool cmp1(Staff a, Staff b){
    if(a.getPay()!=b.getPay()){
        return a.getPay() > b.getPay();
    }
    return a.getName() < b.getName();
}
bool cmp2(Student a, Student b){
    if(a.getFee()!=b.getFee()){
        return a.getFee()<b.getFee();
    }
    return a.getName() < b.getName();
}
int main(){
    int n, m;
    cin >> n >> m;
    vector <Student> v1;
    vector <Staff> v2;
    for(int i=0; i<n; i++){
        string tmp; cin >> tmp;
        cin.ignore();
        string name, address, program;
        int year, fee;
        getline(cin, name);
        getline(cin, address);
        getline(cin, program);
        cin >> year >> fee;
        v1.push_back(Student(name, address, program, year, fee));
    }
    for(int i=0; i<m; i++){
        string tmp; cin >> tmp;
        cin.ignore();
        string name, address, school;
        int pay;
        getline(cin, name);
        getline(cin, address);
        getline(cin, school);
        cin >> pay;
        v2.push_back(Staff(name, address, school, pay));
    }
    sort(v1.begin(), v1.end(), cmp2);
    sort(v2.begin(), v2.end(), cmp1);
    cout << "-----------------\n";
    cout << "Student List : \n";
    for(Student x: v1){
        x.in();
    }    
    cout << "-----------------\n";
    cout << "Staff List : \n";
    for(Staff x: v2){
        x.in();
    }
    system("pause");
    return 0;
}