//module for definition of "moves" class. It will spit its contents into another binary file.

#include<iostream>
#include<fstream>
#include<string.h>	//do we really need this ?

using namespace std;

class moves
{
	char type[256],cat[256];
	int pp,pow,acc,contact,pok[151]; //contact=1 or 0, depending on whether the moves makes contact|"poke" the pokemon this move can be used by.
	public:
		moves()
		{
			strcpy(type,"NULL");
			strcpy(cat,"NULL");
			pp=pow=acc=contact=0;
			for(int i=0;i<151;i++)
			{
				pok[i]=0;
			}
		}
		int newmov();
		int writemov();
};

int main()
{
	//lol
	return 0;
}

int moves::newmov()		//since this will be an admin only section, we don't really need console prompts
{
	cin.getline(type,256);
	cin.getline(cat,256);
	cin>>pp>>pow>>acc>>contact;
	for(int i=0;i<151;i++)
	{
		cin>>pok[i];
		if(pok[i]==0 || pok[i]>151)
		{
			break;
		}
	}
	return 0;
}

int moves::writemov()
{
	fstream fout("moves.db",ios::binary|ios::out);
	fout.write((char *) this,sizeof(this));
	return 0;
}
