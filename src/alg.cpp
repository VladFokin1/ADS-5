// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prior(char op) {
    switch (op) {
      case '(': return 0; 
      case ')': return 1; 
      case '+': case '-': return 2; 
      case '*': case '/': return 3; 
      default: return 4;
    }
}
  
std::string infx2pstfx(std::string inf) {
  TStack <char, 100> stack;
    std::string result = "";
    
    for (int i = 0; i < inf.length(); i++) {
        char sym = inf[i];
        int symPrior = prior(sym);
        if (symPrior == 4) {
            result += sym;
            result += ' ';
        } else {
            if (symPrior == 0 || symPrior > prior(stack.get()) || stack.isEmpty()) {
                stack.push(sym);
            } else if (symPrior == 1) {
                while (prior(stack.get()) != 0) {
                    result += stack.get();
                    result += ' ';
                    stack.pop();
                }
                 stack.pop();
            } else if (symPrior <= prior(stack.get())) {
                if (symPrior <= prior(stack.get())) {
                    result += stack.get();
                    result += ' ';
                    stack.pop();
                }
                stack.push(sym);
            }
        }
    }
    if (!stack.isEmpty()) {
        while (!stack.isEmpty()) {
            result += stack.get();
            result += ' ';
            stack.pop();
        }
        result.pop_back();
    }
    return result;
}

int eval(std::string pref) {
  
  return 0;
}
