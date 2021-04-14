#include "header/lexer.hpp"
#include "header/utils.hpp"
#include <iostream>
#include <string>

Lexer::Lexer(std::string src)
{
    if (src.length() < 1)
    {
        exit(1);
    }
    Src = src;
    SrcSize = Src.length();
    Index = 0;
    CC = Src[Index];
}

void Lexer::Advance(int offset)
{
    if (Index < SrcSize)
    {
        Index += offset;
        CC = Src[Index];
    }
}

void Lexer::SkipWhiteSpace()
{
    while (isspace(CC))
    {
        Advance(1);
    }
}

char Lexer::Peek(int offset)
{
    return Src[(Index + offset < SrcSize) ? Index + offset : SrcSize - 1];
}

void Lexer::LexID()
{
    TokenValue.clear();
    while (isalpha(CC))
    {
        TokenValue.push_back(CC);
        Advance(1);
    }
    bool ExpectedID;
    for (size_t i = 0; i < sizeof(Identifiers) / sizeof(Identifiers[0]); i++)
    {
        if (TokenValue == Identifiers[i])
        {
            ExpectedID = true;
            break;
        }
    }
    if (!ExpectedID)
    {
        Log::Error(String::FormatString("Unexpected Identifire: %", TokenValue));
    }
    TokenKind = TOKEN_ID;
}

void Lexer::LexNumber()
{
    TokenValue.clear();
    while (isdigit(CC))
    {
        TokenValue.push_back(CC);
        Advance(1);
    }
    TokenKind = TOKEN_NUMBER;
}

void Lexer::NextToken()
{
    while (Index <= SrcSize)
    {
        SkipWhiteSpace();
        if (isalpha(CC))
        {
            LexID();
            return;
        }
        else if (isdigit(CC))
        {
            LexNumber();
            return;
        }
        switch (CC)
        {
        case '=':
            if (Peek(1) == '=')
            {
                TokenKind = TOKEN_EQUAL_TO;
                TokenValue = "==";
                Advance(2);
                return;
            }
            TokenKind = TOKEN_EQUAL;
            TokenValue = CC;
            Advance(1);
            return;
        case '+':
            if (Peek(1) == '=')
            {
                TokenKind = TOKEN_PLUS_EQUAL;
                TokenValue = "+=";
                Advance(2);
                return;
            }
            TokenKind = TOKEN_PLUS;
            TokenValue = CC;
            Advance(1);
            return;
        case '-':
            if (Peek(1) == '=')
            {
                TokenKind = TOKEN_MINUS_EQUAL;
                TokenValue = "-=";
                Advance(2);
                return;
            }
            TokenKind = TOKEN_MINUS;
            TokenValue = CC;
            Advance(1);
            return;
        case '>':
            if (Peek(1) == '=')
            {
                TokenKind = TOKEN_EQUAL_GREATER;
                TokenValue = ">=";
                Advance(2);
                return;
            }
            TokenKind = TOKEN_GREATER;
            TokenValue = CC;
            Advance(1);
            return;
        case '<':
            if (Peek(1) == '=')
            {
                TokenKind = TOKEN_EQUAL_LESSER;
                TokenValue = "<=";
                Advance(2);
                return;
            }
            TokenKind = TOKEN_LESSER;
            TokenValue = CC;
            Advance(1);
            return;
        case '(':
            TokenKind = TOKEN_OPEN_BRACKET;
            TokenValue = CC;
            Advance(1);
            return;
        case ')':
            TokenKind = TOKEN_CLOSE_BRACKET;
            TokenValue = CC;
            Advance(1);
            return;
        case '{':
            TokenKind = TOKEN_OPEN_BRAC;
            TokenValue = CC;
            Advance(1);
            return;
        case '}':
            TokenKind = TOKEN_CLOSE_BRAC;
            TokenValue = CC;
            Advance(1);
            return;
        case ',':
            TokenKind = TOKEN_COMMA;
            TokenValue = CC;
            Advance(1);
            return;
        case ':':
            TokenKind = TOKEN_SEMI;
            TokenValue = CC;
            Advance(1);
            return;
        case ';':
            TokenKind = TOKEN_SEMICOLON;
            TokenValue = CC;
            Advance(1);
            return;
        default:
            if (CC != '\0')
            {
                Log::Error(String::FormatChar("Unexpected Token: %", CC));
            }
            return;
        }
    }
    return;
}
