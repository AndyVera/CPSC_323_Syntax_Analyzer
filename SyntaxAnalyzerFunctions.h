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
Lexeme temp4;
Lexeme temp5;

int second_time = 0;
int holding_something = 0;
int holding_something2 = 0;
int holding_something3 = 0;
int holding_something4 = 0;
int scanned_used = 0;
int return_semi_used = 0;


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


//The Syntax Functions implemented

//
void Rat21F (){
  Opt_Function_Definitions();

  a = Lexer();
  //cout << "\nTesting what lexer is: " << a.lexeme_word << "\n";
  if ( a.lexeme_word == "#"){
    cout << a.lexeme_word << " ";
    Opt_Decleration_List();
    Statement_List();

    a = Lexer();
    if ( a.lexeme_word == "#"){
      cout << a.lexeme_word << " ";
    }
  }
  else {
    cout << "What is expected is a '#'\n";
  }


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

    // cout << "\nTesting IDs output: " << ""

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
    cout << "\n";

  Qualifier();
  IDs();
  second_time = 0;
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
      holding_something4 = 1;
      //cout << "\nTesting what temp is: " << temp.lexeme_word << "\n";
    }
  }
}

void Body(){
  a = temp;
  //cout << "\nTesting: " << a.lexeme_word << "\n";
  if ( a.lexeme_word == "{"){
    cout << a.lexeme_word << " ";
    Statement_List();

    a = Lexer();
      if (a.lexeme_word == "}"){
        cout << a.lexeme_word << " ";
      }
  }
  else {
    cout << "What was expected was a '{'\n";
  }
}

void Statement_List(){
  Statement();
}

void Statement(){
  if (holding_something4 == 1){
    a = temp;
    holding_something4 = 0 ;
  }
  else{
  a = Lexer();
}

  //cout << "\ntesting: " << a.lexeme_word << "\n";
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

      If();
    }
    else if (a.lexeme_word == "return"){
      cout << a.lexeme_word << " ";
      Return();
    }
    else if (a.lexeme_word == "put"){
      cout << a.lexeme_word << " ";
      Print();
    }
    else if (a.lexeme_word == "get"){
      cout << a.lexeme_word << " ";
      Scan();
    }
    else if (a.lexeme_word == "while"){
      cout << a.lexeme_word << " ";
      While();
    }
    else if (a.lexeme_word != "{" && a.lexeme_token != "Identifier" && a.lexeme_word != "if" && a.lexeme_word != "return" && a.lexeme_word != "put" && a.lexeme_word != "get" && a.lexeme_word != "while" ){
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
    Expression();

    if (holding_something == 1){
      a = temp;
      holding_something = 0;
    }
    else {
      a = Lexer();
    }
    if ( a.lexeme_word == ";"){
      cout << a.lexeme_word << " ";
    }
  }
  else {
    cout << "What was expected was a '='\n";
  }
}

void Expression(){
  Term();
  Expression_prime();
}

void Term(){
  Factor();
  Term_prime();
}

void Factor(){
  Primary();
}

void Primary(){
  if (holding_something2 == 1){
    a = temp5;
    holding_something2 = 0;
  }
  else{
  a = Lexer();
  }
  //cout << "\nTesting: " << a.lexeme_word << "\n";
  if (a.lexeme_token == "Integer"){
    cout << a.lexeme_word << " ";
  }
  else if (a.lexeme_word == "("){
    cout << a.lexeme_word << " ";
    Expression();
  }
  else if (a.lexeme_token == "Real"){
    cout << a.lexeme_word << " ";
  }
  else if ( a.lexeme_word == "true"){
    cout << a.lexeme_word << " ";
  }
  else if ( a.lexeme_word == "false"){
    cout << a.lexeme_word << " ";
  }
  else if (a.lexeme_token == "Identifier"){
    cout << a.lexeme_word << " ";
    a = Lexer();
    holding_something = 1;
    temp4 = a;
    //cout << "\nTesting: " << a.lexeme_word << "\n";
    if (a.lexeme_word == "("){
      cout << a.lexeme_word << " ";
      IDs();
      a = Lexer();
      if (a.lexeme_word == ")"){
        cout << a.lexeme_word << " ";
      }
    }
  }

}

void Term_prime(){
  if (holding_something == 1){
    a = temp3;
    holding_something = 0;
  }
  else {
    a = Lexer();
  }
//cout << "\nTesting #12: " << a.lexeme_word << "\n";
  if(a.lexeme_word == "*" || a.lexeme_word == "/"){
    cout << a.lexeme_word << " ";
    holding_something = 0;
    Factor();
    Term_prime();
  }
  else {
    temp = a;
    holding_something = 1;
  }
}

void Expression_prime (){
  if (holding_something == 1){
    a = temp;
  }
  else {
    a = Lexer();
  }

  if(a.lexeme_word == "+" || a.lexeme_word == "-"){
    cout << a.lexeme_word << " " ;
    holding_something = 0;
    Term();
    Expression_prime();
  }
  else {
    temp = a;
    holding_something = 1;
    holding_something3 = 1;
  }
}

void If(){
  a = Lexer();

//cout << "\nTesting: " << a.lexeme_word << "\n";
  if (a.lexeme_word == "("){
    cout << a.lexeme_word << " ";
    Condition();

    //a = Lexer(); //NOTE: MAY OR MAY NOT NEED IT)

    //This if statement is for when its another Identifier after the relop
    // if(holding_something == 1){
    //   a = temp4;
    //   holding_something = 0;
    // }

    if (a.lexeme_word == ")"){
      cout << a.lexeme_word << " ";
      Statement();
      If_prime();

    }
  }
}

void Condition(){
  Expression();
  Relop();
  Expression();
}

void Relop(){
  if (holding_something == 1 ) {
    a = temp4;
    holding_something = 0;
  }
  else{
    a = Lexer();
  }

  //NOTE: WITHINT THE CONDITION STATEMENT, EVERYTHING NEEDS TO BE ONE SPACE APART

  if (a.lexeme_word == "==" || a.lexeme_word == "!=" || a.lexeme_word == ">" || a.lexeme_word == "<" || a.lexeme_word == "<=" || a.lexeme_word == "=>") {
    cout << a.lexeme_word << " ";

  }
}

void If_prime(){

  a = Lexer();

  if(a.lexeme_word == "endif"){
    cout << a.lexeme_word << " ";
  }

  else if (a.lexeme_word == "else"){
    cout << a.lexeme_word << " ";
    Statement();

    if (scanned_used == 1){
    a = Lexer();
    }
    if (a.lexeme_word == "endif"){
      cout << a.lexeme_word << " ";
    }
  }
}

void Return(){
  a = Lexer();

  if( a.lexeme_word == ";"){
    cout << a.lexeme_word << " ";
  }
  else if ( a.lexeme_word != ";"){
    holding_something2 = 1;
    temp5 = a;
    Expression();
  //  a = Lexer();
    if ( a.lexeme_word == ";"){
      cout << a.lexeme_word << " ";

    }
  }
}

void Print(){
  a = Lexer();

  if (a.lexeme_word == "("){
    cout << a.lexeme_word << " ";
    Expression();


    if (a.lexeme_word == ")"){
      cout << a.lexeme_word << " ";
      a = Lexer();
      if ( a.lexeme_word == ";"){
        cout << a.lexeme_word << " ";
      }
    }
  }
}

void Scan(){
  a = Lexer();

  if (a.lexeme_word == "("){
    cout << a.lexeme_word << " ";
    IDs();

    a = Lexer();
    if (a.lexeme_word == ")"){
      cout << a.lexeme_word << " ";
      a = Lexer();
      if ( a.lexeme_word == ";"){
        cout << a.lexeme_word << " ";
        scanned_used = 1;
      }
    }
  }
}

void While(){
  a = Lexer();

  if(a.lexeme_word == "("){
    cout << a.lexeme_word << " ";
    Condition();

  //May or May Not Need It
  //  a = Lexer();

    if(a.lexeme_word == ")"){
      cout << a.lexeme_word << " ";
      Statement();



      if ( a.lexeme_word == ";"){
        cout << a.lexeme_word << " ";
      }
    }
  }
}




#endif /*SyntaxAnalyzerFunctions_h*/
