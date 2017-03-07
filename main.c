/**
* Author: BOGDAN MACOVEI
* Finished at: 4th of December
*
* Informations:
*   Project's title: MACO's Research Institute
**/

#include <stdio.h>
#include <stdlib.h>

#include "researchDomain.h"
#include "researchPublication.h"
#include "researchAwards.h"
#include "researchPeople.h"
#include "researchConference.h"
#include "researchRecruitment.h"

#include "researchFunctions.h"
#include "researchMenus.h"

int main()
{
    FILE *in;

    int option, optionManage, optionManage_Domain, optionManage_Researcher, optionManage_Publication;
    int optionManage_Award, optionManage_Conference, optionManage_Recruitment;
    int optionFunctions;

    do
    {
        clearConsole();
        menuWelcome();
        scanf("%d", &option);

        switch(option)
        {
            case MANAGE:
                do
                {
                    clearConsole();
                    menuManage();
                    scanf("%d", &optionManage);

                    switch(optionManage)
                    {
                        case MDOMAIN:
                            clearConsole();
                            do
                            {
                                menuDomain();
                                scanf("%d", &optionManage_Domain);

                                switch(optionManage_Domain)
                                {
                                    case DOMAIN_SHOW:
                                        in = fopen("files/domain.txt", "r+");
                                        int n = inputNumber(in);
                                        int i;
                                        printf("\n\n");
                                        for(i=1; i<=n; i++)
                                            printData_Domain(i);
                                        printf("\n\n");
                                        fclose(in);

                                        system("pause");
                                        system("cls");

                                        break;

                                    case DOMAIN_ADD:
                                        clearConsole();
                                        in = fopen("files/domain.txt", "r+");
                                        readData_Domain(inputNumber(in)+1, in);
                                        fclose(in);
                                        break;

                                    case DOMAIN_EXIT:
                                        break;

                                    default:
                                        break;
                                }

                            } while(optionManage_Domain != DOMAIN_EXIT);
                            break;

                        case MRESEARCHER:
                            clearConsole();
                            do
                            {
                                menuResearcher();
                                scanf("%d", &optionManage_Researcher);

                                switch(optionManage_Researcher)
                                {
                                    case RESEARCHER_SHOW:
                                        in = fopen("files/people.txt", "r+");
                                        int n = inputNumber(in);
                                        int i;
                                        printf("\n\n");
                                        for(i=1; i<=n; i++)
                                            printData_Researcher(i);
                                        printf("\n\n");
                                        fclose(in);

                                        system("pause");
                                        system("cls");

                                        break;

                                    case RESEARCHER_ADD:
                                        clearConsole();
                                        in = fopen("files/people.txt", "r+");
                                        readData_Researcher(inputNumber(in)+1, in);
                                        fclose(in);
                                        break;

                                    case RESEARCHER_EXIT:
                                        break;

                                    default:
                                        break;
                                }

                            } while(optionManage_Researcher != RESEARCHER_EXIT);
                            break;

                        case MPUBLICATION:
                            clearConsole();
                            do
                            {
                                menuPublication();
                                scanf("%d", &optionManage_Publication);

                                switch(optionManage_Publication)
                                {
                                    case PUBLICATION_SHOW:
                                        in = fopen("files/publication.txt", "r+");
                                        int n = inputNumber(in);
                                        int i;
                                        printf("\n\n");
                                        for(i=1; i<=n; i++)
                                            printData_Publication(i);
                                        printf("\n\n");
                                        fclose(in);

                                        system("pause");
                                        system("cls");

                                        break;

                                    case PUBLICATION_ADD:
                                        clearConsole();
                                        in = fopen("files/publication.txt", "r+");
                                        readData_Publication(inputNumber(in)+1, in);
                                        fclose(in);
                                        break;

                                    case PUBLICATION_EXIT:
                                        break;

                                    default:
                                        break;
                                }

                            } while(optionManage_Publication != PUBLICATION_EXIT);
                            break;

                        case MCONFERENCE:
                            clearConsole();
                            do
                            {
                                menuConference();
                                scanf("%d", &optionManage_Conference);

                                switch(optionManage_Conference)
                                {
                                    case CONFERENCE_SHOW:
                                        in = fopen("files/conference.txt", "r+");
                                        int n = inputNumber(in);
                                        int i;
                                        printf("\n\n");
                                        for(i=1; i<=n; i++)
                                            printData_Conference(i);
                                        printf("\n\n");
                                        fclose(in);

                                        system("pause");
                                        system("cls");

                                        break;

                                    case CONFERENCE_ADD:
                                        clearConsole();
                                        in = fopen("files/conference.txt", "r+");
                                        readData_Conference(inputNumber(in)+1, in);
                                        fclose(in);
                                        break;

                                    case CONFERENCE_EXIT:
                                        break;

                                    default:
                                        break;
                                }

                            } while(optionManage_Conference != CONFERENCE_EXIT);
                            break;

                        case MAWARD:
                            clearConsole();
                            do
                            {
                                menuAward();
                                scanf("%d", &optionManage_Award);

                                switch(optionManage_Award)
                                {
                                    case AWARD_SHOW:
                                        in = fopen("files/award.txt", "r+");
                                        int n = inputNumber(in);
                                        int i;
                                        printf("\n\n");
                                        for(i=1; i<=n; i++)
                                            printData_Award(i);
                                        printf("\n\n");
                                        fclose(in);

                                        system("pause");
                                        system("cls");

                                        break;

                                    case AWARD_ADD:
                                        clearConsole();
                                        in = fopen("files/award.txt", "r+");
                                        readData_Award(inputNumber(in)+1, in);
                                        fclose(in);
                                        break;

                                    case AWARD_EXIT:
                                        break;

                                    default:
                                        break;
                                }

                            } while(optionManage_Award != AWARD_EXIT);
                            break;

                        case MRECRUITMENT:
                            clearConsole();
                            do
                            {
                                menuRecruitment();
                                scanf("%d", &optionManage_Recruitment);

                                switch(optionManage_Recruitment)
                                {
                                    case RECRUITMENT_SHOW:
                                        in = fopen("files/recruitment.txt", "r+");
                                        int n = inputNumber(in);
                                        int i;
                                        printf("\n\n");
                                        for(i=1; i<=n; i++)
                                            printData_Recruitment(i);
                                        printf("\n\n");
                                        fclose(in);

                                        system("pause");
                                        system("cls");

                                        break;

                                    case RECRUITMENT_ADD:
                                        clearConsole();
                                        in = fopen("files/recruitment.txt", "r+");
                                        readData_Recruitment(inputNumber(in)+1, in);
                                        fclose(in);
                                        break;

                                    case RECRUITMENT_EXIT:
                                        break;

                                    default:
                                        break;
                                }

                            } while(optionManage_Recruitment != RECRUITMENT_EXIT);
                            break;

                        case MEXIT:
                            break;

                        }

                } while(optionManage != MEXIT);
                break;

            case FUNCTION:
                do
                {
                    clearConsole();
                    menuFunctions();
                    scanf("%d", &optionFunctions);

                    pointerVector();

                    switch(optionFunctions)
                    {
                        case FACTIVRES:
                            (*functions[0])();
                            break;

                        case FPUBLEADERS:
                            (*functions[1])();
                            break;

                        case FRECLEADERS:
                            (*functions[2])();
                            break;

                        case FRESWTITLE:
                            (*functions[3])();
                            break;

                        case FNEWRES:
                            (*functions[4])();
                            break;

                        case FCONFMAXPART:
                            (*functions[5])();
                            break;

                        case FALPHDOMAIN:
                            (*functions[6])();
                            break;

                        case FEXIT:
                            break;
                    }
                } while(optionFunctions != FEXIT);
                break;

                case EXIT:
                    break;
        }

    }
    while(option != EXIT);

    return 0;
}
