#include "PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook()
{
	this->cursor = 0;
	this->saved = 0;
}

void	PhoneBook::LOGO(void) const
{
	std::cout << "\n\n"
			  << "______  _   _  _____  _   _  _____  ______  _____  _____  _   __  _\n"
			  << "| ___ \\| | | ||  _  || \\ | ||  ___| | ___ \\|  _  ||  _  || | / / | |\n"
			  << "| |_/ /| |_| || | | ||  \\| || |__   | |_/ /| | | || | | || |/ /  | |\n"
			  << "|  __/ |  _  || | | || . ` ||  __|  | ___ \\| | | || | | ||    \\  | |\n"
			  << "| |    | | | |\\ \\_/ /| |\\  || |___  | |_/ /\\ \\_/ /\\ \\_/ /| |\\  \\ |_|\n"
			  << "\\_|    \\_| |_/ \\___/ \\_| \\_/\\____/  \\____/  \\___/  \\___/ \\_| \\_/ (_)\n\n\n";
}

void	PhoneBook::RUN(void)
{
	std::string	input;

	LOGO();
	while (true)
	{
		std::cout << "╭                                      ╮\n"
				  << "                 Command                \n"
				  << "                                        \n"
				  << "   1. ADD     -  Add a new Contact      \n"
				  << "   2. SEARCH  -  Display   Contacts     \n"
				  << "   3. EXIT    -  Exit  the Phone Book   \n"
				  << "                                        \n"
				  << "    Enter correct command or numbers    \n"
				  << "╰                                      ╯\n\n";
		std::cout << "> ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		if(input == "ADD" || input == "1")
			ADD();
		else if (input == "SEARCH" || input == "2")
			SEARCH();
		else if (input == "EXIT" || input == "3")
			EXIT();
		else
		{
			std::cout << "Invalid Command...\n"
					  << std::endl;
		}
	}
}

bool	PhoneBook::isValidInput(std::string &s) const
{
	if (!s.length())
	{
		std::cout << "You can't enter an empty.\n"
				  << std::endl;
		return false;
	}
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
		{
			std::cout << "You can't enter spaces or tabs in the field.\n"
					  << std::endl;
			return false;
		}
		if (!std::isprint(s[i]))
		{
			std::cout << "You can't enter non-printable characters in the field.\n"
					  << std::endl;
			return false ;
		}
	}
	return true;
}

void	PhoneBook::ADD(void)
{
	std::string	field[5] = {"First Name", "Last Name", "Nick Name", "Number", "Secret"};
	std::string	input;

	std::cout << "Add new Contact ...\n";
	std::cout << "* If you want to cancel, *** + Enter \n\n";
	for (int i = 0; i < 5;)
	{
		std::cout << field[i] << " : ";
		std::getline(std::cin, input);
		if (!isValidInput(input))
			continue ;
		if (input == "***")
		{
			std::cout << "Cancel..\n\n";
			break ;
		}
		switch (i++)
		{
			case 0 : contacts[cursor].setFirstName(input);	break ;
			case 1 : contacts[cursor].setLastName(input);	break ;
			case 2 : contacts[cursor].setNickName(input);	break ;
			case 3 : contacts[cursor].setNumber(input); 	break ;
			case 4 : contacts[cursor].setSecret(input); 	break ;
		}
	}
	if (++cursor == 8)
		cursor = 0;
	if (saved < 8)
		saved++;
}

void	PhoneBook::PRINT(std::string input, std::string end) const
{
	if (input.length() <= 10)
	{
		std::cout << std::setw(10)
				  << input << end;
	}
	else
	{
		std::cout << std::setw(9)
				  << input.substr(0, 9) << "." << end;
	}
}

void	PhoneBook::PRINT(int cursor) const
{
	std::string	input;

	std::cout << "╭                                                  ╮\n";
	std::cout << cursor << " | "
			  << contacts[cursor].getFirstName() << " |"
			  << contacts[cursor].getLastName()	 << " |"
			  << contacts[cursor].getNickName()	 << " |"
			  << contacts[cursor].getNumber()	 << " |"
			  << std::endl;
	std::cout << "╰                                                  ╯\n\n";\
	std::cout << "If you want to return, Enter any key\n\n";
	std::getline(std::cin, input);
}

bool	PhoneBook::isValidOrder(std::string &input) const
{
	if (input.length() != 1)
	{
		std::cout << "Just enter only one Number"
				  << std::endl;
		return false;
	}
	if (!('1' <= input[0] && input[0] <= '8'))
	{
		std::cout << "Just enter only Number"
				  << std::endl;
		return false;
	}
	if (input[0] - 48 > saved)
	{
		std::cout << "Just enter valid Order"
				  << std::endl;
		return false;
	}
	return true;
}

void	PhoneBook::SEARCH(void) const
{
	std::string	input;

	if (!saved)
	{
		std::cout << "There are no saved contacts.\n"
				  << std::endl;
		return ;
	}
	while (true)
	{
		std::cout << "╭                                                  ╮\n"
				  << "                         Index                      \n"
				  << "                                                    \n"
				  << "                           ‧                        \n"
				  << "                                                    \n";
		for (int i = 0; i < saved; i++)
		{
			std::cout << i + 1 << " | ";
			PRINT(contacts[i].getFirstName(), " |");
			PRINT(contacts[i].getLastName(), " |");
			PRINT(contacts[i].getNickName(), " |");
			PRINT(contacts[i].getNumber(), " |");
			std::cout << std::endl;
		}
		std::cout << "                                                    \n"
				  << "                                                    \n"
				  << "                                                    \n"
				  << "╰                                                  ╯\n\n";
		std::cout << "> ";
		std::getline(std::cin, input);
		if (isValidOrder(input))
		{
			PRINT(input[0] - 49);
			break ;
		}
	}
}

void	PhoneBook::EXIT(void) const
{
	std::cout << " ______                  ______                _   _\n"
			  << " | ___ \\                 | ___ \\              | | | |\n"
			  << " | |_/ / _   _   ___     | |_/ / _   _   ___  | | | |\n"
			  << " | ___ \\| | | | / _ \\    | ___ \\| | | | / _ \\ | | | |\n"
			  << " | |_/ /| |_| ||  __/ _  | |_/ /| |_| ||  __/ |_| |_|\n"
			  << " \\____/  \\__, | \\___|( ) \\____/  \\__, | \\___| (_) (_)\n"
			  << "          __/ |      |/           __/ |              \n"
			  << "         |___/                   |___/               \n\n\n";
	exit(0);
}
