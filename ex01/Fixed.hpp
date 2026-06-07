#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
			int _num;
			static const int _litNum = 8;
	public:
			Fixed();
			Fixed(const Fixed& copy);
			Fixed(const int num);
			Fixed(const float num);
			Fixed& operator=(const Fixed& copy);
			~Fixed();
			int getRawBits() const;
			void setRawBits(int const raw);
			int toInt() const;
			float toFloat() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif