//=====================================SOKOBAN=====================================
//-------------------------Por: Jones Gabriel e Davi Mello-------------------------
//-----------------------------------05/07/2019------------------------------------
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
int main() {
	HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curin;
	GetConsoleCursorInfo(hando, &curin);
	curin.bVisible = false;
	SetConsoleCursorInfo(hando, &curin);
	//--varlist gameplay--
	int cx = 1, cy = 6, level, moves = 0;
	char key;
	//--varlist levels--
	bool lvl1beat = false, lvl2beat = false, lvl3beat = false;
	//========================================================LEVELS========================================================
	string lvl[16][16];
	string lvl1[16][16] = { " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ",
							" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "O", "O", "O", "O", " ", " ",
							" ", " ", " ", "O", "O", "O", "O", "O", "O", "O", "O", " ", " ", "O", " ", " ",
							" ", " ", " ", "O", " ", " ", " ", " ", " ", " ", " ", " ", " ", "O", " ", " ",
							" ", " ", " ", "O", " ", " ", "O", "O", "O", "O", " ", " ", " ", "O", " ", " ",
							" ", " ", " ", "O", "O", " ", "O", " ", " ", "O", "O", " ", "O", "O", " ", " ",
							" ", " ", " ", " ", "O", " ", "O", " ", " ", " ", "O", " ", "O", " ", " ", " ",
							" ", " ", " ", " ", "O", " ", "O", " ", " ", " ", "O", " ", "O", " ", " ", " ",
							" ", " ", " ", " ", "O", " ", "O", " ", " ", " ", "O", " ", "O", " ", " ", " ",
							" ", " ", "O", "O", "O", " ", "O", " ", " ", " ", "O", " ", "O", " ", " ", " ",
							" ", " ", "O", " ", "c", " ", "O", " ", " ", " ", "O", " ", "O", " ", " ", " ",
							" ", " ", "O", " ", "c", " ", "O", " ", " ", " ", "O", ".", "O", " ", " ", " ",
							" ", " ", "O", " ", " ", " ", "O", " ", " ", " ", "O", ".", "O", " ", " ", " ",
							" ", " ", "O", "O", "O", "O", "O", " ", " ", " ", "O", "O", "O", " ", " ", " ",
							" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ",
							" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", };
	string lvl2[16][16] = { " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ",
							" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ",
							" ", " ", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", " ", " ",
							" ", " ", "O", " ", ".", " ", " ", " ", " ", " ", " ", ".", " ", "O", " ", " ",
							" ", " ", "O", " ", "O", " ", "O", " ", " ", "O", " ", "O", " ", "O", " ", " ",
							" ", " ", "O", " ", "c", " ", " ", " ", " ", " ", " ", "c", " ", "O", " ", " ",
							" ", " ", "O", " ", "O", " ", "O", " ", " ", "O", " ", "O", " ", "O", " ", " ",
							" ", " ", "O", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "O", " ", " ",
							" ", " ", "O", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "O", " ", " ",
							" ", " ", "O", " ", "O", " ", "O", " ", " ", "O", " ", "O", " ", "O", " ", " ",
							" ", " ", "O", " ", "c", " ", " ", " ", " ", " ", " ", "c", " ", "O", " ", " ",
							" ", " ", "O", " ", "O", " ", "O", " ", " ", "O", " ", "O", " ", "O", " ", " ",
							" ", " ", "O", " ", ".", " ", " ", " ", " ", " ", " ", ".", " ", "O", " ", " ",
							" ", " ", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", " ", " ",
							" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ",
							" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", };
	string lvl3[16][16] = { " ", " ", "O", "O", "O", "O", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ",
							" ", " ", "O", " ", " ", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O",
							" ", " ", "O", " ", " ", " ", " ", "c", " ", " ", " ", "c", " ", "c", " ", "O",
							" ", " ", "O", " ", "c", "O", " ", "c", " ", "O", " ", " ", "c", " ", " ", "O",
							" ", " ", "O", " ", " ", "c", " ", "c", " ", " ", "O", " ", " ", " ", " ", "O",
							"O", "O", "O", " ", "c", "O", " ", "O", " ", " ", "O", "O", "O", "O", " ", "O",
							"O", " ", "O", "c", " ", "c", " ", "c", " ", " ", "O", "O", " ", " ", " ", "O",
							"O", " ", " ", " ", " ", "c", " ", "O", "c", "O", " ", " ", " ", "O", " ", "O",
							"O", " ", " ", " ", "c", " ", " ", " ", " ", "c", " ", "c", " ", "c", " ", "O",
							"O", "O", "O", "O", "O", " ", " ", "O", "O", "O", "O", "O", "O", "O", "O", "O",
							" ", " ", "O", " ", " ", " ", " ", " ", " ", "O", " ", " ", " ", " ", " ", " ",
							" ", " ", "O", " ", " ", " ", " ", " ", " ", "O", " ", " ", " ", " ", " ", " ",
							" ", " ", "O", ".", ".", ".", ".", ".", ".", "O", " ", " ", " ", " ", " ", " ",
							" ", " ", "O", ".", ".", ".", ".", ".", ".", "O", " ", " ", " ", " ", " ", " ",
							" ", " ", "O", ".", ".", ".", ".", ".", ".", "O", " ", " ", " ", " ", " ", " ",
							" ", " ", "O", "O", "O", "O", "O", "O", "O", "O", " ", " ", " ", " ", " ", " ", };
	//--varlist menu--
	short MenuSelect = 0, InMenu = 1;
	while (1) {
		//==========================================================MENU===========================================================
		while (InMenu != 0) {
			moves = 0;
			//---Título---
			SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
			SetConsoleCursorPosition(hando, { 7,3 });
			cout << "SOKOBAN";
			SetConsoleCursorPosition(hando, { 6,8 });
			cout << "  Jogar    \n      Instru" << char(135) << char(228) << "es   \n        Sair   \n\n\n\n\n\n\n\n\n Por: Jones Gabriel\n          e\n     Davi Mello";
			//---Controles e desenho do menu---
			switch (MenuSelect) {
			case 0: //---JOGAR ativo---
				SetConsoleCursorPosition(hando, { 6,8 });
				cout << ">";
				SetConsoleCursorPosition(hando, { 14,8 });
				cout << "<";
				key = _getch();
				if (key == 's') {
					MenuSelect++;
				}
			break;
			case 1: //---INSTRUÇÕES ativo---
				SetConsoleCursorPosition(hando, { 4,9 });
				cout << ">";
				SetConsoleCursorPosition(hando, { 17,9 });
				cout << "<";
				key = _getch();
				if (key == 's') {
					MenuSelect++;
				} else if (key == 'w') {
					MenuSelect--;
				}
			break;
			case 2: //---SAIR ativo---
				SetConsoleCursorPosition(hando, { 6, 10 });
				cout << ">";
				SetConsoleCursorPosition(hando, { 13,10 });
				cout << "<";
				key = _getch();
				if (key == 'w') {
					MenuSelect--;
				}
			break;
			}
			//---Usuário clicou em JOGAR (vai para o seletor de fases)---
			if (key == '\r' && MenuSelect == 0) {
				InMenu = 2;
				system("CLS");
			}
			//==================SELETOR DE FASES==================
			while (InMenu == 2) {
				//---Desenho do menu---
				SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
				SetConsoleCursorPosition(hando, { 2,3 });
				cout << "SELECIONE A FASE";
				SetConsoleCursorPosition(hando, { 4,7 });
				if (lvl1beat == true) {
					SetConsoleTextAttribute(hando, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
				cout << "  Level 1    \n";
				SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
				if (lvl2beat == true) {
					SetConsoleTextAttribute(hando, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
				cout << "      Level 2    \n";
				SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
				if (lvl3beat == true) {
					SetConsoleTextAttribute(hando, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				}
				cout << "      Level 3    \n\n";
				SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
				cout << "      Voltar    ";
				if (lvl1beat == true && lvl2beat == true && lvl3beat == true) {
					SetConsoleTextAttribute(hando, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					cout << "\n\n\n\n     Parab" << char(130) << "ns!\n\n    Voc" << char(136) << " venceu\n  todos os n" << char(161) << "veis!";
				}
				SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
				//---setinhas do seletor reduzido---
				if (MenuSelect != 3) {
					SetConsoleCursorPosition(hando, { 4, 7 + MenuSelect });
					cout << ">";
					SetConsoleCursorPosition(hando, { 14, 7 + MenuSelect });
					cout << "<";
				}
				//---Controles e desenho do menu---
				switch (MenuSelect) {
					//---LEVEL 1 ativo---
				case 0:
					key = _getch();
					if (key == 's') {
						MenuSelect++;
					} else if (key == '\r') {
						InMenu = 0;
						level = 1;
						//---transferência do level 1 para a matriz do level atual---
						for (int y = 0; y < 16; y++) {
							for (int x = 0; x < 16; x++) {
								lvl[y][x] = lvl1[y][x];
							}
						}
						//---ajustar posição inicial do personagem---
						cx = 3;
						cy = 10;
					}
					break;
					//---LEVEL 2 ativo---
				case 1:
					key = _getch();
					if (key == 's') {
						MenuSelect++;
					} else if (key == 'w') {
						MenuSelect--;
					} else if (key == '\r') {
						InMenu = 0;
						level = 2;
						//---transferência do level 2 para a matriz do level atual---
						for (int y = 0; y < 16; y++) {
							for (int x = 0; x < 16; x++) {
								lvl[y][x] = lvl2[y][x];
							}
						}
						//---ajustar posição inicial do personagem---
						cx = 7;
						cy = 7;
					}
				break;
					//---LEVEL 3 ativo---
				case 2:
					key = _getch();
					if (key == 's') {
						MenuSelect++;
					} else if (key == 'w') {
						MenuSelect--;
					} else if (key == '\r') {
						InMenu = 0;
						level = 3;
						//---transferência do level 3 para a matriz do level atual---
						for (int y = 0; y < 16; y++) {
							for (int x = 0; x < 16; x++) {
								lvl[y][x] = lvl3[y][x];
							}
						}
						//---ajustar posição inicial do personagem---
						cx = 1;
						cy = 6;
					}
				break;
					//---VOLTAR ativo---
				case 3:
					SetConsoleCursorPosition(hando, { 4,11 });
					cout << ">";
					SetConsoleCursorPosition(hando, { 13,11 });
					cout << "<";
					key = _getch();
					if (key == 'w') {
						MenuSelect--;
					} else if (key == '\r') {
						//---voltar para o menu---
						InMenu = 1;
						system("CLS");
						MenuSelect = 0;
					}
				break;
				}
			}
			//===============INSTRUÇÕES===============
			if (key == '\r' && MenuSelect == 1 && InMenu == 1) {
				system("CLS");
				SetConsoleCursorPosition(hando, { 1,3 });
				cout << "  Seu objetivo " << char(130) << "\nmovimentar as caixas \n at" << char(130) << " todas ocuparem \n o espa" << char(135) << "o demarcado \n    por pontos.\n\n";
				cout << "Controles = W,A,S,D;\n   Reiniciar = R;\n   Desistir = Q;\n\n\n     > Voltar <";
				key = _getch();
				while (key != '\r') {
					key = _getch();
				}
				system("CLS");
			}
			//===============SAIR===============
			if (key == '\r' && MenuSelect == 2 && InMenu == 1) {
				return 0;
			}
		}
		//========================================================MAP-BUILD========================================================
		SetConsoleCursorPosition(hando, { 0,3 });
		SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
		for (int mapy = 0; mapy < 16; mapy++) {
			cout << "  ";
			for (int mapx = 0; mapx < 16; mapx++) {
				if (mapx == cx && mapy == cy) {
					cout << "@";
				} else if (lvl[mapy][mapx] == "c") {
					 if ((level == 1 && lvl1[mapy][mapx] == ".") || (level == 2 && lvl2[mapy][mapx] == ".") || (level == 3 && lvl3[mapy][mapx] == ".")) {
						SetConsoleTextAttribute(hando, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					} else {
						SetConsoleTextAttribute(hando, FOREGROUND_RED);
					}
					cout << char(219);
					SetConsoleTextAttribute(hando, DEFAULT_PALETTE);
				} else if (lvl[mapy][mapx] == "O") {
					cout << char(219);
				} else if ((level == 1 && lvl1[mapy][mapx] == ".") || (level == 2 && lvl2[mapy][mapx] == ".") || (level == 3 && lvl3[mapy][mapx] == ".")) {
					cout << ".";
				} else {
					cout << " ";
				}
			}
			cout << "\n";
		}
		cout << "\nMovimentos: " << moves << "          ";
		//========================================================WINCHECK========================================================
		short boxcount = 0;
		for (int y = 0; y < 16; y++) {
			for (int x = 0; x < 16; x++) {
				if ((level == 1 && lvl1[y][x] == "." && lvl[y][x] != "c") || (level == 2 && lvl2[y][x] == "." && lvl[y][x] != "c") || (level == 3 && lvl3[y][x] == "." && lvl[y][x] != "c")) {
					boxcount++;
				}
			}
		}
		//---pausar e reiniciar---
		if (boxcount == 0) {
			Sleep(2000);
			switch (level) {
			case 1:
				lvl1beat = true;
			break;
			case 2:
				lvl2beat = true;
			break;
			case 3:
				lvl3beat = true;
			break;
			}
			system("CLS");
			SetConsoleCursorPosition(hando, { 0, 6 });
			cout << "Voc" << char(136) << " venceu a fase " << level << "\n com " << moves << " movimentos!\n\n    Clique ENTER\n    para retornar\n      ao menu.";
			while (key != '\r') {
				key = _getch();
			}
			system("CLS");
			InMenu = 1;
			MenuSelect = 0;
		}
		//========================================================MOVEMENT========================================================
		if (InMenu == 0) {
			key = _getch();
		}
		//------------------------------------left------------------------------------
		if (key == 'a' && lvl[cy][cx - 1] != "O") {
			cx--;
			moves++;
			//---movimentar caixa---
			if ((lvl[cy][cx] == "c" && lvl[cy][cx - 1] == " ") || (lvl[cy][cx] == "c" && lvl[cy][cx - 1] == ".")) {
				lvl[cy][cx] = lvl[cy][cx + 1];
				lvl[cy][cx - 1] = "c";
			}
			//---colisão-caixa-parede---
			if (lvl[cy][cx] == "c" && lvl[cy][cx - 1] != " ") {
				cx++;
				moves--;
			}
		}
		//------------------------------------right------------------------------------
		if (key == 'd' && lvl[cy][cx + 1] != "O") {
			cx++;
			moves++;
			//---movimentar caixa---
			if ((lvl[cy][cx] == "c" && lvl[cy][cx + 1] == " ") || (lvl[cy][cx] == "c" && lvl[cy][cx + 1] == ".")) {
				lvl[cy][cx] = " ";
				lvl[cy][cx + 1] = "c";
			}
			//---colisão caixa parede---
			if (lvl[cy][cx] == "c" && lvl[cy][cx + 1] != " ") {
				cx--;
				moves--;
			}
		}
		//------------------------------------up------------------------------------
		if (key == 'w' && lvl[cy - 1][cx] != "O") {
			cy--;
			moves++;
			//---moveimentar caixa---
			if ((lvl[cy][cx] == "c" && lvl[cy - 1][cx] == " ") || (lvl[cy][cx] == "c" && lvl[cy - 1][cx] == ".")) {
				lvl[cy][cx] = " ";
				lvl[cy - 1][cx] = "c";
			}
			//---colisão caixa parede---
			if (lvl[cy][cx] == "c" && lvl[cy - 1][cx] != " ") {
				cy++;
				moves--;
			}
		}
		//------------------------------------down------------------------------------
		if (key == 's' && lvl[cy + 1][cx] != "O") {
			cy++;
			moves++;
			//---movimentar caixa---
			if ((lvl[cy][cx] == "c" && lvl[cy + 1][cx] == " ") || (lvl[cy][cx] == "c" && lvl[cy + 1][cx] == ".")) {
				lvl[cy][cx] = " ";
				lvl[cy + 1][cx] = "c";
			}
			//---colisão caixa parede---
			if (lvl[cy][cx] == "c" && lvl[cy + 1][cx] != " ") {
				cy--;
				moves--;
			}
		}
		//---restart---
		if (key == 'r') {
			switch (level) {
			case 1:
				for (int y = 0; y < 16; y++) {
					for (int x = 0; x < 16; x++) {
						lvl[y][x] = lvl1[y][x];
					}
				}
				cx = 3;
				cy = 10;
			break;
			case 2:
				for (int y = 0; y < 16; y++) {
					for (int x = 0; x < 16; x++) {
						lvl[y][x] = lvl2[y][x];
					}
				}
				cx = 7;
				cy = 7;
			break;
			case 3:
				for (int y = 0; y < 16; y++) {
					for (int x = 0; x < 16; x++) {
						lvl[y][x] = lvl3[y][x];
					}
				}
				cx = 1;
				cy = 6;
			break;
			}
			moves = 0;
		}
		if (key == 'q') {
			system("CLS");
			InMenu = 1;
			MenuSelect = 0;
		}
		SetConsoleCursorPosition(hando, { 2, 3 });
	}
}
