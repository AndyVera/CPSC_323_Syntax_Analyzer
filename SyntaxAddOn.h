#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#ifndef SyntaxAddOn_h
#define SyntaxAddOn_h

using namespace std;
ifstream inputfile;
ofstream outputfile;
int current_state = 0;
int previous_state = 0;
string lexeme_string_source;
string::iterator ptr;
char lexeme_string_input;
int index___ = 0;

void change_stream_contents (const char* input, const char* output){
  inputfile.open(input);
  outputfile.open(output);
}

int checking_proper_streams(){
  if (inputfile.is_open() != 1){
    cout << "Could not properly open the input file to fetch data from\n";
    return 1;
  }
  if(outputfile.is_open() != 1){
    cout << "Could not properly open the outut file to insert data into\n";
    return 1;
  }
  return 0;
}

void checking_input_and_starting_iterator(){
string lexeme_string_first ((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
lexeme_string_source = lexeme_string_first;
ptr = lexeme_string_source.begin();
}

string keywords[14] = { "true","function","integer","false",
			            "boolean", "real","if",	"endif",
			            "else",	"return","put",	"get","while", "for"} ;

string separators[6] = { "}",		"{",		"(",		")",
			",",	";"};

string operators[11] = {"<=",	 "+",		"-", 	"*",
			"/",		 ">",		"<",		"=>",
			"!=",	 "=", "==" };

void closing_streams(){
    inputfile.close();
    outputfile.close();
}

void Lexer() {

  int DFSM[5][4];
  DFSM[0][0] = 0; DFSM[0][1] = 1; DFSM[0][2] = 2; DFSM[0][3] = 3;

  DFSM[1][0] = 1; DFSM[1][1] = 1; DFSM[1][2] = 1; DFSM[1][3] = 3;

  DFSM[2][0] = 2; DFSM[2][1] = 3; DFSM[2][2] = 2; DFSM[2][3] = 4;

  DFSM[3][0] = 3; DFSM[3][1] = 3; DFSM[3][2] = 3; DFSM[3][3] = 3;

  DFSM[4][0] = 4; DFSM[4][1] = 3; DFSM[4][2] = 4; DFSM[4][3] = 3;

  string lexeme_string;

  while(*ptr != '\0'){
   lexeme_string_input = *ptr;

    //State 0
    if(isalpha(lexeme_string_input) && current_state == 0 ){
        current_state = DFSM[current_state][1];
        lexeme_string += lexeme_string_input;
        //cout << "so far: " << lexeme_string << '\n';
    }
    else if(isdigit(lexeme_string_input) && current_state == 0 ){
        current_state = DFSM[current_state][2];
        lexeme_string += lexeme_string_input;
        //cout << "so far: " << lexeme_string << '\n';
    }
    else if((lexeme_string_input == '.') && current_state == 0 ){
        current_state = DFSM[current_state][3];
    }

    //State 1
    else if (isalpha(lexeme_string_input) && current_state == 1){
      //  previous_state = current_state;
        current_state = DFSM[current_state][1];
        lexeme_string += lexeme_string_input;
        //cout << "so far: " << lexeme_string << '\n';
    }
    else if (lexeme_string_input == '_' && current_state == 1){
      current_state = DFSM[current_state][1];
      lexeme_string += lexeme_string_input;
    }

    else if (isdigit(lexeme_string_input) && current_state == 1){
      //  previous_state = current_state;
        current_state = DFSM[current_state][2];
        lexeme_string += lexeme_string_input;
        //cout << "so far: " << lexeme_string << '\n';

    }

    else if(lexeme_string_input == '.' && current_state == 1){
      //  previous_state = current_state;
        current_state = DFSM[current_state][3];
        lexeme_string += lexeme_string_input;
        //cout << "so far: " << lexeme_string << '\n';

    }

    //State 2
    else if (isdigit(lexeme_string_input) && current_state == 2){
        //previous_state = current_state;
        current_state = DFSM[current_state][2];
        lexeme_string += lexeme_string_input;
        //cout << "so far: " << lexeme_string << '\n';
    }

    else if (isalpha(lexeme_string_input) && current_state == 2){
        //cout << setw(16) << "Integer" << "|" << setw(17) << lexeme_string << '\n';
        current_state = DFSM[current_state][1];
        lexeme_string += lexeme_string_input;
        //cout << "so far: " << lexeme_string << '\n';
    }

    else if(lexeme_string_input == '.' && current_state == 2){
    //previous_state = current_state;
    current_state = DFSM[current_state][3];
    lexeme_string += lexeme_string_input;
    //cout << "so far: " << lexeme_string << '\n';
    }

    // State 3
    else if (isalpha(lexeme_string_input) && current_state == 3){
      current_state = DFSM[current_state][1];
      lexeme_string += lexeme_string_input;
      //cout << "so far: " << lexeme_string << '\n';
    }

    else if (isdigit(lexeme_string_input) && current_state == 3){
      current_state = DFSM[current_state][2];
      lexeme_string += lexeme_string_input;
      //cout << "so far: " << lexeme_string << '\n';
    }

    else if (lexeme_string_input == '.' && current_state == 3){
    current_state = DFSM[current_state][3];
    lexeme_string += lexeme_string_input;
    //cout << "so far: " << lexeme_string << '\n';
    }

    //State 4

    else if (isalpha(lexeme_string_input) && current_state == 4){
      current_state = DFSM[current_state][1];
      lexeme_string += lexeme_string_input;
      //cout << "so far: " << lexeme_string << '\n';
    }
    else if (isdigit(lexeme_string_input) && current_state == 4){
      current_state = DFSM[current_state][2];
      lexeme_string += lexeme_string_input;
      //cout << "so far: " << lexeme_string << '\n';
    }
    else if (lexeme_string_input == '.' && current_state == 4){
      current_state = DFSM[current_state][3];
      lexeme_string += lexeme_string_input;
      //cout << "so far: " << lexeme_string << '\n';
    }

    //If its a white space, then stop lexer and identify lexeme
    if(*ptr == ' ' || *ptr == '\n'){
      break;
    }

    //If it is not a white space, letter, digit, or decimal point, then it can be an
    //operator or separator
    if(*ptr != ' ' && *ptr != '\n' && *ptr != '.' && isdigit(lexeme_string_input) == 0 && isalpha(lexeme_string_input) == 0 ){
      lexeme_string += lexeme_string_input;
    }

    ++ptr;

  }



    //checks if its a Operator or Separator
    if(current_state == 0 ){
      int sep_index, op_index;
      for(int i = 0; i <= 6; ++i){
        if( separators[i] == lexeme_string){
          outputfile << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Separator\n";
          break;
        }
        sep_index = i + 1;
      }
      for(int j = 0; j <= 10; ++j){
        if(operators[j] == lexeme_string){
          outputfile << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Operator\n";
          break;
        }
        op_index = j + 1;
      }
      if (op_index == 11 && sep_index == 7){
          outputfile << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Invalid\n";
      }

  }

    //First checks if its a Keyword, if not then its an Identifier
    if (current_state == 1){

      for (int i = 0; i < 15; ++i){
        if(keywords[i] == lexeme_string){
          outputfile << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Keyword\n";
          break;
        }
        index___ = i + 1;
      }

      if (index___ == 15){
        outputfile << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Identifier\n";
      }
    }

    //Checks if its an integer
    if (current_state == 2){
      outputfile << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Integer\n";

    }

    //Checks if its an Invalid token
    if (current_state == 3){
      outputfile << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Invalid\n";
    }

    //Checks if its a Real
    if(current_state == 4){
      outputfile << "Lexeme: " << setw(16) <<  left <<lexeme_string << "  Token: Real\n";

    }

    //Resets values for next lexeme
    current_state = 0;
    ++ptr;
}



#endif /*SyntaxAddOn_h*/
