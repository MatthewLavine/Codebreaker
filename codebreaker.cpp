#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

int codebreaker(int complexity, int digits) {
  int attempts = complexity-1;
  cout << "Welcome to Codebreaker!" << endl;
  string code = "";
  srand(time(0));
  for (int i=0;i<digits;i++) {
    code += to_string(rand() % 6+1);
  }

  cout << "Guess the secret number! (" + to_string(digits) + " digits)" << endl;
  cout << "You have " + to_string(attempts) + " attempts" << endl;
  while(true) {
    string guess;
    cin >> guess;
    if(guess.length() != digits) {
      cout << "You must guess a " + to_string(digits) + " digit number!" << endl;
      continue;
    }
    attempts--;
    for(int i=0;i<digits;i++) {
      if(guess[i] == code[i]) {
        cout << "✔";
      } else {
        cout << "✗";
      }
    }
    cout << "    " + to_string(attempts) + " attempt(s) remaining" << endl;
    if(guess == code) {
      cout << "You win!" << endl;
      break;
    }
    if(attempts <= 0) {
      cout << "You lose!" << endl;
      break;
    }
  }
  cout << "Play again? (y/n)" << endl;
  string again;
  cin >> again;
  if(again == "y") {
    codebreaker(complexity, digits);
  }
  return 0;
}

int main() {
  const int complexity = 6;
  const int digits = 5;
  codebreaker(complexity, digits);
  return 0;
}
