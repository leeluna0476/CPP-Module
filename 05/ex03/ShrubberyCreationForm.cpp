#include "ShrubberyCreationForm.hpp"

// @brief Implementation to a class ShrubberyCreationForm which inherits an abstract class AForm

/**
 * @brief Default constructor
 *
 * Initializes the name to "Shrubbery", the grade to sign to 145, the grade to execute to 137, and the target name to "seojilee_shrubbery"
 * Calls a multi-parameter constructor of AForm to initialize its members.
 */
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137), target_name("seojilee_shrubbery")
{
	target_file.open(target_name.c_str());
}

/**
 * @brief Single-parameter constructor
 *
 * Initializes the name to "Shrubbery", the grade to sign to 145, the grade to execute to 137, and the target name + "_shrubbery" to target given as a parameter.
 * Calls a multi-parameter constructor of AForm to initialize its members.
 *
 * @param target name of the target of the form
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", 145, 137), target_name(target + "_shrubbery")
{
	target_file.open(target_name.c_str());
}

/**
 * @brief Copy constructor
 *
 * Copies another ShrubberyCreationForm object at construction.
 * Calls a copy constructor of AForm to copy its members.
 *
 * @param other the target of the copy
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target_name(other.target_name)
{
	target_file.open(target_name.c_str());
}

/**
 * @brief Copy assignment operator
 *
 * Copies another Form object after construction.
 * Calls a copy assignment operator of AForm to copy its members.
 *
 * @param other the target of the copy
 */
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	target_name = other.target_name;
	target_file.close();
	target_file.open(target_name.c_str());
	return *this;
}

/**
 * @brief Destructor
 */
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	target_file.close();
}

/**
 * @brief A function that executes the form
 *
 * Overrided from AForm::execute().
 * Draws an ASCII tree to the target file.
 * Checks the form is signed.
 * Checks the grade of the bureaucrat given as a parameter is high enough to execute the form.
 * Otherwise, throws an appropriate exception.
 *
 * @param executor A bureaucrat that tries to execute the form
 */
void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const \
			throw(FormNotSigned, GradeTooLowException)
{
	if (sign == false)
		throw FormNotSigned();
	else if (executor.getGrade() > grade_to_exec)
		throw GradeTooLowException();
	drawASCIITree();
}

/**
 * @brief A function that prints an ASCII tree to the target file
 *
 * Generates an ASCII tree in a string.
 * Prints it to the target file.
 */
void	ShrubberyCreationForm::drawASCIITree(void) const
{
	std::string	tree = "                                                         .\n\
                                              .         ;\n\
                 .              .              ;%     ;;\n\
                   ,           ,                :;%  %;\n\
                    :         ;                   :;%;'     .,\n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'\n\
                        `@%.  `;@%.      ;@@%;\n\
                          `@%%. `@%%    ;@@%;\n\
                            ;@%. :@%%  %@@%;\n\
                              %@bd%%%bd%%:;\n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '\n\
                                %@@@o%;:(.,'\n\
                            `.. %@@@o%::;\n\
                               `)@@@o%::;\n\
                                %@@(o)::;\n\
                               .%@@@@%::;\n\
                               ;%@@@@%::;.\n\
                              ;%@@@@%%:;;;.\n\
                          ...;%@@@@@%%:;;;;,..";
	target_file << tree << std::endl;
}
