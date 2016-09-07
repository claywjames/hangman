#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <ctype.h>

using namespace std;

string getWord();
char getGuess();

int main() {
    srand(time(NULL)); //create the seed for rand() using the current time
    int i, guessesRemaining = 5;
    string word = getWord(), wrongGuesses(6, '\0');
    string guessedWord(word.length(), '_');
    
    system("CLS");
    cout << word << endl;
    for (i = 0; i < guessedWord.length(); i++) cout << guessedWord[i] << " ";
    cout << endl << "Guesses left: " << guessesRemaining << endl;
    cout << "Wrong Guesses: " << endl;
    for (i = 0; i < wrongGuesses.length(); i++)
        if (isalpha(wrongGuesses[i])) cout << wrongGuesses[i] << endl;
    char guess = getGuess();

    return 0;
}


string getWord() {
    int randChoice = rand() % 979; //random number between 0 and 978
    ifstream dictionaryFile("dictionary.txt");
    stringstream dictionaryBuffer;

    dictionaryBuffer << dictionaryFile.rdbuf();
    string dictionary = dictionaryBuffer.str();

    int i;
    for (i = 0; i < randChoice; i++) dictionary = dictionary.substr(dictionary.find('\n') + 1);
    string word = dictionary.substr(0, dictionary.find('\n'));
    
    return word;
}

char getGuess() {
    return 'a';
}