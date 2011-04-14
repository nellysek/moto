/*@uthor Bishare_sufi*/
#include <stdio.h>
#include "CUnit/CUnit.h"
#include "extract_states.h"

/* run cunit with gcc cunit_extractStates.c exract_states.c -o 
cunit_extractStates  -lcunit */   /* ./cunit_extractStates */
/* when you compile this comment the main in extract_states.c */

void test_motors(void){

/*asserts for generate function */
/* I just wanted to check if it was possible to test my own code */
/*asserts for 
  generate function I just check if the code is reacting as expected*/

CU_ASSERT(generate_value_Con_motor(FORWARD) == FORWARD); 
CU_ASSERT(generate_value_Con_motor(BACKWARD) == BACKWARD);
CU_ASSERT(generate_value_Con_motor(TURN_LEFT) == TURN_LEFT);
CU_ASSERT(generate_value_Con_motor(TURN_RIGHT) == TURN_RIGHT);

}

void test_motors1(void){

 /*asserts for 
   generate function I just check if the code is reacting as expected*/

CU_ASSERT(generate_value_Pan_motor(FORWARD) == FORWARD);
CU_ASSERT(generate_value_Pan_motor(BACKWARD) == BACKWARD);
CU_ASSERT(generate_value_Pan_motor(TURN_LEFT) == TURN_LEFT);
CU_ASSERT(generate_value_Pan_motor(TURN_RIGHT) == TURN_RIGHT);

/*asserts for 
  generate function I just check if the code is reacting as expected*/ 

CU_ASSERT(generate_value_Pan_motor(INCREASE_MOTOR | LEFT_MOTOR) == INCREASE_MOTOR | LEFT_MOTOR); 
CU_ASSERT(generate_value_Pan_motor(INCREASE_MOTOR | RIGHT_MOTOR) == INCREASE_MOTOR | RIGHT_MOTOR);
CU_ASSERT(generate_value_Pan_motor(INCREASE_MOTOR | LEFT_MOTOR | RIGHT_MOTOR) == INCREASE_MOTOR | LEFT_MOTOR | RIGHT_MOTOR);

CU_ASSERT(generate_value_Pan_motor(INCREASE_MOTOR | FRONT_MOTOR) == INCREASE_MOTOR | FRONT_MOTOR);
CU_ASSERT(generate_value_Pan_motor(INCREASE_MOTOR | REAR_MOTOR) == INCREASE_MOTOR | REAR_MOTOR);
CU_ASSERT(generate_value_Pan_motor(INCREASE_MOTOR | FRONT_MOTOR | REAR_MOTOR) == INCREASE_MOTOR | FRONT_MOTOR | REAR_MOTOR);

/*asserts for 
generate function I just check if the code is reacting as expected*/ 

CU_ASSERT(generate_value_Pan_motor(DECREASE_MOTOR | LEFT_MOTOR) == DECREASE_MOTOR | LEFT_MOTOR); 
CU_ASSERT(generate_value_Pan_motor(DECREASE_MOTOR | RIGHT_MOTOR) == DECREASE_MOTOR | RIGHT_MOTOR);
CU_ASSERT(generate_value_Pan_motor(DECREASE_MOTOR | LEFT_MOTOR | RIGHT_MOTOR) == DECREASE_MOTOR | LEFT_MOTOR | RIGHT_MOTOR);

CU_ASSERT(generate_value_Pan_motor(DECREASE_MOTOR | FRONT_MOTOR) == DECREASE_MOTOR | FRONT_MOTOR);
CU_ASSERT(generate_value_Pan_motor(DECREASE_MOTOR | REAR_MOTOR) == DECREASE_MOTOR | REAR_MOTOR);
CU_ASSERT(generate_value_Pan_motor(DECREASE_MOTOR | FRONT_MOTOR | REAR_MOTOR) == DECREASE_MOTOR | FRONT_MOTOR | REAR_MOTOR);

}

void test_motors2(void){

/*asserts for 
  generate function I just check if the code is reacting as expected*/
 
CU_ASSERT(generate_value_Inc_motor(INCREASE_MOTOR | LEFT_MOTOR) == INCREASE_MOTOR | LEFT_MOTOR);
CU_ASSERT(generate_value_Inc_motor(INCREASE_MOTOR | RIGHT_MOTOR) == INCREASE_MOTOR | RIGHT_MOTOR);
CU_ASSERT(generate_value_Inc_motor(INCREASE_MOTOR | LEFT_MOTOR | RIGHT_MOTOR) == INCREASE_MOTOR | LEFT_MOTOR | RIGHT_MOTOR);

CU_ASSERT(generate_value_Inc_motor(INCREASE_MOTOR | FRONT_MOTOR) == INCREASE_MOTOR | FRONT_MOTOR);
CU_ASSERT(generate_value_Inc_motor(INCREASE_MOTOR | REAR_MOTOR) == INCREASE_MOTOR | REAR_MOTOR);
CU_ASSERT(generate_value_Inc_motor(INCREASE_MOTOR | FRONT_MOTOR | REAR_MOTOR) == INCREASE_MOTOR | FRONT_MOTOR | REAR_MOTOR);

}

void test_motors3(void){

/*asserts for 
  generate function I just check if the code is reacting as expected*/ 

CU_ASSERT(generate_value_Dec_motor(DECREASE_MOTOR | LEFT_MOTOR) == DECREASE_MOTOR | LEFT_MOTOR);
CU_ASSERT(generate_value_Dec_motor(DECREASE_MOTOR | RIGHT_MOTOR) == DECREASE_MOTOR | RIGHT_MOTOR);
CU_ASSERT(generate_value_Dec_motor(DECREASE_MOTOR | LEFT_MOTOR | RIGHT_MOTOR) == DECREASE_MOTOR | LEFT_MOTOR | RIGHT_MOTOR);

CU_ASSERT(generate_value_Dec_motor(DECREASE_MOTOR | FRONT_MOTOR) == DECREASE_MOTOR | FRONT_MOTOR);
CU_ASSERT(generate_value_Dec_motor(DECREASE_MOTOR | REAR_MOTOR) == DECREASE_MOTOR | REAR_MOTOR);
CU_ASSERT(generate_value_Dec_motor(DECREASE_MOTOR | FRONT_MOTOR | REAR_MOTOR) == DECREASE_MOTOR | FRONT_MOTOR | REAR_MOTOR);

}


void test_check(char* msg){
if(CU_get_error() == CUE_SUCCESS){
  fprintf(stdout, "Passed successfully!\n", msg);
}                                                   
else{                                               
     fprintf(stdout, "%s failed\n", msg);
}
}

/* main function for suite test*/

int main(int argc){
CU_ErrorCode erc = CU_initialize_registry();
if(erc == CUE_SUCCESS){
    fprintf(stdout,"\ntest register initialized successfully!\n");  
  }
else{
    fprintf(stdout, "failed to initialize test register");
return;
}

/* add test for the suite */

   CU_pSuite motors = CU_add_suite("Extract states", NULL, NULL);
   test_check("Suite extract_states");

   CU_add_test(motors, "Test motors", test_motors);
   test_check("Test test_motors");

   CU_add_test(motors, "Test motors1", test_motors1);
   test_check("Test test_motors1");

   CU_add_test(motors, "Test motors2", test_motors2);
   test_check("Test test_motors2");

   CU_add_test(motors, "Test motors3", test_motors3);
   test_check("Test test_motors3");


   CU_console_run_tests();
   CU_cleanup_registry();

}
