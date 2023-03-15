#include <iostream>
#include <cstring>
#pragma warning (disable:4996)

namespace Students
{
	enum class Major
	{
		Cs,
		Is,
		I,
		Si,
		unknown
	};

	void PrintMajor(const Major& major)
	{
		switch (major)
		{
		case Major::Cs: std::cout << "Computer sience" << std::endl; break;
		case Major::Is: std::cout << "Information systems" << std::endl; break;
		case Major::I: std::cout << "Informatics" << std::endl; break;
		case Major::Si: std::cout << "Software engineering" << std::endl; break;
		default: std::cout << "Unknown" << std::endl;
		}
	}

	struct Student
	{
		char name[24] = "";
		int fn = -1;
		Major studentMajor = Major::unknown;
	};

	void print(const Student& st)
	{
		std::cout << "Name: " << st.name << ", fn: " << st.fn << " ";
		PrintMajor(st.studentMajor);
		std::cout << std::endl;
	}
}

namespace Univeristy
{
	using namespace Students;

	const size_t STUDENTS_COUNT = 4;

	struct University
	{
		Student students[STUDENTS_COUNT];
	};

	enum class SortBy
	{
		name,
		fn,
		major
	};

	bool compare(const Student& lhs, const Student& rhs, SortBy sortBy)
	{
		switch (sortBy)
		{
		case SortBy::name: return strcmp(lhs.name, rhs.name) < 0; break;
		case SortBy::fn:   return lhs.fn < rhs.fn;
		case SortBy::major: return lhs.studentMajor < rhs.studentMajor;
		default: return false;
		}
	}
	void sortStudentsInUni(University& uni, SortBy sortBy)
	{
		for (int i = 0; i < STUDENTS_COUNT - 1; i++)
		{
			int minIndex = i;
			for (int j = i; j < STUDENTS_COUNT; j++)
			{
				if (compare(uni.students[j], uni.students[minIndex], sortBy))
					minIndex = j;
			}

			if (i != minIndex)
				std::swap(uni.students[i], uni.students[minIndex]);
		}
	}

	void printUni(const University& uni)
	{
		for (size_t i = 0; i < STUDENTS_COUNT; i++)
			print(uni.students[i]);
	}
}

int main() 
{
	using namespace Univeristy;

	University uni{ "Ivan Petrov", 434, Major::Cs ,
			"Peter Ivanov", 987, Major::Si,
			"Alex Angelov", 12, Major::I  ,
			"Kristian Kasabov", 12, Major::I} ;

	printUni(uni);
	std::cout << "----------------" << std::endl;
	sortStudentsInUni(uni, SortBy::name);
	printUni(uni);
	std::cout << "----------------" << std::endl;
	sortStudentsInUni(uni, SortBy::fn);
	printUni(uni);
	std::cout << "----------------" << std::endl;

	sortStudentsInUni(uni, SortBy::major);
	printUni(uni);
	std::cout << "----------------" << std::endl;
}