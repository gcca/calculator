#include <iostream>

#include <arithmetic.h>

int main(void)
{
  std::cout << "CALCULATOR" << std::endl;

  std::cout << "(15, 7):" << std::endl
            << "\t+: " << (Number(15) + Number(7)) << std::endl
            << "\t-: " << (Number(15) - Number(7)) << std::endl
            << "\t*: " << (Number(15) * Number(7)) << std::endl
            << "\t/: " << (Number(15) / Number(7)) << std::endl;

  return 0;
}
