#pragma once

#include <string>
#include "income.h"

using namespace std;

void Income::SetSource(const std::string ksource) {
    if (ValidateSource(ksource))
        this->source = ksource;
    else
        InvalidSource(ksource);
}

std::string Income::GetSource() const {
    return source;
}

void Income::SetDate(const Date kdate) {
    this->date = kdate;
}

Date Income::GetDate() const {
    return date;
}

void Income::SetSumm(const int ksumm) {
    if (ValidateSumm(ksumm))
        this->summ = ksumm;
    else
        InvalidSumm(ksumm);
}

int Income::GetSumm() const {
    return summ;
}

void Income::print(std::ostream& ost) const {
    ost << "Date: ";
	Date tdate = this->GetDate();
    tdate.print(ost);
    ost << "Source: " << this->GetSource() << endl;
    ost << "Sum: " << this->GetSumm() << " rubles" << endl;
    ost << endl;
}

void Income::read(std::istream& ist) {
	Date tdate;
	tdate.read(ist);
	this->SetDate(tdate);
	std::string tsource;
	if (std::getline(ist, tsource, ' ')) {
		this->SetSource(tsource);
		int tsumm;
		if (ist >> tsumm) {
			this->SetSumm(tsumm);
		}
		ist.ignore();
	};
}

bool Income::ValidateSource(const std::string& source) {
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&()_+-={[]};',.";
    for (char ch : source) {
        if (alphabet.find(ch) == std::string::npos) {
            return false;
        }
    }
    return true;
}

void Income::InvalidSource(const std::string& source)
{
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&()_+-={[]};',.";

    if (source.empty() || !ValidateSource(source) || source.find_first_not_of(alphabet) != std::string::npos) {
        throw std::runtime_error("Invalid name!");
    }
}

bool Income::ValidateSumm(const int& summ)
{
    if (summ < 0) {
        return false;
    }
    return true;
}

void Income::InvalidSumm(const int& summ)
{
    if (summ < 0) {
        throw std::runtime_error("Invalid summ!");
    }
}