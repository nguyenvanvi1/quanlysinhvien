#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>
#include "time.h"


// Ham thay doi kich thuoc console.
void resizeConsole(int width, int height);

// Ham to mau.
void textcolor(int x);

// Ham dich chuyen con tro sang vi tri x y.
void gotoxy(int x,int y);

// Ham xoa man hinh.
void XoaManHinh();

// Ham lay key ban phim
/* GetAsyncKeyState(VK_ESCAPE) => b?t s? ki?n phím Esc */ 

// Hàm tu viet.
void ToMau(int x, int y, char *a, int color);
