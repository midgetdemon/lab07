#ifndef __POW_HPP__
#define __POW_HPP__

#include <cmath>
#include "base.hpp"

class Pow : public Base{
	private:
		Base * left;
		Base * right;
	public: 
		Pow(Base * leftNode, Base * rightNode) : Base(){
			left = leftNode;
			right = rightNode;
		}
		~Pow(){
			delete left;
			delete right;
		}
		double evaluate(){
			return pow(left->evaluate(), right->evaluate());
		}
		std::string stringify(){
			return "(" + left->stringify() + "**" + right->stringify() + ")"; 
		}
};
#endif  
