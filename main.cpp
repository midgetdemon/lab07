#include "factory.hpp"

int main(int argc, char** argv) {
  Factory myFactory;
  Base* tree = myFactory.parse(argv, argc);
  if(tree){
    cout << tree->stringify() << " = " << tree->evaluate() << endl;
    delete tree;
  }
  else{
    cout << "Invalid expression." << endl;
  }
}
