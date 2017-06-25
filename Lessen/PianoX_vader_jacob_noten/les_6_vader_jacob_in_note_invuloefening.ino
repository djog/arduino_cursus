#include "pitches.h"
/* 88 NOTEN PIANO A0-C8 EN 88 NOTEN PIANO C8-A0 */

int melody[] = {

  //VADER JACOB
  //tone(8,131,250);//Va
  //delay(500)
  NOTE_        ,
  //tone(8,147,250);//der
  //delay(500);
  NOTE_         ,
  //tone(8,165,250);//Ja
  //delay(500);
  NOTE_         ,
  //tone(8,131,250);//cob
  //delay(500);
  NOTE,        ,

  //VADER JACOB
  //tone(8,131,250);//Va
  //delay(500)
  NOTE_        ,
  //tone(8,147,250);//der
  //delay(500);
  NOTE_         ,
  //tone(8,165,250);//Ja
  //delay(500);
  NOTE_         ,
  //tone(8,131,250);//cob
  //delay(500);
  NOTE_         ,

  //SLAAPT GIJ NOG
  //tone(8,165,250);//slaapt
  //delay(500);
  NOTE_           ,
  //tone(8,175,250);//gij
  //delay(500);
  NOTE_           ,
  //tone(8,196,750);//nog
  //delay(1000);
  NOTE_           ,

  //SLAAPT GIJ NOG
  //tone(8,165,250);//slaapt
  //delay(500);
  NOTE_           ,
  //tone(8,175,250);//gij
  //delay(500);
  NOTE_         ,
  //tone(8,196,750);//nog
  //delay(1000);
  NOTE_          ,

   
  //ALLE KLOKKEN LUIDEN
  //tone(8,196,125);//al-
  //delay(500);
  NOTE_          ,
  //tone(8,220,125);//le
  //delay(500);
  NOTE_              ,
  //tone(8,196,125);//klok-
  //delay(500);
  NOTE_                    ,
  //tone(8,175,125);//ken
  //delay(500);
  NOTE_           ,
  //tone(8,165,750);//lui-
  //delay(1000);
  NOTE_            ,
  //tone(8,131,750);//den
  //delay(1000);
  NOTE_               ,

  //ALLE KLOKKEN LUIDEN
  //tone(8,196,125);//al-
  //delay(500);
  NOTE_                ,
  //tone(8,220,125);//le
  //delay(500);
  NOTE_              ,
  //tone(8,196,125);//klok-
  //delay(500);
  NOTE_             ,
  //tone(8,175,125);//ken
  //delay(500);
  NOTE_             ,
  //tone(8,165,750);//lui-
  //delay(1000);
  NOTE_            ,
  //tone(8,131,750);//den
  //delay(1000);
  NOTE_           ,

  //BIM BAM BOM
  //tone(8,220,700);//bim
  //delay(1000);
  NOTE_                ,
  //tone(8,165,700);//bam
  //delay(1000);
  NOTE_               ,
  //tone(8,220,1300);//bom
  //delay(2000);
  NOTE_            ,

  //BIM BAM BOM
  //tone(8,220,700);//bim
  //delay(1000);
  NOTE_           ,
  //tone(8,165,700);//bam
  //delay(1000);
  NOTE_           ,
  //tone(8,220,1300);//bom
  //delay(2000);
  NOTE_            
};


int noteDurations[] = {
  4,4,4,4,
  4,4,4,4,
  4,4,4,
  4,4,4,
  4,4,4,4,4,4,
  4,4,4,4,4,4,
  4,4,4,
  4,4,4
};

void setup() 
{

  for (int thisNote = 0; thisNote < 32; thisNote++) 
  { 
    // herhaal de noten van deze melodie

    int noteDuration = 1000/noteDurations[thisNote];
    // voor het berekenen van de nootduur wordt 1 seconde gebruikt. 1 seconde is 1000.
    // 1000 wordt gedeeld door het noottype (0,1,2,4,8) 
    // 1000/0, 1000/1, 1000/2, 1000/4, 1000/8

    tone(8, melody[thisNote],noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    // om de noten van elkaar te onderscheiden, zet er een minimumtijd tussen.
    // de notenduur + 30% lijkt goed te werken:

    delay(pauseBetweenNotes);

    noTone(8);
    // stop de toon te spelen op pin 8:
  }
}

void loop() 
{
  // loop leeg laten, zo komt er geen herhaling en wordt de melodie maar 1x afgespeeld.
}

