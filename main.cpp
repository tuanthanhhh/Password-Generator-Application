#include "RamdomCharacter.h"

char numbers, specialCharacters, lowercaseLetters, uppercaseLetters;

char PassWord[100];
int t[100];
int lengthOfPassWord = 0;
int n = 0; //bien check coi ky tu nao co r
int checkNumber = 0, checkLowercase = 0, checkUpper = 0, checkSpecialCharacter = 0;
int check3;


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

    if (lowercaseLetters == 'y') //checkNumber, checkLowercase, checkUpper, checkSpecialCharacter;
        checkLowercase = 1;		//numbers, specialCharacters, lowercaseLetters, uppercaseLetters
    if (numbers == 'y')
        checkNumber = 1;
    if (specialCharacters == 'y')
        checkSpecialCharacter = 1;
    if (uppercaseLetters == 'y')
        checkUpper = 1;

    srand((unsigned int)time(NULL));

    check3 = checkLowercase + checkNumber + checkSpecialCharacter + checkUpper;
    if (check3 == 0)
    {
        cout << "\nCan't create PassWord" << endl;
        return 0;
    }

    for (int i = 0; i < lengthOfPassWord; i++)
    {
        PassWord[i] = RandomTypeCharacter(lengthOfPassWord, check3, checkNumber, checkLowercase, checkUpper, checkSpecialCharacter);
        if (i + check3 >= lengthOfPassWord)
        {
            t[i] = n;
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