#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include "../Pr_2/income.h"
#include "../Pr_2/income.cpp"
#include "../Pr_2/date.h"
#include "../Pr_2/date.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(ValidFormatDate)
		{
			std::vector<std::string> Cases
			{
				"2021.10.12",
				"2001.1.1",
				"2023.12.11"
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Date::ValidateDate(Cases[i]);
				Assert::IsTrue(result);
			}
		}

		TEST_METHOD(InvalidFormatDate)
		{
			std::vector<std::string> Cases
			{
				"10-12.2023",
				"ab.cd.df",
				"Hello"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Date::InvalidDate(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidFormatSource)
		{
			std::vector<std::string> Cases
			{
				"File1",
				"Dont_Delete_Pls",
				"Very_Important_File",
				"New_file1",
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Income::ValidateSource(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatSource)
		{
			std::vector<std::string> Cases
			{
				"Hello?",
				"19|84",
				"Привет"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Income::InvalidSource(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidFormatSumm)
		{
			std::vector<int> Cases
			{
				23,
				1,
				0,
				11
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Income::ValidateSumm(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatSumm)
		{
			std::vector<int> Cases
			{
				-1,
				-2
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Income::InvalidSumm(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidTestFileData)
		{
			std::istringstream input("2023.12.11 Source 2048");
			std::string str_source = "Source";
			Income file;
			file.read(input);
			Date date;
			date = file.GetDate();
			Assert::AreEqual(2023, static_cast<int>(date.GetYear()));
			Assert::AreEqual(12, static_cast<int>(date.GetMonth()));
			Assert::AreEqual(11, static_cast<int>(date.GetDay()));
			Assert::AreEqual(str_source, file.GetSource());
			Assert::AreEqual(2048, file.GetSumm());
		}
		TEST_METHOD(InvalidTestMenu)
		{
			std::vector<std::string> cases
			{
				"1231 13123.1 3213 1 fadasd",
				"aaad 131 vdvs a1",
				"da312 das 123"
			};
			for (int i = 0; i < cases.size(); i++)
			{
				std::istringstream input(cases[i]);
				try
				{
					Income file;
					file.read(input);
					throw std::runtime_error("Error in runtime");
				}
				catch (const std::runtime_error& e)
				{
					std::cerr << "Error Message: " << e.what() << std::endl;
				}
			}
		}
		TEST_METHOD(ValidMenuWrite)
		{
			std::istringstream input("2023.12.11 Source 2048");
			Income file;
			file.read(input);
			std::ostringstream expected_output;
			Date date = file.GetDate();
			expected_output << "Date: ";
			date.print(expected_output);
			expected_output << "Source: " << file.GetSource() << std::endl;
			expected_output << "Sum: " << file.GetSumm() << " rubles" << std::endl << std::endl;
			std::ostringstream actual_output;
			file.print(actual_output);
			Assert::AreEqual(expected_output.str(), actual_output.str());
		}

		TEST_METHOD(ValidDateWrite)
		{
			std::istringstream input("2023.12.11");
			Date date;
			const char point = '.';
			date.read(input);
			std::ostringstream expected_output;
			expected_output << "Date: "
				<< date.GetYear() << point
				<< std::setfill('0') << std::setw(2) << date.GetMonth() << point
				<< std::setfill('0') << std::setw(2) << date.GetDay() << std::endl;
			std::ostringstream actual_output;
			actual_output << "Date: ";
			date.print(actual_output);
			Assert::AreEqual(expected_output.str(), actual_output.str());
		}
	};
}
