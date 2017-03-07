/**
* Author: BOGDAN MACOVEI
* Started at: 3rd of December
*
* Informations:
*   Represent the menus for this project
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

enum
{
    MANAGE              = 1,    FUNCTION, EXIT,
    MDOMAIN             = 11,   MRESEARCHER, MPUBLICATION, MCONFERENCE, MAWARD, MRECRUITMENT, MEXIT,
    FACTIVRES           = 21,   FPUBLEADERS, FRECLEADERS, FRESWTITLE, FNEWRES, FCONFMAXPART, FALPHDOMAIN, FEXIT,
    DOMAIN_SHOW         = 111,  DOMAIN_ADD, DOMAIN_EXIT,
    RESEARCHER_SHOW     = 121,  RESEARCHER_ADD, RESEARCHER_EXIT,
    PUBLICATION_SHOW    = 131,  PUBLICATION_ADD, PUBLICATION_EXIT,
    CONFERENCE_SHOW     = 141,  CONFERENCE_ADD, CONFERENCE_EXIT,
    AWARD_SHOW          = 151,  AWARD_ADD, AWARD_EXIT,
    RECRUITMENT_SHOW    = 161,  RECRUITMENT_ADD, RECRUITMENT_EXIT
};

void clearConsole()
{
    system("cls");
}

void welcome()
{
    printf("\n\t\tWELCOME TO MACO'S RESEARCH INSTITUTE\n\n\n");
    printf(" SELECT AN OPTION FROM THIS MENU\n\n");
}

void menuWelcome()
{
    welcome();
    printf("1. MANAGE DATABASE\n");
    printf("2. FUNCTIONS\n");
    printf("3. EXIT");

    printf("\n\nPlease enter an option...");
    printf("\nOption: ");
}

void menuManage()
{
    clearConsole();
    printf("\n MANAGE DATABASE\n\n");
    printf("11. DOMAIN\n");
    printf("12. RESEARCHER\n");
    printf("13. PUBLICATION\n");
    printf("14. CONFERENCE\n");
    printf("15. AWARD\n");
    printf("16. RECRUITMENT\n");
    printf("17. EXIT");

    printf("\n\nPlease enter an option...");
    printf("\nOption: ");
}

void menuDomain()
{
    clearConsole();
    printf("\n MANAGE DOMAINS\n\n");
    printf("111. SHOW DOMAINS\n");
    printf("112. ADD A NEW DOMAIN\n");
    printf("113. EXIT");

    printf("\n\nPlease enter an option...");
    printf("\nOption: ");
}

void menuResearcher()
{
    clearConsole();
    printf("\n MANAGE RESEARCHERS\n\n");
    printf("121. SHOW RESEARCHERS\n");
    printf("122. ADD A NEW RESEARCHER\n");
    printf("123. EXIT");

    printf("\n\nPlease enter an option...");
    printf("\nOption: ");
}

void menuPublication()
{
    clearConsole();
    printf("\n MANAGE PUBLICATION\n\n");
    printf("131. SHOW PUBLICATIONS\n");
    printf("132. ADD A NEW PUBLICATION\n");
    printf("133. EXIT");

    printf("\n\nPlease enter an option...");
    printf("\nOption: ");
}

void menuConference()
{
    clearConsole();
    printf("\n MANAGE CONFERENCES\n\n");
    printf("141. SHOW CONFERENCES\n");
    printf("142. ADD A NEW CONFERENCE\n");
    printf("143. EXIT");

    printf("\n\nPlease enter an option...");
    printf("\nOption: ");
}


void menuAward()
{
    clearConsole();
    printf("\n MANAGE AWARDS\n\n");
    printf("151. SHOW AWARDS\n");
    printf("152. ADD A NEW AWARD\n");
    printf("153. EXIT");

    printf("\n\nPlease enter an option...");
    printf("\nOption: ");
}

void menuRecruitment()
{
    clearConsole();
    printf("\n MANAGE RECRUITMENTS\n\n");
    printf("161. SHOW RECRUITMENTS\n");
    printf("162. ADD A NEW RECRUITMENT\n");
    printf("163. EXIT");

    printf("\n\nPlease enter an option...");
    printf("\nOption: ");
}

void menuFunctions()
{
    clearConsole();
    printf("\nFUNCTION\n\n");
    printf("21. Active researchers\n");
    printf("22. Publication leaders\n");
    printf("23. Recruitment leaders\n");
    printf("24. Researchers with a specified title\n");
    printf("25. New researchers\n");
    printf("26. Conferences with a maximum number of participants\n");
    printf("27. Alphabetically sort of the domains\n");
    printf("28. Exit");

    printf("\n\nPlease enter an option...");
    printf("\nOption: ");
}
