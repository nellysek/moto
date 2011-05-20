/**
 * Functions:    rightMotorLimitIncrease()
 *               rightMotorLimitDecrease()
 *               leftMotorLimitIncrease()
 *               leftMotorLimitDecrease()
 *               frontMotorLimitIncrease()
 *               frontMotorLimitDecrease()
 *               rearMotorLimitIncrease()
 *               rearMotorLimitDecrease()
 * Author(s):    Magnus Bergqvist
 *
 * Description:  Functions contains the logic
 *               that determines and returns
 *               a valid input value to the motors.
 *               Returned values are calibrated for
 *               the functions corresponding motor.
 *
 * Deprecated due to change in logic when moto_map() was implemented.
 */
 
uint16_t rightMotorLimitIncrease(uint16_t currentPulse,
                                        uint16_t increment){
    if((currentPulse + increment) < MAX_PULSE_RIGHT){
        return (currentPulse + increment);
    }
    else{
        return MAX_PULSE_RIGHT;
    }
}

uint16_t rightMotorLimitDecrease(uint16_t currentPulse,
                                        uint16_t decrement){
    if((currentPulse - decrement) > MIN_PULSE_RIGHT){
        return (currentPulse - decrement);
    }
    else{
        return MIN_PULSE_RIGHT;
    }
}

uint16_t leftMotorLimitIncrease(uint16_t currentPulse,
                                        uint16_t increment){
    if((currentPulse + increment) < MAX_PULSE_LEFT){
        return (currentPulse + increment);
    }
    else{
        return MAX_PULSE_LEFT;
    }
}

uint16_t leftMotorLimitDecrease(uint16_t currentPulse,
                                        uint16_t decrement){
    if((currentPulse - decrement) > MIN_PULSE_LEFT){
        return (currentPulse - decrement);
    }
    else{
        return MIN_PULSE_LEFT;
    }
}

uint16_t frontMotorLimitIncrease(uint16_t currentPulse,
                                        uint16_t increment){
    if((currentPulse + increment) < MAX_PULSE_FRONT){
        return (currentPulse + increment);
    }
    else{
        return MAX_PULSE_FRONT;
    }
}

uint16_t frontMotorLimitDecrease(uint16_t currentPulse,
                                        uint16_t decrement){
    if((currentPulse - decrement) > MIN_PULSE_FRONT){
        return (currentPulse - decrement);
    }
    else{
        return MIN_PULSE_FRONT;
    }
}

uint16_t rearMotorLimitIncrease(uint16_t currentPulse,
                                        uint16_t increment){
    if((currentPulse + increment) < MAX_PULSE_REAR){
        return (currentPulse + increment);
    }
    else{
        return MAX_PULSE_REAR;
    }
}

uint16_t rearMotorLimitDecrease(uint16_t currentPulse,
                                        uint16_t decrement){
    if((currentPulse - decrement) > MIN_PULSE_REAR){
        return (currentPulse - decrement);
    }
    else{
        return MIN_PULSE_REAR;
    }
}
