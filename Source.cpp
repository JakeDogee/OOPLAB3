#include <iostream>
#include <Windows.h>
#include <Time.h>
const int MAX = 5;
using namespace std;

class Time {
private:
    int hour;
    int min;
    int sec;

public:
    Time()
    {
        hour = 0;
        min = 0;
        sec = 0;
    }
    Time(int valuehours, int valueminutes, int valueseconds)
    {
        hour = valuehours;
        min = valueminutes;
        sec = valueseconds;
    }
    Time(const Time& copy) {
        this->hour = copy.hour;
        this->min = copy.min;
        this->sec = copy.sec;
    }
    ~Time()
    {}

    void gethours(int valuehours) { this->hour = valuehours; }
    void getminutes(int valueminutes) { this->min = valueminutes; }
    void getseconds(int valueseconds) { this->sec = valueseconds; }

    void Print() {

        if (this->hour < 10) { cout << "0" << this->hour << ":"; }
        else { cout << this->hour << ":"; }
        if (this->min < 10) { cout << "0" << this->min << ":"; }
        else { cout << this->min << ":"; }
        if (this->sec < 10) { cout << "0" << this->sec << "|"; }
        else { cout << this->sec << "|"; }

        if (this->hour <= 12)
        {
            if (this->hour < 10) { cout << "0" << this->hour << ":"; }
            else { cout << this->hour << ":"; }
            if (this->min < 10) { cout << "0" << this->min << ":"; }
            else { cout << this->min << ":"; }
            if (this->sec < 10) { cout << "0" << this->sec << "AM"; }
            else { cout << this->sec << "AM"; }
        }
        else
        {
            if (this->hour < 10) { cout << "0" << this->hour << ":"; }
            else { cout << this->hour << ":"; }
            if (this->min < 10) { cout << "0" << this->min << ":"; }
            else { cout << this->min << ":"; }
            if (this->sec < 10) { cout << "0" << this->sec << "PM"; }
            else { cout << this->sec << "PM"; }
        }
        cout << " \n";
    }
    void ChangeTime() {
        while (this->sec >= 60) {
            getseconds(this->sec - 60);
            this->min++;
        }
        while (this->min >= 60) {
            getminutes(this->min - 60);
            this->hour++;
        }
        while (this->hour >= 24) {
            gethours(this->hour - 24);
        }
    }

    void GetRealTime() {
        SYSTEMTIME tt;
        GetLocalTime(&tt);
        this->hour = tt.wHour;
        this->min = tt.wMinute;
        this->sec = tt.wSecond;
    }

    void Randometime(Time Ex[]) {
        srand(time(NULL));
        for (int i = 0; i <= MAX; i++) {
            Ex[i].hour = rand() % 24;
            Ex[i].min = rand() % 100;
            Ex[i].sec = rand() % 100;
            Ex[i].ChangeTime();
        }
    }

    int operator<=(Time Ex) {
        int oop_min = hour * 60 + min;
        int ex_min = Ex.hour * 60 + Ex.min;
        int res = oop_min - ex_min;
        return res;
    }

    int operator+=(int n) {
        min += n;
        return min;
    }

    void Sortby(Time Ex[], Time Rtime) {
        Time temp;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX - i; j++) {

                if ((Ex[j] <= Rtime) > (Ex[j + 1] <= Rtime))
                {
                    temp = Ex[j];
                    Ex[j] = Ex[j + 1];
                    Ex[j + 1] = temp;
                }
            }
        }
    }
    void addition(int n, Time Ex[]) {
        for (int i = 0; i <= MAX; i++) {
            Ex[i] += n;
            Ex[i].ChangeTime();
        }
        cout << "\nДадавання  " << n << " хвилин до часу :" << endl;
    }
};


int main() {

    system("chcp 1251");
    Time RealTime;
    Time CopyArray[MAX];

    CopyArray[0].Randometime(CopyArray);
    RealTime.GetRealTime();
    cout << "\nТеперішній час :" << endl;
    RealTime.Print();
    cout << "\nВідсортований випадковий час :" << endl;
    RealTime.Sortby(CopyArray, RealTime);
    for (int i = 0; i < MAX; i++) {
        CopyArray[i].Print();
    }
    CopyArray[0].addition(40, CopyArray);
    for (int i = 0; i < MAX; i++) {
        CopyArray[i].Print();
    }
    return 0;
}
