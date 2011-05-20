%% QuickCheck test created by Magnus Bergqvist
%% due to the fact that the nature of the moto_map
%% function makes it hard to test with CUnit tests.

-module(moto_driver_functions_erl).
-compile(export_all).
-include_lib("eqc/include/eqc.hrl").

test(map)->                                            
    ?FORALL({Actual,Lower,Upper},
	    {choose(1000,2000),choose(1001,1500),choose(1500,1999)},
	    begin
	       ReturnVal = moto_driver_functions:moto_map(Actual,Lower,Upper),
	       (ReturnVal >= Lower) andalso (ReturnVal =< Upper)
	    end
).
