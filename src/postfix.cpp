#include "postfix.h"
#include "stack.h"
#include <exception>
#include <map>
#include <stdexcept>

std::map<char, int> operators = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

TPostfix::TPostfix(std::string infix) : infix(infix){};

std::vector<Token> TPostfix::GetPostfix() {
  std::vector<Token> postfix;
  Stack<char> stack;

  for (size_t i = 0; i < infix.size(); i++) {
    char c = infix.at(i);
    if (std::isspace(c)) {
      continue;
    }

    if (std::isdigit(c)) {
      int num = 0;
      while (std::isdigit(c)) {
        num *= 10;
        num += c - '0';
        if (i + 1 == infix.size()) {
          break;
        }

        char n = infix.at(i + 1);
        if (std::isdigit(n)) {
          c = n;
          i++;
          continue;
        }

        break;
      }
      postfix.push_back({TOKEN_TYPE_NUM, {num}});
    } else if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      while (!stack.isEmpty() && stack.top() != '(') {
        postfix.push_back({2, {stack.pop()}});
      }
      stack.pop();
    } else if (operators.count(c)) {
      while (!stack.isEmpty() && stack.top() != '(' &&
             (operators.at(stack.top()) >= operators.at(c))) {
        postfix.push_back({TOKEN_TYPE_OP, {stack.pop()}});
      }

      stack.push(c);
    } else {
      throw std::invalid_argument("wrong expression");
    }
  }

  while (stack.getSize()) {
    postfix.push_back({TOKEN_TYPE_OP, {stack.pop()}});
  }

  return postfix;
}

std::string TPostfix::GetStringifiedPostfix() {
  auto postfix = GetPostfix();

  std::string res;
  for (const Token e : postfix) {
    switch (e.type) {
    case TOKEN_TYPE_NUM:
      res.append(std::to_string(e.value.num));
      break;
    case TOKEN_TYPE_OP:
      res.push_back(e.value.op);
      break;
    };
  }

  return res;
}

double TPostfix::Calculate() {
  auto postfix = GetPostfix();

  Stack<double> stack;
  double tmp;
  for (const Token token : postfix) {
    switch (token.type) {
    case TOKEN_TYPE_OP:
      switch (token.value.op) {
      case '+':
        stack.push(stack.pop() + stack.pop());
        break;
      case '-':
        tmp = stack.pop();
        stack.push(stack.pop() - tmp);
        break;
      case '*':
        stack.push(stack.pop() * stack.pop());
        break;
      case '/':
        tmp = stack.pop();
        stack.push(stack.pop() / tmp);
        break;
      }
      break;
    case TOKEN_TYPE_NUM:
      stack.push(token.value.num);
      break;
    }
  }
  return stack.pop();
}
