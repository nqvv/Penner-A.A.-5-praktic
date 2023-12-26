#pragma once

#include <iostream>

struct Date {
    int year;
    int month;
    int day;
        
    void SetYear(const int year);
    int GetYear() const;

    void SetMonth(const int month);
    int GetMonth() const;

    void SetDay(const int day);
    int GetDay() const;

    void print(std::ostream& ost = std::cout) const;
    void read(std::istream& ist);

    static bool ValidateDate(const int year, const int month, const int day);
    static void InvalidDate(const int year, const int month, const int day);
};

