#include "RamdomCharacter.h"

char numbers, specialCharacters, lowercaseLetters, uppercaseLetters;

char PassWord[1000];
int matrixCheckCharacter[1000];
int lengthOfPassWord = 0;
int typeCharacter = 0; 
int checkNumber = 0, checkLowercase = 0, checkUpper = 0, checkSpecialCharacter = 0;
int checkNumeberOfCharacter;


int main()
{

    cout << "===========================================================================" << endl;
    cout << " " << endl;
    cout << "                   PASSWORD GENERATOR APPLICATION" << endl;
    cout << " " << endl;
    cout << "===========================================================================" << endl;
    
    cout << "Enter The Length Number Of PassWord:    ";
    cin >> lengthOfPassWord;

    while (lengthOfPassWord < 4)
    {
        if (cin.fail())
        {
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            lengthOfPassWord = 0;
        }
        cout << "The Password length is not correct. Choose another number: ";
        cin >> lengthOfPassWord;
    }
    cout << "Use Number? [y/n]:             ";
    cin >> numbers;
    
    while (numbers != 'y' && numbers != 'n')
    {
        cout << "Wrong character. Again:       ";
        cin >> numbers;
    }
    cout << "Use special character? [y/n]:          ";
    cin >> specialCharacters;
   
    while (specialCharacters != 'y' && specialCharacters != 'n')
    {
        cout << "Wrong character. Again:       ";
        cin >> specialCharacters;
    }
    cout << "Use uppercase letters? [y/n]:   ";
    cin >> uppercaseLetters;
    
    while (uppercaseLetters != 'y' && uppercaseLetters != 'n')
    {
        cout << "Wrong character. Again:       ";
        cin >> uppercaseLetters;
    }
    cout << "Use  lowercase letters? [y/n]:  ";
    cin >> lowercaseLetters;
    
    while (lowercaseLetters != 'y' && lowercaseLetters != 'n')
    {
        cout << "Wrong character. Again:       ";
        cin >> lowercaseLetters;
    }

    if (lowercaseLetters == 'y') 
        checkLowercase = 1;		
    if (numbers == 'y')
        checkNumber = 1;
    if (specialCharacters == 'y')
        checkSpecialCharacter = 1;
    if (uppercaseLetters == 'y')
        checkUpper = 1;

    checkNumeberOfCharacter = checkLowercase + checkNumber + checkSpecialCharacter + checkUpper;
    if (checkNumeberOfCharacter == 0)
    {
        cout << "\nCan't create PassWord" << endl;
        return 0;
    }

    for (int i = 0; i < lengthOfPassWord; i++)
    {
        PassWord[i] = RandomTypeCharacter(lengthOfPassWord, checkNumeberOfCharacter, checkNumber, checkLowercase, checkUpper, checkSpecialCharacter);
        if (i + checkNumeberOfCharacter >= lengthOfPassWord)
        {
            matrixCheckCharacter[i] = typeCharacter;
        }
    }

    cout << "===========================================================================" << endl;
    cout << "" << endl;
    cout << "Password is:    ";

    for (int i = 0; i < lengthOfPassWord; i++)
    {

        cout << PassWord[i];
    }

    cout << "" << endl;
    cout << "" << endl;
    cout << "===========================================================================" << endl;

    getchar();
    return 0;
}