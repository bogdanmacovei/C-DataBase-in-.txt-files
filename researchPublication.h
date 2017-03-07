/**
* Author: BOGDAN MACOVEI
* Started at: 25th of November
*
* Informations:
*   Represent the simulation of the database Research publications
*   with a structure that define a new type
*   named PUBLICATION
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    size_t  _id_publication;            // one number in range [1, number_of_publication]
    size_t  _id_domain_publication;     // completed with the id of one domain
    size_t  _id_leader_publication;     // completed with the id of one scientist (default: leader of the domain)
    size_t  _participants;              // completed with the number of other scientists
    char    _date_publication[11];      // format YYYY/MM/DD - need validation

} PUBLICATION;

PUBLICATION publication_array[100];

void readData_Publication(int local_id_publication, FILE *in)
{
    if(local_id_publication == 0)
        local_id_publication = 1;
    // current ID is also the publication's ID

    publication_array[local_id_publication]._id_publication = local_id_publication;
    printf("Publication id #%d:\n", local_id_publication);

    fprintf(in, "%d\t\t\t", local_id_publication);

    // Leader's ID

    printf("Leader's ID: ");
    scanf("%d", &publication_array[local_id_publication]._id_leader_publication);

    fprintf(in, "%d\t\t\t", publication_array[local_id_publication]._id_leader_publication);

    // Number of participants

    printf("Number of participants at this project: ");
    scanf("%d", &publication_array[local_id_publication]._participants);

    fprintf(in, "%d\t\t\t", publication_array[local_id_publication]._participants);

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

        scanf("%s", &publication_array[local_id_publication]._date_publication);
        number_error++;
    }
    while(!isValidDate(publication_array[local_id_publication]._date_publication));

    fprintf(in, "%s\n", publication_array[local_id_publication]._date_publication);

    printf("\n");

}

/// Print data (just for a specific ID, for selection)
///     I use the publication.txt file to select the local_id
/// I read the file while indexFile (the current index in file)
///     is not equal with the local_id index

void printData_Publication(int local_id_publication)
{
    FILE *in = fopen("files/publication.txt", "r");
    fillPublication_structure(publication_array);
    if(local_id_publication > inputNumber(in))
    {
        fclose(in);
        return;
    }

    fclose(in);

    if(local_id_publication == 1)
    {
        printf(" ID\t|\tIDL\t|\tNUMBL\t|\tDATE\n");
        printf("----------------------------------------------------------------------------\n");
    }


    printf(" %d\t|\t", publication_array[local_id_publication]._id_publication);
    printf("%d\t|\t", publication_array[local_id_publication]._id_leader_publication);
    printf("%d\t|\t", publication_array[local_id_publication]._participants);
    printf("%s\n", publication_array[local_id_publication]._date_publication);
}

void fillPublication_structure(PUBLICATION *local_array)
{
    FILE *in = fopen("files/publication.txt", "r+");
    int i=0;
    char c;
    while(!feof(in))
    {
        i++;
        fscanf(in, "%d", &local_array[i]._id_publication);
        fscanf(in, "%d", &local_array[i]._id_leader_publication);
        fscanf(in, "%d", &local_array[i]._participants);
        fscanf(in, "%s", &local_array[i]._date_publication);
    }

    fclose(in);
}
