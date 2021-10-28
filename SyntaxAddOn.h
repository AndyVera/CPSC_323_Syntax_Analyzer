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
  // cout << "Inutfile is: " << input << "\n";
  // cout << "Outputfile is: " << output << "\n";
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
//cout << "\nWhat was acquiered from file is: " << lexeme_string_source << '\n';
ptr = lexeme_string_source.begin();
}

string keywords[14] = { "true","function","integer","false",
			            "boolean", "real","if",	"endif",
			            "else",	"return","put",	"get","while", "for"} ;

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

  string lexeme_string;

  while(*ptr != '\0'){
   lexeme_string_input = *ptr;
   //cout << "input: " << lexeme_string_input << "\n";

   //if(*ptr != ' '){
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


    // else if (lexeme_string_input == ' ' && current_state == 1 && (lexeme_string.length() == 1)){
    //     current_state = 0;
    //     previous_state = 0;
    //     cout << setw(16) << "Identifier" << "|" << setw(17) << lexeme_string << '\n';
    //     lexeme_string = '\0';
    //}

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

    if(*ptr == ' ' || *ptr == '\n'){
      break;
    }

    ++ptr;

  }
  //if ( *ptr == ' ' || *ptr == '\0'){

    // cout << "\n\n";

    if (current_state == 1){
      // while (index___ < 14){
      // //  cout << keywords[index___] << '\n';
      //  cout <<"-" << lexeme_string << "-" << "\n";
      // //  cout << "index__ for keywords: " << index___ << "\n\n";
      //   if(keywords[index___] == lexeme_string){
      //     cout << "Lexeme: " << setw(16) << left << lexeme_string << " Token: Keyword\n";
      //     index___ = 0;
      //     break;
      //   }
      //   index___++;
      // }
      // //cout << "Index: " <<index___ << '\n';
      // if (index___ == 14){
      //   index___ = 0;
      //   cout << "Lexeme: " << setw(16) << left << lexeme_string << " Token: Identifier\n";
      // }



      for (int i = 0; i < 15; ++i){
        if(keywords[i] == lexeme_string){
          cout << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Keyword\n";
          break;
        }
        index___ = i + 1;
      }

      if (index___ == 15){
        cout << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Identifier\n";
      }
    }

    if (current_state == 2){
      cout << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Integer\n";

    }

    if (current_state == 3){
      cout << "Lexeme: " << setw(16) << left << lexeme_string << "  Token: Invalid\n";
    }
    if(current_state == 4){
      cout << "Lexeme: " << setw(16) <<  left <<lexeme_string << "  Token: Real\n";

    }
    current_state = 0;
    previous_state = 0;
    lexeme_string = '\0';
    ++ptr;
  //}
//}
}



#endif /*SyntaxAddOn_h*/
