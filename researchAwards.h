/**
* Author: BOGDAN MACOVEI
* Started at: 26th of November
*
* Informations:
*   Represent the simulation of the database Research awards
*   with a structure that define a new type
*   named AWARDS
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    size_t  _id_award;                  // one number in range [1, number_of_award]
    size_t  _title_award;               // 1, 2, 3 and 0 (=nothing)
    size_t  _id_publication_award;      // the publication's id (including domain's id and researcher's id)
    char    _date_conference[11];       // format YYYY/MM/DD - need validation

} AWARDS;

AWARDS award_array[100];

void readData_Award(int local_id_award, FILE *in)
{
    if(local_id_award == 0)
        local_id_award = 1;

    // current ID is also the award's ID

    award_array[local_id_award]._id_award = local_id_award;
    printf("Award id #%d:\n", local_id_award);

    fprintf(in, "%d\t\t\t", local_id_award);

    // Title (0, 1, 2, 3) (0 = nothing, 1 = first rank, 2 ... )

    printf("Title (0, 1, 2, 3): ");
    scanf("%d", &award_array[local_id_award]._title_award);

    fprintf(in, "%d\t\t\t", award_array[local_id_award]._title_award);

    // Publication's ID

    printf("Publication's ID: ");
    scanf("%d", &award_array[local_id_award]._id_publication_award);

    fprintf(in, "%d\t\t\t", award_array[local_id_award]._id_publication_award);

    // I use again the validation data

    // I use number_error to switch the message if it's necessary
    // (for invalid data)

    int number_error = 0;

    do
    {
        if(number_error != 0)
            printf("Error! Please reenter the creation date (yyyy/mm/dd): ");
        else
            printf("Creation date (yyyy/mm/dd): ");

        scanf("%s", &award_array[local_id_award]._date_conference);
        number_error++;
    }
    while(!isValidDate(award_array[local_id_award]._date_conference));

    fprintf(in, "%s\n", award_array[local_id_award]._date_conference);

    printf("\n");

}

/// Print data (just for a specific ID, for selection)
///     I use the award.txt file to select the local_id
/// I read the file while indexFile (the current index in file)
///     is not equal with the local_id index

void printData_Award(int local_id_award)
{
    FILE *in = fopen("files/award.txt", "r");
    fillAward_structure(award_array);
    if(local_id_award > inputNumber(in))
    {
        fclose(in);
        return;
    }

    fclose(in);

    if(local_id_award == 1)
    {
        printf(" ID\t|\tTITLE\t|\tIDP\t|\tDATE\n");
        printf("----------------------------------------------------------------------------\n");
    }


    printf(" %d\t|\t", award_array[local_id_award]._id_award);
    printf("%d\t|\t", award_array[local_id_award]._title_award);
    printf("%d\t|\t", award_array[local_id_award]._id_publication_award);
    printf("%s\n", award_array[local_id_award]._date_conference);
}

void fillAward_structure(AWARDS *local_array)
{
    FILE *in = fopen("files/award.txt", "r+");
    int i=0;
    char c;
    while(!feof(in))
    {
        i++;
        fscanf(in, "%d", &local_array[i]._id_award);
        fscanf(in, "%d", &local_array[i]._title_award);
        fscanf(in, "%d", &local_array[i]._id_publication_award);
        fscanf(in, "%s", &local_array[i]._date_conference);
    }

    fclose(in);
}
