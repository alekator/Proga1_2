#ifndef PROGA2_DATA_H
#define PROGA2_DATA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
class Date {
public:
    Date();
    Date(int day, int month, int year, int hour, int minute, int second);
    Date(Date &a);
    ~Date();
    void SetDay(int day);
    void SetMonth(int month);
    void SetY(int year);
    void SetH(int hour);
    void SetMinute(int minute);
    void SetSecond(int second);
    void Plus(char k);
    void DayPlus();
    void HourPlus();
    void MinutePlus();
    void SecondPlus();
    void Minus(char k);
    void DayMinus();
    void HourMinus();
    void MinuteMinus();
    void SecondMinus();
    static int countCalc(int num);
    void ToString();
    char* Getstr();
    friend Date operator+(const Date &d1, const Date &d2);
    friend Date operator-(const Date &d1, const Date &d2);
    Date &operator=(const Date &right);
private:
    int Day, Month, Year, Hour, Minute, Second;
    char* str;
    static bool CheckData(int day, int month, int year);
    static bool CheckTime(int hour, int minute, int second);
    static bool CheckDay(int day, int month, int year);
};

#endif //PROGA2_DATA_H
