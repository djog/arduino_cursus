double NaarVoltage(const int gemeten_waarde)
{
  //Delen door 1024, dan keer 5.0 en dan terug geven
  const double gemeten_waarde_als_double
    = static_cast<double>(gemeten_waarde);
  const double fractie 
    = gemeten_waarde_als_double
    / 1024.0;
  const double voltage 
    = fractie 
    * 5.0;
  return voltage;
}
