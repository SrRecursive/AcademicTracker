#include "../include/main.hpp"

int main(int argc, char **argv)
{
	int option;
	std::string usernameLogin;

	do
	{
		option = main_menu();
		switch (option)
		{	
		case 1:
			usernameLogin = login();
			if (usernameLogin != "")
			{
				login_menu(usernameLogin);
			}
			break;
		case 2:
			registration();
			break;
		case 3:
			std::cout << "Exiting..." << std::endl;
			break;
		default:
			std::cout << "There's been an option error" << std::endl;
			return (1);
		}
	}while (option != 3);
	return (0);
}

std::string login(void)
{
	std::string usernameLogin;

	std::cout << "Login: ";
	std::cin >> usernameLogin;
	if (check_username(usernameLogin) == false)
	{
		std::cout << "User doesn't exist!" << std::endl;
		return ("");
	}
	return (usernameLogin);
}

void registration(void)
{
	std::string username, filePath, folderName = "Users";

	if (!std::filesystem::exists(folderName))
	{
		std::filesystem::create_directory(folderName);
	}
	do
	{
		std::cout << "Introduce the username: ";
		std::cin >> username;
		filePath = "./Users/" + username + ".txt";

		if (check_username(username) == true)
		{
			std::cout << "The user already exists!" << std::endl;
		}
	}while (check_username(username) == true);
	std::ofstream file(filePath);

	if (!file.is_open())
	{
		std::cerr << "Error opening the file" << std::endl;
		return;
	}
	std::cout << "User created!" << std::endl;
	file.close();
}