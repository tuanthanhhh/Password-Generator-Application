#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

int GetRandom(int min, int max);
char RandomLowercase();
char RandomUpper();
char RamdomNumber();
char RandomSpecialCharacter();
char RandomTypeCharacter(int lengthPassWord, int numberOfCharacter, int checkNumber, int checkLower, int checkUpper, int checkSpecialCharacter);
struct RD;
