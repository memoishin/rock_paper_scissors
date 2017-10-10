

# include <iostream>
# include <cstdlib>
# include <cmath>
# include <ctime>

using namespace std;

//Prototypes
char random4rps();
char readchoice();
void add2list(char element, char array[],int capacity,int& used);
void evaluatechoices(char userchoice, char pcchoice, int& tie,int& win, int& loss);
char selectRPS(int rocks,int papers ,int scissors);
char make_choice(char longlist[],int usedlong,char shortlist[],int usedshort);

int main()
{
     srand(time(0));
    
    char user_choice;
    char pc_choice = random4rps(); //Initial PC choice intialized to random
     
    const int LONG_SIZE = 100;
	char long_array[LONG_SIZE];
	int used_long = 0;

	const int SHORT_SIZE = 4;
	char short_array[SHORT_SIZE];
	int used_short = 0;
 
    int tie = 0, win = 0, loss = 0;

    cout << "--------------------------------------------\n";
    cout << "           Rock Paper Scissors              \n";
	cout << "--------------------------------------------\n";  
	cout << "\tPress [R] for Rock    \n";
	cout << "\tPress [P] for Paper   \n";
	cout << "\tPress [S] for Scissors\n";
	cout << "--------------------------------------------\n\n";
    
	user_choice = readchoice();    
    
    while (user_choice != 'Q') //Program Quits if user enters Q
    {
		//Calling Functions
    	evaluatechoices(user_choice, pc_choice, tie, win, loss);  
         
        add2list(user_choice, long_array, LONG_SIZE, used_long);
        
        add2list(user_choice, short_array, SHORT_SIZE, used_short);
         
        pc_choice = make_choice(long_array,used_long, short_array,used_short);
         
        user_choice = readchoice();
     
    }

     return 0;
}

//This function makes choice for the computer.
char make_choice(char longlist[],int usedlong,char shortlist[],int usedshort){
//DO NOT CHANGE THIS FUNCTION. Your task is to USE IT CORRECTLY.

    int rockcounter = 0;
    int papercounter = 0;
    int scissorscounter = 0;
     
    do{                
      
         for(int i = 1; i< (usedlong-usedshort+1);i++){
             bool match = true;
                          
             for(int j=0;j<usedshort;j++){            
                if(shortlist[j]!=longlist[i+j]){
                    match = false;                
                }           
            }//endfor
        
            if(match){
                if(longlist[i-1]=='R'){
                    rockcounter++;
                }
                else if(longlist[i-1]=='P'){
                    papercounter++;
                }
                else {
                    scissorscounter++;
                }
            }//endif
         }//endfor
         
         usedshort--;//Try with a shorter short list;
         
    }while(usedshort>0 &&  rockcounter == 0 &&  papercounter == 0 &&  scissorscounter == 0);
     
    char mychoice = selectRPS(rockcounter,papercounter,scissorscounter);

    return mychoice;
}

//This function makes a random choice for the computer.
char random4rps()
{
	const char LOWER_BOUND = 'P';
	const char UPPER_BOUND = 'S';
	
	char pcchoice = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
	
	while (pcchoice == 'Q')
	{
		pcchoice = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
	}
	
	return pcchoice;
}

//This function reads user choice and validates the input.
char readchoice()
{
	char userchoice;
	cout << "Make Your Choice. Enter [R, P or S]. Press [Q] to Quit : ";
	cin  >>userchoice;
	
	while(userchoice != 'R' && userchoice != 'P' && userchoice != 'S' && userchoice != 'Q')
	{
		cout <<"Invalid Entry : Ensure Upper Case : Enter [P,R,S or Q] : ";
		cin  >> userchoice;
	}
	return userchoice;
}

//This function evaluates user choice and pc choice, declares winner, and prints scores.
void evaluatechoices(char userchoice, char pcchoice, int& tie,int& win, int& loss)
{
	cout << "Computer Chose : "<<pcchoice <<endl;
	
	if (userchoice == pcchoice)
	{
		cout << "Game Tie\n";
		tie++;
	}
	else if ((userchoice == 'P' && pcchoice == 'R') || (userchoice == 'R' && pcchoice == 'S') || (userchoice == 'S' && pcchoice == 'P'))
	{
		cout << "You Win \n";
		loss++;
	}
	else
	{
		cout << "Computer Wins\n";
		win++;
	}
	
	cout << " -----------------\n";
	cout << "|PC SCORE   : " <<win <<" |\n";
	cout << "|USER SCORE : "<<loss <<" |\n";
	cout << "|TOTAL TIES : "<<tie  <<" |\n";
	cout << " -----------------\n\n";
	
}

//This function adds elements to the array
void add2list(char element, char array[],int capacity,int& used)
{
	for (int i = capacity - 1; i > 0; i--) 
	{
		array[i] = array[i-1];
	}
	array[0] = element;
	
 	if (used < capacity)
	{
		used++;
	}
}

//This function is used in the make choice function to make a choice for the computer.
char selectRPS(int rocks,int papers ,int scissors)
{
	char pcchoice;
	
	if (rocks == papers == scissors)
	{
		pcchoice = random4rps();
	}
	else if (rocks >= papers && rocks >= scissors)
	{
		pcchoice = 'P';
	}
	else if (papers >= rocks && papers >= scissors)
	{
		pcchoice = 'S';
	}
	else
	{
		pcchoice = 'R';
	}
	
	return pcchoice;
}
