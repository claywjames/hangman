#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <vector>

using namespace std;

void playGame();
void playTurn(string word, string &wrongGuesses, string &guessedWord, int &guessesRemaining);
string getWord();
void drawHangman(int guessesRemaining);
char getGuess();
vector<int> matchingLetterPositions(char guess, string word);

int main() {
    srand(time(NULL)); //create the seed for rand() using the current time
    
    playGame();
    cout << "Thanks for playing!!!" << endl;

    return 0;
}


void playGame() {
    string word = getWord(), wrongGuesses;
    string guessedWord(word.length(), '_');
    int guessesRemaining = 6;

    while (guessesRemaining > 0 && guessedWord != word) 
        playTurn(word, wrongGuesses, guessedWord, guessesRemaining);
    
    system("CLS");
    drawHangman(guessesRemaining);
    for (int i = 0; i < guessedWord.length(); i++) cout << guessedWord[i] << " ";
    cout << endl << "Guesses left: " << guessesRemaining << endl;
    if (guessedWord == word) {
        cout << "You Win!" << endl;
    } else {
        cout << "The word was: " << word << endl;
    }
    char playAgain;
    cout << "Would you like to keep playing?(Y/N)" << endl;
    cin >> playAgain;
    if (playAgain == 'Y') playGame();

}

void playTurn(string word, string &wrongGuesses, string &guessedWord, int &guessesRemaining) {
    system("CLS");

    drawHangman(guessesRemaining);
    int i;
    for (i = 0; i < guessedWord.length(); i++) cout << guessedWord[i] << " ";
    cout << endl << "Guesses left: " << guessesRemaining << endl;
    cout << "Wrong Guesses: " << endl;
    for (i = 0; i < wrongGuesses.length(); i++)
        if (isalpha(wrongGuesses[i])) cout << wrongGuesses[i] << endl;

    char guess = getGuess();
    vector<int> correctLetterPositions = matchingLetterPositions(guess, word);
    if (correctLetterPositions.size() == 0) {
        wrongGuesses.insert(wrongGuesses.begin(), guess);
        --guessesRemaining;
    } else {
        for (i = 0; i < correctLetterPositions.size(); i++)
            guessedWord[correctLetterPositions[i]] = guess;
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

void drawHangman(int guessesRemaining) {
    switch (guessesRemaining) {
        case 6:
            cout << "    _____\n   |    |\n        |\n        |\n        |\n        |\n        |\n        |\n        |\n";
            break;
        case 5:
            cout << "    _____\n   |    |\n   O    |\n        |\n        |\n        |\n        |\n        |\n        |\n";
            break;
        case 4:
            cout << "    _____\n   |    |\n   O    |\n   |    |\n        |\n        |\n        |\n        |\n        |\n";
            break;
        case 3:
            cout << "    _____\n   |    |\n   O    |\n  /|    |\n        |\n        |\n        |\n        |\n        |\n";
            break;
        case 2:
            cout << "    _____\n   |    |\n   O    |\n  /|\\   |\n        |\n        |\n        |\n        |\n        |\n";
            break;
        case 1:
            cout << "    _____\n   |    |\n   O    |\n  /|\\   |\n  /     |\n        |\n        |\n        |\n        |\n";
            break;
        case 0:
            cout << "    _____\n   |    |\n   O    |\n  /|\\   |\n  / \\   |\n        |\n        |\n        |\n        |\n";
            break;
    }
}

char getGuess() {
	char guess;

	cout << "Guess a letter." << endl;
	cin >> guess;

	return guess;
}

vector<int> matchingLetterPositions(char guess, string word) {
    vector<int> positionVector;
	for (int i = 0; i < word.length(); i++)
		if (word[i] == guess) positionVector.push_back(i);

	return positionVector;
}

