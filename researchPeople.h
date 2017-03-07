/**
* Author: BOGDAN MACOVEI
* Started at: 25th of November
*
* Informations:
*   Represent the simulation of the database Research people
*   with a structure that define a new type
*   named RESEARCHER
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    size_t  _id_researcher;             // one number in range [1, number_of_researchers]
    size_t  _leader_id_domain;          // completed with the id of one domain, or with 0
    char    _name_researcher[40];       // first name and last name
    char    _date_researcher[11];       // format YYYY/MM/DD - need validation
    char    _title_researcher;          // represent the scientific title of the researcher (1, 2, 3 or 0 = nothing)

} RESEARCHER;

RESEARCHER researcher_array[100];

char isValidNameResearcher(int _index, char *field)
{
    int i;
    for(i = 1; i < _index; ++i)
    {
        if(!strcmp(researcher_array[i]._name_researcher, field))
            return 0;
    }
    return 1;
}

/// Get the input data

void readData_Researcher(int local_id_researcher, FILE *in)
{
    if (local_id_researcher == 0)
        local_id_researcher = 1;

    researcher_array[local_id_researcher]._id_researcher = local_id_researcher;
    printf("Researcher id #%d:\n", local_id_researcher);

    fprintf(in, "%d\t\t\t", researcher_array[local_id_researcher]._id_researcher);

    // I use number_error to switch the message if it's necessary
    // (for invalid data)

    int number_error = 0;

    do
    {
        if(number_error != 0)
            printf("Error! This researcher is already in database. \nPlease reenter the name of the researcher: ");
        else
            printf("Name of the researcher: ");

        scanf("%s", &researcher_array[local_id_researcher]._name_researcher);

        number_error++;
    }
    while(!isValidNameResearcher (local_id_researcher,
            researcher_array[local_id_researcher]._name_researcher));

    fprintf(in, "%s\t\t\t", researcher_array[local_id_researcher]._name_researcher);

    researcher_array[local_id_researcher]._leader_id_domain = 0; // I suppose that the researcher is not a leader

    // I know that I have all the domains
    //      so I verify every domain
    //      and if the local researcher's ID is equal
    //      with a domain's leader ID
    //      I make the modification

    DOMAIN domain[100];
    FILE *domainIn = fopen("files/domain.txt", "r");
    fillDomain_structure(domain);
    int index_domain;
    int number_domain = inputNumber(domainIn);
    for(index_domain = 1; index_domain <= number_domain; index_domain++)
        if(domain[index_domain]._id_leader == local_id_researcher)
            researcher_array[local_id_researcher]._leader_id_domain = domain[index_domain]._id_domain;
    fclose(domainIn);

    fprintf(in, "%d\t\t\t", researcher_array[local_id_researcher]._leader_id_domain);

    researcher_array[local_id_researcher]._title_researcher = 0; // I suppose that has not a scientific title

    PUBLICATION publication[100];
    FILE *publicationIn = fopen("files/publication.txt", "r");
    fillPublication_structure(publication);
    int index_publication;
    int number_publication = inputNumber(publicationIn);

    int local_publication = 0;
    for(index_publication = 1; index_publication <= number_publication; index_publication++)
        if(publication[index_publication]._id_leader_publication == local_id_researcher)
        {
            local_publication = publication[index_publication]._id_publication;
            break;
        }

    fclose(publicationIn);

    if(local_publication != 0)
    {
        AWARDS award[100];
        FILE *awardIn = fopen("files/award.txt", "r");
        fillAward_structure(award);
        int index_award;
        int number_award = inputNumber(awardIn);

        int local_award = 0;
        for(index_award = 1; index_award <= number_award; index_award++)
            if(award[index_award]._id_publication_award == local_publication)
            {
                local_award = award[index_award]._title_award;
                researcher_array[local_id_researcher]._title_researcher = local_award;
                break;
            }

        fclose(awardIn);
    }


    fprintf(in, "%d\t\t\t", researcher_array[local_id_researcher]._title_researcher);

    // I use again the validation data

    number_error = 0;

    do
    {
        if(number_error != 0)
            printf("Error! Please reenter the creation date (yyyy/mm/dd): ");
        else
            printf("Creation date (yyyy/mm/dd): ");

        scanf("%s", &researcher_array[local_id_researcher]._date_researcher);
        number_error++;
    }
    while(!isValidDate(researcher_array[local_id_researcher]._date_researcher));

    fprintf(in, "%s\n", researcher_array[local_id_researcher]._date_researcher);

    printf("\n");
}

/// Print data (just for a specific ID, for selection)
///     I use the people.txt file to select the local_id
/// I read the file while indexFile (the current index in file)
///     is not equal with the local_id index

void printData_Researcher(int local_id_researcher)
{
    FILE *in = fopen("files/people.txt", "r");
    fillResearcher_structure(researcher_array);
    if(local_id_researcher > inputNumber(in))
    {
        fclose(in);
        return;
    }

    fclose(in);

    if(local_id_researcher == 1)
    {
        printf(" ID\t|\tNAME\t|\tLD\t|\tTITLE\t|\tDATE\n");
        printf("----------------------------------------------------------------------------\n");
    }

    printf(" %d\t|\t", researcher_array[local_id_researcher]._id_researcher);
    printf("%s\t|\t", researcher_array[local_id_researcher]._name_researcher);
    printf("%d\t|\t", researcher_array[local_id_researcher]._leader_id_domain);
    printf("%d\t|\t", researcher_array[local_id_researcher]._title_researcher);
    printf("%s\n", researcher_array[local_id_researcher]._date_researcher);
}

void fillResearcher_structure(RESEARCHER *local_array)
{
    FILE *in = fopen("files/people.txt", "r");
    int i=0;
    char c;
    while(!feof(in))
    {
        i++;
        fscanf(in, "%d", &local_array[i]._id_researcher);
        fscanf(in, "%s", &local_array[i]._name_researcher);
        fscanf(in, "%d", &local_array[i]._leader_id_domain);
        fscanf(in, "%d", &local_array[i]._title_researcher);
        fscanf(in, "%s", &local_array[i]._date_researcher);
    }

    fclose(in);
}
