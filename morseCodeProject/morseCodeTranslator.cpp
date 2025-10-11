#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool run = true;

string inputText;

vector<char> alphebet = {' ','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h','i','j','k','l','n','m','o','p','q','r','s','t','u','v','w','x','y','z', '1', '2', '3', '4', '5', '6', '7', '8', '9','0', '.', '-', '!', '?', ',', '&'};
vector<string> morse = {"/", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.","....","..", ".---", "-.-", ".-..", "-.", "--", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-", "-....-", "-.-.--", "..--..", "--..--", ".-..."};

vector<string> finalS = {};
vector<char> finalC = {};

string encoderA(char input, vector<string> morseCode, vector<char> alphebet)  {
  int count = 0;

  for (char letter : alphebet) {
    if (input == alphebet[count]) {
      return morseCode[count];
    } else if (input != alphebet[count])  {
      count++;
    }
  }
  return " ";
}

char encoderM(string input, vector<string> morseCode, vector<char> alphebet)  {
  int count = 0;

  for (string letter : morseCode) {
    if (input == morseCode[count]) {
      return alphebet[count];
    } else if (input != morseCode[count])  {
      count++;
    }
  }
  return ' ';
}

string combinerA(vector<string> final, string seperator)  {
  string container = "";
  for (string x : final) {
    container += (x + seperator);
  }
  return container;
}

string combinerM(vector<char> final, string seperator)  {
  string container = "";
  for (char x : final) {
    container += (x + seperator);
  }
  return container;
}

string lowerCase(string str)  {
  string strLower = "";
  for (char character : str)  {
    strLower += tolower(character);
  }

  return strLower;
}

int main() {
  cout << "Hello! Welcome to the C++ Morse Code Translator!\n-----------------------------------------------------------\n";
  while (run) {
    finalS = {};
    finalC = {};

    string inputText = "";
    string finalStr = "";

    int mode = 0;
    char modeCheck ='n';
  
    while (modeCheck != 'y')  {
      cout << "Select 1 for alphebet -> morse code || Select 2 for morse code -> alphebet || Select 3 to exit the program\n";

      cin >> mode; if (mode > 3 || mode == 0)  {cout << "ERROR"<<endl; continue;}
  
      cout << "You selected mode '"<<mode<<"' correct?\n(y/n)\n";

      cin >> modeCheck;
      if (modeCheck == 'y' && mode == 3) {
        return 1;
      }
      else if (!(modeCheck == 'y' || modeCheck == 'n')) {
        cout<<"ERROR";
      }
    }
    cout << "-----------------------------------------------------------" << endl;

    cout << "Input text: ";
    getline(cin >> ws, inputText);

    inputText = lowerCase(inputText);

    if (mode == 1)  {
      for (char letter : inputText) {
        finalS.push_back(encoderA(letter, morse, alphebet));
      }
      cout << "-----------------------------------------------------------" << endl;
      cout << combinerA(finalS, " ") << endl;

    } else if (mode == 2) {
      string word = "";
      vector<string> fixedInputText = {};

      for (char c : inputText)  {
        if (c == ' ') {
          fixedInputText.push_back(word);
          word = "";
        } else {
          word += c;
        }
      }
      fixedInputText.push_back(word);

      for (string word : fixedInputText)  {
        finalC.push_back(encoderM(word, morse, alphebet));
      }
      cout << "-----------------------------------------------------------" << endl;
      cout << combinerM(finalC, "") << endl;
      
    } 
    cout << "-----------------------------------------------------------" << endl;
  }
  return 0;
}
