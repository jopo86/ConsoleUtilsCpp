#include "ConsoleUtils.h"

#ifdef OS_WINDOWS

    void ConsoleUtils::Clear()
    {
        system("CLS");
    }

    void ConsoleUtils::SetColor(int color)
    {
        if (currentColor == color) return;
        if (currentColor == NO_COLOR) ResetStyle();

        SetConsoleTextAttribute(hConsole, color);
        currentColor = color;
    }

    void ConsoleUtils::ResetStyle()
    {
        SetConsoleTextAttribute(hConsole, WHITE);
        currentColor = WHITE;
    }

#else

    void ConsoleUtils::Clear()
    {
        system("clear");
    }

    void ConsoleUtils::SetColor(int color)
    {
        if (currentColor == color) return;
        if (currentColor == NO_COLOR) ResetStyle();

        std::cout << "\033[" << color << "m";
        currentColor = color;
    }

    void ConsoleUtils::ResetStyle()
    {
        std::cout << "\033[0m";
        currentColor = NO_COLOR;
    }

#endif

int ConsoleUtils::GetColor()
{
    return currentColor;
}

void ConsoleUtils::SetItalic()
{
    std::cout << "\033[3m";
}

void ConsoleUtils::SetUnderline()
{
    std::cout << "\033[4m";
}
