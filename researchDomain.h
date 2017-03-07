/**
* Author: BOGDAN MACOVEI
* Started at: 25th of November
*
* Informations:
*   Represent the simulation of the database Research domain
*   with a structure that define a new type
*   named DOMAIN
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/// In this local machine, size_t is unsigned long int

typedef struct
{
    size_t  _id_domain;                 // one number in range [1, number_of_domains]
    size_t  _id_leader;                 // FK
    size_t  _number_domain;             // the numbers of researches in this domain
    char    _name_domain[30];           // Computer Science, Maths ...
    char    _date_domain[11];           // format YYYY/MM/DD - need validation

} DOMAIN;

DOMAIN domain_array[100];

/// Verify if the date is in a correct format
///     I use the extern class of memory because
///     I want to use this function everywhere in
///     this project

/// the date format is yyyy/mm/ll, so in this function:
///     I just verify if the string respect the input format
///     without verifying if the date is valid


char isValidDate(char *field)
{
    int i;

    if(strlen(field) != 10)
        return 0;

    for(i = 0; i < 10; ++i)
    {
        if(i==4 || i==7)
            continue;
        if(!isdigit(field[i]))
            return 0;
    }

    if(field[4] != '/' || field[7] != '/')
        return 0;

    return 1;
}

/// Verify if the domain does not already exist

char isValidNameDomain(int index, char *field)
{
    int i;
    for(i = 1; i < index; ++i)
    {
        if(!strcmp(domain_array[i]._name_domain, field))
            return 0;
    }
    return 1;
}

/// Get the input data and write this data in domain.txt
///     I use FILE *in as a local parameter
///     because I want to overwrite this file

void readData_Domain(int local_id_domain, FILE *in)
{
    // current ID is also the domain's ID

    domain_array[local_id_domain]._id_domain = local_id_domain;
    printf("Domain id #%d:\n", local_id_domain);

    fprintf(in, "%d\t\t\t", local_id_domain);

    // I use number_error to switch the message if it's necessary
    // (for invalid data)

    int number_error = 0;

    do
    {
        if(number_error != 0)
            printf("Error! This domain is already in database. \nPlease reenter the name of the domain: ");
        else
            printf("Name of the domain: ");

        scanf("%s", &domain_array[local_id_domain]._name_domain);

        number_error++;
    }
    while(!isValidNameDomain (local_id_domain,
            domain_array[local_id_domain]._name_domain));

    fprintf(in, "%s\t\t\t", domain_array[local_id_domain]._name_domain);

    // leader's ID (we'll be verified when it will be values in the researchPeople database

    printf("Leader's ID: ");
    scanf("%d", &domain_array[local_id_domain]._id_leader);

    fprintf(in, "%d\t\t\t", domain_array[local_id_domain]._id_leader);

    // I'll use this for recruiting people

    printf("Maximum number of researchers: ");
    scanf("%d", &domain_array[local_id_domain]._number_domain);

    fprintf(in, "%d\t\t\t", domain_array[local_id_domain]._number_domain);

    // I use again the validation data

    number_error = 0;

    do
    {
        if(number_error != 0)
            printf("Error! Please reenter the creation date (yyyy/mm/dd): ");
        else
            printf("Creation date (yyyy/mm/dd): ");

        scanf("%s", &domain_array[local_id_domain]._date_domain);
        number_error++;
    }
    while(!isValidDate(domain_array[local_id_domain]._date_domain));

    fprintf(in, "%s\n", domain_array[local_id_domain]._date_domain);

    printf("\n");

}

/// Print data (just for a specific ID, for selection)
///     I use the domain.txt file to select the local_id
/// I read the file while indexFile (the current index in file)
///     is not equal with the local_id index

void printData_Domain(int local_id_domain)
{
    FILE *in = fopen("files/domain.txt", "r");
    fillDomain_structure(domain_array);
    if(local_id_domain > inputNumber(in))
    {
        fclose(in);
        return;
    }

    fclose(in);

    if(local_id_domain == 1)
    {
        printf(" ID\t|\tNAME\t|\tIDL\t|\tMEMB\t|\tDATE\n");
        printf("----------------------------------------------------------------------------\n");
    }


    printf(" %d\t|\t", domain_array[local_id_domain]._id_domain);
    printf("%s\t|\t", domain_array[local_id_domain]._name_domain);
    printf("%d\t|\t", domain_array[local_id_domain]._id_leader);
    printf("%d\t|\t", domain_array[local_id_domain]._number_domain);
    printf("%s\n", domain_array[local_id_domain]._date_domain);
}

/// I make this function to use the file's data
///     and to work in this program with structures

void fillDomain_structure(DOMAIN *local_array)
{
    FILE *in = fopen("files/domain.txt", "r+");
    int i=0;
    char c;
    while(!feof(in))
    {
        i++;
        fscanf(in, "%d", &local_array[i]._id_domain);
        fscanf(in, "%s", &local_array[i]._name_domain);
        fscanf(in, "%d", &local_array[i]._id_leader);
        fscanf(in, "%d", &local_array[i]._number_domain);
        fscanf(in, "%s", &local_array[i]._date_domain);
    }

    fclose(in);
}
