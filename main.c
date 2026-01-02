#include "ui.h"
#include "user.h"
#include "game.h"

/* ===== MAIN MENU ===== */
int mainMenu(){
    int choice;
    while(1){
        cls();
        header("S N A K E   G A M E");

        centerText("1) Login", GREEN);
        centerText("2) Sign Up", CYAN);
        centerText("3) Exit", RED);
        emptyLine();
        line();
        printf(YELLOW "\n   Choose: " RESET);
        scanf("%d",&choice);

        if(choice==1) return 1;
        if(choice==2) return 2;
        if(choice==3) return 0;

        cls();
        header("Invalid Choice!");
        centerText("Please choose 1, 2 or 3", RED);
        line();
        pressEnter();
    }
}

/* ===== SCOREBOARD FOR MAP ===== */
void scoreMenu(int mapNumber, const char* currentUser){
    int yourBest = 0;
    int globalBest = 0;
    char globalName[50] = "---";
    yourBest = getUserBestScore(currentUser, mapNumber);
    getGlobalBestScore(mapNumber, &globalBest, globalName);

    char title[80];
    sprintf(title, "S C O R E  (M A P  %d)", mapNumber);

    cls();
    header(title);

    char line1[120];
    char line2[120];

    sprintf(line1, "Your Best Score: %d", yourBest);
    sprintf(line2, "Global Best: %d by %s", globalBest, globalName);

    centerText(line1, GREEN);
    centerText(line2, CYAN);

    emptyLine();
    centerText("Press Enter to return", YELLOW);
    line();
    pressEnter();
}

/* ===== MAP MENU ===== */
void mapMenu(int mapNumber,char* currentUser){
    int choice;
    char title[60];

    while(1){
        cls();
        sprintf(title,"M A P  %d  M E N U",mapNumber);
        header(title);

        centerText("1) Start Game", GREEN);
        centerText("2) Scoreboard", PURPLE);
        centerText("3) Back", RED);

        emptyLine();
        line();

        printf(YELLOW "\n   User: %s\n" RESET,currentUser);
        printf(YELLOW "   Choose: " RESET);
        scanf("%d",&choice);

        if(choice==1){

            startGame(mapNumber, currentUser);
        }
        else if(choice==2){
            scoreMenu(mapNumber, currentUser);
        }
        else if(choice==3){
            return;
        }
        else{
            cls();
            header("Invalid Choice!");
            centerText("Choose 1, 2 or 3", RED);
            line();
            pressEnter();
        }
    }
}

/* ===== MAP SELECT ===== */
void mapSelectMenu(char* currentUser){
    int choice;
    while(1){
        cls();
        header("M A P   S E L E C T");

        centerText("1) Map 1", GREEN);
        centerText("2) Map 2", CYAN);
        centerText("3) Logout", RED);

        emptyLine();
        line();

        printf(YELLOW "\n   Choose: " RESET);
        scanf("%d",&choice);

        if(choice==1) mapMenu(1,currentUser);
        else if(choice==2) mapMenu(2,currentUser);
        else if(choice==3) return;
        else{
            cls();
            header("Invalid Choice!");
            centerText("Please choose 1, 2 or 3", RED);
            line();
            pressEnter();
        }
    }
}

int main(){
    system("color 0A");

    char currentUser[50]="";

    while(1){
        int c = mainMenu();
        if(c==0) break;

        if(c==1){
            if(loginPage(currentUser))
                mapSelectMenu(currentUser);
        }
        if(c==2){
            if(signupPage(currentUser))
                mapSelectMenu(currentUser);
        }
    }

    cls();
    header("Goodbye!");
    centerText("Thanks for playing!", GREEN);
    line();
    printf("\n");
    return 0;
}

