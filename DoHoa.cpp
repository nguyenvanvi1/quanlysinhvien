#include "DoHoa.h"
// Ham thay doi kich thuoc console.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Ham to mau.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Ham dich chuyen con tro sang vi tri x y.
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// Ham xoa man hinh.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Ham lay key ban phim
/* GetAsyncKeyState(VK_ESCAPE) => b?t s? ki?n phím Esc */ 

// Hàm t? vi?t
//void ToMau(int x, int y, char *a, int color) // x, y là t?a ð? con tr? c?n nh?y ð?n ð? vi?t, a là chu?i c?n truy?n vào, color là màu truy?n vào.
//{
//	gotoxy(x, y);
//	textcolor(color);
//	printf("%s", a);
//	textcolor(7);
//}
