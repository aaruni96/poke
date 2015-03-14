//code to add pokemon to whatever database

//this module seems to be working just fine, for now.
//things to do : enable multiple records in file (so, ios::append).

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class pokemon
{
	char name[256], nick[256],species[256],blurb[4096];	//that ought to be 'nuff for poke names | blurb is the pokedex info
	int num,permastat[6],batstat[2];
	float ht,wt;
/*	move attack[4];	//move will be another class with all the attack stats. I'm beginning to see complications from this stage itself.
	forget about move for now. this module basically tests binary reading and writing. will re-enable "move" during final compilation
*/
	public:
		pokemon()
		{
			num=0;ht=wt=0;
			for(int i=0;i<6;i++)
			{
				permastat[i]=0;
			}
			for(int i=0;i<2;i++)
			{
				batstat[i]=100;
			}
			strcpy(name,"GLITCH");
			strcpy(nick,"GLITCH");
			strcpy(species,"UNDEF");
			strcpy(blurb,"Lorem ipsum dolores");
			//something for move too?
		}
		int add();
		int pwrite();
		int pread();
		int print();
};

int main()
{
	pokemon p1;
	p1.add();
	p1.pwrite();
	p1.pread();
	p1.print();
}

int pokemon::add()
{
	cout<<"Name\t";cin.getline(name,256);
	cout<<"Nick\t";cin.getline(nick,256);
	cout<<"Species\t";cin.getline(species,256);
	cout<<"Blurb\t";cin.getline(blurb,4096);
	cout<<"num\t";cin>>num;
	cout<<"Stats\t";
	for(int i=0;i<6;i++)
	{
		cin>>permastat[i];
	}
	cout<<"Height, weight\n";
	cin>>ht>>wt;
	return 0;
}

int pokemon::pwrite()
{
	ofstream fout("pokemon.db",ios::binary);
	fout.write((char *) this, sizeof(pokemon));
	return 0;
}

int pokemon::pread()
{
	ifstream fin("pokemon.db",ios::binary);
	fin.read((char*) this, sizeof(pokemon));
	return 0;
}

int pokemon::print()
{
	cout<<name<<endl<<nick<<endl<<species<<endl<<blurb<<endl<<num<<endl;
	for(int i=0;i<6;i++)
	{
		cout<<permastat[i]<<endl;
	}
	cout<<ht<<endl<<wt<<endl;
	return 0;
}
