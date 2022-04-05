/*
    Author : Anik Saha
    Project Name : Phonebook
    Date created : 20/01/2022
    Description : By using this file we can save contacts and do these operations in it.
        1) view all contacts.
        2) add a contact.
        3) remove a contact.
        4) search details of any contact number.
        5) update details of any contact.
        6) delete whole phonebook (delete all contacts present in phonebook).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#define KEY "\t\t\t\tEnter your Choice : "
void start();
void phone_list_record();
void add_contact();
void remove_contact_all();
void search_contact();
void update_contact();
void remove_contact();
void print_phone_book_menu();
void input_function();


struct parson
{

    char name[30];
    char country_code[4];
    long int phone_number;
    char sex[8];
    char email[100];

};

typedef struct parson parson;

int main()
{
    start();
    return 0;
}
void start()
{
    char phone_book;
    print_phone_book_menu();
    while(1)
    {
        printf("\n");
        print_phone_book_menu();
        printf("%s", KEY);
        phone_book = getche();

        switch(phone_book)
        {
        case '1':
            phone_list_record();
             _getch();
            break;

        case '2':
            add_contact();
           _getch();
            break;

        case '3':
            update_contact();
            _getch();
            break;

        case '4':
            search_contact();
            _getch();
            break;

        case '5':
            remove_contact();
           _getch();
            break;

        case '6':
            remove_contact_all();
           _getch();
            break;

        case '7':
            exit(0);
            break;

        default :
            system("cls");
            printf("\n**********You have entered unavailable option**********\n");
            printf("\n*****Please Enter any one of below available options****\n");
            break;

        }
    }

}

void print_phone_book_menu()
{

    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                  Welcome TO My phone book                    *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t1) list record\n\n");
    printf("\t\t\t2) Add person\n\n");
    printf("\t\t\t3) Update person\n\n");
    printf("\t\t\t4) Search person DetailsRemove person\n\n");
    printf("\t\t\t5) Remove person\n\n");
    printf("\t\t\t6) Delete all contacts\n\n");
    printf("\t\t\t7) exit Phonebook\n\n\n");

}

void phone_list_record()
{
    system("cls");
    FILE *pb;
    pb = fopen("phone_book", "rb");

    if(pb == NULL)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tError in file opening, places try again !\n");
        printf("\t\t\t\tPress any key to continue....\n");
        return;
    }
    else
    {
        parson p;
        printf("\n\t\t\t\t******************************************************************************\n");
        printf("\t\t\t\t*                  Here is all records listed in phonebook                   *\n");
        printf("\t\t\t\t******************************************************************************\n\n\n");
        printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    SEX\t\t             EMAIL\n");
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        fseek(pb,-(sizeof(p)*15000L),2);
        while(fread(&p, sizeof(p), 1, pb)== 1)
        {
            int i, len1, len2, len3, len4;
            len1 = 40 - strlen(p.name);
            len2 = 19 - strlen(p.country_code);
            len3 = 15;
            len4 = 21 - strlen(p.sex);
            printf("%s",p.name);
            for(i=0; i<len1; i++)
            {
                printf(" ");
            }
            printf("%s",p.country_code);
            for(i=0; i<len2; i++)
            {
                printf(" ");
            }
            printf("%ld",p.phone_number);
            for(i=0; i<len3; i++)
            {
                printf(" ");
            }
            printf("%s",p.sex);
            for(i=0; i<len4; i++)
            {
                printf(" ");
            }
            printf("%s",p.email);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(pb);
        printf("\n\n\t\t\t\t\t\tPress any key to continue....");
    }

}
void add_contact()
{
    system("cls");

    FILE *pb;
    pb = fopen("phone_book", "ab+");
    if(pb == NULL)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tError in file opening, places try again !\n");
        printf("\t\t\t\tPress any key to continue....");
        return;
    }
    else
    {
        parson p;
        input_function(&p);
        fwrite(&p, sizeof(p), 1, pb);
        fflush(stdin);
        fclose(pb);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tNew contact added Successfully\n");
        printf("\t\t\t\tPress any key to continue....");
    }

}

void input_function(parson *p)
{
    system("cls");

    printf("\n\t\t\t\t******************************************************************************\n");
    printf("\t\t\t\t*                           Here is add new phonebook                          *\n");
    printf("\t\t\t\t******************************************************************************\n\n\n");

    printf("\t\t\t\t\t\t\tEnter Name : ");
    scanf("%[^\n]s",p->name);

    printf("\t\t\t\t\t\t\tEnter country code : ");
    scanf("%s",p->country_code);

    printf("\t\t\t\t\t\t\tEnter phone number : ");
    scanf("%ld",&p->phone_number);

    printf("\t\t\t\t\t\t\tEnter gender :");
    scanf("%s",p->sex);

    printf("\t\t\t\t\t\t\tEnter email : ");
    scanf("%s",p->email);

}

void remove_contact_all()
{
    system("cls");
    remove("./phone_book");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tAll data in the phonebook deleted successfully\n");
    printf("\t\t\t\tPress any key to continue ...");

}

void search_contact()
{
    long int search_number;
    printf("\nEnter Phone number of the person you want to search : ");
    scanf("%ld",&search_number);
    FILE *pb;
    pb = fopen("phone_book", "rb");
    if (pb == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....");
        return;
    }
    else
    {
        int count = 0;
        parson p;
        fseek(pb,-(sizeof(p)),2);
        while (fread(&p, sizeof(p), 1, pb)==1)
        {
            if (p.phone_number == search_number)
            {
                printf("  NAME\t\t\t\t   COUNTRY CODE\t\t    PHONE NO\t\t    SEX\t\t             EMAIL\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");

                int i, len1, len2, len3, len4;
                len1 = 40 - strlen(p.name);
                len2 = 19 - strlen(p.country_code);
                len3 = 15;
                len4 = 21 - strlen(p.sex);
                printf("%s",p.name);
                for(i=0; i<len1; i++)
                {
                    printf(" ");
                }
                printf("%s",p.country_code);
                for(i=0; i<len2; i++)
                {
                    printf(" ");
                }
                printf("%ld",p.phone_number);
                for(i=0; i<len3; i++)
                {
                    printf(" ");
                }
                printf("%s",p.sex);
                for(i=0; i<len4; i++)
                {
                    printf(" ");
                }
                printf("%s",p.email);
                count++;
                break;
            }
            else continue;
        }
        if(count == 0)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tPerson is not in the Phonebook\n");
        }
        fflush(stdin);
        fclose(pb);
        printf("\n\t\t\t\tPress any key to continue....");
    }

}

void update_contact()
{
     system("cls");
     long int update_number;
     printf("\n\n\n\n\n\n\n\n\n\n\t\tEnter Phone number of the person you want to update details : ");
     scanf("%ld",&update_number);
     FILE *pb, *temp;
     pb = fopen("phone_book", "rb");
     temp = fopen("temp", "wb+");
     if(pb == NULL)
     {
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tError in file opening, Plz try again !\n");
        printf("\t\t\t\tPress any key to continue....");
        return;
     }
     else
     {
          int count = 0;
          parson p;
          while(fread(&p, sizeof(p), 1, pb)== 1)
          {
               if (p.phone_number == update_number)
               {
                    input_function(&p);
                    fwrite(&p, sizeof(p), 1, temp);
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tData updated successfully\n");
                    count = 1;
               }

               else fwrite(&p,sizeof(p),1,temp);
               fflush(stdin);
          }
           if(count == 0)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tNo record found for %ld number\n",update_number);
        }
        fclose(pb);
        fclose(temp);
        remove("phone_book");
        rename("temp","phone_book");
        fflush(stdin);
        printf("\n\t\t\t\tPress any key to continue....");

     }

}

void remove_contact()
{
     system("cls");
     long int remove_number;
     printf("\nEnter Phone number of the person you want to update details : ");
     scanf("%ld",&remove_number);
     FILE *pb, *temp;
     pb = fopen("phone_book", "rb");
     temp = fopen("temp", "wb+");
     if(pb == NULL)
     {
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tError in file opening, Plz try again !\n");
        printf("\t\t\t\tPress any key to continue....");
        return;
     }
     else
     {
          int count = 0;
          parson p;
        while(fread(&p, sizeof(p), 1, pb)== 1)
        {
            if(p.phone_number == remove_number)
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tPerson removed successfully\n");
                count = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(count == 0)
        {
             system("cls");
             printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tNo record found for %ld number\n",remove_number);
        }
        fclose(pb);
        fclose(temp);
        remove("phone_book");
        rename("temp","phone_book");
        fflush(stdin);
        printf("\t\t\t\tPress any key to continue....");
     }

}
