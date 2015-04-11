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
  if (GetNoteIndex("AS") != 11) { OnError("AS == 11"); }
  if (GetNoteIndex("As") != 11) { OnError("As == 11"); }
  if (GetNoteIndex("as") != 11) { OnError("as == 11"); }
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
  const int aantal_achtste_maten = 1 + (rand() % 8);
  const int achtste_maat_duur_msec = 250;
  const int toon_duur_msec = aantal_achtste_maten * achtste_maat_duur_msec;
  tone(pin_piezo,toon_hoogte,toon_duur_msec);
  delay(toon_duur);
}
