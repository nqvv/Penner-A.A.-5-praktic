#pragma once

#include <iostream>
#include <sstream>
#include "date.h"

void Date::SetYear(const int year)
{
	this->year = year;
}

int Date::GetYear() const
{
	return year;
}

void Date::SetMonth(const int month)
{
	this->month = month;
}

int Date::GetMonth() const
{
	return month;
}

void Date::SetDay(const int day)
{
	this->day = day;
}

int Date::GetDay() const
{
	return day;
}

void Date::print(std::ostream& ost) const
{
	ost << this->GetYear() << "." << this->GetMonth() << "." << this->GetDay() << std::endl;
}

void Date::read(std::istream& ist)
{
	int year, month, day;
	char point = '.';
	if (!(ist >> year >> point >> month >> point >> day)) {
		throw std::runtime_error("Неверный формат даты");
	}

	else if (ValidateDate(year, month, day))
	{
		this->SetYear(year);
		this->SetMonth(month);
		this->SetDay(day);
	}

	if (point != '.') {
		throw std::runtime_error("Неверный разделитель даты. Используйте точку.");
;
	}

	ist.ignore();
}

bool Date::ValidateDate(const int year, const int month, const int day) {
	if (month < 1 || month > 12 || day < 1 || day > 31 || year > 2023)
	{
		throw std::runtime_error("date is invalid 5");
		return false;
	}

	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2 && day > 29)
	{
		throw std::runtime_error("date is visokosniy god, Feb day !>29");
		return false;
	}

	if (((year % 4 != 0 || year % 100 == 0) && year % 400 != 0) && month == 2 && day > 28)
	{
		throw std::runtime_error("date is ne visokosniy god, Feb day !>28");
		return false;
	}

	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
	{
		throw std::runtime_error("v month ne > 31 day");
		return false;
	}

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		throw std::runtime_error("v month ne > 30 day");
		return false;
	}
	return true;
}

void Date::InvalidDate(const int year, const int month, const int day)
{
	if (!ValidateDate(year, month, day)) {
		throw std::runtime_error("Invalid time!");
	}
	ValidateDate(year, month, day);
}
