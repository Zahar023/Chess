#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <windows.h>
#define B 0
#define W 1
using namespace std;
using namespace sf;
enum Figure
{
	NOTHING,
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QEEN,
	KING,
};