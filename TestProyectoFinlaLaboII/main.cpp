#include <iostream>
#include "appManager.h"
#include "windows.h"

using namespace std;

void resizeTerminal(int width, int height) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT r;
    COORD c;

    r.Left = 0;
    r.Top = 0;
    r.Right = width - 1;
    r.Bottom = height - 1;
    c.X = width;
    c.Y = height;

    SetConsoleWindowInfo(hOut, TRUE, &r);
    SetConsoleScreenBufferSize(hOut, c);
}

int main()
{   AppManager app;
    resizeTerminal(120,30);
    app.login();

    return 0;
}
