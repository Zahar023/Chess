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
struct board
{
	int presence; //наличие фигуры на клетке
	Figure figure; //тип фигуры, если она есть
	int colorCell; //цвет клетки
	int colrFigure; //цвет фигуры
	int xp;
	int yp; //адресса по иксу и игреку
	int fn; //номер фигуры на клетке
};
struct fi
{
	int xx;
	int yy; //адресса для вывода спрайтов
};