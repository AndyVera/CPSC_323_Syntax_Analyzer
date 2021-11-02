#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "SyntaxAddOn.h"

#ifndef SyntaxAnalyzerFunctions_h
#define SyntaxAnalyzerFunctions_h

Lexeme a;
Lexeme temp;
Lexeme temp2;
Lexeme temp3;
int second_time = 0;

void TestPrint_Start(){
  cout << "The Syntax Functions are going to be declared\n";
}

//Function Definitions
void Rat21F ();
void Opt_Function_Definitions ();
void Function_Definitions ();
void Function ();
void Opt_Parameter_List ();
void Parameter_List ();
void Parameter ();
void Qualifier ();
void Body ();
void Opt_Decleration_List ();
void Decleration_list ();
void Decleration ();
void IDs ();
void Statement_List();
void Statement ();
void Compound ();
void Assign ();
void If ();
void If_prime ();
void Return ();
void Print ();
void Scan ();
void While ();
void Condition ();
void Relop ();
void Expression ();
void Expression_prime ();
void Term ();
void Term_prime ();
void Factor ();
void Primary ();

void TestPrint_End(){
  cout <<  "The Syntax Rules have been declared\n\n";
}

//The Syntax Functions implemented
void Rat21F (){
  Opt_Function_Definitions();

}

void Opt_Function_Definitions(){
  Function_Definitions();
}

void Function_Definitions(){
  Function();
}

void Function() {
 a = Lexer();

  if (a.lexeme_word == "function"){
    cout << a.lexeme_word << " ";
    a = Lexer();

    //Inner Loop 2
    if (a.lexeme_token == "Identifier"){
      cout << a.lexeme_word << " ";
      a = Lexer();

      //Inner Loop 1
      if (a.lexeme_word == "("){
        cout << a.lexeme_word << " ";
        Opt_Parameter_List();


        a = temp;
        //cout << "\nlexeme after coming from Opt_Parameter_List is: " << a.lexeme_word << "--\n";

        if ( a.lexeme_word == ")"){
          cout << a.lexeme_word << " ";
          Opt_Decleration_List();

          Body();
        }
        else {
          cout << "What was expected was a ')'\n";
        }
      }
      else {
        cout << "What was expected is a '('\n";
      }
      //End of Inner Loop 1


    }
    else {
      cout << "What was expected is an 'Identifier'\n";
    }
    //End of Inner Loop 2
  }

  else {
    cout << "What was expected was the keyword 'function'\n";
  }
}

void Opt_Parameter_List(){
  Parameter_List();
}

void Parameter_List(){
  Parameter();

    a = Lexer();
    if (a.lexeme_word == ")");
    temp = a;
  if( a.lexeme_word == ","){
    cout << a.lexeme_word << " ";
    Parameter_List();
  }
}

void Parameter(){
  IDs();
  Qualifier();
}

void IDs(){
    a = Lexer();

  if (a.lexeme_token == "Identifier"){
      cout << a.lexeme_word << " ";
  }

  else {
    cout << "What was expected is an 'Identifier'\n";
  }
}
void Qualifier(){

  if ( second_time == 0){
  a = Lexer();
  }

  else if ( second_time == 1){
    a = temp2;
  }

  if (a.lexeme_word == "integer" || a.lexeme_word == "boolean" || a.lexeme_word == "real"){
    cout << a.lexeme_word << " ";
  }
  else {
    cout << "What was expected was either an 'integer', 'boolean', or 'real'\n";
  }
}

void Opt_Decleration_List(){
  //cout << "\nWorking #8\n";
  Decleration_list();
}

void Decleration_list(){
  //cout << "Working #9\n";
  Decleration();
}

void Decleration(){
  //cout << "Working #10\n";
  Qualifier();
  IDs();
  a = Lexer();
  if( a.lexeme_word == ";"){
    cout << a.lexeme_word << " ";
    a = Lexer();

    if (a.lexeme_token == "Keyword" ){
      second_time = 1;
      temp2 = a;
      Decleration();
    }
    else {
      temp = a;
    }
  }
}

void Body(){
  a = temp;
  //cout << "\nTesting: " << a.lexeme_word << "\n";
  if ( a.lexeme_word == "{"){
    cout << a.lexeme_word << " ";
    Statement_List();
  }
  else {
    cout << "What was expected was a '{'\n";
  }
}

void Statement_List(){
  Statement();
}

void Statement(){
  a = Lexer();
    if (a.lexeme_word == "{"){
      cout << a.lexeme_word << " ";
      Compound();
    }
    else if (a.lexeme_token == "Identifier"){
      cout << a.lexeme_word << " ";

      Assign();
    }
    else if (a.lexeme_word == "if"){
      cout << a.lexeme_word << " ";

      //If();
    }
    else if (a.lexeme_word == "return"){
      cout << a.lexeme_word << " ";

      //Return();
    }
    else if (a.lexeme_word == "put"){
      //Expression();
    }
    else if (a.lexeme_word == "get"){
      cout << a.lexeme_word << " ";

      //Scan();
    }
    else if (a.lexeme_word == "while"){
      cout << a.lexeme_word << " ";

      //While();
    }
    else {
      cout << "What was expected were either '{', an 'Identifier', 'if', 'return', 'put', 'get', or 'while'\n";

    }
}

void Compound(){
  Statement_List();
}

void Assign() {
  a = Lexer();

  if (a.lexeme_word == "="){
    cout << a.lexeme_word << " ";
    //xpression();
  }
}






#endif /*SyntaxAnalyzerFunctions_h*/
