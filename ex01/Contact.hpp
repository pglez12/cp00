#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact
{
	public:
		void			setFirstName(const std::string &firstName);
		void			setLastName	(const std::string &lastName);
		void			setNickName	(const std::string &nickName);
		void			setNumber	(const std::string &number);
		void			setSecret	(const std::string &secret);

		std::string		getFirstName() const;
		std::string		getLastName	() const;
		std::string		getNickName	() const;
		std::string		getNumber	() const;
		std::string		getSecret	() const;

	private:
		std::string		firstName;
		std::string		lastName;
		std::string		nickName;
		std::string		number;
		std::string		secret;
};

#endif
