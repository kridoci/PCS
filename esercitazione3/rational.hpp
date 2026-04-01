#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <concepts>

template<typename I> requires std::integral<I>
class rational {
private:
	I num_;
	I den_;

// MCD
	I mcd(I a, I b) const {
		if (a < 0) a = -a;
		if (b < 0) b = -b;
		while (b != 0) {
			I temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	// semplficiazione 
	void simplify() {
		if (den_ == 0) {
			return; 
		}
		
		I div = mcd(num_, den_);
		num_ = num_ / div;
		den_ = den_ / div;
		
		if (den_ < 0) {
			num_ = -num_;
			den_ = -den_;
		}
	}

public:
	// costruttore
	rational() : num_(I{0}), den_(I{1}) {}

	rational(const I& num, const I& den) : num_(num), den_(den) {
		if (den_ == 0) {
			if (num_ > 0) {
				num_ = 1;
			} else if (num_ < 0) {
				num_ = -1;
			} else {
				num_ = 0;
			}
		} else {
			simplify();
		}
	}

	
	I num() const { return num_; }
	I den() const { return den_; }

	//  somma
	rational& operator+=(const rational& other) {
		if (den_ == 0 && num_ == 0) return *this;
		if (other.den_ == 0 && other.num_ == 0) {
			num_ = 0; den_ = 0; return *this; 
		}
		if (den_ == 0) { 
			if (other.den_ == 0 && num_ != other.num_) { num_ = 0; }
			return *this; 
		}
		if (other.den_ == 0) { 
			num_ = other.num_; den_ = 0; return *this; 
		}

		num_ = (num_ * other.den_) + (other.num_ * den_);
		den_ = den_ * other.den_;
		simplify();
		return *this;
	}

	rational operator+(const rational& other) const {
		rational ret = *this;
		ret += other;
		return ret;
	}

	// sott
	rational& operator-=(const rational& other) {
		if (den_ == 0 && num_ == 0) return *this;
		if (other.den_ == 0 && other.num_ == 0) {
			num_ = 0; den_ = 0; return *this; 
		}
		if (den_ == 0) { 
			if (other.den_ == 0 && num_ == other.num_) { num_ = 0; }
			return *this; 
		}
		if (other.den_ == 0) { 
			num_ = -other.num_; den_ = 0; return *this; 
		}

		num_ = (num_ * other.den_) - (other.num_ * den_);
		den_ = den_ * other.den_;
		simplify();
		return *this;
	}

	rational operator-(const rational& other) const {
		rational ret = *this;
		ret -= other;
		return ret;
	}

	// molt
	rational& operator*=(const rational& other) {
		if (den_ == 0 && num_ == 0) return *this;
		if (other.den_ == 0 && other.num_ == 0) {
			num_ = 0; den_ = 0; return *this; 
		}
		if (den_ == 0 || other.den_ == 0) {
			if (num_ == 0 || other.num_ == 0) { 
				num_ = 0; den_ = 0; return *this;
			}
			I sign1;
			if (num_ > 0) { sign1 = 1; } else { sign1 = -1; }
			
			I sign2;
			if (other.num_ > 0) { sign2 = 1; } else { sign2 = -1; }
			
			num_ = sign1 * sign2;
			den_ = 0;
			return *this;
		}

		num_ = num_ * other.num_;
		den_ = den_ * other.den_;
		simplify();
		return *this;
	}

	rational operator*(const rational& other) const {
		rational ret = *this;
		ret *= other;
		return ret;
	}

	// divisione
	rational& operator/=(const rational& other) {
		if (den_ == 0 && num_ == 0) return *this;
		if (other.den_ == 0 && other.num_ == 0) {
			num_ = 0; den_ = 0; return *this; 
		}
		if (den_ == 0 && other.den_ == 0) { 
			num_ = 0; den_ = 0; return *this;
		}
		if (den_ == 0) { 
			I sign1;
			if (num_ > 0) { sign1 = 1; } else { sign1 = -1; }
			
			I sign2;
			if (other.num_ > 0) { sign2 = 1; } else { sign2 = -1; }
			
			num_ = sign1 * sign2;
			return *this;
		}
		if (other.den_ == 0) { 
			num_ = 0; den_ = 1; return *this;
		}
		if (other.num_ == 0) { 
			I sign1;
			if (num_ > 0) { sign1 = 1; } else { sign1 = -1; }
			
			if (num_ == 0) { 
				den_ = 0; 
			} else { 
				num_ = sign1; den_ = 0; 
			}
			return *this;
		}

		num_ = num_ * other.den_;
		den_ = den_ * other.num_;
		simplify();
		return *this;
	}

	rational operator/(const rational& other) const {
		rational ret = *this;
		ret /= other;
		return ret;
	}
};

// stampa
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
	if (r.den() == 0) {
		if (r.num() == 0) {
			os << "NaN";
		} else if (r.num() > 0) {
			os << "Inf";
		} else {
			os << "-Inf";
		}
	} else if (r.den() == 1) {
		os << r.num(); 
	} else {
		os << r.num() << "/" << r.den();
	}
	return os;
}

#endif