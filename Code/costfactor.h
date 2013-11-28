class costfactor
{	public:

	string make;
	int factor;

	costfactor()
	{
		make='\0';
		factor=0;
	}

	costfactor(string s, int fac)
	{
		make=s;
		factor=fac;

	}

};