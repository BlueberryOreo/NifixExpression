#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <conio.h>
#include <map>

#ifndef ERROR_CODE
#define ERROR_CODE int
#endif

#ifndef OVERFLOW
#define OVERFLOW 0
#endif

#ifndef UNPAIR
#define UNPAIR -1
#endif

#ifndef UNDERFLOW
#define UNDERFLOW -2
#endif

#ifndef SUCCESS
#define SUCCESS 1
#endif

#ifndef SYNTAX_ERROR
#define SYNTAX_ERROR -3
#endif

#ifndef OPERATOR_ERROR
#define OPERATOR_ERROR -4
#endif

#ifndef MATH_ERROR
#define MATH_ERROR -5
#endif

using namespace std;

const int N = 1e3 + 10;
//const map<char, int> priority({
//	{'+', 2}, 
//	{'-', 3},
//	{'*', 4}, 
//	{'/', 5}, 
//	{'(', 1},
//	{')', 1},
//	{'#', 0},
//});