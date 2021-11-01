#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "SyntaxAddOn.h"

#ifndef SyntaxAnalyzerFunctions_h
#define SyntaxAnalyzerFunctions_h

Lexeme a;
Lexeme temp;

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
   Lexeme b = Lexer();

  if (b.lexeme_token == "Identifier"){

      cout << b.lexeme_word << " ";
      Qualifier();

      a = Lexer();
      temp = a;

      if(a.lexeme_word == ","){
        IDs();
      }
  }

  else {
    cout << "What was expected is an 'Identifier'\n";
  }
}

void Qualifier(){
  a = Lexer();
  if (a.lexeme_word == "integer" || a.lexeme_word == "boolean" || a.lexeme_word == "real"){
    cout << a.lexeme_word << " ";
  }
}

void Opt_Decleration_List(){
  cout << "\nWorking #8\n";

}



#endif /*SyntaxAnalyzerFunctions_h*/
