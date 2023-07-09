#include "RamdomCharacter.h"

extern int n;
extern int t[100];

int GetRandom(int min, int max)
{
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
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
    char test;
    int i = GetRandom(1, 3);
    switch (i)
    {
    case 1:
    {
        test = GetRandom(33, 47);
        break;
    }
    case 2:
    {
        test = GetRandom(58, 64);
        break;
    }
    case 3:
    {
        test = GetRandom(91, 96);
        break;
    }
    case 4:
    {
        test = GetRandom(123, 126);
        break;
    }
    default:
        break;
    }
    return test;
}


char RandomTypeCharacter(int lengthPassWord, int numberOfCharacter, int checkNumber, int checkLower, int checkUpper, int checkSpecialCharacter)
{
    char m;
    int check2 = 1;
    while (check2 == 1)
    {
        int check = 0;
        while (check == 0)
        {
            check = 1;
            n = GetRandom(1, 4);
            for (int count = lengthPassWord - numberOfCharacter; count < lengthPassWord; count++)
            {
                if (t[count] == n)
                {
                    check = 0;
                    break;
                }
            }
        }
        switch (n)
        {
        case 1:   //Ramdon Number 
        {
            if (checkNumber)
            {
                m = RamdomNumber();
                check2 = 0;
            }
            break;
        }
        case 2:   //Random Lowercase Letters
        {
            if (checkLower)
            {
                m = RandomLowercase();
                check2 = 0;
            }
            break;
        }
        case 3:   //Random Upper Letters
        {
            if (checkUpper)
            {
                m = RandomUpper();
                check2 = 0;
            }
            break;
        }
        case 4:   //Random Special Character
        {
            if (checkSpecialCharacter)
            {
                m = RandomSpecialCharacter();
                check2 = 0;
            }
            break;
        }
        default:
            break;
        }
    }
    return m;
}
