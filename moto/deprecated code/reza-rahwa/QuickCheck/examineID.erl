%%
%%  Author(s): Rahwa Bahta, Reza Moussavi
%%

-module(examineID).
-compile(export_all).
-include_lib("eqc/include/eqc.hrl").

-record(bitstype,{id, increase, panic, right, left, front,rear}).

%% Evaluate ID of diferent possible messages examined by C code
prop_inputID()->
	?FORALL(Msg, gen_msg(),
		parse_two_bits(msg_to_binary(Msg))== 
			test_msg_handler_examineID:test(Msg#bitstype.id,
			Msg#bitstype.increase,Msg#bitstype.panic,
			Msg#bitstype.left,Msg#bitstype.right,
			Msg#bitstype.front,Msg#bitstype.rear)).

%% get a message in tye of record and give an associated binary
msg_to_binary(Msg)->
	Id=Msg#bitstype.id,
	Inc=Msg#bitstype.increase,
	Pan=Msg#bitstype.panic,
	Le=Msg#bitstype.left,
	Ri=Msg#bitstype.right,
	Fr=Msg#bitstype.front,
	Re=Msg#bitstype.rear,
	<<Id:2, Inc:1, Pan:1, Ri:1, Le:1, Fr:1, Re:1>>.

%% generate random message in a form of record
gen_msg()->
	Msg=#bitstype{id = choose(0,3),
		increase= choose(0,1), 
		panic= choose(0,1),
		right= choose(0,1),
		left= choose(0,1),
		front= choose(0,1),
		rear= choose(0,1)},
	Msg.

%% return two most left bits of binary message
parse_two_bits(Bin)->
	<<Bits:2,_Rest:6>>=Bin,
	Bits.
