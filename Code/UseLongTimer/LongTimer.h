#include "Arduino.h"

/* 
  LongTimer, timer extending millis
  (C) 2015 Richel Bilderbeek
*/

struct LongTimer
{
  //There are 2147483648 unsigned long value
  static const unsigned long m_max = 2147483647;
  LongTimer() : m_cnt(0), m_cur_msec(0), m_prev_msec(0) 
  { 
    Update(); 
  }
  
  ///The number of msecs passed since the program started
  unsigned long GetMsecs() const { return m_cur_msec; }

  ///The number of seconds passed since the program started
  unsigned long GetSecs() const { return ( (GetMsecs() + (648 * m_cnt)) / 1000) + (2147483 * m_cnt); }

  ///The number of minutes passed since the program started
  unsigned long GetMins() const { return GetSecs() / 60; }

  ///The number of hours passed since the program started
  unsigned long GetHours() const { return GetMins() / 60; }

  ///The number of days passed since the program started
  unsigned long GetDays() const { return GetHours() / 24; }
  
  int GetCnt() const { return m_cnt; }
  
  void Update() 
  { 
    m_cur_msec = millis();
    
    //Detect overflow
    if (m_cur_msec < m_prev_msec) ++m_cnt; 
    
    m_prev_msec = m_cur_msec;
  }
  private:
  ///How often has millis overflown?
  int m_cnt; 

  ///Current number of msecs passed, excluding the number of times millis has overflown
  unsigned long m_cur_msec; 

  ///Previous number of msecs passed, excluding the number of times millis has overflown
  ///Used to detect overflow
  unsigned long m_prev_msec;
  
};
