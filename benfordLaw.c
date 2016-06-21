/* Name: Benford's Law Tester
   Author: Adam Douglas
   Purpose: To find percentile distribution of leading digits from a set of data
*/

#include<stdio.h>
#include<stdlib.h>

// Declares subprograms for formatting and prompting
void continuePrompt();
void dash();
void printTitle(char *title);

// Declares the subprogram for the splash screen and menu
void welcome();
void menu();

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
    // Pauses and prompts the user to continue
    printf("Press a key and enter to go to continue...");
    getchar();

    while(getchar() == '\n')
    {
        getchar();
    }
}

void dash()
{
    // Prints a line of dashes
    printf("-----------------------------------------------------------------");
    printf("--------------");
}

void printTitle(char *title)
{ 
    // Prints the title
    printf("%s\n", title);
}

void welcome()
{
    // Declares the phrase for string manipulation
    char *phrase = "Benford's Law Tester";
    
    printf("\n\n\n %s \n\n\n", phrase);

    continuePrompt();
}

void menu()
{
    int menuChoice;
     
    system("clear");
    printf("\n");
    printTitle("Main Menu");
    dash();
    printf("\n");
    
    // Print the menu options and get user input
    printf("Which set of data would you like to test?\n");
    printf("1 - Fibonacci Numbers\n");
    printf("2 - World Populations\n");
    printf("3 - World Areas\n");
    printf("4 - Cube Numbers\n");
    scanf("%d", &menuChoice);
    
    openFile(menuChoice);
}

void openFile(int menuChoice)
{
    FILE *file;
    float indexes = 0;
    float numberCount[9];
    //char *tempData = "Temp";
    char tempLead = '\n';
    
    for(int i = 0; i <= 8; i++)
    {
        numberCount[i] = 0;
    }

    switch(menuChoice)
    {
        case 1: file = fopen("fibonacci.txt", "r");
                indexes = 100;
        break;
        case 2: file = fopen("populations.txt", "r");
                indexes = 238;
        break;
        case 3: file = fopen("areas.txt", "r");
                indexes = 234;
        case 4: file = fopen("cubes.txt", "r");
                indexes = 1000;
        break;
        default: printf("Sorry, there was a problem with your input.");
        break;
    }
    
    for(int i = 0; i < indexes; i++)
    {
        while (tempLead != '\n' && tempLead != EOF) {
            tempLead = fgetc(file);
        }
        tempLead = fgetc(file);
        //data>>dataStore[i];
        //tempLead = tempData[0];
        
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
        printf("Distribution for %d is %f\n", i+1, distribution);
    }
}


