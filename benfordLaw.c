/* Name: Benford's Law Tester
   Author: Adam Douglas
   Purpose: To find percentile distribution of leading digits from a set of data
*/

#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void continuePrompt();
void dash();
void printTitle(string title);
// Declares subprograms for formatting and prompting

void welcome();
void menu();
// Declares the subprogram for the splash screen and menu

void openFile(int menuChoice);
void calculateDistribution(float numberCount[], float indexes);

int main()
{
    welcome();
    menu();    
    continuePrompt();
}
    
void continuePrompt()
{
    system("pause");
    // Pauses and prompts the user to continue
}

void dash()
{
    cout<<"-------------------------------------------------------------------";
    cout<<"------------"<<endl;
    // Prints a line of dashes
}

void printTitle(string title)
{ 
    cout<<setw((79-title.length())/2)<<' '<<title<<endl;
    // Takes the length of the screen and the title and centers it
}

void welcome()
{
    string phrase = "Benford's Law Tester";
    // Declares the phrase for string manipulation
    
    for(int i = 0; i < 2; i++)
        cout<<"\n";
    
    for(int i = 0; i < phrase.length(); i++)
        cout<<setw(29+i)<<" "<<phrase[i]<<endl;
    // Prints the title across the screen
        
    for(int i = 0; i < 2; i++)
        cout<<"\n";
        
    continuePrompt();
}

void menu()
{
    int menuChoice;
     
    system("cls");
    cout<<"\n";
    printTitle("Main Menu");
    dash();
    cout<<"\n";
    
    cout<<"Which set of data would you like to test?"<<endl;
    cout<<"\n";
    cout<<"1 - Fibonacci Numbers"<<endl;
    cout<<"2 - World Populations"<<endl;
    cout<<"3 - World Areas"<<endl;
    cout<<"4 - Cube Numbers"<<endl;
    cout<<"\n";
    cin>>menuChoice;
    
    openFile(menuChoice);
}

void openFile(int menuChoice)
{
    ifstream data;
    float indexes, numberCount[9];
    string tempData;
    char tempLead;
    int tempIndexes;
    
    for(int i = 0; i <= 8; i++)
        numberCount[i] = 0;
    
    switch(menuChoice)
    {
        case 1: data.open("fibonacci.txt", ios::in);
                indexes = 100;
        break;
        case 2: data.open("populations.txt", ios::in);
                indexes = 238;
        break;
        case 3: data.open("areas.txt", ios::in);
                indexes = 234;
        case 4: data.open("cubes.txt", ios::in);
                indexes = 1000;
        break;
        default: cout<<"Sorry, there was a problem with your input."<<endl;
        break;
    }
    
    tempIndexes = indexes;
    string dataStore[tempIndexes];
    
    for(int i = 1; i <= indexes; i++)
    {
        data>>dataStore[i-1];
        tempData = dataStore[i-1];
        tempLead = tempData[0];
        
        switch(tempLead)
        {
            case '1': numberCount[0]++;  break;
            case '2': numberCount[1]++;  break;
            case '3': numberCount[2]++;  break;
            case '4': numberCount[3]++;  break;
            case '5': numberCount[4]++;  break;
            case '6': numberCount[5]++;  break;
            case '7': numberCount[6]++;  break;
            case '8': numberCount[7]++;  break;
            case '9': numberCount[8]++;  break;
        }
    }

    calculateDistribution(numberCount, indexes);
} 
    
void calculateDistribution(float numberCount[], float indexes)
{     
    float distribution;
    for(int i = 0; i <= 8; i++)
    {
        distribution = (numberCount[i]/indexes)*100;
        cout<<"Distribution for "<<i+1<<" is "<<distribution<<"%"<<endl;       
    }
}


