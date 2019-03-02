#include <string>
#include <iostream>
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

//std::cout << "Measured runtime: " << yellow << timer.count() << reset << std::endl;

int main()
{
  std::cout<<red<<"what ";
  std::cout<<green<<"a ";
  std::cout<<yellow<<"color";
  std::cout<<cyan<<"full ";
  std::cout<<magenta<<"world"<<std::endl;
}
