#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

string WORD_LIST[] =
{
    "angle", "ant", "apple", "arch", "arm", "army",
    "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
    "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
    "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
    "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
    "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
    "cow", "cup", "curtain", "cushion",
    "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
    "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
    "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
    "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
    "hospital", "house", "island", "jewel",  "kettle", "key", "knee", "knife", "knot",
    "leaf", "leg", "library", "line", "lip", "lock",
    "map", "match", "monkey", "moon", "mouth", "muscle",
    "nail", "neck", "needle", "nerve", "net", "nose", "nut",
    "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
    "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
    "rail", "rat", "receipt", "ring", "rod", "roof", "root",
    "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
    "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
    "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
    "store", "street", "sun", "supercalifragilisticexpialidocious", "table", "tail", "thread", "throat", "thumb", "ticket",
    "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
    "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
string chooseWord()
{
    int randomIndex = rand() % WORD_COUNT;
    return WORD_LIST[randomIndex];
}

void renderGame(string guessedWord, int badGuessCount)
{
    cout << guessedWord << endl;
    cout << "Number of wrong guesses: " << badGuessCount << endl;
}

string update(string& guessedWord, string secretWord, char guess)
{
    for (int i = secretWord.length() - 1; i >= 0; i--)
    {
        if (secretWord[i] == guess)
        {
            guessedWord[i] = guess;
        }
    }
    return guessedWord;
}

bool checkguess(char guess, string secretWord)
{
    for(int i=0; i<secretWord.length(); i++)
        if(guess == secretWord[i]) return true;
    return false;
}

int main()
{
    srand(time(0));
    string secretWord = chooseWord();
    string guessedWord = string(secretWord.length(), '-');
    int badGuessCount = 0;
    while(badGuessCount <= 10)
    {
        char guess;
        cin >> guess;
        if(checkguess(guess, secretWord)){
            update(guessedWord, secretWord, guess);
            if(secretWord == guessedWord)
            {
                renderGame(guessedWord, badGuessCount);
                return 0;
            }
            else cout << guessedWord;
        }
        else
        {
            badGuessCount++;
            cout << guessedWord;

        }

    }
    cout << "YOU'RE DEAD!";

    return 0;
}
