#ifndef GRADE_HPP
# define GRADE_HPP

/* <--Libraries Section--> */
# include <iostream>
# include <string>
# include <fstream>

/* <--Functions Section--> */

/**
 * #### Add Grade Function
 * Add a subject and a grade to the user file.
*/
void	add_grade(std::string filePath);

/**
 * #### Edit Grade Function
 * Edit a existing grade in the user file.
 * 
*/
void	edit_grade(std::string filePath);

/**
 * #### Remove Grade Function
 * Remove a existing grade in the user file
*/
void	remove_grade(std::string filePath);

/**
 * #### Show Grade Function
 * Show grades in the user file
*/
void	show_grade(std::string filePath);

/**
 * #### Show Average Function
 * Show the average grade of every subject
*/
void	show_average(std::string filePath);

#endif
