/**
* Author: BOGDAN MACOVEI
* Started at: 26th of November
*
* Informations:
*   Represent the simulation of the database Research conferences
*   with a structure that define a new type
*   named CONFERENCE
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    size_t  _id_conference;             // one number in range [1, number_of_conferences]
    size_t  _id_publication_conference; // completed with the id of publication
    size_t  _number_participants;       // number of participants at conference
    char    _date_conference[11];       // format YYYY/MM/DD - need validation

} CONFERENCE;

CONFERENCE conference_array[100];

void readData_Conference(int local_id_conference, FILE *in)
{
    if(local_id_conference == 0)
        local_id_conference = 1;

    // current ID is also the conference's ID

    conference_array[local_id_conference]._id_conference = local_id_conference;
    printf("Conference id #%d:\n", local_id_conference);

    fprintf(in, "%d\t\t\t", local_id_conference);

    // Publication ID

    printf("Publication's ID: ");
    scanf("%d", &conference_array[local_id_conference]._id_publication_conference);

    fprintf(in, "%d\t\t\t", conference_array[local_id_conference]._id_publication_conference);

    // Number of guests

    printf("Number of participants: ");
    scanf("%d", &conference_array[local_id_conference]._number_participants);

    fprintf(in, "%d\t\t\t", conference_array[local_id_conference]._number_participants);

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

        scanf("%s", &conference_array[local_id_conference]._date_conference);
        number_error++;
    }
    while(!isValidDate(conference_array[local_id_conference]._date_conference));

    fprintf(in, "%s\n", conference_array[local_id_conference]._date_conference);

    printf("\n");

}

/// Print data (just for a specific ID, for selection)
///     I use the conference.txt file to select the local_id
/// I read the file while indexFile (the current index in file)
///     is not equal with the local_id index

void printData_Conference(int local_id_conference)
{
    FILE *in = fopen("files/conference.txt", "r");
    fillConference_structure(conference_array);
    if(local_id_conference > inputNumber(in))
    {
        fclose(in);
        return;
    }

    fclose(in);

    if(local_id_conference == 1)
    {
        printf(" ID\t|\tIDP\t|\tNUMB\t|\tDATE\n");
        printf("----------------------------------------------------------------------------\n");
    }


    printf(" %d\t|\t", conference_array[local_id_conference]._id_conference);
    printf("%d\t|\t", conference_array[local_id_conference]._id_publication_conference);
    printf("%d\t|\t", conference_array[local_id_conference]._number_participants);
    printf("%s\n", conference_array[local_id_conference]._date_conference);
}

void fillConference_structure(CONFERENCE *local_array)
{
    FILE *in = fopen("files/conference.txt", "r+");
    int i=0;
    char c;
    while(!feof(in))
    {
        i++;
        fscanf(in, "%d", &local_array[i]._id_conference);
        fscanf(in, "%d", &local_array[i]._id_publication_conference);
        fscanf(in, "%d", &local_array[i]._number_participants);
        fscanf(in, "%s", &local_array[i]._date_conference);
    }

    fclose(in);
}
