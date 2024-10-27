#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

bool isLeapDay(int year){
    return ((year % 4 ==0 && year % 100 != 0) || (year % 400 == 0));
}

void dayOfYear(const char *date){
    int day, month, year;
    sscanf(date, "%d-%d-%d", &day, &month, &year);

    int daysInMonth[] = {31, 28+isLeapDay(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayCount = day;
    for(int i=0; i<month-1; i++){
        dayCount += daysInMonth[i];
    }
    int year2 = year; //16/01/2004
    if (month < 3) {
        month += 12;
        year2--;
    }
    int dayOfWeek = (day + 2 * month + 3 * (month + 1) / 5 + year2 + year2 / 4 - year2 / 100 + year2 / 400) % 7;
    
    const char* dayNames[] = {"thu hai", "thu ba", "thu tu", "thu nam", "thu sau", "thu bay", "chu nhat"};
    
    cout << "Ngay " << date << " la ngay thu " << dayCount << " trong nam, va la " << dayNames[dayOfWeek] << " trong tuan." << endl;
}
int main(){
    char inpDate[11];
    cout << "Nhap vao ngay-thang-nam (dd-mm-yyyy): ";
    cin >> inpDate;
    dayOfYear(inpDate);
    system("pause");
    return 0;
}