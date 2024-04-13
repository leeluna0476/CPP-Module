#include "ShrubberyCreationForm.hpp"

// name = "ShrubberyCreation"
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137), filename("seojilee_shrubbery")
{
	target_shrubbery.open(filename.c_str());
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", 145, 137), filename(target + "_shrubbery")
{
	target_shrubbery.open(filename.c_str());
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), filename(other.filename)
{
	target_shrubbery.open(filename.c_str());
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	filename = other.filename;
	target_shrubbery.close();
	target_shrubbery.open(filename.c_str());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	target_shrubbery.close();
}

// check that the form is signed
// check that the grade of the bureaucrat is high enough
// otherwise, throw an appropriate exception
void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
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
                                              .         ;  \n\
                 .              .              ;%     ;;   \n\
                   ,           ,                :;%  %;   \n\
                    :         ;                   :;%;'     .,   \n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'   \n\
                        `@%.  `;@%.      ;@@%;         \n\
                          `@%%. `@%%    ;@@%;        \n\
                            ;@%. :@%%  %@@%;       \n\
                              %@bd%%%bd%%:;     \n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '         \n\
                                %@@@o%;:(.,'         \n\
                            `.. %@@@o%::;         \n\
                               `)@@@o%::;         \n\
                                %@@(o)::;        \n\
                               .%@@@@%::;         \n\
                               ;%@@@@%::;.          \n\
                              ;%@@@@%%:;;;. \n\
                          ...;%@@@@@%%:;;;;,..    Gilo97";
	target_shrubbery << tree << std::endl;
}
