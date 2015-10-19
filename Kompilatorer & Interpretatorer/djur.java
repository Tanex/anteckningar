public class Djur 
{ 
	public int vikt;
	public void läte() { }
}

public class Katt extends Djur
{
	public int antal_svansar;
}

public class Hund extends Djur
{
	public in antal_ben;
}

public class Cast
{
	public static void f(Djur djur)
	{
		Hund hund = (Hund)djur; //Dynamic cast
		hund.antal_ben = 2;
	}
}