#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "SyntaxAddOn.h"
#include "SyntaxAnalyzerFunctions.h"

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

  //struct that holds both, the lexeme and token type, to be referecenced and used in the Syntax Analyzer
  // Lexeme a;
  // Lexeme b;

  TestPrint_Start();
  TestPrint_End();

  // a = Lexer();
  // cout << "Lexeme: " << a.lexeme_word << " Token: " << a.lexeme_token << "\n";
  // b = Lexer();
  // cout << "Lexeme: " << b.lexeme_word << " Token: " << b.lexeme_token << "\n";

  Rat21F();


  closing_streams();
  cout << "\n\nSyntax Analyzer Done!!!\n";
}
