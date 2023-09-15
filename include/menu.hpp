#ifndef MENU_HPP
# define MENU_HPP

/* <--Libraries Section--> */
# include <iostream>
# include <string>
# include <fstream>
# include <limits>

/* <--Functions Section--> */

/**
 * #### Login Menu Function
 * 
 * Display the login menu which contains the following options:
 * - Add grades
 * - Remove grades
 * - Edit grades
 * - Show grades
 * - Show average
 * - Exit
*/
void	login_menu(std::string usernameLogin);

/**
 * #### Main Menu Function
 * 
 * Display the main menu which contains the following options:
 * - Login
 * - Register
 * - Exit
 * 
 * #### Return Value
 * - 1 Display the login
 * - 2 Display the register
 * - 3 Exit the program
*/
int		main_menu(void);

#endif
