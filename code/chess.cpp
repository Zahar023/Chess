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
int main()
{
	int fl_cut = 0; //флаг на сруб
	int cut_cntb = 0; //счётчик срубленых чёрных фигур
	int cut_cntw = 0; //счётчик срубленых белых фигур
	int winw = 0;//победа белых
	int winb = 0;// победа чёрных
	int hod = 1;
	int fl_hod = 1;
	int fl_ruls = 1;

	board cell[8][8];
	for (int count = 0; count < 8; count++)
	{
		for (int cnt = 0; cnt < 8; cnt++)
		{
			if ((cnt + count) % 2 == 1)
				cell[cnt][count] = { 0,NOTHING,0,NULL };
			else
				cell[cnt][count] = { 0,NOTHING,1,NULL };
		}
	}
	//задаём наличие фигур на поле, цвет клеток и цвет фигур
	for (int count = 0; count < 8; count += 7)
	{
		for (int cnt = 0; cnt < 4; cnt++)
		{
			cell[cnt][count].figure = static_cast <Figure> (cnt + 2);
		}
	}
	for (int count = 0; count < 8; count += 7)
	{
		for (int cnt = 0; cnt < 4; cnt++)
		{
			cell[7 - cnt][count].figure = static_cast <Figure> (cnt + 2);
		}
	}
	cell[4][0].figure = KING;
	cell[4][7].figure = KING;
	//задаём начальное положение вида фигур на поле
	for (int count = 0; count < 8; count += 7)
	{
		for (int cnt = 0; cnt < 8; cnt++)
		{
			cell[cnt][count].presence = 1;
			if (count == 7)
			{
				cell[cnt][count].colrFigure = 1;
			}
		}
	}
	for (int count = 2; count < 6; count++)
	{
		for (int cnt = 0; cnt < 8; cnt++)
		{
			cell[cnt][count].colrFigure = 3;
		}
	}
	//задём цвет всех фигур
	for (int count = 1; count < 8; count += 5)
	{
		for (int cnt = 0; cnt < 8; cnt++)
		{
			cell[cnt][count].presence = 1;
		}
	}
	//прописываем характеристики для пустых клеток

	for (int count = 0; count < 8; count++)
	{
		cell[count][1].presence = 1;
		cell[count][1].colrFigure = 0;
		cell[count][1].figure = PAWN;
	}
	//создание чёрных пешек
	for (int count = 0; count < 8; count++)
	{
		cell[count][6].presence = 1;
		cell[count][6].colrFigure = 1;