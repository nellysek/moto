/*Skeleton created by Magnus Bergqvist*/
/* This particular set of test cases created by Kristofer Hansson Aspman */
/* compile with something like this:
    gcc cunit_moto_msg_handler.c ../src/moto_msg_handler.c -DPC 
    -o cunit_moto_msg_handler -lcunit
*/

#include <stdio.h>
#include "CUnit/CUnit.h"
#include "cunit_moto_msg_handler.h"

/*Holds the definition of the type msg and the macros INT_TO_BITFIELD(a)
and BITFIELD_TO_CHAR(a)*/
#include "../src/moto_msg_manipulation.h"
/*Includes the tested functions examineID, ...*/
#include "../src/moto_msg_handler.h"

/*test_examineID checks so that the function returns 0 when a properly*/
/* formatted message is sent in as argument to the function */
void test_moto_examineID(void){

    msg binary;
    unsigned char a = 0xa3;
    binary = INT_TO_BITFIELD(&a);
    msg_pointer mp = &binary;
    
    CU_ASSERT(examineID(mp)==0);
}

/*test_examineID_bad_msg checks so that the function returns 1 when the bad*/
/* message (0xF) is sent in as argument to the function */
void test_moto_examineID_bad_msg(void){

    msg binary;
    unsigned char a = 0xF;
    binary = INT_TO_BITFIELD(&a);
    msg_pointer mp = &binary;
    
    CU_ASSERT(examineID(mp)==1);
}

#ifndef MASTER_TEST_SUITE
/*check_add_ok() gives a print_out on the screen when a test suite or a test
has been created, the char** passed to this function should always be in the 
style:
    suite "suite name"
    test "test name"*/
void check_add_ok(char* msg){

    if(CU_get_error() == CUE_SUCCESS){
            fprintf(stdout, "%s created successfully!\n",msg);
    }
    else{
        fprintf(stdout, "failed to create %s\n",msg);
    }
}

int main(int argc){
/***************************************************************************/
    CU_ErrorCode ec = CU_initialize_registry();    
    if(ec == CUE_SUCCESS){
        fprintf(stdout, "\ntest register initialized successfully!\n");   
    }
    else{
        fprintf(stdout, "Failed to initialize test register");
        return;
    }   

/***************************************************************************/
/* add start stop motor tests */

    CU_pSuite msg_handler = CU_add_suite("msg_handler",NULL,NULL);    
    check_add_ok("suite msg_handler");

    CU_add_test(msg_handler, "test_moto_examineID", test_moto_examineID);
    check_add_ok("test test_moto_examineID");
    
    CU_add_test(msg_handler, "test_moto_examineID_bad_msg",
        test_moto_examineID_bad_msg);
    check_add_ok("test test_moto_examineID_bad_msg");
    
    CU_console_run_tests();
    CU_cleanup_registry();
}
#endif
