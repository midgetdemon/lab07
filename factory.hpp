#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <string>
#include <stack>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "sub.hpp"

using namespace std;

class Factory{
	public:
    Factory(){ }
    Base* parse(char** input, int length){
      stack<string> ops;
      stack <Base*> nodes;
      if(length < 2){
        return nullptr;
      }
      for(int i = 1; i<length; ++i){
        if(isdigit(input[i][0])){
          for(int j = 1; j < strlen(input[i]); ++j){
            if(!isdigit(input[i][j])){
              return nullptr;
            }
          }
          int operation = atoi(input[i]);
          Base* oper = new Op(operation);
          nodes.push(oper);
        }
        else{
          string strin = static_cast<string>(input[i]);
          if(strin == "+" || strin == "/" || strin == "*" || strin == "**" || strin == "-"){
            if(ops.size() > 0){
              string parent = ops.top();
              ops.pop();
              Base* child1 = nodes.top();
              nodes.pop();
              Base* child2 = nodes.top();
              nodes.pop();
              if(parent == "+"){
                nodes.push(new Add(child2, child1));
              }
              else if(parent == "/"){
                nodes.push(new Div(child2, child1));
              }
              else if(parent == "*"){
                nodes.push(new Mult(child2, child1));
              }
              else if(parent == "**"){
                nodes.push(new Pow(child2, child1));
              }
              else if(parent == "-"){
                nodes.push(new Sub(child2, child1));
              }
            }
            ops.push(strin);
          }
          else{
            return nullptr;
          }
        }
      }
      string parent = ops.top();
      ops.pop();
      Base* child1 = nodes.top();
      nodes.pop();
      Base* child2 = nodes.top();
      nodes.pop();
      if(parent == "+"){
        nodes.push(new Add(child2, child1));
      }
      else if(parent == "/"){
        nodes.push(new Div(child2, child1));
      }
      else if(parent == "*"){
        nodes.push(new Mult(child2, child1));
      }
      else if(parent == "**"){
        nodes.push(new Pow(child2, child1));
      }
      else if(parent == "-"){
        nodes.push(new Sub(child2, child1));
      }
      if(!ops.empty() && nodes.size() == 1){
        return nullptr;
      }
      Base* node = nodes.top();
      nodes.pop();
      return node;
    }
};

#endif
