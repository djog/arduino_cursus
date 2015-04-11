/*
const int note_b0  =   31;
const int note_c1  =   33;
const int note_cs1 =   35;
const int note_d1  =   37;
const int note_ds1 =   39;
const int note_e1  =   41;
const int note_f1  =   44;
const int note_fs1 =   46;
const int note_g1  =   49;
const int note_gs1 =   52;
const int note_a1  =   55;
const int note_as1 =   58;
const int note_b1  =   62;
const int note_c2  =   65;
const int note_cs2 =   69;
const int note_d2  =   73;
const int note_ds2 =   78;
const int note_e2  =   82;
const int note_f2  =   87;
const int note_fs2 =   93;
const int note_g2  =   98;
const int note_gs2 =  104;
const int note_a2  =  110;
const int note_as2 =  117;
const int note_b2  =  123;
const int note_c3  =  131;
const int note_cs3 =  139;
const int note_d3  =  147;
const int note_ds3 =  156;
const int note_e3  =  165;
const int note_f3  =  175;
const int note_fs3 =  185;
const int note_g3  =  196;
const int note_gs3 =  208;
const int note_a3  =  220;
const int note_as3 =  233;
const int note_b3  =  247;
const int note_c4  =  262;
const int note_cs4 =  277;
const int note_d4  =  294;
const int note_ds4 =  311;
const int note_e4  =  330;
const int note_f4  =  349;
const int note_fs4 =  370;
const int note_g4  =  392;
const int note_gs4 =  415;
const int note_a4  =  440;
const int note_as4 =  466;
const int note_b4  =  494;
const int note_c5  =  523;
const int note_cs5 =  554;
const int note_d5  =  587;
const int note_ds5 =  622;
const int note_e5  =  659;
const int note_f5  =  698;
const int note_fs5 =  740;
const int note_g5  =  784;
const int note_gs5 =  831;
const int note_a5  =  880;
const int note_as5 =  932;
const int note_b5  =  988;
const int note_c6  = 1047;
const int note_cs6 = 1109;
const int note_d6  = 1175;
const int note_ds6 = 1245;
const int note_e6  = 1319;
const int note_f6  = 1397;
const int note_fs6 = 1480;
const int note_g6  = 1568;
const int note_gs6 = 1661;
const int note_a6  = 1760;
const int note_as6 = 1865;
const int note_b6  = 1976;
const int note_c7  = 2093;
const int note_cs7 = 2217;
const int note_d7  = 2349;
const int note_ds7 = 2489;
const int note_e7  = 2637;
const int note_f7  = 2794;
const int note_fs7 = 2960;
const int note_g7  = 3136;
const int note_gs7 = 3322;
const int note_a7  = 3520;
const int note_as7 = 3729;
const int note_b7  = 3951;
const int note_c8  = 4186;
const int note_cs8 = 4435;
const int note_d8  = 4699;
const int note_ds8 = 4978;
*/


//A = 0
int GetNoteIndex(String note)
{
  note.toLowerCase();
  if (note == "a") return 0;
  if (note == "ais" || note == "bes") return 1;
  if (note == "b") return 2;
  if (note == "c") return 3;
  if (note == "cis" || note == "des") return 4;
  if (note == "d") return 5;
  if (note == "dis" || note == "es") return 6;
  if (note == "e") return 7;
  if (note == "f") return 8;
  if (note == "fis" || note == "ges") return 9;
  if (note == "g") return 10;
  if (note == "gis" || note == "as") return 11;
}

String GetNote(const int index)
{
  switch (index)
  {
    case  0: return "a";
    case  1: return "ais";
    case  2: return "b";
    case  3: return "c";
    case  4: return "cis";
    case  5: return "d";
    case  6: return "dis";
    case  7: return "e";
    case  8: return "f";
    case  9: return "fis";
    case 10: return "g";
    case 11: return "gis";
  }  
}

int GetFrequency(String note, const int octave_original)
{
  //Allow as to be of lower octave
  note.toLowerCase();
  const int octave = note == "as" ? octave_original - 1 : octave_original;
  if (octave < 0) return 0;
  const double frequency_a0 = 22.5; //By definition, as a4 = 440, a3 = 220, a2 = 110, a1 = 55
  const double twelfth_root_of_two = 1.0594630943592952645;
  double f = frequency_a0;
  //Go to the correct octave
  for (int i=0; i!=octave; ++i) { f*=2.0; }
  //Go to the correct note
  const int note_index = GetNoteIndex(note);
  for (int i=0; i!=note_index; ++i) { f*=twelfth_root_of_two; } 
}

const int pin_piezo = 8;
const int pin_error = 13;

void OnError(const String& error)
{
  Serial.print("ERROR: ");
  Serial.println(error);
  while (1)
  {
    //Blink error LED
    digitalWrite(pin_error,!digitalRead(pin_error));
    delay(1000);
  } 
}

void Test()
{
  if (GetNoteIndex("A") != 0) { OnError("A == 0"); }
  if (GetNoteIndex("a") != 0) { OnError("a == 0"); }
  if (GetNoteIndex("AS") != 1) { OnError("AS == 1"); }
  if (GetNoteIndex("As") != 1) { OnError("As == 1"); }
  if (GetNoteIndex("as") != 1) { OnError("as == 1"); }
}

void setup()
{
  Serial.begin(9600);
  pinMode(pin_piezo,OUTPUT); 
  pinMode(pin_error,OUTPUT); 
  Test();
}

void loop()
{
  const String noot = GetNote(rand() % 12);
  const int octaaf = rand() % 8;
  const int toon_hoogte = GetFrequency(noot,octaaf);
  const int toon_duur = 100 + rand() % 900;
  tone(pin_piezo,toon_hoogte,toon_duur);
}
