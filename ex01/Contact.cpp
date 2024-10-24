# include "Contact.hpp"

/* Setter */

void Contact::setFirstName(const std::string& firstName)
{
	this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
	this->lastName = lastName;
}

void Contact::setNickName(const std::string& nickName)
{
	this->nickName = nickName;
}

void Contact::setNumber(const std::string& number)
{
	this->number = number;
}

void Contact::setSecret(const std::string& secret)
{
	this->secret = secret;
}

/* Getter */

std::string Contact::getFirstName() const
{
	return this->firstName;
}

std::string Contact::getLastName() const
{
	return this->lastName;
}

std::string Contact::getNickName() const
{
	return this->nickName;
}

std::string Contact::getNumber() const
{
	return this->number;
}

std::string Contact::getSecret() const
{
	return this->secret;
}
