#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

extern int typeCharacter;
extern int matrixCheckCharacter[1000];
int GetRandom(int min, int max);
char RandomLowercase();
char RandomUpper();
char RamdomNumber();
char RandomSpecialCharacter();
char RandomTypeCharacter(int lengthPassWord, int numberOfCharacter, int checkNumber, int checkLower, int checkUpper, int checkSpecialCharacter);


