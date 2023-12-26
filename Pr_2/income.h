#pragma once

#include <string>

#include "date.h"

struct Income {
    Date date;
    std::string source;
    int summ;

    void SetSource(const std::string source);
    std::string GetSource() const;

    void SetDate(const Date date);
    Date GetDate() const;

    void SetSumm(const int size);
    int GetSumm() const;

    void print(std::ostream& ost = std::cout) const;
    void read(std::istream& ist);

    static bool ValidateSource(const std::string& source);
    static void InvalidSource(const std::string& source);

    static bool ValidateSumm(const int& summ);
    static void InvalidSumm(const int& summ);
};

