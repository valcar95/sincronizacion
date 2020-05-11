#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "list.h"
//#include <time.h>
#include <sys/time.h>
#define NUM_OFFICES 4
#define NUM_LOANS_BY_OFFICE 1000

list_t book_catalog;


typedef struct __thread_params {
 list_t *l;
 int office_number;
 int successfull_count;
 int failed_count;
} thread_params;

void make_loans(void* params);
int main(int argc, char *argv[]){
    
    init_list(&book_catalog);
    init_book_catalog(&book_catalog);
    pthread_t offices[NUM_OFFICES];
    thread_params params[NUM_OFFICES];
        /* Create threads */
    for (int i = 0; i < 4; i++)
    {
        thread_params p= {&book_catalog,i,0,0};
        params[i] = p;

        pthread_create(&offices[i], NULL, &make_loans, &params[i]);
    }

    int successfull_count = 0;
    int failed_count = 0;
    
    for (int j = 0; j < 4; j++)
    {
        pthread_join(offices[j], NULL);

        successfull_count += params[j].successfull_count;
        failed_count += params[j].failed_count;
    }
    
    printf("Total successful loans %d, total failed loans %d \n", successfull_count, failed_count);
    printf("Number of remaining available books %d \n", (TOTAL_BOOKS-successfull_count));
}


void make_loans(void* args) {
    thread_params *params = (thread_params* )args;
    int successful_loans=0;
    int failed_loans=0;

    int seed=(int)rand();
    srand((unsigned) seed);

    printf("Office  %d con seed %d \n",params->office_number,seed);

    for(int i=0; i < NUM_LOANS_BY_OFFICE; i++){
        int book_to_loan = rand() % (9999 + 1 - 0) + 0;
        int loaned=loan_book(params->l,book_to_loan);
        if(loaned==1){
            successful_loans++;
        }
        else{
            failed_loans++;
        }
        
    }

    params->failed_count=failed_loans;
    params->successfull_count=successful_loans;

    printf("Office  %d has finished its workload, successful loans %d, failed loans %d \n",params->office_number,successful_loans,failed_loans);
    
    
}

