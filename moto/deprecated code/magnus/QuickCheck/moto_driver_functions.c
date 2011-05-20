#include <math.h>
#include "moto_driver_functions.h"

/* !
 * @author Magnus Bergqvist
 * @function moto_map
 * @param uint16_t, uint16_t, uint16_t
 * @return uint16_t
 * @brief Returns a pulse width value adapted to a specific motor/ESC-pair.
 * @details The map function takes an input value (actual), and upper \n
            and lower boundary values for the wanted output as arguments. \n
            According to these values combined with boundaries for the \n
            systems actual output signals it returns a suitable \n
            value for the calling function to use.
 */
 
int moto_map(int actual, int lowerBoundary, int upperBoundary){    
    /* 
     * step size depending on inner value spectrum 
     * compared to ESC output spectrum
     */
    double steps = (double)(upperBoundary - lowerBoundary) / 
                    (double)(MAX_ESC_PULSE - MIN_ESC_PULSE);
    
    /*
     * Calculating the result and make sure all values start from 
     * lowerBoundary
     */
    double result = lowerBoundary + ((actual-MIN_ESC_PULSE)*steps);
    
    /*
     * modfCrap is a variable to take care of int val. after a modf on result,
     * which we don't care about. We just want the decimal part to get
     * the rounding of the numbers more accurate
     */
    double modfCrap;
    
    /*
     * modfRest will store the decimals from var. result to be used below
     * to determine if the returned value should be rounded up or down
     */
    double modfRest = modf(result, &modfCrap);
    
    /* 
     * final created to get a return variable that conforms with the
     * coding standard and allows final adjustment to the result before
     * it's returned.
     */
    int final;
    
    /* If fractional part of result < 0.5 do nothing */
    if(modfRest < 0.5){
        final = (int)result;
    }
    /* Else add 1 to get a rounding upwards. */
    else{
        final = (int)result + 1;
    }
    
    /* 
     * A final check is performed to see that the result haven't been rounded
     * up or down so that it goes outside the boundaries.
     */   
    if (final >= lowerBoundary && final <= upperBoundary){
        return final;
    }
    else if(final < lowerBoundary){
        return lowerBoundary;
    }
    else{
        return upperBoundary;
    }
}
