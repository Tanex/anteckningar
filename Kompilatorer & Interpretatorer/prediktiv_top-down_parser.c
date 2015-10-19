int lookahead;
extern int scan(); //extern scanner som returnerar nästa token

void match(int expected)
{
	if ( lookahead != expected)
		error("Syntax error!");
	lookahead = scan();
}

void simple()
{
	if (lookahead == integer)
		match(integer);
	else if (lookahead == char)
		match(char);
	else if (lookahead == num)
	{
		match(num);
		match(dotdot);
		match(num);
	}
	else
		error("Syntax error!");
}

void type()
{
	if (lookahead == integer || lookahead == char || lookahead == num)
		simple();
	else if (lookahead == array)
	{
		match(array);
		match([);
		simple();
		match(]);
		match(of);
		type();
	}
	else if (lookahead == ^)
	{
		match(^);
		match(id);
	}
	else 
		error("Syntax error. Not a data type!");
}

void sats()
{
	if (lookahead == begin)
	{
		match(begin);
		opt_satslista();
		match(end);
	}
	else
		error("Syntax error!");
}

void opt_satslista()
{
	if (lookahead == if || lookahead == while || lookahead == ...)
		satslista();
	else
		/*empty*/;
}

void expr()
{
	if (lookahead == id || lookahead == num)
	{
		expr();
		match(+);
		term();	
	}

	else
		error("Syntax error!");
}

void parse()
{
	lookahead = scan();
	type();
}