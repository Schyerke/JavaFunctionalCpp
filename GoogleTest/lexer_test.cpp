#include "lexer_test.hpp"

LexerTest::LexerTest()
{
	
}

void LexerTest::setUp(std::string program)
{
	lexer = Lexer(program);
}

SyntaxToken LexerTest::lex()
{
	return lexer.lex();
}

char LexerTest::current()
{
	return lexer.current();
}

char LexerTest::peekNext()
{
	return lexer.peekNext();
}

char LexerTest::lookAhead(int offset)
{
	return lexer.lookAhead(offset);
}

int LexerTest::advance()
{
	lexer.advance();
	return lexer.index;
}

int LexerTest::get_current_index()
{
	return lexer.index;
}


