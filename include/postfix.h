#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include <vector>

union TokenValue {
  int num;
  char op;
};
#define TOKEN_TYPE_NUM 1
#define TOKEN_TYPE_OP 2
typedef struct {
  /*
   * TOKEN_TYPE_NUM - value.num
   * TOKEN_TYPE_OP  - value.op
   */
  unsigned char type;
  TokenValue value;
} Token;

class TPostfix {
  std::string infix;

public:
  TPostfix() { infix = "a + b"; }
  TPostfix(std::string infix);
  std::string GetInfix() { return infix; }
  std::vector<Token> GetPostfix();
  std::string GetStringifiedPostfix();
  double Calculate();
};

#endif
