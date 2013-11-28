class cars
{
public:
	string make;
	string model;
	int year;
	string color;
	int VID;
	int conc;

	cars()
	{ make='\0';
	  model='\0';
	  color='\0';
	  year=0;
	 VID=0;
	 conc=0;
	}

	int	concat(string make, string model)
		{
		int x;
		int e;
		string u;
		u=make+model;
		while (u[x] != '\0')    // While the string isn't at the end... 
		 { 
        e=e+(u[x]);    // Transform the char to int 
        x++; 
		} 

		return e;
	}



cars(string a, string b , string c, int d, int e)
	{
		make=a;
		model=b;
		color=c;
		year=d;
		VID=e;
		

		int x=0;
		int oo=0;
		string u;
		u=make+model;
		while (u[x] != '\0')    // While the string isn't at the end... 
		 { 
        oo=oo+(u[x]);    // Transform the char to int 
        x++; 
		} 

		conc=oo;

		

	

	}

};