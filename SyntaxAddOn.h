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
string lexeme_string;
string::iterator ptr;
char lexeme_string_input;

void change_stream_contents (const char* input, const char* output){
  cout << "Inutfile is: " << input << "\n";
  cout << "Outputfile is: " << output << "\n";
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
lexeme_string = lexeme_string_first;
cout << "\nWhat was acquiered from file is: " << lexeme_string << '\n';
ptr = lexeme_string.begin();
}

string keywords[14] = { "true","function","integer","false",
			            "boolean", "real","if",	"endif",
			            "else",	"return","put",	"get","while"} ;

string separators[7] = { "}",		"{",		"(",		")",
			",",	";"};

string operators[11] = {"<=",	 "+",		"-", 	"*",
			"/",		 ">",		"<",		"=>",
			"!=",	 "=" };

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

  static string lexeme_string;

  while(*ptr != ' '){
   lexeme_string_input = *ptr;
   //cout << "input: " << lexeme_string_input << "\n";

    //starting state - frist input
    if(isalpha(lexeme_string_input) && current_state == 0 ){
        current_state = DFSM[0][1];
        lexeme_string += lexeme_string_input;
        cout << "starting: " << lexeme_string << "\n";
    }
    else if(isdigit(lexeme_string_input) && current_state == 0 ){
        current_state = DFSM[0][2];
        lexeme_string += lexeme_string_input;
        cout << "starting num: " << lexeme_string << "\n"<< "added once\n";
    }
    else if((lexeme_string_input == '.') && current_state == 0 ){
        current_state = DFSM[0][3];
    }

    //second input
    else if (isalpha(lexeme_string_input) && current_state == 1){
        previous_state = current_state;
        current_state = DFSM[current_state][1];
        lexeme_string += lexeme_string_input;
        cout << "so far: " << lexeme_string << '\n';
    }

    else if (isdigit(lexeme_string_input) && current_state == 1){
        previous_state = current_state;
        current_state = DFSM[current_state][2];
        lexeme_string += lexeme_string_input;
        cout << "so far: " << lexeme_string << '\n';

    }

    else if(lexeme_string_input == '.' && current_state == 1){
        previous_state = current_state;
        current_state = DFSM[current_state][3];
        cout << "so far: " << lexeme_string << '\n';

    }


    // else if (lexeme_string_input == ' ' && current_state == 1 && (lexeme_string.length() == 1)){
    //     current_state = 0;
    //     previous_state = 0;
    //     cout << setw(16) << "Identifier" << "|" << setw(17) << lexeme_string << '\n';
    //     lexeme_string = '\0';
    //}

    //third input
    else if (isdigit(lexeme_string_input) && current_state == 2){
        previous_state = current_state;
        current_state = DFSM[current_state][2];
        lexeme_string += lexeme_string_input;
        cout << "so far: " << lexeme_string << '\n';
    }

    else if (isalpha(lexeme_string_input) && current_state == 2){
        //cout << setw(16) << "Integer" << "|" << setw(17) << lexeme_string << '\n';
        lexeme_string = '\0';
        lexeme_string += lexeme_string_input;
        current_state = 0;
        previous_state = 0;
    }

    else if(lexeme_string_input == '.' && current_state == 2){
    previous_state = current_state;
    current_state = DFSM[current_state][3];
    lexeme_string += lexeme_string_input;
      cout << "so far: " << lexeme_string << '\n';
}







    ++ptr;
  }
  if ( *ptr == ' '){
    current_state = 0;
    previous_state = 0;
    lexeme_string = '\0';
    ++ptr;
  }

}



#endif /*SyntaxAddOn_h*/
