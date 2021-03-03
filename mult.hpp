#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult: public Base{
	private:
		Base* left;
		Base* right;
	public:
		Mult(Base* leftNode, Base* rightNode): Base(){
			left = leftNode;
			right = rightNode;
		}
		double evaluate(){
			return left->evaluate()*right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() + "*" + right->stringify() + ")";
		}
};

#endif
