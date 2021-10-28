#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "SyntaxAddOn.h"

using namespace std;

int main (int argc, const char* argv[]){

  if (argc != 3){
    cout << "Didn't enter the correct number of argumens!\n";
    cout << "The proper and acceptable format is:\n <exe file> <input text file> <output text file>\n";
    return 0;
  }

  change_stream_contents(argv[1],argv[2]);
  if(checking_proper_streams() == 1){
    return 1;
  }
  checking_input_and_starting_iterator();

  Lexer();
  Lexer();
  Lexer();
  Lexer();
  Lexer();
  
  closing_streams();
  cout << "Syntax Analyzer Done!!!\n";
}
