#include "../include/menu.hpp"
#include "../include/grade.hpp"

int main_menu(void)
{
	int option = 0;
	while (option < 1 || option > 3)
	{
		std::cout << "\033[0;36m**************************" << std::endl;
		std::cout << "*    \033[1;33mAcademic Tracker    \033[0;36m*" << std::endl;
		std::cout << "**************************" << std::endl;
		std::cout << "* \033[1;33m1. Login               \033[0;36m*" << std::endl;
		std::cout << "* \033[1;33m2. Register            \033[0;36m*" << std::endl;
		std::cout << "* \033[1;33m3. Exit                \033[0;36m*" << std::endl;
		std::cout << "**************************\033[0m" << std::endl;
		std::cout << "Introduce your option: ";
		std::cin >> option;
		if (option < 1 || option > 3)
		{
			std::cout << "Invalid option!" << std::endl;
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return (option);
}

void login_menu(std::string usernameLogin)
{
	int	option = 0;
	std::string filePath = "./Users/" + usernameLogin + ".txt";

	while (option != 6)
	{
		std::cout << "\033[0;36m*************************" << std::endl;
		std::cout << "*       \033[1;33mDashboard\033[0;36m       *" << std::endl;
		std::cout << "*************************" << std::endl;
		std::cout << "*\033[1;33m 1. Add grades         \033[0;36m*" << std::endl;
		std::cout << "*\033[1;33m 2. Remove grades      \033[0;36m*" << std::endl;
		std::cout << "*\033[1;33m 3. Edit grades        \033[0;36m*" << std::endl;
		std::cout << "*\033[1;33m 4. Show grades        \033[0;36m*" << std::endl;
		std::cout << "*\033[1;33m 5. Show average       \033[0;36m*" << std::endl;
		std::cout << "*\033[1;33m 6. Exit               \033[0;36m*" << std::endl;
		std::cout << "*************************\033[0m" << std::endl;


		std::cout << "Select an option: ";
		std::cin >> option;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		switch (option)
		{
		case 1:
			add_grade(filePath);
			break;
		case 2:
			remove_grade(filePath);
			break;
		case 3:
			edit_grade(filePath);
			break;
		case 4:
			show_grade(filePath);
			break;
		case 5:
			show_average(filePath);
			break;
		case 6:
			std::cout << "Exiting the dashboard..." << std::endl;
			break;
		default:
			std::cout << "Invalid option!" << std::endl;
			break;
		}
	}
}