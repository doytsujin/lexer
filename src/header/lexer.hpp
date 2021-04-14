#ifndef LEXER_H
#define LEXER_H
#include <string>

class Lexer
{
public:
    std::string Src;
    std::size_t SrcSize;
    char CC; // CC: current char
    unsigned int Index;
    enum token
    {
        TOKEN_ID,            // Identifires
        TOKEN_STRING,        // ""
        TOKEN_NUMBER,        // 0 - 9
        TOKEN_EQUAL,         // =
        TOKEN_PLUS,          // +
        TOKEN_MINUS,         // -
        TOKEN_GREATER,       // >
        TOKEN_LESSER,        // <
        TOKEN_EQUAL_TO,      // ==
        TOKEN_PLUS_EQUAL,    // +=
        TOKEN_MINUS_EQUAL,   // -=
        TOKEN_EQUAL_GREATER, // >=
        TOKEN_EQUAL_LESSER,  // <=
        TOKEN_OPEN_BRACKET,  // (
        TOKEN_CLOSE_BRACKET, // )
        TOKEN_OPEN_BRAC,     // {
        TOKEN_CLOSE_BRAC,    // }
        TOKEN_COMMA,         // ,
        TOKEN_SEMI,          // :
        TOKEN_SEMICOLON,     // ;
        TOKEN_EOF,           // End Of Line
    };
    std::string Identifiers[4] = {"public", "class", "void", "int"};
    token TokenKind;
    std::string TokenValue;
    Lexer(std::string Src);
    void Advance(int offset);
    void SkipWhiteSpace();
    void LexNumber();
    void LexID();
    void NextToken();
    char Peek(int offset);
};

#endif