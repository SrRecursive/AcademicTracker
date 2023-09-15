#include "../include/grade.hpp"
#include "../include/checker.hpp"

void add_grade(std::string filePath)
{
	std::ofstream file(filePath, std::ios::app);
	std::string subject;
	int grade;

	std::cout << "Introduce the subject: ";
	std::cin >> subject;
	if (check_subject(filePath, subject) == true)
	{
		std::cout << "There can't be two identical subjects!" << std::endl;
		return;
	}
	std::cout << "Introduce the grade: ";
	std::cin >> grade;
	file << subject << ": " << grade << std::endl;
	file.close();
}

void remove_grade(std::string filePath)
{
	int grade;
	std::string subject, line, findLine;
	std::ifstream file(filePath);
	std::ofstream newfile("temp.txt");

	if (!file.is_open() || !newfile.is_open())
	{
		std::cerr << "Error opening the file" << std::endl;
		return;
	}
	std::cout << "Introduce the subject: ";
	std::cin >> subject;
	std::cout << "Introduce the grade: ";
	std::cin >> grade;
	findLine = subject + ": " + std::to_string(grade);
	if (check_subject(filePath, findLine) == false)
	{
		std::cout << "Does not exist!" << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		if (line.find(findLine) != std::string::npos)
		{
			continue;
		}
		newfile << line << std::endl;
	}
	file.close();
	newfile.close();
	if (std::remove(filePath.c_str()) != 0)
	{
		std::cerr << "Error removing the original file" << std::endl;
		return;
	}
	if (std::rename("temp.txt", filePath.c_str()) != 0)
	{
		std::cerr << "Error renaming the temp file" << std::endl;
		return;
	}
	std::cout << "Grade removed" << std::endl;
}

void edit_grade(std::string filePath)
{
	int grade, newGrade;
	std::string subject, line, findLine;
	std::ifstream file(filePath);
	std::ofstream newfile("temp.txt");

	if (!file.is_open() || !newfile.is_open())
	{
		std::cerr << "Error opening the file" << std::endl;
		return;
	}
	std::cout << "Introduce the subject: ";
	std::cin >> subject;
	std::cout << "Introduce the grade: ";
	std::cin >> grade;
	findLine = subject + ": " + std::to_string(grade);
	if (check_subject(filePath, findLine) == false)
	{
		std::cout << "Does not exist!" << std::endl;
		return;
	}
	std::cout << "Introduce the new grade: ";
	std::cin >> newGrade;
	while (std::getline(file, line))
	{
		if (line.find(findLine) != std::string::npos)
		{
			line = subject + ": " + std::to_string(newGrade);
		}
		newfile << line << std::endl;
	}
	file.close();
	newfile.close();
	if (std::remove(filePath.c_str()) != 0)
	{
		std::cerr << "Error removing the original file" << std::endl;
		return;
	}
	if (std::rename("temp.txt", filePath.c_str()) != 0)
	{
		std::cerr << "Error renaming the temp file" << std::endl;
		return;
	}
	std::cout << "Grade edited!" << std::endl;
}

void show_grade(std::string filePath)
{
	std::ifstream file(filePath);
	std::string line;
	int counter = 0;

	if (!file.is_open())
	{
		std::cerr << "Error opening the file" << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		if (counter == 0)
		{
			std::cout << "Your grades" << std::endl;
		}
		std::cout << line << std::endl;
		counter++;
	}
	file.close();
	if (counter == 0)
	{
		std::cout << "You don't have any grades!" << std::endl;
		return;
	}
}

void show_average(std::string filePath)
{
	std::string line;
	std::ifstream file(filePath);
	float average = 0;
	int counter = 0;
	size_t pos;

	if (!file.is_open())
	{
		std::cerr << "Error opening the file" << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		counter++;
		pos = line.find(":");
		if (pos != std::string::npos)
		{
			average += std::stoi(line.substr(pos + 2));
		}
	}
	file.close();
	if (counter == 0)
	{
		std::cout << "You don't have any grades!" << std::endl;
		return;
	}
	average /= counter;
	std::cout << "Your average is " << average << std::endl;
}