#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137), target_name("seojilee_shrubbery")
{
	target_file.open(target_name.c_str());
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", 145, 137), target_name(target + "_shrubbery")
{
	target_file.open(target_name.c_str());
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target_name(other.target_name)
{
	target_file.open(target_name.c_str());
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	target_name = other.target_name;
	target_file.close();
	target_file.open(target_name.c_str());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	target_file.close();
}

// check that the form is signed
// check that the grade of the bureaucrat is high enough
// otherwise, throw an appropriate exception
void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const \
			throw(FormNotSigned, GradeTooLowException)
{
	if (sign == false)
		throw FormNotSigned();
	else if (executor.getGrade() > grade_to_exec)
		throw GradeTooLowException();
	drawASCIITree();
}

// generate ascii tree
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
