#include <iostream>
#include <fstream>
#include <unistd.h>
//#include <string>

/*
	By Mafius Kity
           __..--''``---....___   _..._    __
 /// //_.-'    .-/";  `        ``<._  ``.''_ `. / // /
///_.-' _..--.'_    \                    `( ) ) // //
/ (_..-' // (< _     ;_..__               ; `' / ///
 / // // //  `-._,_)' // / ``--...____..-' /// / //

 * */

using namespace std;

/*Invalid Test
 * Action: Perform a test for the nth primer number provided in command 
 * line for 0 and <0 cases return error
 * Entrance: Integer nth primer number provided in command line
 * Exit: Integer number, 1 for error and 0 for ok result
 * Assumptions: Position is integer, dumb
 * Algorithmic: Thisin't necessary!
 */
int invalid_test(int position){
	if(position<1){
		if(position==0){
			cout<<"Does not exist the 0nth number os any sequency!\n";
			return 1;
		}
		else{
			cout<<"Dosen't use negative numbers!\n";
			return 1;
		}
	}
	else{
		return 0;
	}
}

int main(int argc,char *argv[]){
	
	//Var declaration
	int nth, opt, a;
	int t=1, n=1, j=0, i=3, p, pt, r=1,l=1, nl;
	int* plist=new int[0];
	ofstream memo_write;
	int* mlist= new int[0];
	
	//Flags treatement
	while((opt=getopt(argc,argv,"hvn:t:rl:"))!=-1){
		/* 
		* h: Help
		* v: Version
		* l: plist of primer numbers 0=all
		* n: Search in file memory mode
		* t: n+default algoritm mode
		* r: reset file memory file
		*/
		switch(opt){
			case 'h':
				cout<<"\nUsage: Primer [[-option]] nth\n";
				cout<<"\t[[-option]]:\n";
				cout<<"\t\t-h\tShow this help\n";
				cout<<"\t\t-v\tShow the program version\n";
				cout<<"\t\t-n nth\tSearch the nth primer number in the f";
				cout<<"e memory\n";
				cout<<"\t\t-t nth\tPerform -n and if not found, run the ";
				cout<<"defaut algorithmic";
				cout<<"hmic\n";
				cout<<"\t\t-r\tReset memory file\n";
				cout<<"\t\t-l n\tPrint the list of n primer numbers in f";
				cout<<"ile memory (n=0 for all)\n";
				cout<<"\n---CAUTION!!!---\n";
				cout<<"\tUse only one flag to avoid bugs... because this";
				cout<<" version is unstable";
				cout<<"_________________________________________"<<endl;
				return 0;
			case 'v':
				cout<<"Version 1.0"<<endl;
				return 0;
			case 'n':
				nth=atoi(optarg);
				n=0;
				break;
			case 't':
				nth=atoi(optarg);
				t=0;
				break;
			case 'r':
				r=0;
				a=1;
				break;
			case 'l':
				l=0;
				nl=abs(atoi(optarg)); //Why i dont tink this before?
				break;
			case '?':
				cout<<"Try Primer -h"<<endl;
				return 2;
		}
	}
	 
	//No flag treatment
	if(n==1&&t==1&&l==1&&r==1){
		nth=atoi(argv[1]);
		if(invalid_test(nth)){
			return 3;
		}
		if(nth<3){
			if(nth==1){
				cout<<1<<endl;
				return 0;
			}
			else if(nth==2){
				cout<<2<<endl;
				return 0;
			}
		}
		plist=new int[nth-2]; //The case 1 and 2 was defined
		p=3;
	}
	
	//Standard check memory file
	ifstream memo_read;
	int pnumber=0;
	string line;
	
	memo_read.open("memory.primer");
	if(!memo_read.is_open()){
	cout<<"memory.primer as not found\n";
		return 4;
	}
	getline(memo_read,line);
	if(line=="\0"){
		cout<<"Error in memory.primer, restauring the file..."<<endl;
		r=0;
		l=1;
		n=1;
		t=1;
	}
	else {
		pt=stoi(line);
	}
	
	//File search mode 
	//And list mode
	if(n==0||t==0||l==0){
		if(invalid_test(nth)){ //In c++ 1=TRUE and 0=FALSE
			return 3;
		}
		
		//Readind memory file
		mlist= new int[pt];
		while(getline(memo_read,line)){
			mlist[pnumber]=stoi(line);
			pnumber++;
		}
		memo_read.close();
		
		//List print
		if(l==0){
			int in=0;
			
			nth=0;
			if(nl==0){
				nl=pt-1;
			}
			if(nl>=pt){
				cout<<"The list has in "<<pt-1<<"nth\n";
				return 7;
			}
			while(in<nl){
				cout<<mlist[in]<<endl;
				in++;
			}
		}
		
		//-n and -t flag
		if(nth<=pnumber&&l==1){
			cout<<mlist[nth-1]<<endl; /*The getline not reset the read of
			memory archive*/
			return 0;
		}
		if(n==0){ //-n flag
			cout<<"Not found in memory archive\n";
			return 5;
		}
		
		//-t not nth primer in memory file found
		i=mlist[pt-2]; /*-1 because vector initiate in 0, and -1 decause 
		pt is the length of vector of memory file, read alony in line 12
		* 9*/
		i+=2; //Resolve bug for the 4nth position repeat 3
		if(nth!=0){
			plist = new int[nth-pt+1]; /*The p cases has defined in memory file
			method 
			* +1 is necessary for evit bugs in 50, 110 and anothers nth's
			* Do not tink about this bug bro*/
			p=pt;
			a=1;
		}
	}
	
	if(memo_read.is_open()){
		memo_read.close();
	}
	
	//Algoritchmic mode and -r flag
		/*
		 * p is the actual position
		 * j is the vector counter
		 * i is the actual number
		 * k is the divisor
		 * nth is the target position
		 * plist is the vector of primers
		 */
	if(r==1&&l==1){ //This code has confuse
		int k;
	
		for(i;p<=nth;i+=2){
			k=3;
			while(i%k!=0){
				k+=2;
			}
			if(k==i){
				plist[j]=i;
				j++;
				p++;
			}
		}
		j--; //For no flag start memory.primer correctly
		cout<<plist[j]<<endl;
		a=1;
	}
	
	//Saving in the memory file
	if(nth>=pt||r==0){
		memo_write.open("memory.primer");
		if(!memo_write.is_open()){
			cout<<"Wrhite error in memo.primer file\n";
			return 6;
		}
	
		string wline;
		
		//-r flag redefine memory file
		if(a==1&&t==1){
			/* I tink i dosen't has good use the getopt flags
			* Whiwout flag saving*/
			memo_write<<j+4<<endl;
			memo_write<<1<<endl;
			memo_write<<2;
			if(r==0){
				memo_write<<"\n"<<3;
			}
			else{
				j++; //Solve bug in -n flag repeat 3 in 3 and4 nth
			}
		}
		//-t flag saving
		else if(t==0){
			memo_write<<to_string(nth+1);
			j++;
			for(i=0;i<pt-1;i++){ /* -1 Resolve the 0 in new line of the
				memory file*/
				wline="\n"+to_string(mlist[i]);
				memo_write<<wline;
			}
		}
		for(i=0;i<j;i++){
			wline="\n"+to_string(plist[i]);
			memo_write<<wline;
		}
		memo_write.close();
	}
	
	//Deleting vectors and pointers
	delete[] mlist;
	mlist=nullptr;
	delete[] plist;
	plist=nullptr;
	return 0;
}
