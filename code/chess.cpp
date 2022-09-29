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
		//создание белых пешек
	for (int count = 0; count < 8; count++)
	{
		for (int cnt = 0; cnt < 8; cnt++)
		{
			cell[count][cnt].xp = 150 + cnt * 100;
			cell[count][cnt].yp = 150 + count * 100;
		}
	}
	//задаём координаты каждой клетки на доске
	fi fig[32];

	for (int count = 0; count < 2; count++)
	{
		for (int cnt = 0; cnt < 8; cnt++)
		{
			cell[cnt][count].fn = count * 8 + cnt;
			fig[count * 8 + cnt].xx = cell[count][cnt].xp;
			fig[count * 8 + cnt].yy = cell[count][cnt].yp;
		}
	}
	//задаём координаты на доске для каждой чёрной фигуры
	for (int count = 6; count < 8; count++)
	{
		for (int cnt = 0; cnt < 8; cnt++)
		{
			cell[cnt][count].fn = (count - 4) * 8 + cnt;
			fig[(count - 4) * 8 + cnt].xx = cell[count][cnt].xp;
			fig[(count - 4) * 8 + cnt].yy = cell[count][cnt].yp;
		}
	}
	//задаём координаты на доске для каждой белой фигуры

	RenderWindow window(VideoMode(1920, 1080), "window");

	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text lit("", font, 40);
	lit.setFillColor(Color(132, 87, 74, 1500));//задём х-ки шрифта

	Text txt("", font, 40);
	txt.setFillColor(Color(132, 87, 74, 1500));//задём х-ки шрифта

	Texture texture;
	texture.loadFromFile("bk.png");
	Sprite bk(texture);

	Texture text;
	text.loadFromFile("wh.png");
	Sprite wh(text);


	Texture pawnbt;
	pawnbt.loadFromFile("pawnb.png");
	Sprite pawnb(pawnbt);

	Texture pawnwt;
	pawnwt.loadFromFile("pawnw.png");
	Sprite pawnw(pawnwt);

	Texture rookbt;
	rookbt.loadFromFile("rookb.png");
	Sprite rookb(rookbt);

	Texture rookwt;
	rookwt.loadFromFile("rookw.png");
	Sprite rookw(rookwt);

	Texture knightbt;
	knightbt.loadFromFile("knightb.png");
	Sprite knightb(knightbt);

	Texture knightwt;
	knightwt.loadFromFile("knightw.png");
	Sprite knightw(knightwt);

	Texture bishopwt;
	bishopwt.loadFromFile("bishopw.png");
	Sprite bishopw(bishopwt);

	Texture bishopbt;
	bishopbt.loadFromFile("bishopb.png");
	Sprite bishopb(bishopbt);

	Texture kingwt;
	kingwt.loadFromFile("kingw.png");
	Sprite kingw(kingwt);

	Texture kingbt;
	kingbt.loadFromFile("kingb.png");
	Sprite kingb(kingbt);

	Texture qeenwt;
	qeenwt.loadFromFile("qeenw.png");
	Sprite qeenw(qeenwt);

	Texture qeenbt;
	qeenbt.loadFromFile("qeenb.png");
	Sprite qeenb(qeenbt);

	//создаём спрайт для каждой фигуры

	char move[8];
	//строка для записи адреса хода

	int countM = 0;
	//счётчик символов в адресе хода
	int adr[4];
	//переменная для перевода символов в числовую форму адреса
	int ntb = 1;
	int nalf = 1;
	// флаги для проверки ввода
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::TextEntered)
			{
				nalf = 1;
				ntb = 1;
				fl_hod = 1;
				fl_ruls = 1;

				if (!((49 <= event.text.unicode && event.text.unicode <= 56) || (97 <= event.text.unicode && event.text.unicode <= 104)))
				{
					ntb = 0;
				}
				move[countM] = static_cast<char>(event.text.unicode);
				cout << "vvod " << countM + 1 << "  -  " << static_cast<char>(event.text.unicode) << endl;
				if (countM % 2 == 0)
				{
					adr[countM] = static_cast<int>(move[countM]) - 97;
				}
				if (countM % 2 == 1)
				{
					adr[countM] = static_cast<int>(move[countM]) - 49;
				}
				cout << adr[countM] << endl;
				countM++;
				//ввод адреса хода и его проврка на границы
				if (countM > 1 && cell[adr[0]][adr[1]].presence == 1)
				{
					if (hod != cell[adr[0]][adr[1]].colrFigure)
					{
						fl_hod = 0;
					}
				}
				//проверка на цвет ходящей фигуры
				if ((countM > 1) && ((cell[adr[0]][adr[1]].presence) == 0))
				{
					nalf = 0;
					adr[0] = 0; adr[1] = 0; adr[2] = 0; adr[3] = 0; countM = 0;
					cout << endl << "error" << endl;
					cout << endl << "!!!!!!!" << endl;
				}
				//проверка на наличие фигуры по адресу01
				else if (ntb == 0 || fl_hod == 0)
				{
					adr[0] = 0; adr[1] = 0; adr[2] = 0; adr[3] = 0; countM = 0;
					cout << endl << "error" << endl;
				}
				//обнуление после ввода неверного символа
				if (countM > 3)
				{
					fl_ruls = ruls(cell, adr[0], adr[1], adr[2], adr[3]);
				}
				if (fl_ruls == 0)
				{
					adr[0] = 0; adr[1] = 0; adr[2] = 0; adr[3] = 0; countM = 0;
					cout << endl << "error" << endl;
				}
				if (countM > 3 && ntb == 1 && fl_hod == 1 && fl_ruls == 1)
				{
					if (cell[adr[0]][adr[1]].colrFigure == 0)
					{
						fl_cut = cut(cell, adr[0], adr[1], adr[2], adr[3], cut_cntb, fig);
						if (fl_cut == 1)
						{
							cut_cntb++;
						}
					}
					else
					{
						fl_cut = cut(cell, adr[0], adr[1], adr[2], adr[3], cut_cntw, fig);
						if (fl_cut == 1)
						{
							cut_cntw++;
						}
					}
					if (fl_cut != 2)
					{
						if (cell[adr[2]][adr[3]].fn == 4)
						{
							winw = 1;
						}
						if (cell[adr[2]][adr[3]].fn == 28)
						{
							winb = 1;
						}
						if (hod == 1)hod = 0;
						else if (hod == 0)hod = 1;

						cell[adr[2]][adr[3]].presence = 1;
						cell[adr[2]][adr[3]].figure = cell[adr[0]][adr[1]].figure;
						cell[adr[2]][adr[3]].colrFigure = cell[adr[0]][adr[1]].colrFigure;

						cell[adr[0]][adr[1]].presence = 0;
						cell[adr[0]][adr[1]].figure = NOTHING;
						cell[adr[0]][adr[1]].colrFigure = 3;

						int num1 = cell[adr[0]][adr[1]].fn;
						fig[num1].xx = cell[adr[3]][adr[2]].xp;
						fig[num1].yy = cell[adr[3]][adr[2]].yp;

						cell[adr[2]][adr[3]].fn = cell[adr[0]][adr[1]].fn;
						cell[adr[0]][adr[1]].fn = 0;
					}
					countM = 0;

				}
			}
		}



		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (y % 2 == 0)
				{
					wh.setPosition(150 + (x * 200), 150 + (y * 100));
					window.draw(wh);
				}
				else
				{
					wh.setPosition(250 + (x * 200), 250 + ((y - 1) * 100));
					window.draw(wh);
				}
			}
		}
		//рисуем белые клетки
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (y % 2 == 1)
				{
					bk.setPosition(150 + (x * 200), 150 + (y * 100));
					window.draw(bk);
				}
				else
				{
					bk.setPosition(250 + (x * 200), 250 + ((y - 1) * 100));
					window.draw(bk);
				}
			}
		}
		//рисуем чёрные клетки
		for (int count = 0; count < 8; count++)
		{
			char chr[1];
			chr[0] = 65 + count;
			lit.setString(chr[0]);
			lit.setPosition(190 + count * 100, 50);
			window.draw(lit);
		}
		//рисуем буквы
		for (int count = 0; count < 8; count++)
		{
			char chr[1];
			chr[0] = 49 + count;
			lit.setString(chr[0]);
			lit.setPosition(50, 170 + count * 100);
			window.draw(lit);
		}
		//рисуем цифры

		for (int count = 8; count < 16; count++)
		{
			pawnb.setPosition(fig[count].xx, fig[count].yy);
			window.draw(pawnb);
		}

		for (int count = 16; count < 24; count++)
		{
			pawnw.setPosition(fig[count].xx, fig[count].yy);
			window.draw(pawnw);
		}

		rookb.setPosition(fig[0].xx, fig[0].yy);
		window.draw(rookb);

		rookb.setPosition(fig[7].xx, fig[7].yy);
		window.draw(rookb);


		rookw.setPosition(fig[31].xx, fig[31].yy);
		window.draw(rookw);

		rookw.setPosition(fig[24].xx, fig[24].yy);
		window.draw(rookw);


		knightb.setPosition(fig[1].xx, fig[1].yy);
		window.draw(knightb);

		knightb.setPosition(fig[6].xx, fig[6].yy);
		window.draw(knightb);


		knightw.setPosition(fig[25].xx, fig[25].yy);
		window.draw(knightw);

		knightw.setPosition(fig[30].xx, fig[30].yy);
		window.draw(knightw);


		bishopb.setPosition(fig[2].xx, fig[2].yy);
		window.draw(bishopb);

		bishopb.setPosition(fig[5].xx, fig[5].yy);
		window.draw(bishopb);


		bishopw.setPosition(fig[26].xx, fig[26].yy);
		window.draw(bishopw);

		bishopw.setPosition(fig[29].xx, fig[29].yy);
		window.draw(bishopw);


		kingw.setPosition(fig[28].xx, fig[28].yy);
		window.draw(kingw);


		kingb.setPosition(fig[4].xx, fig[4].yy);
		window.draw(kingb);



		qeenw.setPosition(fig[27].xx, fig[27].yy);
		window.draw(qeenw);


		qeenb.setPosition(fig[3].xx, fig[3].yy);
		window.draw(qeenb);

		if (ntb == 0)
		{
			txt.setString("нет такой буквы");
			txt.setPosition(1200, 540);
			window.draw(txt);
		}
		if (nalf == 0 && ntb == 1)
		{
			txt.setString("там пусто");
			txt.setPosition(1200, 540);
			window.draw(txt);
		}
		if (fl_cut == 2)
		{
			txt.setString("огонь по своим");
			txt.setPosition(1200, 540);
			window.draw(txt);
			fl_cut == 0;
		}
		if (winw == 1)
		{
			txt.setString("белые победили");
			txt.setPosition(1200, 540);
			window.draw(txt);
		}
		if (winb == 1)
		{
			txt.setString("чёрные победили");
			txt.setPosition(1200, 540);
			window.draw(txt);
		}
		if (fl_hod == 0 && hod == 1)
		{
			txt.setString("сейчас ход белых");
			txt.setPosition(1200, 540);
			window.draw(txt);
		}
		if (fl_hod == 0 && hod == 0)
		{
			txt.setString("сейчас ход чёрных");
			txt.setPosition(1200, 540);
			window.draw(txt);
		}
		if (fl_ruls == 0 && fl_cut != 2)
		{
			txt.setString("фигура так не ходит");
			txt.setPosition(1200, 540);
			window.draw(txt);
		}

		window.display();
		window.clear(Color(250, 200, 250, 0));

	}
	return 0;

}