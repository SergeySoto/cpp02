#include "Fixed.hpp"

Fixed::Fixed() : _num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : _num(copy._num) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const num) {
	std::cout << "Int constructor called" << std::endl;
	_num = num << _litNum;
}

Fixed::Fixed(float const num) {
	std::cout << "Float constructor called" << std::endl;
	_num = roundf(num * (1 << _litNum));
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_num = other._num;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_num;
}

void Fixed::setRawBits(int const raw) {
	this->_num= raw;
}

int Fixed::toInt() const {
	return _num >> _litNum;
}

float Fixed::toFloat() const {
	return (float)_num / (1 << _litNum);
}

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
	out << f.toFloat();
	return out;
}