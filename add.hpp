#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add: public Base{
	private:
		Base* left;
		Base* right;
	public:
		Add(Base* leftNode, Base* rightNode): Base(){
			left = leftNode;
			right = rightNode;
		}
		~Add(){
			delete left;
			delete right;
		}
		double evaluate(){
			return left->evaluate() + right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() + "+" + right->stringify() + ")";
		}
};

#endif
