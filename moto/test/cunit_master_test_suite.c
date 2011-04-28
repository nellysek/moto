#ifdef MASTER_TEST_SUITE

#include "CUnit/CUnit.h"
#include "cunit_moto_msg_handler.h"

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
