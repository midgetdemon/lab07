#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <string>

class Rand : public Base {
	private:
		double randVal;
	public:
		Rand() : Base() {
			randVal = rand() % 100;
		}

		virtual double evaluate(){
			return randVal;
		}
		virtual std::string stringify(){
			return std::to_string(randVal);
		}
};
#endif 
