/*Created by Magnus Bergqvist*/ /*Extended by Bishare Sufi*/
/* compile with something like this:
    gcc cunit_moto_driver_functions.c ../src/moto_driver_functions.c -DPC 
    -o cunit_moto_driver_functions -lcunit
*/

#include <stdio.h>
#include "CUnit/CUnit.h"
#include "../src/moto_driver_functions.h"
/*this is where right- left- front- and rearPulse comes from as extern
unsigned chars, originating from the tested .c-file*/

/*test_increaseMotorPulse checks so that expected results are returned, even
when it comes to the higher and lower limits of the spectra*/
void test_moto_startMotors(void){

    moto_startMotors();
    CU_ASSERT(rightPulse==40);
    CU_ASSERT(leftPulse==40);
    CU_ASSERT(frontPulse==40);
    CU_ASSERT(rearPulse==40);
}

void test_moto_stopMotors(void){

    moto_stopMotors();
    CU_ASSERT(rightPulse==0);
    CU_ASSERT(leftPulse==0);
    CU_ASSERT(frontPulse==0);
    CU_ASSERT(rearPulse==0);
}

/*added by Bishare Sufi*/

void test_moto_hover(void){
    
      moto_hover();
      CU_ASSERT(rightPulse == 90);
      CU_ASSERT(leftPulse == 90);
      CU_ASSERT(frontPulse == 90);
      CU_ASSERT(rearPulse == 90);

}

void test_moto_goForward(void){
     
     moto_goForward();
     CU_ASSERT(frontPulse == 88);
     CU_ASSERT(rearPulse == 92);

}

void test_moto_goBackward(void){
     
     moto_goBackward();
     CU_ASSERT(frontPulse == 90);
     CU_ASSERT(rearPulse == 90);

} 

void test_moto_strafeRight(void){
     
     moto_strafeRight();
     CU_ASSERT(leftPulse == 92);
     CU_ASSERT(rightPulse == 88);

}

void test_moto_strafeLeft(void){
     
     moto_strafeLeft();
     CU_ASSERT(leftPulse == 90);
     CU_ASSERT(rightPulse == 90);

}


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

    CU_pSuite start_stop = CU_add_suite("start_stop_motors",NULL,NULL);    
    check_add_ok("Suite start_stop_motors");

    CU_add_test(start_stop, "test_moto_startMotors ", test_moto_startMotors);
    check_add_ok("Test test_moto_startMotors");
    
    CU_add_test(start_stop, "test_moto_stopMotors ", test_moto_stopMotors);
    check_add_ok("Test test_moto_stopMotors");

/* added hover, go forward, backward, strafe_Right/Left motor tests by Bishare */

    CU_add_test(start_stop, "test_moto_hover ", test_moto_hover);
    check_add_ok("Test test_moto_hover"); 

    CU_add_test(start_stop, "test go forward ", test_moto_goForward);
    check_add_ok("Test test_go_forward");

    CU_add_test(start_stop, "test go backward ", test_moto_goBackward);
    check_add_ok("Test test_go_backward");

    CU_add_test(start_stop, "test strafeRight ", test_moto_strafeRight);
    check_add_ok("Test test_strafeRight");
    
    CU_add_test(start_stop, "test strafeLeft ", test_moto_strafeLeft);
    check_add_ok("Test test_strafeLeft");
    


    CU_console_run_tests();
    CU_cleanup_registry();
}
