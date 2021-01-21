#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct books{
    char title[50];
    char author[50];
    int year;
    float book_rate;
    struct books *next;
};

struct customer{
    char name[50];
    int age;
    float customer_rate;
    struct customer *next;
};

// customer is defined as struct
struct customer *head_customer=NULL;


// book is defined as typedef
typedef struct books book;
book *head_book=NULL;

void display_customer(struct customer *customer_pointer){
    /*
     Simple function, that prints separate element of customer structure
     */

    printf("\n-----------------------------------------");
    printf("\nName of the customer: %s", customer_pointer->name);
    printf("\nAge of the customer: %d", customer_pointer->age);
    printf("\nRating of the customer: %f", customer_pointer->customer_rate);
    printf("\n-----------------------------------------");

}

void display_book(book *current_book){
    /*
     * Simple function, prints separate elements of typedef book
     */
    printf("\n-----------------------------------------");
    printf("\nTitle of book: %s\n",current_book->title);
    printf("Author of the book: %s\n",current_book->author);
    printf("Year the book was written: %d\n",current_book->year);
    printf("User rating of the book: %f",current_book->book_rate);
    printf("\n-----------------------------------------");

}

void add_customer(){
    /*
     * This function, checks that malloc function worked succesfully, then prompts the user for data.
     * Then stores the data into a newly created "node".
     * Then loops through all elements of linked list, untill find the last one with no address of the next node, and assigns it.
     */
    struct customer *temporary_customer;
    struct customer *current_customer;
    temporary_customer = (struct customer*)malloc(sizeof(struct customer));


    if(temporary_customer==NULL){
        printf("No free memory to allocate!\n");
        return;
    }
    else{
        printf("\n-----------------------------------------");

        printf("\nEnter the information about the customer >");

        printf("\nType the name of the customer:");
        scanf("%*c%[^\n]s",temporary_customer->name);

        printf("\nType the age of the customer:");
        scanf("%d%*c",&(temporary_customer->age));


        printf("\nType the rating of this book:");
        scanf("%f%*c",&(temporary_customer->customer_rate));

        printf("\n-----------------------------------------");

        temporary_customer->next=NULL;


        if(head_customer==NULL){
            head_customer = temporary_customer;

        }
        else{
            current_customer = head_customer;
            while(current_customer->next!=NULL){
                current_customer = current_customer->next;
            }
            current_customer->next = temporary_customer;
        }

    }
}

void add_book(){
    /*
     * Works in the same way as add_customer function, the only difference is typedef and struct.
     */
    book *temporary;
    book *book_pointer;
    temporary = (book*)malloc(sizeof(book));

    if(temporary==NULL){
        printf("No free memory to allocate!");
    }
    else{

        printf("\n-----------------------------------------");

        printf("\nEnter the information about the book:");

        printf("\nType the name of the book:");
        scanf("%*c%[^\n]s",temporary->title);

        printf("\nType the author of the book:");
        scanf("%*c%[^\n]s",temporary->author);

        printf("\nType the year of the book:");
        scanf("%d%*c",&(temporary->year));

        printf("\nType the rating of this book:");
        scanf("%f", &(temporary->book_rate));

        printf("\n-----------------------------------------");

        temporary->next=NULL;


        if (head_book==NULL){
            head_book = temporary;
        }
        else{
            book_pointer = head_book;
            while(book_pointer->next != NULL){
                book_pointer = book_pointer->next;
            }
            book_pointer->next=temporary;

        }
    }

}

void show_customers(){
    /*
     * Check that library is full, if True, then loops through it displaying all the customers
     */
    struct customer *temporary;
    if (head_customer==NULL){
        printf("Library is empty, add some books!");
    }
    else{
        temporary = head_customer;
        while (temporary!=NULL){
            display_customer(temporary);
            temporary = temporary->next;
        }
    }
}

void show_books(){
    /*
     * Identical to show_customers function:
     */
    book *temporary_pointer;
    if(head_book == NULL){
        printf("There are no books currently in the library !");
    }
    else{
        temporary_pointer = head_book;
        printf("Books, currently at your disposal are:");
        while (temporary_pointer != NULL){
            display_book(temporary_pointer);
            temporary_pointer = temporary_pointer->next;
        }
    }
}

void update_customer(){
    /*
     * Prompts user for the name of the customer. Then checks for a case when linked list empty.
     * Then loops through linked_list until finds the desired customer.
     * If customer found, user edits him
     * If customer not found, the program returns a message.
     */
    struct customer *temporary_customer;
    char guess[50];
    printf("\nType the name of the customer:");
    scanf("%*c%[^\n]s",guess);
    int count = 0;

    temporary_customer = head_customer;
    if(head_customer==NULL){
        printf("There are no available customers to update\n");
    }
    else if(head_customer!=NULL){
        while (temporary_customer != NULL){
            if (strcmp(temporary_customer->name,guess) == 0){
                count++;
                printf("\nUpdate following information about customer:");

                printf("\nType the name of customer: ");
                scanf("%*c%[^\n]s",temporary_customer->name);

                printf("\nType the age of the customer: ");
                scanf("%d%*c",&(temporary_customer->age));

                printf("\nType the rating of the customer: ");
                scanf("%f",&(temporary_customer->customer_rate));


            }
            temporary_customer = temporary_customer->next;
        }
    }
    if(count<1){
        printf("\nNo customer with this name found!");
    }
}

void update_book(){
    /*
     * Identical to update_customer()
     */
    book *temporary_book;
    char book_name[50];
    int count = 0;

    printf("Write the title of the book you want to update:");
    scanf("%*c%[^\n]s",book_name);

    if(head_book==NULL){
        printf("There are not books in the library to update!\n");
        return;
    }
    else if(head_book!=NULL){
        temporary_book = head_book;
        while (temporary_book!=NULL){
            if( strcmp(book_name,temporary_book->title) == 0 ){
                count++;
                printf("\nEnter the information about the book:");

                printf("\nType the name of the book:");
                scanf("%*c%[^\n]s",temporary_book->title);

                printf("\nType the author of the book:");
                scanf("%*c%[^\n]s",temporary_book->author);

                printf("\nType the year of the book:");
                scanf("%d%*c",&(temporary_book->year));


                printf("\nType the rating of this book:");
                scanf("%f%*c", &(temporary_book->book_rate));

                printf("\nThe book was updated!");

                display_book(temporary_book);
                break;
            }
            temporary_book = temporary_book->next;
        }
        if(count < 1) {
            printf("\nNo book with this name exists in the library!");
        }
    }



    }

void remove_customer(){
    /*
     * This function prompts user for customer name, then checks special cases, where the list is not empty. And if there is only one element
     * After loops through linked list two times, first time to find the desired "node", second time to make pass on the next element of this node to the previous one
     * and delete it dconsequently.
     */
    struct customer *current_customer;
    struct customer *temporary_customer;
    char customer_name[50];
    current_customer = head_customer;

    printf("\nType the name of customer, you want to be removed:");
    scanf("%*c%[^\n]s",customer_name);
    if (head_customer == NULL){
        printf("\nThere are no customers to remove from!");
        return;
    }
    else if(current_customer->next == NULL){
        if(strcmp(current_customer->name,customer_name) == 0){
            printf("\nLucky one:");
            display_customer(current_customer);
            head_customer = NULL;
        }
        else{
            printf("\nThere is no such customer in the list!");
            return;
        }
    }
    else{

        while (current_customer!=NULL){
            if(strcmp(current_customer->name,customer_name) == 0){
                temporary_customer = current_customer;
            }
            current_customer = current_customer->next;
        }

        current_customer = head_customer;

        while (current_customer!=NULL){
            if(current_customer->next == temporary_customer){
                current_customer->next = temporary_customer->next;
                display_customer(current_customer);
                free(current_customer);
                break;
            }
        }
    }


}

void remove_book(){

    char book_name[50];
    printf("Write the title of the book you want to remove:");
    scanf("%*c%[^\n]s",book_name);
    book *temporary_book;
    book *current_book;
    if (head_book==NULL){
        printf("\nLibrary is empty, no books to remove!");
        return;
    }
    else if(head_book->next==NULL){
        printf("\nThere is only one book in the library to delete:");
        if(strcmp(head_book->title,book_name) == 0){
            display_book(head_book);
            head_book->next=NULL;
        }
        else{
            printf("\nThere is no such book in the library!");
            return;
        }
    }
    else{

        temporary_book = head_book;

        while (temporary_book!=NULL){
            if(strcmp(book_name,temporary_book->title) == 0){
                current_book = temporary_book;
                break;
            }
            temporary_book = temporary_book->next;
        }

        temporary_book = head_book;

        while (temporary_book!=NULL){
            if(temporary_book->next == current_book){
                temporary_book->next = current_book->next;
                printf("\nYou deleted following book from library:\n");
                display_book(current_book);
                free(current_book);
                break;
            }
            temporary_book = temporary_book->next;


        }

    }
}



int main(){
    printf("Type a character from 1 to 9\n");
    printf("1 - For adding a book\n");
    printf("2 - For showing all the books\n");
    printf("3 - For updating a book, after finding it by title\n");
    printf("4 - For removing a book, after finding it by title\n");
    printf("5 - For adding a customer\n");
    printf("6 - For showing all the customers\n");
    printf("7 - For updating a customer\n");
    printf("8 - For removing a customer\n");
    printf("9 - For quitting the program\n");

    int integer;
    integer=0;
    while(integer!=9) {
        printf("\n-----------------------------------------");
        printf("\n              Main Menu                  \n:");
        scanf("%d", &integer);
        switch (integer) {
            case 1:
                add_book();
                continue;

            case 2:
                show_books();
                continue;

            case 3:
                update_book();
                continue;

            case 4:
                remove_book();
                continue;

            case 5:
                add_customer();
                continue;

            case 6:
                show_customers();
                continue;

            case 7:
                update_customer();
                continue;

            case 8:
                remove_customer();
                continue;

            case 9:
                exit(0);

            default:
                printf("Type a character from 1 to 9\n");
                printf("1 - For adding a book\n");
                printf("2 - For showing all the books\n");
                printf("3 - For updating a book, after finding it by title\n");
                printf("4 - For removing a book, after finding it by title\n");
                printf("5 - For adding a customer\n");
                printf("6 - For showing all the customers\n");
                printf("7 - For updating a customer\n");
                printf("8 - For removing a customer\n");
                printf("You have to enter a number between 1-9, 9 for quiting.");
                continue;


        }
    }
}