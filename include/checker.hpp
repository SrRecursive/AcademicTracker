#ifndef CHECKER_HPP
# define CHECKER_HPP

/* <--Defines Section--> */

/* <--Libraries Section--> */

# include <iostream>
# include <string>
# include <fstream>

/* <--Functions Section--> */

/**
 * #### Check Username Function
 * Check if the username exists in the Users folder
 * 
 * #### Return Value
 * - If the username exists return True
 * - If the username doesn't exist return False
*/
bool	check_username(std::string usernameLogin);

/**
 * #### Check Subject Function
 * Check if the subject exists in the user file
 * 
 * #### Return Value
 * - If the subject exists return True
 * - If the subject doesn't exist return False
*/
bool	check_subject(std::string filePath, std::string subject);

#endif