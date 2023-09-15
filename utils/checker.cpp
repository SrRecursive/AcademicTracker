#include "../include/checker.hpp"

bool check_username(std::string usernameLogin)
{
	std::string filePath = "./Users/" + usernameLogin + ".txt";
	std::ifstream file(filePath);

	if (!file.is_open())
	{
		return (false);
	}
	file.close();
	return (true);
}

bool	check_subject(std::string filePath,std::string subject)
{
	std::string line;
	std::ifstream file(filePath);
	
	if (!file.is_open())
	{
		return (false);
	}
	while (std::getline(file, line))
	{
		if (line.find(subject) != std::string::npos)
		{
			file.close();
			return (true);
		}
	}
	file.close();
	return (false);
}