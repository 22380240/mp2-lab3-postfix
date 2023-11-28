#include "postfix.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  string expression;
  TPostfix postfix("(((1 + 2 * 2)) * 5 + 1 * 2 + 7) / 5");
  double res;

  setlocale(LC_ALL, "Russian");

  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
  cout << "Постфиксная форма: " << postfix.GetStringifiedPostfix() << endl;
  res = postfix.Calculate();
  cout << res << endl;

  return 0;
}
