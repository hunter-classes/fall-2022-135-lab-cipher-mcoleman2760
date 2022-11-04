#include <iostream>
#include "funcs.h"
#include <string>
int main() {


 std::cout << "\nencryptCaesar:\nplaintext: I like to listen to music \nShift: 5\n";
  std::cout << encryptCaesar("I like to listen to music.", 5);
  std::cout << "\n------------------\n";
  
  std::cout << "\nsolve:\nciphertext: N qnpj yt qnxyjs yt rzxnh.\n";
  std::cout << solve("N qnpj yt qnxyjs yt rzxnh.");
  std::cout << "\n------------------\n";

 

std::cout << "\nencryptCaesar:\nplaintext: I want to build a big business and be rich one day \nShift: 21\n";
  std::cout << encryptCaesar("I want to build a big business and be rich one day", 21);
  std::cout << "\n------------------\n";


std::cout << "\nsolve:\nciphertext: D rvio oj wpdgy v wdb wpndiznn viy wz mdxc jiz yvt\n";
  std::cout << solve("D rvio oj wpdgy v wdb wpndiznn viy wz mdxc jiz yvt");
   std::cout << "\n------------------\n";
 return 0;

}
