#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <stdexcept>

class Div : public Base {
	private:
		Base * left;
		Base * right;
	public:
		Div(Base* leftNode, Base* rightNode) : Base(){
			left = leftNode;
			right = rightNode;
			if(right->evaluate() < 0.000001){
				throw std::invalid_argument("Divide by zero");
			}
		}
		~Div(){
			delete left;
			delete right;
		}
		double evaluate(){
			return left->evaluate()/right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() + "/" + right->stringify() + ")";
		}
};
#endif
