#include <iostream>
#include <string>

#include "lowercase.h"

int main() {
  std::cout << " 输入一个字符串" << std::endl;
  std::string InputString;
  std::cin >> InputString;
  std::cout << "全小写转化:" << to_lower(InputString) << std::endl;
  return 0;
}