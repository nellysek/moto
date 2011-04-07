#include <stdio.h>
#include "CUnit/CUnit.h"

/* compile with something like this:  gcc function.c -o finction -lcunit */

int plus_one(int num){
    if(num+1 > 0){
        return num+1;
    }
    else{
        return 0;
    }
}

void test_plus_one(void)
{
    CU_ASSERT(plus_one(0) == 1);
    CU_ASSERT(plus_one(-10) == 0);
    CU_ASSERT(plus_one(-1) == 0);
    CU_ASSERT(plus_one(5) == 6);
}


int main(int argc){

/***************************************************************************/
CU_ErrorCode ec = CU_initialize_registry();    
    if(ec == CUE_SUCCESS){
        fprintf(stdout, "Test Register Initialized Successfully!\n");   
    }
    else{
        fprintf(stdout, "Failed to initialize test register");
        return;
    }    
/***************************************************************************/
    CU_pSuite pS = CU_add_suite("operator_suite",NULL,NULL);    
    if(CU_get_error() == CUE_SUCCESS){
            fprintf(stdout, "Suite Created Successfully!\n");
    }
    else{
        fprintf(stdout, "Failed to create test suite");
        return;
    }
    
/***************************************************************************/
    CU_pTest pT = CU_add_test(pS, "TestPlusOne", test_plus_one);
    if(CU_get_error() == CUE_SUCCESS){
                fprintf(stdout, "Test Added Successfully!\n");
                CU_console_run_tests();
    }
    else{
        fprintf(stdout, "Failed to add test to suite");
        return;
    }
/***************************************************************************/
    CU_cleanup_registry();
}
