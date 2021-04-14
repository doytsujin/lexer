#include <iostream>
#include "header/lexer.hpp"
#include "header/utils.hpp"

int main()
{
    std::string ss = "void str == +=/";
    Lexer l(ss);
    while (l.Index < l.SrcSize)
    {
        l.NextToken();
        std::cout << l.TokenKind << " : " << l.TokenValue << std::endl;
    }
    return 0;
}