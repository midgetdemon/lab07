#include "factory.hpp"

int main(int argc, char** argv) {
  Factory myFactory;
  Base* tree = myFactory.parse(argv, argc);
  if(tree){
    cout << tree->stringify() << " = " << tree->evaluate() << endl;
  }
  else{
    cout << "Invalid expression." << endl;
  }
  delete tree;
}
