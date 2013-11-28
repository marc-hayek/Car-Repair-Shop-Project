#include<iostream>
using namespace std;
#include<cmath>
#include<fstream>
#include<string>

#include "customersclass.h"
#include "carsclass.h"
#include "servicesclass.h"
#include "bstandcust.h"
#include "carbst.h"
#include "compareclasses.h"
#include "listlinkstack.h"
#include "requestrecord.h"
#include "costfactor.h"
#include "mostclass.h"

void addmake(string s, most a[])
{
	for(int m=0;m<15;m++)
		if(s==a[m].make)
		{a[m].nummake++;
	
	break;}
}

void addserve(string s, int num ,most a[])
{
	for(int m=0;m<15;m++)
		if(s==a[m].make)
		{a[m].numserve=a[m].numserve+num;
		break;
		}
}

int mostmake(most a[])
{
	int max=0;
	int index=0;
	max=a[0].nummake;
	for(int m=1;m<15;m++)
	{if(a[m].nummake>max)
		{max=a[m].nummake;
		 index=m;}
	}
	//cout<<a[index].numserve;
	//return a[index].make;
	return index;
	
}

int mostserved(most a[])
{
	int max=0;
	int index=0;
	max=a[0].numserve;
	for(int m=1;m<15;m++)
	{if(a[m].numserve>max)
	{max=a[m].numserve;
		 index=m;}
	}

	//return a[index].make;
	return index;
}


void main()
{
cout<<endl<<endl;
cout<<"   -------------------------------------------------------------------------"<<endl;
cout<<"   | *           * ******* *          * **     ****    *         * ******* |"<<endl;
cout<<"   |  *         *  *       *        *        *      *  *  *   *  * *       |"<<endl; 
cout<<"   |   *   *   *   *****   *        *        *      *  *    *    * *****   |"<<endl;
cout<<"   |    * * * *    *       *        *        *      *  *         * *       |"<<endl; 
cout<<"   |     *   *     ******* *******    * **     ****    *         * ******* |"<<endl;
cout<<"   -------------------------------------------------------------------------"<<endl;


	BST<string,customers,LastnamescustomCompare,LastnameCompare> custtree;
	carBST<int,cars,conccarsCompare,concCompare> cctree;
	LList<services> servicelist;
	LStack<request> stack;
	const int maxsize=15;
	costfactor fac[maxsize];
	most info[maxsize];
	
	
	

	ifstream inTemp;
	string s,u,i,o;
	int w=0;
	int y=0;
	int revenue=0;

	 if(inTemp==0)
			cout<<"Error opening customers.txt file\n";
	 else
	 {inTemp.open("customers.txt",ios::in);

	 while(!inTemp.eof())
	 //while(w!=42)
	 {
			
			
			inTemp>>u;
			inTemp>>i;
			inTemp>>o;
			inTemp>>w;
			customers a(u,i,o,w);
			custtree.insert(a);
	 }

	 }
	 inTemp.close();


	 inTemp.clear();

	 //custtree.print();

if(inTemp==0)
			cout<<"Error opening cars.txt file\n";
	 else
	 {
		 inTemp.open("cars.txt",ios::in);
			
			
		 
		 while(!inTemp.eof())
	// while(y!=81)
	 {
		 
			inTemp>>u;
			inTemp>>i;
			inTemp>>w;
			inTemp>>o;
			inTemp>>y;

			
			cars a(u,i,o,w,y);
			cctree.insert(a);
			
			
	
	 }

	 }
	 inTemp.close();
	  inTemp.clear();
	
	//cctree.print();
	


	y=0;
	string comb;
	string baba;
	string comb2;
	string comb3;

if(inTemp==0)
			cout<<"Error opening services.txt file\n";
	 else
	 {inTemp.open("services.txt",ios::in);
	//	getline(inTemp,baba);
	//	cout<<baba;
	 
	 while(y!=13)
	 {		if(y==3||y==4||y==9||y==10||y==12)
	 {	inTemp>>comb;
		inTemp>>comb2;
		inTemp>>comb3;
		u=comb+" "+comb2+" "+comb3;
		inTemp>>w;
			inTemp>>y;
			services a(y,u,w);
			servicelist.insert(a);

	 }
	 else{	inTemp>>comb;
		inTemp>>comb2;
		u=comb+" "+comb2;
		inTemp>>w;
			inTemp>>y;
			services a(y,u,w);
			servicelist.insert(a);
	 }
	
	 }

	 }
	 inTemp.close();


	 if(inTemp==0)
			cout<<"Error opening costfactor.txt file\n";
	 else
	 {inTemp.open("costfactor.txt",ios::in);
	 
	for(int m=0;m<maxsize;m++)
	 {
			inTemp>>u;
			inTemp>>w;
			costfactor a(u,w);
			fac[m]=a;
	 }

	 }
	 inTemp.close();

	 if(inTemp==0)
			cout<<"Error opening most.txt file\n";
	 else
	 {inTemp.open("most.txt",ios::in);
	 
	for(int m=0;m<maxsize;m++)
	 {
			inTemp>>u;
			most a(u);
			info[m]=a;
			
			
	 }

	 }
	 inTemp.close();


	 





	 int cid;
	 int vid;
	 int drop;
	 int numb;
	 int setser;

	cout<<"\t\t\t     |         To         |"<<endl;
	cout<<"\t\t\t     |*Karage Car Service*|"<<endl;
		cout<<"\t\t\t     |--------------------|"<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t Customer and Service Information"<<endl;
			cout<<"\t\t\t --------------------------------"<<endl<<endl<<endl<<endl;
		 if(inTemp==0)
			cout<<"Error opening requests.txt file\n";
	 else
	 {inTemp.open("requests.txt",ios::in);
	 	
		 while(!inTemp.eof())
	 //for(int m=0;m<10;m++)

	 {
			inTemp>>cid;
			inTemp>>vid;
			
			inTemp>>numb;
			request b(cid,vid,numb,0);
			b.setservice();
	
			for(int i=0;i<numb;i++)
			{
				inTemp>>setser;
				b.SID[i]=setser;


			}
			inTemp>>drop;
			b.dropoff=drop;
	
			stack.push(b);}
	
		 }

	 inTemp.close();
	 	 

	request req;
	 customers one;
	 cars two;
	 services serve;
	
	 while(!stack.empty()){
	 stack.pop(req);

	 custtree.findid(req.CID,one);
	 cout<<"First Name: "<<one.firstname<<"\tLast Name: "<<one.lastname<<endl;
	 cout<<"Adress: "<<one.adress<<endl;
	 cctree.findid(req.VID,two);
	 cout<<two.make<<"\t"<<two.model<<"\t"<<two.year<<"\t"<<two.color<<endl;
	 addmake(two.make,info);
	 addserve(two.make,req.renum,info);

	 

	 int fact;
	 int cost=0;

	 for(int j=0;j<req.renum;j++)
	 {	
		servicelist.search(req.SID[j],serve);
		cout<<j+1<<"."<<serve.service<<"  ";
		for(int g=0;g<15;g++)
		{
			if(two.make==fac[g].make)
			{fact=fac[g].factor;
			break;}

		}
		
		//cost=cost+(servicelist.costreturn(req.SID[j])*fact);
		cost=cost+(serve.cost*fact);
		

	 }

	 revenue=revenue+cost;

	 cout<<"\nCost of repairs: "<<cost<<" L.L";
	
	 cout<<"\n\n-----------------------"<<endl<<endl;

	 


	 }
	
	
	 int mstmake=mostmake(info);
	 int mstserve=mostserved(info);

	 //cout<<"\nCar make that is repaired the most: "<<info[mstmake].make
		// <<" "<<info[mstmake].nummake<<endl;
	 //cout<<"\nCar make that got the highest average number of service requests: "
		//	<<info[mstserve].make
		//	<<" "<<info[mstserve].numserve<<endl;
	 //cout<<"\nTotal Revenue: "<<revenue<<" L.L"<<endl<<endl;

	
		 cout<<"\t\t\t General Information"<<endl;
		 cout<<"\t\t\t -------------------"<<endl<<endl;

		 cout<<"1.Car make that is repaired the most"<<endl;
		 cout<<"2.Car make that got the highest average number of service requests"<<endl;
		 cout<<"3.Total Revenue"<<endl;
			 
	 int inf;
	 cin>>inf;
	 //while(!cin.eof())
	while(inf!=0)
	 {
		
		

		 if(inf==1)
		 {
			 cout<<"\n-Car make that is repaired the most: "<<info[mstmake].make<<","
			 <<" "<<"Repaired "<<info[mstmake].nummake<<" times"<<endl<<endl;

		 }

		 else if(inf==2)
		 {
			cout<<"\n-Car make that got the highest average number of service requests:"<<endl;
			cout<<" "<<info[mstserve].make<<", "
			<<info[mstserve].numserve<<" services"<<endl<<endl;
		 }

		 else if(inf==3)
		 {
			 cout<<"\n-Total Revenue: "<<revenue<<" L.L"<<endl<<endl;

		 }

		
		 cout<<"-Please choose another option or type in \" 0 \" to exit the program: ";
		 cin>>inf;


		 




	 }


cout<<endl<<endl;
cout<<"\t\t\t   |------------|"<<endl;
cout<<"\t\t\t   |*Thank You!*|"<<endl;
		cout<<"\t\t\t   |------------|"<<endl<<endl;




}