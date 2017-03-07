/**
* Author: BOGDAN MACOVEI
* Started at: 29th of November
*
* Informations:
*   Represent the general functions for this project
**/

#include <stdio.h>
#include <string.h>
#include <windows.h>

/// Represent the number of line in a file
///     that is equal with the number of the input data
///     in structure

int inputNumber(FILE *in)
{
    int numberOfLines = 0;
    char c;

    while(!feof(in))
    {
        fscanf(in, "%c", &c);
        if(c=='\n')
            numberOfLines++;
    }

    return numberOfLines - 1;
}

/// ============== FUNCTIONS ============== ///

/// 1. Active researchers
///     := are the researchers from the domain
///     where are the maximum members that work
///     at a publication
///     ---
///     I make maximum from participants at a publication,
///         and for that max I verify the leader
///         and for the leader I will know the domain
///     Result: "The domain X contains the maximum number of active researchers"

void activeResearchers()
{
    PUBLICATION publication_array[100];
    RESEARCHER researcher_array[100];
    DOMAIN domain_array[100];

    fillPublication_structure(publication_array);
    fillResearcher_structure(researcher_array);
    fillDomain_structure(domain_array);

    FILE *in1 = fopen("files/publication.txt", "r");
    FILE *in2 = fopen("files/people.txt", "r");

    int numbPublication = inputNumber(in1);
    int numbResearcher = inputNumber(in2);

    fclose(in1);
    fclose(in2);

    // Maximum from participants at a publication
    int maxPublication = 0, IDLeader, IDDomain;
    int i;

    for(i = 1; i <= numbPublication; i++)
        if(publication_array[i]._participants > maxPublication)
        {
            maxPublication = publication_array[i]._participants;
            IDLeader = publication_array[i]._id_leader_publication;
        }

    // I search for the IDLeader in my Researchers database

    for(i = 1; i <= numbResearcher; i++)
        if(researcher_array[i]._id_researcher == IDLeader)
        {
            IDDomain = researcher_array[i]._leader_id_domain;
            break;
        }

    if(IDDomain <= 100)
        printf("\nThe domain %s contains the maximum number of active researchers\n\n", domain_array[IDDomain]._name_domain);
    system("pause");
}

/// 2. Publication leaders
///     := are researchers that work for a publication
/// ---
///     I verify the IDL from publications
///         and I'll print on the console the name of researcher
///     Firstly I have to sort the vector of names (not repeating names)

void publicationLeaders()
{
    PUBLICATION publication_array[100];
    RESEARCHER researcher_array[100];

    fillPublication_structure(publication_array);
    fillResearcher_structure(researcher_array);

    FILE *in1 = fopen("files/publication.txt", "r");

    int numbPublication = inputNumber(in1);

    char names[numbPublication][10];

    fclose(in1);

    int i, j, IDLeader;

    for(i = 1; i <= numbPublication; i++)
    {
        IDLeader = publication_array[i]._id_leader_publication;
        strcpy(names[i], researcher_array[IDLeader]._name_researcher);
    }

    printf("\n");

    // Sorting names array

    for(i = 1; i < numbPublication; i++)
        for(j = i + 1; j <= numbPublication; j++)
            if(strcmp(names[i], names[j]) > 0)
            {
                strcpy(names[0], names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], names[0]);
            }

    printf("\nPublication leaders are: \n");

    // Print just distinct values

    printf("Leader: %s\n", names[1]);
    for(i = 2; i <= numbPublication; i++)
        if(strcmp(names[i], names[i-1]))
            printf("Leader: %s\n", names[i]);

    printf("\n");
    system("pause");
}

/// 3. Recruitment leader for a specified domain and number of places
///     := for an input string
///     I'll print on the display the name of the researcher
///     and the number of free places

void recruitment()
{
    RESEARCHER researcher_array[100];
    DOMAIN domain_array[100];

    fillResearcher_structure(researcher_array);
    fillDomain_structure(domain_array);

    FILE *in1 = fopen("files/domain.txt", "r");

    int numbDomain = inputNumber(in1);

    fclose(in1);

    char domainIn[20];
    printf("\nDomain name: ");
    scanf("%s", &domainIn);

    int i, IDLeader;

    printf("\n");

    short int ok = 0;

    for(i = 1; i <= numbDomain; i++)
        if(!strcmp(domain_array[i]._name_domain, domainIn))
        {
            IDLeader = domain_array[i]._id_leader;
            if(strcmp(researcher_array[IDLeader]._name_researcher, ""))
                printf("The Leader is %s and there are %d places\n",
                   researcher_array[IDLeader]._name_researcher, domain_array[i]._number_domain);
            else
                printf("The Leader is unknown and there are %d places\n",
                       domain_array[i]._number_domain);
            ok = 1;
        }

    if(!ok)
        printf("Invalid data!");

    printf("\n");
    system("pause");
}

/// 4. Researchers with a specified title

void titleResearcher()
{
    RESEARCHER researcher_array[100];
    fillResearcher_structure(researcher_array);

    FILE *in1 = fopen("files/people.txt", "r");

    int numbResearcher = inputNumber(in1), title, i;

    fclose(in1);

    printf("\nTitle (0, 1, 2, 3): ");
    scanf("%d", &title);

    printf("\nResearchers with title %d are:\n\n", title);

    for(i = 1; i <= numbResearcher; i++)
        if(researcher_array[i]._title_researcher == title)
            printf("%s\n", researcher_array[i]._name_researcher);

    printf("\n");
    system("pause");
}

/// 5. New researchers
///     := researchers added in current year
///     from 01.01/current_year to current_date
///     where I consider current_date == current_year
/// ---
///     Input: current_year
///     Output: Researchers added in current_year: [X..]

void newResearchers()
{
    RESEARCHER researcher_array[100];
    fillResearcher_structure(researcher_array);

    FILE *in1 = fopen("files/people.txt", "r");

    int numbResearcher = inputNumber(in1), i;

    fclose(in1);

    char current_year[5];

    printf("\nCurrent year: ");
    scanf("%s", &current_year);

    printf("\nResearchers added in %s:\n\n", current_year);

    for(i = 1; i <= numbResearcher; i++)
    {
        char *year = strtok(researcher_array[i]._date_researcher, "/");
        if(!strcmp(year, current_year))
            printf("%s\n", researcher_array[i]._name_researcher);
    }

    printf("\n");
    system("pause");
}

/// 6. Conferences with a maximum number of participants
///     := I'll show the date of the conference, the domain and the leader

void conferences()
{
    CONFERENCE conference_array[100];
    DOMAIN domain_array[100];
    RESEARCHER researcher_array[100];
    PUBLICATION publication_array[100];

    fillConference_structure(conference_array);
    fillDomain_structure(domain_array);
    fillResearcher_structure(researcher_array);
    fillPublication_structure(publication_array);

    FILE *in1 = fopen("files/conference.txt", "r");

    int numbConference = inputNumber(in1);

    fclose(in1);

    int maxConference = 0, i, IDConference, IDPublication;

    for(i = 1; i <= numbConference; i++)
        if(conference_array[i]._number_participants > maxConference)
        {
            maxConference = conference_array[i]._number_participants;
            IDConference = conference_array[i]._id_conference;
            IDPublication = conference_array[i]._id_publication_conference;
        }

    int IDLeader = publication_array[IDPublication]._id_leader_publication;
    int IDDomain = researcher_array[IDLeader]._leader_id_domain;

    printf("\nThe maximum number of participants (%d) are in date %s.\nDomain: %s | Leader: %s\n\n",
           conference_array[IDConference]._number_participants,
           conference_array[IDConference]._date_conference,
           domain_array[IDDomain]._name_domain,
           researcher_array[IDLeader]._name_researcher);

    system("pause");
}


/// 7. Alphabetically sort of the domains
///     := using QSORT

int cmp_qsortDomains(const void *domain1, const void *domain2)
{
    const DOMAIN *dom1 = (const DOMAIN *) domain1;
    const DOMAIN *dom2 = (const DOMAIN *) domain2;
    return strcmp(dom1->_name_domain, dom2->_name_domain);
}

void qsort_Domains()
{
    DOMAIN domain_array[100];
    fillDomain_structure(domain_array);

    FILE *in = fopen("files/domain.txt", "r");

    int numbDomain = inputNumber(in);

    fclose(in);

    qsort(domain_array, numbDomain, sizeof(DOMAIN), cmp_qsortDomains);

    int i;

    for(i = 1; i <= numbDomain; i++)
    {
        if(i == 1)
        {
            printf("\n ID\t|\tNAME\t|\tIDL\t|\tMEMB\t|\tDATE\n");
            printf("----------------------------------------------------------------------------\n");
        }

        printf(" %d\t|\t", domain_array[i]._id_domain);
        printf("%s\t|\t", domain_array[i]._name_domain);
        printf("%d\t|\t", domain_array[i]._id_leader);
        printf("%d\t|\t", domain_array[i]._number_domain);
        printf("%s\n", domain_array[i]._date_domain);
    }

    printf("\n");
    system("pause");
}

/// Making the vector of pointers

void (*functions[7]) (void);

void pointerVector()
{
    functions[0] = &activeResearchers;
    functions[1] = &publicationLeaders;
    functions[2] = &recruitment;
    functions[3] = &titleResearcher;
    functions[4] = &newResearchers;
    functions[5] = &conferences;
    functions[6] = &qsort_Domains;
}
