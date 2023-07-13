#include "RamdomCharacter.h"

extern int typeCharacter;
extern int matrixCheckCharacter[1000];

int GetRandom(int min, int max)
{
    std::random_device randomDevice;
    std::mt19937 engine(randomDevice());
    std::uniform_int_distribution<int> distribution(min, max );
    return distribution(engine);
}
char RandomLowercase()
{
    return (char)GetRandom(97, 122);
}
char RandomUpper()
{
    return (char)GetRandom(65, 90);
}
char RamdomNumber()
{
    return (char)GetRandom(48, 57);
}
char RandomSpecialCharacter()
{
    char specialCharacter;
    switch (GetRandom(1, 3))
    {
    case 1:
    {
        specialCharacter = GetRandom(33, 47);
        break;
    }
    case 2:
    {
        specialCharacter = GetRandom(58, 64);
        break;
    }
    case 3:
    {
        specialCharacter = GetRandom(91, 96);
        break;
    }
    case 4:
    {
        specialCharacter = GetRandom(123, 126);
        break;
    }
    default:
        break;
    }
    return specialCharacter;
}


char RandomTypeCharacter(int lengthPassWord, int numberOfCharacter, int checkNumber, int checkLower, int checkUpper, int checkSpecialCharacter)
{
    char character;
    int checkTakeCharacter = 1;
    while (checkTakeCharacter == 1)
    {
        int checkEnoughCharacter = 0;
        while (checkEnoughCharacter == 0)
        {
            checkEnoughCharacter = 1;
            typeCharacter = GetRandom(1, 4);
            for (int count = lengthPassWord - numberOfCharacter; count < lengthPassWord; count++)
            {
                if (matrixCheckCharacter[count] == typeCharacter)
                {
                    checkEnoughCharacter = 0;
                    break;
                }
            }
        }
        switch (typeCharacter)
        {
        case 1:   //Ramdon Number 
        {
            if (checkNumber)
            {
                character = RamdomNumber();
                checkTakeCharacter = 0;
            }
            break;
        }
        case 2:   //Random Lowercase Letters
        {
            if (checkLower)
            {
                character = RandomLowercase();
                checkTakeCharacter = 0;
            }
            break;
        }
        case 3:   //Random Upper Letters
        {
            if (checkUpper)
            {
                character = RandomUpper();
                checkTakeCharacter = 0;
            }
            break;
        }
        case 4:   //Random Special Character
        {
            if (checkSpecialCharacter)
            {
                character = RandomSpecialCharacter();
                checkTakeCharacter = 0;
            }
            break;
        }
        default:
            break;
        }
    }
    return character;
}
