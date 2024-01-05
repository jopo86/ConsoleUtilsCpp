#include "../src/ConsoleUtils.h"

int main()
{
    ConsoleUtils::Clear();
    ConsoleUtils::SetColor(ConsoleUtils::RED);
    std::cout << "Hello, world!" << std::endl;
    ConsoleUtils::ResetStyle();
    return 0;
}
