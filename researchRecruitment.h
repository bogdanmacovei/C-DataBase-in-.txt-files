/**
* Author: BOGDAN MACOVEI
* Started at: 26th of November
*
* Informations:
*   Represent the simulation of the database Research recruitment
*   with a structure that define a new type
*   named RECRUITMENT
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    size_t  _id_recruitment;
    size_t  _id_domain_recruitment;
    char    _date_recruitment[11];      // format YYYY/MM/DD - need validation

} RECRUITMENT;

RECRUITMENT recruitment_array[100];

void readData_Recruitment(int local_id_recruitment, FILE *in)
{
    if(local_id_recruitment == 0)
        local_id_recruitment = 1;

    // current ID is also the award's ID

    recruitment_array[local_id_recruitment]._id_recruitment = local_id_recruitment;
    printf("Recruitment id #%d:\n", local_id_recruitment);

    fprintf(in, "%d\t\t\t", local_id_recruitment);

    // Domain's ID

    printf("Domain's ID: ");
    scanf("%d", &recruitment_array[local_id_recruitment]._id_domain_recruitment);

    fprintf(in, "%d\t\t\t", recruitment_array[local_id_recruitment]._id_domain_recruitment);

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

        scanf("%s", &recruitment_array[local_id_recruitment]._date_recruitment);
        number_error++;
    }
    while(!isValidDate(recruitment_array[local_id_recruitment]._date_recruitment));

    fprintf(in, "%s\n", recruitment_array[local_id_recruitment]._date_recruitment);

    printf("\n");

}

void printData_Recruitment(int local_id_recruitment)
{
    FILE *in = fopen("files/recruitment.txt", "r");
    fillRecruitment_structure(recruitment_array);
    if(local_id_recruitment > inputNumber(in))
    {
        fclose(in);
        return;
    }

    fclose(in);

    if(local_id_recruitment == 1)
    {
        printf(" ID\t|\tIDD\t|\tDATE\n");
        printf("----------------------------------------------------------------------------\n");
    }


    printf(" %d\t|\t", recruitment_array[local_id_recruitment]._id_recruitment);
    printf("%d\t|\t", recruitment_array[local_id_recruitment]._id_domain_recruitment);
    printf("%s\n", recruitment_array[local_id_recruitment]._date_recruitment);
}

void fillRecruitment_structure(RECRUITMENT *local_array)
{
    FILE *in = fopen("files/recruitment.txt", "r+");
    int i=0;
    char c;
    while(!feof(in))
    {
        i++;
        fscanf(in, "%d", &local_array[i]._id_recruitment);
        fscanf(in, "%d", &local_array[i]._id_domain_recruitment);
        fscanf(in, "%s", &local_array[i]._date_recruitment);
    }

    fclose(in);
}
