#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <ctype.h>

using namespace std;

void playGame();
void playTurn(string word, string &wrongGuesses, string &guessedWord, int guessesRemaining);
string getWord();
void drawHangman(int guessesRemaining);
char getGuess();

int main() {
    srand(time(NULL)); //create the seed for rand() using the current time
    
    playGame();
    cout << "Thanks for playing!!!" << endl;

    return 0;
}


void playGame() {
    string word = getWord(), wrongGuesses(6, '\0');
    string guessedWord(word.length(), '_');
    int guessesRemaining = 6;

    while (guessesRemaining > 0 && guessedWord != word) {
        playTurn(word, &wrongGuesses, &guessedWord, guessesRemaining);
        --guessesRemaining;
    }

    char playAgain;
    cout << "Would you like to keep playing?(Y/N)" << endl;
    cin >> playAgain;
    if (playAgain == 'Y') playGame();

}

void playTurn(string word, string &wrongGuesses, string &guessedWord, int guessesRemaining) {
    system("CLS");

    drawHangman(guessesRemaining)
    int i;
    for (i = 0; i < guessedWord.length(); i++) cout << guessedWord[i] << " ";
    cout << endl << "Guesses left: " << guessesRemaining << endl;
    cout << "Wrong Guesses: " << endl;
    for (i = 0; i < wrongGuesses.length(); i++)
        if (isalpha(wrongGuesses[i])) cout << wrongGuesses[i] << endl;

    char guess = getGuess();
    int correctLetterPositions = matchingLetterPositions(guess, word);
    if (correctLetterPositions.empty()) {
        cout << "incorrect";
        wrongGuesses
    }
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