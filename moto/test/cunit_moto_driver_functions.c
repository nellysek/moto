<<<<<<< HEAD
/*Created by Magnus Bergqvist*/ /*Extent by Bishare Sufi*/
/* compile with something like this:
    gcc cunit_moto_driver_functions.c ../src/moto_driver_functions.c -DPC 
=======
/*!
 * @file cunit_moto_driver_functions.c
 * @brief cunit tests for moto_driver_functions.c
 * @date 2011-04-25
 * @author Magnus Bergqvist
 * @version 5
 * @history 2011-04-07 - created first draft \n
            2011-04-15 - adjusted it for new moto_driver_functions.c \n
            2011-04-18 - updated and new tests added
            2011-04-23 - new tests added, auto adjustment possibilities \n
                         to code changes was added
            2011-04-25 - new tests added and minor adjustments to other
 * @details compile with something like this: \n
    gcc cunit_moto_driver_functions.c cunit_stubs.c \n
    ../src/moto_driver_functions.c -DPC \n
>>>>>>> bc1dd8bcc56d44bbff2349bf5cb4a9da3de3e268
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
 

/* Variables to temporary store the values for comparsion in */ 
int rightP;
int leftP;
int frontP;
int rearP;

/* 
 * A function that eases up the work of storing motor signal values in \n
 * the temporary variables in a convenient way
 */
void temp_copy(void){
    rightP = rightPulse;
    leftP = leftPulse;
    frontP = frontPulse;
    rearP = rearPulse;
}

/* 
 * test_moto_startMotors checks so that expected predefined 
 * values are returned
 */
void test_moto_startMotors(void){

    moto_startMotors();
    CU_ASSERT(rightPulse==IDLE_SPEED);
    CU_ASSERT(leftPulse==IDLE_SPEED);
    CU_ASSERT(frontPulse==IDLE_SPEED);
    CU_ASSERT(rearPulse==IDLE_SPEED);
}

/* 
 * test_moto_stopMotors checks so that expected predefined 
 * values are returned
 */
void test_moto_stopMotors(void){

    moto_stopMotors();
    CU_ASSERT(rightPulse==STOP_PULSE);
    CU_ASSERT(leftPulse==STOP_PULSE);
    CU_ASSERT(frontPulse==STOP_PULSE);
    CU_ASSERT(rearPulse==STOP_PULSE);
}

/* 
 * test_moto_increaseAllNormal checks so that expected predefined 
 * values are returned
 */
void test_moto_increaseAllNormal(void){

    moto_startMotors();
    temp_copy(); /*copy all motor values to temp variables*/

    moto_increaseAllNormal();

    CU_ASSERT(rightPulse == rightP + NORMAL_STEP);
    CU_ASSERT(leftPulse == leftP + NORMAL_STEP);
    CU_ASSERT(frontPulse == frontP + NORMAL_STEP);
    CU_ASSERT(rearPulse == rearP + NORMAL_STEP);
    
    /*
     * Set all motor pulses close to an upper value and see if the
     * logic will keep the value of exceeding it's maximum.
     */
    rightPulse = MAX_PULSE_RIGHT - (NORMAL_STEP * 2);
    leftPulse = MAX_PULSE_LEFT - (NORMAL_STEP * 2);
    frontPulse = MAX_PULSE_FRONT - (NORMAL_STEP * 2);
    rearPulse = MAX_PULSE_REAR - (NORMAL_STEP * 2);
     
    temp_copy();
          
    moto_increaseAllNormal();
    CU_ASSERT(rightPulse == rightP + NORMAL_STEP);
    CU_ASSERT(leftPulse == leftP + NORMAL_STEP);
    CU_ASSERT(frontPulse == frontP + NORMAL_STEP);
    CU_ASSERT(rearPulse == rearP + NORMAL_STEP);
    
    temp_copy();
    
    moto_increaseAllNormal();
    CU_ASSERT(rightPulse == MAX_PULSE_RIGHT);
    CU_ASSERT(leftPulse == MAX_PULSE_LEFT);
    CU_ASSERT(frontPulse == MAX_PULSE_FRONT);
    CU_ASSERT(rearPulse == MAX_PULSE_REAR);
    
    moto_increaseAllNormal();
    CU_ASSERT(rightPulse == MAX_PULSE_RIGHT);
    CU_ASSERT(leftPulse == MAX_PULSE_LEFT);
    CU_ASSERT(frontPulse == MAX_PULSE_FRONT);
    CU_ASSERT(rearPulse == MAX_PULSE_REAR);
}
/* 
 * test_moto_decreaseAllNormal checks so that expected predefined 
 * values are returned
 */
void test_moto_decreaseAllNormal(void){

    temp_copy();

    moto_decreaseAllNormal();
    CU_ASSERT(rightPulse == rightP - NORMAL_STEP);
    CU_ASSERT(leftPulse == leftP - NORMAL_STEP);
    CU_ASSERT(frontPulse == frontP - NORMAL_STEP);
    CU_ASSERT(rearPulse == rearP - NORMAL_STEP);
    
    rightPulse = MIN_PULSE_RIGHT + (NORMAL_STEP * 2);
    leftPulse = MIN_PULSE_LEFT + (NORMAL_STEP * 2);
    frontPulse = MIN_PULSE_FRONT + (NORMAL_STEP * 2);
    rearPulse = MIN_PULSE_REAR + (NORMAL_STEP * 2);
     
    temp_copy();
          
    moto_decreaseAllNormal();
    CU_ASSERT(rightPulse == rightP - NORMAL_STEP);
    CU_ASSERT(leftPulse == leftP - NORMAL_STEP);
    CU_ASSERT(frontPulse == frontP - NORMAL_STEP);
    CU_ASSERT(rearPulse == rearP - NORMAL_STEP);
    
    temp_copy();
    
    moto_decreaseAllNormal();
    CU_ASSERT(rightPulse == MIN_PULSE_RIGHT);
    CU_ASSERT(leftPulse == MIN_PULSE_LEFT);
    CU_ASSERT(frontPulse == MIN_PULSE_FRONT);
    CU_ASSERT(rearPulse == MIN_PULSE_REAR);
    
    moto_decreaseAllNormal();
    CU_ASSERT(rightPulse == MIN_PULSE_RIGHT);
    CU_ASSERT(leftPulse == MIN_PULSE_LEFT);
    CU_ASSERT(frontPulse == MIN_PULSE_FRONT);
    CU_ASSERT(rearPulse == MIN_PULSE_REAR);

}

<<<<<<< HEAD
/*added motor tests asserts by Bishare Sufi*/

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

void test_moto_rotateLeft(void){

     moto_rotateLeft();
     CU_ASSERT(leftPulse == 92);
     CU_ASSERT(rightPulse == 92);
     CU_ASSERT(frontPulse == 88);
     CU_ASSERT(rearPulse == 88);

}

void test_moto_rotateRight(void){

     moto_rotateRight();
     CU_ASSERT(leftPulse == 90);
     CU_ASSERT(rightPulse == 90);
     CU_ASSERT(frontPulse == 90);
     CU_ASSERT(rearPulse == 90);

}

void test_moto_increaseAllNormal(void){

     moto_increaseAllNormal();
     CU_ASSERT(rightPulse == 92);
     CU_ASSERT(leftPulse == 92);
     CU_ASSERT(frontPulse == 92);
     CU_ASSERT(rearPulse == 92);

}

void test_moto_increaseAllPanic(void){

     moto_increaseAllPanic();
     CU_ASSERT(rightPulse == 96);
     CU_ASSERT(leftPulse == 96);
     CU_ASSERT(frontPulse == 96);
     CU_ASSERT(rearPulse == 96);

}

void test_moto_decreaseAllNormal(void){

     moto_decreaseAllNormal();
     CU_ASSERT(rightPulse == 94);
     CU_ASSERT(leftPulse == 94);
     CU_ASSERT(frontPulse == 94);
     CU_ASSERT(rearPulse == 94);

=======
void test_moto_increaseAllPanic(void){

    temp_copy(); /*copy all motor values to temp variables*/
    moto_increaseAllPanic();

    CU_ASSERT(rightPulse == rightP + PANIC_STEP);
    CU_ASSERT(leftPulse == leftP + PANIC_STEP);
    CU_ASSERT(frontPulse == frontP + PANIC_STEP);
    CU_ASSERT(rearPulse == rearP + PANIC_STEP);
    
    /*
     * Set all motor pulses close to an upper value and see if the
     * logic will keep the value of exceeding it's maximum.
     */
    rightPulse = MAX_PULSE_RIGHT - (PANIC_STEP * 2);
    leftPulse = MAX_PULSE_LEFT - (PANIC_STEP * 2);
    frontPulse = MAX_PULSE_FRONT - (PANIC_STEP * 2);
    rearPulse = MAX_PULSE_REAR - (PANIC_STEP * 2);
     
    temp_copy();
          
    moto_increaseAllPanic();
    CU_ASSERT(rightPulse == rightP + PANIC_STEP);
    CU_ASSERT(leftPulse == leftP + PANIC_STEP);
    CU_ASSERT(frontPulse == frontP + PANIC_STEP);
    CU_ASSERT(rearPulse == rearP + PANIC_STEP);
    
    temp_copy();
    
    moto_increaseAllPanic();
    CU_ASSERT(rightPulse == MAX_PULSE_RIGHT);
    CU_ASSERT(leftPulse == MAX_PULSE_LEFT);
    CU_ASSERT(frontPulse == MAX_PULSE_FRONT);
    CU_ASSERT(rearPulse == MAX_PULSE_REAR);
    
    moto_increaseAllPanic();
    CU_ASSERT(rightPulse == MAX_PULSE_RIGHT);
    CU_ASSERT(leftPulse == MAX_PULSE_LEFT);
    CU_ASSERT(frontPulse == MAX_PULSE_FRONT);
    CU_ASSERT(rearPulse == MAX_PULSE_REAR);
>>>>>>> bc1dd8bcc56d44bbff2349bf5cb4a9da3de3e268
}

void test_moto_decreaseAllPanic(void){

<<<<<<< HEAD
     moto_decreaseAllPanic();
     CU_ASSERT(rightPulse == 90);
     CU_ASSERT(leftPulse == 90);
     CU_ASSERT(frontPulse == 90);
     CU_ASSERT(rearPulse == 90);

}

void test_moto_increaseLeftNormal(void){
 
     moto_increaseLeftNormal();
     CU_ASSERT(leftPulse == 92);

}

void test_moto_increaseRightNormal(void){

     moto_increaseRightNormal();
     CU_ASSERT(rightPulse == 92);

}

void test_moto_increaseFrontNormal(void){

     moto_increaseFrontNormal();
     CU_ASSERT(frontPulse == 92);

}

void test_moto_increaseRearNormal(void){

     moto_increaseRearNormal();
     CU_ASSERT(rearPulse == 92);

}

void test_moto_increaseLeftPanic(void){

     moto_increaseLeftPanic();
     CU_ASSERT(leftPulse == 96);

}

void test_moto_increaseRightPanic(void){

     moto_increaseRightPanic();
     CU_ASSERT(rightPulse == 96);

}

void test_moto_increaseFrontPanic(void){

     moto_increaseFrontPanic();
     CU_ASSERT(frontPulse == 96);

}

void test_moto_increaseRearPanic(void){

     moto_increaseRearPanic();
     CU_ASSERT(rearPulse == 96);

}

void test_moto_decreaseLeftNormal(void){

     moto_decreaseLeftNormal();
     CU_ASSERT(leftPulse == 94);
     
}

void test_moto_decreaseRightNormal(void){

     moto_decreaseRightNormal();
     CU_ASSERT(rightPulse == 94);

}

void test_moto_decreaseFrontNormal(void){

     moto_decreaseFrontNormal();
     CU_ASSERT(frontPulse == 94);

}

void test_moto_decreaseRearNormal(void){

     moto_decreaseRearNormal();
     CU_ASSERT(rearPulse == 94);

}

void test_moto_decreaseLeftPanic(void){

     moto_decreaseLeftPanic();
     CU_ASSERT(leftPulse == 90);

}

void test_moto_decreaseRightPanic(void){

     moto_decreaseRightPanic();
     CU_ASSERT(rightPulse == 90);

}

void test_moto_decreaseFrontPanic(void){

     moto_decreaseFrontPanic();
     CU_ASSERT(frontPulse == 90);

}

void test_moto_decreaseRearPanic(void){

     moto_decreaseRearPanic();
     CU_ASSERT(rearPulse == 90);

}

void test_printMotorStatus(void){

     printMotorStatus();
    // CU_ASSERT(printf(leftPulse) == 90);
     CU_ASSERT(printf(rightPulse,leftPulse) == 90);
    // CU_ASSERT(printf(frontPulse) == 90);
     CU_ASSERT(printf(frontPulse,rearPulse) == 90);

}

void test_sendMsg(void){

     sendMsg();
     CU_ASSERT(currentPulse(rightPulse) == 90);
     CU_ASSERT(currentPulse(leftPulse) == 90);
     CU_ASSERT(currentPulse(frontPulse) == 90);
     CU_ASSERT(currentPulse(rearPulse) == 90);

}


/*check_add_ok() gives a print_out on the screen when a test suite or a test
has been created, the char** passed to this function should always be in the 
style:
    suite "suite name"
    test "test name"*/
=======
    temp_copy();

    moto_decreaseAllPanic();
    CU_ASSERT(rightPulse == rightP - PANIC_STEP);
    CU_ASSERT(leftPulse == leftP - PANIC_STEP);
    CU_ASSERT(frontPulse == frontP - PANIC_STEP);
    CU_ASSERT(rearPulse == rearP - PANIC_STEP);
    
    rightPulse = MIN_PULSE_RIGHT + (PANIC_STEP * 2);
    leftPulse = MIN_PULSE_LEFT + (PANIC_STEP * 2);
    frontPulse = MIN_PULSE_FRONT + (PANIC_STEP * 2);
    rearPulse = MIN_PULSE_REAR + (PANIC_STEP * 2);
     
    temp_copy();
          
    moto_decreaseAllPanic();
    CU_ASSERT(rightPulse == rightP - PANIC_STEP);
    CU_ASSERT(leftPulse == leftP - PANIC_STEP);
    CU_ASSERT(frontPulse == frontP - PANIC_STEP);
    CU_ASSERT(rearPulse == rearP - PANIC_STEP);
    
    temp_copy();
    
    moto_decreaseAllPanic();
    CU_ASSERT(rightPulse == MIN_PULSE_RIGHT);
    CU_ASSERT(leftPulse == MIN_PULSE_LEFT);
    CU_ASSERT(frontPulse == MIN_PULSE_FRONT);
    CU_ASSERT(rearPulse == MIN_PULSE_REAR);
    
    moto_decreaseAllPanic();
    CU_ASSERT(rightPulse == MIN_PULSE_RIGHT);
    CU_ASSERT(leftPulse == MIN_PULSE_LEFT);
    CU_ASSERT(frontPulse == MIN_PULSE_FRONT);
    CU_ASSERT(rearPulse == MIN_PULSE_REAR);

}

/*
 * check_add_ok() gives a print_out on the screen when a test suite or a test
 * has been created, the char** passed to this function should always be in
 * the style:
 *    suite "suite name"
 *    test "test name"
 */
>>>>>>> bc1dd8bcc56d44bbff2349bf5cb4a9da3de3e268
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
    check_add_ok("Suite start_stop_motors");

    CU_add_test(start_stop, "Test start motors ", test_moto_startMotors);
    check_add_ok("Test test_moto_startMotors");
    
    CU_add_test(start_stop, "Test stop motors ", test_moto_stopMotors);
    check_add_ok("Test test_moto_stopMotors");

/*added motor tests by Bishare Sufi*/

<<<<<<< HEAD
    CU_add_test(start_stop, "Test moto hover ", test_moto_hover);
    check_add_ok("Test test_moto_hover"); 

    CU_add_test(start_stop, "Test go forward ", test_moto_goForward);
    check_add_ok("Test test_go_forward");

    CU_add_test(start_stop, "Test go backward ", test_moto_goBackward);
    check_add_ok("Test test_go_backward");

    CU_add_test(start_stop, "Test strafeRight ", test_moto_strafeRight);
    check_add_ok("Test test_strafeRight");
=======
    /* Add appropriate test functions to the start_stop suite */
    CU_add_test(start_stop, "test_moto_startMotors", test_moto_startMotors);
    check_add_ok("test test_moto_startMotors");
>>>>>>> bc1dd8bcc56d44bbff2349bf5cb4a9da3de3e268
    
    CU_add_test(start_stop, "Test strafeLeft ", test_moto_strafeLeft);
    check_add_ok("Test test_strafeLeft");

    CU_add_test(start_stop, "Test rotateLeft ", test_moto_rotateLeft);
    check_add_ok("Test test_rotate_left");

    CU_add_test(start_stop, "Test rotateRight ", test_moto_rotateRight);
    check_add_ok("Test test_rotate_right");
    
<<<<<<< HEAD
    CU_add_test(start_stop, "Test increase all normal ", test_moto_increaseAllNormal);
    check_add_ok("Test test_increase_all_normal");

    CU_add_test(start_stop, "Test increase all panic ", test_moto_increaseAllPanic);
    check_add_ok("Test test_increase_all_panic");

    CU_add_test(start_stop, "Test decrease all normal ", test_moto_decreaseAllNormal);
    check_add_ok("Test test_decrease_all_normal");

    CU_add_test(start_stop, "Test decrease all panic ", test_moto_decreaseAllPanic);
    check_add_ok("Test test_decrease_all_panic");

    CU_add_test(start_stop, "Test increaseLeftNormal ", test_moto_increaseLeftNormal);
    check_add_ok("Test test_increase_left_normal");

    CU_add_test(start_stop,"Test increaseRightNormal",test_moto_increaseRightNormal);
    check_add_ok("Test test_increase_right_normal");

    CU_add_test(start_stop,"Test increaseFrontNormal",test_moto_increaseFrontNormal);
    check_add_ok("Test test_increase_front_normal");

    CU_add_test(start_stop,"Test increaseRearNormal ", test_moto_increaseRearNormal);
    check_add_ok("Test test_increase_rear_normal"); 

    CU_add_test(start_stop, "Test increaseLeftPanic ", test_moto_increaseLeftPanic);
    check_add_ok("Test test_increase_left_panic");

    CU_add_test(start_stop, "Test increaseRightPanic ", test_moto_increaseRightPanic);
    check_add_ok("Test test_increase_right_panic");

    CU_add_test(start_stop, "Test increaseFrontPanic ", test_moto_increaseFrontPanic);
    check_add_ok("Test test_increase_front_panic");

    CU_add_test(start_stop, "Test increaseRearPanic ", test_moto_increaseRearPanic);
    check_add_ok("Test test_increase_rear_panic");   

    CU_add_test(start_stop, "Test decreaseLeftNormal ", test_moto_decreaseLeftNormal);
    check_add_ok("Test test_decrease_left_normal");

    CU_add_test(start_stop, "Test decreaseRightNormal ", test_moto_decreaseRightNormal);
    check_add_ok("Test test_decrease_right_normal");

    CU_add_test(start_stop, "Test decreaseFrontNormal ", test_moto_decreaseFrontNormal);
    check_add_ok("Test test_decrease_front_normal");

    CU_add_test(start_stop, "Test decreaseRearNormal ", test_moto_decreaseRearNormal);
    check_add_ok("Test test_decrease_rear_normal");

    CU_add_test(start_stop, "Test decreaseLeftPanic ", test_moto_decreaseLeftPanic);
    check_add_ok("Test test_decrease_left_panic");

    CU_add_test(start_stop, "Test decreaseRightPanic ", test_moto_decreaseRightPanic);
    check_add_ok("Test test_decrease_right_panic");

    CU_add_test(start_stop, "Test decreaseFrontPanic ", test_moto_decreaseFrontPanic);
    check_add_ok("Test test_decrease_front_panic");

    CU_add_test(start_stop, "Test decreaseRearPanic ", test_moto_decreaseRearPanic);
    check_add_ok("Test test_decrease_rear_panic");

    CU_add_test(start_stop, "Test printMotorStatus ", test_printMotorStatus);
    check_add_ok("Test test_print_motor_status");

    CU_add_test(start_stop, "Test sendMsg ", test_sendMsg);
    check_add_ok("Test test_send_MSG");

    CU_console_run_tests();
    CU_cleanup_registry();

=======
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
    
    CU_add_test(increase_decrease_all, "test_moto_increaseAllPanic",
        test_moto_increaseAllPanic);
    check_add_ok("test test_moto_increaseAllPanic");
    
    CU_add_test(increase_decrease_all, "test_moto_decreaseAllPanic",
        test_moto_decreaseAllPanic);
    check_add_ok("test test_moto_decreaseAllPanic");
    
    /*--------------------------------------------------------------------*/

    CU_console_run_tests(); /* control test manually from console */
    //CU_automated_run_tests(); /* run tests automatically */
    //CU_list_tests_to_file(); /* print out to xml-file */
    CU_cleanup_registry(); /* a call to a self explanatory function name ;)*/
>>>>>>> bc1dd8bcc56d44bbff2349bf5cb4a9da3de3e268
}
