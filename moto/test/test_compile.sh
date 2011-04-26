#! /bin/bash
gcc cunit_moto_driver_functions.c cunit_stubs.c ../src/moto_driver_functions.c -DPC -o cunit_moto_driver_functions -lcunit
echo "test compiled"
