
\ rlist ( n - )
.s
fload
.s cr
bottom 464 + rlist
.s

\ 200001D0 : 00 00 00 00 D1 42 00 00 04 65 78 69 14 00 00 00   .....B...exi....    
\ 200001E0 : D5 42 00 00 03 6B 65 79 17 00 00 00 55 5A 00 00   .B...key....UZ..    
\ 200001F0 : 04 65 6D 69 1A 00 00 00 79 5A 00 00 02 63 72 00   .emi....yZ...cr.    
\ 20000200 : 1D 00 00 00 89 49 00 00 05 70 61 72 20 00 00 00   .....I...par ...    
\ 20000210 : 19 5D 00 00 04 77 6F 72 23 00 00 00 5D 4B 00 00   .]...wor#...]K..    
\ 20000220 : 03 64 75 70 26 00 00 00 15 43 00 00 04 64 72 6F   .dup&....C...dro    
\ 20000230 : 29 00 00 00 F5 42 00 00 04 73 77 61 2C 00 00 00   )....B...swa,...    
\ 20000240 : 69 43 00 00 04 6F 76 65 2F 00 00 00 95 43 00 00   iC...ove/....C..    
 
\ next ( adrs count  - adrs + count print: h. at addr)
: next + dup rbyte h. space ;

\ drop at end is optional
\ go (  - )
: go bottom 464 next 4 next 1 next 3 next 4 0 do 1 next loop drop cr ;

