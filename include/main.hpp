#ifndef MAIN_HPP
# define MAIN_HPP

/* <--Libraries Section--> */

# include "grade.hpp"
# include "menu.hpp"
# include "checker.hpp"
# include <filesystem>

/* <--Functions Section--> */

/**
 * #### Login Function
 * 
 * Introduce the username login to enter the menu.
 * 
 * #### Return values:
 * 
 * - If the user doesn't exist returns a empty string
 * - If the user exists returns the username login
*/
std::string	login(void);

/**
 * #### Registration Function
 * 
 * Creates the folder Users if it doesn't exist, then it registers the user if it doesn't exist.
*/
void		registration(void);

#endif