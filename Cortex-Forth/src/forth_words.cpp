// forth_words.cpp  wa1tnr
// Tue Sep  3 12:49:22 UTC 2019 0.2.0-alpha.1 non-usart-c-03_sep-aa-  shred: abn-715"
// On branch non-usart-c-03_sep-aa-

/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// #include <Arduino.h>
// #include <SPI.h>
#include "SdFat.h"
// #include "Adafruit_SPIFlash.h"

// #undef WANT_MKDIR_FORTH
// #define WANT_MKDIR_FORTH

// extern File myFile;

extern File thisFile;

// extern thisFile = (File) myFile;

/*
143   myFile = fatfs.open(FILE_NAME, FILE_WRITE);
144 
145   thisFile = (File) myFile; // local tnr kludge
*/



#include "../common.h"
// #define WORKING_DIR "/forth"
// #define VERBIAGE_AA #undef VERBIAGE_AA

/*
#if defined(__SAMD51__) || defined(NRF52840_XXAA)
  Adafruit_FlashTransport_QSPI flashTransport(PIN_QSPI_SCK, PIN_QSPI_CS, PIN_QSPI_IO0, PIN_QSPI_IO1, PIN_QSPI_IO2, PIN_QSPI_IO3);
#else
  #if (SPI_INTERFACES_COUNT == 1)
    Adafruit_FlashTransport_SPI flashTransport(SS, &SPI);
  #else
    Adafruit_FlashTransport_SPI flashTransport(SS1, &SPI1);
  #endif
#endif
*/

/*
Adafruit_SPIFlash flash(&flashTransport);
*/

/*
// file system object from SdFat
FatFileSystem fatfs;

File myFile;
*/

/*
void mkdir_forth(void) {
  if (!fatfs.exists(WORKING_DIR)) {
    Serial.print(WORKING_DIR);
    Serial.println(" directory not found, creating...");
    if (!fatfs.mkdir(WORKING_DIR)) {
      Serial.print("Error, failed to create ");
      Serial.print(WORKING_DIR);
      Serial.println(" directory!");
      Serial.println("Entering an endless loop (as a trap) after a delay of 4 seconds.");
      delay(4000);
      while(1);
    }
#ifdef VERBIAGE_AA
    Serial.print("Created ");
    Serial.print(WORKING_DIR);
    Serial.println(" directory!");
#else
    Serial.print(" +dcr ");
#endif // #ifdef VERBIAGE_AA
  } else {
#ifdef VERBIAGE_AA
      Serial.print(WORKING_DIR);
      Serial.println("  directory was previously created.  No worries.  Continuing.. ");
#else
      Serial.print(" +dpc ");
#endif // #ifdef VERBIAGE_AA
  }
}
*/

// #define WRITE_FORTH(a) {myFile.print((a));}
#define WRITE_FORTH(a) {thisFile.print((a));}

/*
void flash_setup(void) {
  // Open serial communications and wait for port to open:
  Serial.begin(38400);
  while (!Serial) {
    delay(1); // wait for serial port to connect. Needed for native USB port only
  }

#ifdef VERBIAGE_AA
  Serial.print("\nInitializing Filesystem on external flash...");
#else
  Serial.print(" ckpt AA ");
#endif // #ifdef VERBIAGE_AA
  
  // Init external flash
  flash.begin();

  // Init file system on the flash
  fatfs.begin(&flash);

#ifdef VERBIAGE_AA
  Serial.println("initialization done.");
#else
  Serial.print(" ckpt BB ");
#endif // #ifdef VERBIAGE_AA

  if (!fatfs.remove(FILE_NAME)) {
    Serial.print("Failed to remove "); Serial.println(FILE_NAME);
  }


#ifdef WANT_MKDIR_FORTH
  mkdir_forth(); // tnr kludge
#endif // #ifdef WANT_MKDIR_FORTH

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = fatfs.open(FILE_NAME, FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
#ifdef VERBIAGE_AA
    Serial.print("Writing to "); Serial.print(FILE_NAME); Serial.print(" ");
#else
    Serial.print(" ckpt CC ");
#endif // #ifdef VERBIAGE_AA
*/

void forth_words(void) {
// file contents - - - - - - - - - - - - - - - -

//  myFile.print("\r");

// max ( n1 n2 -- max )
//    WRITE_FORTH(     ": max over over - 0< if swap drop -1 then if exit then swap drop ;\r"

// min ( n1 n2 -- min )
//  ) WRITE_FORTH(     ": min over over - 0< if drop exit then swap drop ;\r"
//  ) WRITE_FORTH(     "\n\r"

      WRITE_FORTH(     ": svi 1 drop ;\r"
) // temporarily close parens (cpp macro)

/*
// testc ( -- )

    ) WRITE_FORTH(     ": testcc -1 512 0 do 1 + dup , loop ;\r"

// >prn ( n -- )
    ) WRITE_FORTH(     ": >prn 32 over over - 0< if 46 emit drop drop exit then drop 127 1 - over over swap - 0< if 46 emit drop drop exit then drop emit ;\r"

// delay ( n -- )
    ) WRITE_FORTH(     ": delay drop 1234 0 do 1 drop loop ;\r"

// ecol ( -- ) \ emit a colon
    ) WRITE_FORTH(     ": ecol 58 emit ;\r"

// hadr ( addr -- addr ) print to display
    ) WRITE_FORTH(     ": hadr dup 1 + h. ecol space ;\r")


// Can pack memory efficiently using the comma word:

\ 0abbccdd    1a2b3c4d

180079837 , 439041101 , 3008 16 - blist

BB0 05 00 00 00 19 00 00 00 DD CC BB 0A 4D 3C 2B 1A ............M<+.
BC0 00 00 00 00 01 00 00 00 02 00 00 00 03 00 00 00 ................
BD0 04 00 00 00 05 00 00 00 06 00 00 00 07 00 00 00 ................
BE0 08 00 00 00 09 00 00 00 0A 00 00 00 0B 00 00 00 ................
BF0 0C 00 00 00 0D 00 00 00 0E 00 00 00 0F 00 00 00 ................
C00 10 00 00 00 11 00 00 00 12 00 00 00 13 00 00 00 ................
C10 14 00 00 00 15 00 00 00 16 00 00 00 17 00 00 00 ................
C20 18 00 00 00 19 00 00 00 1A 00 00 00 1B 00 00 00 ................



//  ) WRITE_FORTH(
// rhlist ( addr -- )
      WRITE_FORTH(     ": rhlist hadr 16 + dup 16 - over over\r"
    ) WRITE_FORTH(     "do 1 + over over swap - 1 - 0<\r"
    ) WRITE_FORTH(     "if dup rbyte dup 16 - 0< if 48 emit then h. 100 delay then loop\r"
    ) WRITE_FORTH(     "drop ;\r"

// ralist ( addr -- )
    ) WRITE_FORTH(     ": ralist space space 16 + dup 16 - over over\r"
    ) WRITE_FORTH(     "do 1 + over over swap - 1 - 0<\r"
    ) WRITE_FORTH(     "if dup rbyte >prn 100 delay then loop\r"
    ) WRITE_FORTH(     "drop ;\r"

// hlist ( addr -- )
    ) WRITE_FORTH(     ": hlist hadr 16 + dup 16 - over over\r"
    ) WRITE_FORTH(     "do 1 + over over swap - 1 - 0<\r"
    ) WRITE_FORTH(     "if dup c@ dup 16 - 0< if 48 emit then h. 100 delay then loop\r"
//  ) WRITE_FORTH(     "if dup rbyte dup 16 - 0< if 48 emit then h. 100 delay then loop\r"
    ) WRITE_FORTH(     "drop ;\r"

// alist ( addr -- )
    ) WRITE_FORTH(     ": alist space space 16 + dup 16 - over over\r"
    ) WRITE_FORTH(     "do 1 + over over swap - 1 - 0<\r"
    ) WRITE_FORTH(     "if dup c@ >prn 100 delay then loop\r"
//  ) WRITE_FORTH(     "if dup rbyte >prn 100 delay then loop\r"
    ) WRITE_FORTH(     "drop ;\r"

// bottom ( -- addr )
    ) WRITE_FORTH(     ": bottom 536870912 ;\r"
    ) WRITE_FORTH(     ": topbottom bottom 16384 + 1024 - 1024 + 16 - ;\r"

// blist ( addr -- )
    ) WRITE_FORTH(     ": blist cr -999 swap 196604 1148 - min 0 max\r"
//  ) WRITE_FORTH(     "196608 1148 - min 0 max 1 - 8 0 do\r"
    ) WRITE_FORTH(     "dup 1 - 8 0 do dup hlist 16 - alist cr\r"
    ) WRITE_FORTH(     "swap drop loop 1 + swap drop cr ;\r"


// rlist ( addr -- addr + report_size )
    ) WRITE_FORTH(     ": rlist cr -999 swap bottom 195552 + min 0 max\r"
    ) WRITE_FORTH(     "dup 1 - 8 0 do dup rhlist 16 - ralist cr\r"
    ) WRITE_FORTH(     "swap drop loop 1 + swap drop cr ;\r"



// : rlist -999 swap cr bottom 195552 + min 0 max
// dup 1 - 8 0 do
// dup rhlist 16 - ralist cr swap drop
// loop 1 + swap drop cr ;



// at the Ok prompt, type:
    ) WRITE_FORTH(     "wag wag 8 wiggle\r"

// canonical for 24 August:
// rlist and blist

// example:
//        bottom 464 + rlist cr 84 blist cr

// rdump was deprecated. 24 Aug

    ) WRITE_FORTH(     ": emits 0 do emit loop space ;\r"
    ) WRITE_FORTH(     ": said fs@ emits space cr space ;\r"
    ) WRITE_FORTH(     ": stuffit 69 68 67 66 65 5 ;\r"
    ) WRITE_FORTH(     "69 68 67 66 65 5 emits cr\r"

    ) WRITE_FORTH(     "2048 allot\r" // 18k address space 03 SEP 2019
    ) WRITE_FORTH(     "variable bend variable buff here buff !\r"
    ) WRITE_FORTH(     "2048 allot here bend ! 1 drop\r"
    ) WRITE_FORTH(     ": svd buff @ 2701 + blist ;\r"  // so adding a 'cr' to the end of the line faked out the parser into not seeing a single character entity as the last entity on the line. ;)
    ) WRITE_FORTH(     ": sve buff @ 4 + cr ;\r"
    ) WRITE_FORTH(     ": goa svd sve 26 0 do 1 + 32 i + over ! loop cr cr svd cr ;\r"

// review:  value address !

    ) WRITE_FORTH(     ": ldelay 1024 0 do 1 delay loop cr ;\r" 

// ###bookmark

// variable sfi .s empty sfi .s 1144 drop 44 sfi ! .s empty sfi @ .s 44


    // sfi knows if the editor has already been initialized, to
    //    allocate a buffer, or not.
    // sfi was mostly disabled for a bug hunt and hasn't been reinstated fully.

    ) WRITE_FORTH(     "variable sfi 0 sfi ! 1 drop\r"

    ) WRITE_FORTH(     "variable sbc -1 sbc !\r" // sam buffer counter

// key-stored:
    ) WRITE_FORTH(     "variable kst 254 kst ! 1 drop\r"

    ) WRITE_FORTH(     ": bsz 128 ; : bmk bsz 1 - ;\r" // increased from 16 to 128 bytes. ;)

// buffer decrement
    ) WRITE_FORTH(     ": bfd swap 1 - bmk and bmk 2 - over\r"
    ) WRITE_FORTH(     "over swap - 0< if\r"
    ) WRITE_FORTH(     "swap 1 - bmk and\r"
    ) WRITE_FORTH(     "1 - bmk and\r"
    ) WRITE_FORTH(     "1 - bmk and\r"
    ) WRITE_FORTH(     "swap then drop swap ;\r"

// buffer increment
// ( count addr -- count+1 addr )
    ) WRITE_FORTH(     ": bfi\r"
    ) WRITE_FORTH(     "kst @\r"
    ) WRITE_FORTH(     "200 - 0< if\r"
    ) WRITE_FORTH(     "bfd bfd then\r"
    ) WRITE_FORTH(     "swap 1 + bmk and bmk 2 - over\r"
    ) WRITE_FORTH(     "over swap - 0< if\r"
    ) WRITE_FORTH(     "swap 1 + bmk and\r"
    ) WRITE_FORTH(     "1 + bmk and\r"
    ) WRITE_FORTH(     "1 + bmk and\r"
    ) WRITE_FORTH(     "swap then drop swap ;\r"
// message: here
    ) WRITE_FORTH(     ": mhe 72 emit 101 emit 114 emit 101 emit 58 emit space ;\r"
    ) WRITE_FORTH(     ": bfc 0 ;\r" // any positive int < (bsz - 2) .. or zero

// conditionally initialize the buffer:
*/


/*
    ) WRITE_FORTH(     ": sxa sfi @ invert if mhe\r" // messsage: here
    ) WRITE_FORTH(     "here dup . bsz allot here swap 1 + -1 sfi ! then ;\r"
*/



/*
// unconditionally init:
    ) WRITE_FORTH(     ": sxa mhe here dup . bsz allot here swap 1 + ;\r"
    ) WRITE_FORTH(     ": txb bfi .s cr ;\r"

    ) WRITE_FORTH(     ": lxa -99 sxa ;\r"

// re-initialization protection:
//  ) WRITE_FORTH(     ": sam sfi @ if 1 drop exit then lxa\r"


    ) WRITE_FORTH(     ": sam lxa\r"
    ) WRITE_FORTH(     "bfc swap bfi\r"
    ) WRITE_FORTH(     "over over + begin\r"
    ) WRITE_FORTH(     "sbc @ 1 + sbc !\r" // increment counter
//  value address !

// backspace ASCII 0x08 related processing 8, 199, 254, kst
    // 254 stored in kst to indicate reset
    // 199 stored to indicate backspace key was pressed

    ) WRITE_FORTH(     "254 kst ! 1 drop\r" // reset kst
    ) WRITE_FORTH(     "key dup\r" // ONLY keystroke gained

// send +++ if backspace is pressed:
    ) WRITE_FORTH(     "9 - 0< if 199 kst ! then\r" // ONLY time '9' is useful in compare

// - - - - standard comparison: 254 vs 199
// everyone store:
    // one path chosen from a single pick of one of these two lines
    // which exchanges 'swap c!' for 'swap drop drop' (the swap was factored out)
    ) WRITE_FORTH(     "kst @ negate 253 + 0< if swap c! then\r"
    ) WRITE_FORTH(     "kst @ 200 - 0< if drop drop then\r"

// read-only and  stack balanced, after these two lines:
*/



/*
    ) WRITE_FORTH(     "dup blist\r"  // blist ( addr -- addr+incr )
    ) WRITE_FORTH(     "drop\r"
*/




/* instead, want a simple emit (to start with):

*/


//  ) WRITE_FORTH(     "dup alist drop\r" // alist will update your address to the new offset if you let it, so dup for a spare copy of tos, alist, then drop the result
// since alist works, it can be picked apart, too:

//  ) WRITE_FORTH(     "if dup c@ >prn 100 delay then loop\r"

//  ) WRITE_FORTH(     "dup c@ 21 min 126 max emit\r"
// since that didn't work, need a stack print to figure out the offset math:
//  ) WRITE_FORTH(     "cr 65 emit 65 emit 65 emit 65 emit 65 emit space space .s space space\r"
// so it's just 'over over +' to get the address wanted:
//  ) WRITE_FORTH(     "over over + c@ cr .s cr 32 max 126 min emit space\r" // may not want that last space

// bsz size of the buffer
// sbc counter for each keystroke given

/*
    ) WRITE_FORTH(     "sbc @ 1 + dup sbc !\r" // sam buffer counter, increment it
    ) WRITE_FORTH(     "sbc @ 125 - 0< if -1 sbc ! then\r"
// nothing -- sbc -- sbc 125 -- DIFF -- BOOL -- consumed at IF to nothing -- -1 -- -1 addr -- nothing
    ) WRITE_FORTH(     "bsz - 0< invert if\r" // compare sbc to bsz
    ) WRITE_FORTH(         "cr cr cr 67 emit 67 emit 67 emit cr cr cr\r" // just get their attention
    ) WRITE_FORTH(     "then 1 drop\r"

    ) WRITE_FORTH(     "over over + c@ 32 max 126 min emit\r" // keyboard echo

    ) WRITE_FORTH(     "bfi over over + 1 drop\r"
    ) WRITE_FORTH(     "again ;\r"
    )
*/

}

// \ sam is the name of the built-in editor.

/*
*/

// - - - exercise blist
//   WRITE_FORTH("variable myvar 439041101 myvar c! myvar 32 - blist\r");
//                                         1a2b3c4d

// file contents - - - - - - - - - - - - - - - -

/*

    // close the file:
    myFile.close();
#ifdef VERBIAGE_AA
    Serial.println(" has now been done.");
#else
    Serial.print(" ckpt DD ");
#endif // #ifdef VERBIAGE_AA
  } else {
    // if the file didn't open, print an error:
    Serial.print("error opening "); Serial.println(FILE_NAME);
  }

  // re-open the file for reading:

  myFile = fatfs.open(FILE_NAME);
  // thisFile = (File) myFile; // local tnr kludge

  if (myFile) {
#ifdef VERBIAGE_AA
    Serial.print(FILE_NAME); Serial.println(" .. will now be read and printed");
    Serial.println("to the console.  Attention: design has strange line endings!\r\n");
#else
    Serial.print(" ckpt EE ");
#endif // #ifdef VERBIAGE_AA

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
#ifdef VERBIAGE_AA
      Serial.write(myFile.read());
#else
#ifdef FBUFF_PRN // suppress when undefined
      Serial.print("+");
#endif
      int ij = myFile.read(); // do the read anyway - try to break something
#endif // #ifdef VERBIAGE_AA
    }
    // close the file:
    myFile.close();
#ifdef VERBIAGE_AA
    Serial.println("\r\n");
    Serial.print(FILE_NAME); Serial.println(" .. is now closed, safely.");
#else
    Serial.print(" ckpt FF ");
#endif // #ifdef VERBIAGE_AA

    // re-open the file for reading:

    File dataFile = fatfs.open(FILE_NAME, FILE_READ);
#ifdef VERBIAGE_AA
    Serial.print(FILE_NAME);
    Serial.println(" is now re-opened (for reading).");
#else
    Serial.print(" ckpt GG ");
#endif // #ifdef VERBIAGE_AA

    thisFile = (File) dataFile;
    thisFile.rewind();
#ifdef VERBIAGE_AA
    Serial.println("FILE STAYS OPEN (and rewound) (for a possible fload).");
#else
    Serial.print(" ckpt HH ");
#endif // #ifdef VERBIAGE_AA
  } else {
    // if the file didn't open, print an error:
    Serial.print("error opening "); Serial.println(FILE_NAME);
  }
}
*/