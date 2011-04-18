/*!
 * @file cunit_moto_driver_functions.c
 * @brief cunit tests for moto_driver_functions.c
 * @date 2011-04-18
 * @author Magnus Bergqvist
 * @version 3
 * @history 2011-04-07 - created first draft \n
            2011-04-15 - adjusted it for new moto_driver_functions.c \n
            2011-04-18 - updated and new tests added
 * @details compile with something like this: \n
    gcc cunit_moto_driver_functions.c cunit_stubs.c \n
    ../src/moto_driver_functions.c -DPC \n
    -o cunit_moto_driver_functions -lcunit
 */

#include <stdio.h>
#include "CUnit/CUnit.h"
#include "cunit_stubs.h" /* test stubs to replace arduino functions */

#include "../src/moto_driver_functions.h"
/* 
 * moto_driver_functions.h is where right- left- front- and rearPulse 
 * comes from, originating from the tested .c-file
 */



/* 
 * test_moto_startMotors checks so that expected predefined 
 * values are returned
 */
void test_moto_startMotors(void){

    moto_startMotors();
    CU_ASSERT(rightPulse==40);
    CU_ASSERT(leftPulse==40);
    CU_ASSERT(frontPulse==40);
    CU_ASSERT(rearPulse==40);
}

/* 
 * test_moto_stopMotors checks so that expected predefined 
 * values are returned
 */
void test_moto_stopMotors(void){

    moto_stopMotors();
    CU_ASSERT(rightPulse==0);
    CU_ASSERT(leftPulse==0);
    CU_ASSERT(frontPulse==0);
    CU_ASSERT(rearPulse==0);
}

/* 
 * test_moto_increaseAllNormal checks so that expected predefined 
 * values are returned
 */
void test_moto_increaseAllNormal(void){

    int rightP = rightPulse;
    int leftP = leftPulse;
    int frontP = frontPulse;
    int rearP = rearPulse;

    moto_increaseAllNormal();

    CU_ASSERT(rightPulse == rightP + NORMAL_INCREMENT);
    CU_ASSERT(leftPulse == leftP + NORMAL_INCREMENT);
    CU_ASSERT(frontPulse == frontP + NORMAL_INCREMENT);
    CU_ASSERT(rearPulse == rearP + NORMAL_INCREMENT);
}
/* 
 * test_moto_decreaseAllNormal checks so that expected predefined 
 * values are returned
 */
void test_moto_decreaseAllNormal(void){

    int rightP = rightPulse;
    int leftP = leftPulse;
    int frontP = frontPulse;
    int rearP = rearPulse;

    moto_decreaseAllNormal();

    CU_ASSERT(rightPulse == rightP - NORMAL_INCREMENT);
    CU_ASSERT(leftPulse == leftP - NORMAL_INCREMENT);
    CU_ASSERT(frontPulse == frontP - NORMAL_INCREMENT);
    CU_ASSERT(rearPulse == rearP - NORMAL_INCREMENT);
}

/*
 * check_add_ok() gives a print_out on the screen when a test suite or a test
 * has been created, the char** passed to this function should always be in
 * the style:
 *    suite "suite name"
 *    test "test name"
 */
void check_add_ok(char* msg){

    if(CU_get_error() == CUE_SUCCESS){
            fprintf(stdout, "%s created successfully!\n",msg);
    }
    else{
        fprintf(stdout, "failed to create %s\n",msg);
    }
}

/*
 * main() is where the test suites are set up and the tests are added to them
 * This requires that the test functions are created above this point in the
 * file
 */
int main(int argc){
    /* Initialize test registry and act upon the success/failure of it */
    CU_ErrorCode ec = CU_initialize_registry();
    if(ec == CUE_SUCCESS){
        fprintf(stdout, "\ntest register initialized successfully!\n");
    }
    else{
        fprintf(stdout, "Failed to initialize test register");
        return 1;
    }   


    /*--------------------------------------------------------------------*/
    /* Create a test suite for start_stop functions */
    CU_pSuite start_stop = CU_add_suite("start_stop_motors",NULL,NULL);    
    check_add_ok("suite start_stop_motors");

    /* Add appropriate test functions to the start_stop suite */
    CU_add_test(start_stop, "test_moto_startMotors", test_moto_startMotors);
    check_add_ok("test test_moto_startMotors");
    
    CU_add_test(start_stop, "test_moto_stopMotors",
        test_moto_stopMotors);
    check_add_ok("test test_moto_stopMotors");
    
    /*--------------------------------------------------------------------*/
    
    /* Create a test suite for increase/decrease all-functions */
    CU_pSuite increase_decrease_all = 
        CU_add_suite("increase_decrese_all",NULL,NULL);
    check_add_ok("suite increase_decrease_all");
    
    /* Add appropriate test functions to the increase_decrease_all suite */
    CU_add_test(increase_decrease_all, "test_moto_increaseAllNormal",
        test_moto_increaseAllNormal);
    check_add_ok("test test_moto_increaseAllNormal");
    
    CU_add_test(increase_decrease_all, "test_moto_decreaseAllNormal",
        test_moto_decreaseAllNormal);
    check_add_ok("test test_moto_decreaseAllNormal");
    
    /*--------------------------------------------------------------------*/

    CU_console_run_tests(); /* control test manually from console */
    //CU_automated_run_tests(); /* run tests automatically */
    CU_list_tests_to_file(); /* print out to xml-file */
    CU_cleanup_registry(); /* a call to a self explanatory function name ;)*/
}
