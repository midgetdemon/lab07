#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub: public Base{
	private:
		Base* left;
		Base* right;
	public:
		Sub(Base* leftNode, Base* rightNode): Base(){
			left = leftNode;
			right = rightNode;
		}
		~Sub(){
			delete left;
			delete right;
		}
		double evaluate(){
			return left->evaluate() - right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() + "-" + right->stringify() + ")";
		}
};

#endif
