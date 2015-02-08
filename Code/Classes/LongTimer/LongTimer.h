#include "Arduino.h"

/* 
  LongTimer, timer extending millis
  (C) 2015 Richel Bilderbeek
  
  2015-02-08: v 1.0: initial version
  2015-02-08: v 1.1: removed need to call Update
*/

struct LongTimer
{
  LongTimer() : m_cnt(0), m_cur_msec(0), m_prev_msec(0) 
  { 
 
  }
  
  ///The number of msecs passed since the program started
  unsigned long GetMsecs() const 
  { 
    return m_cur_msec;   
  }

  ///The number of seconds passed since the program started
  unsigned long GetSecs() const 
  { 
    Update();
    return ( (GetMsecs() + (648 * m_cnt)) / 1000) + (2147483 * m_cnt); 
  }

  ///The number of minutes passed since the program started
  unsigned long GetMins() const 
  { 
    return GetSecs() / 60; 
  }

  ///The number of hours passed since the program started
  unsigned long GetHours() const 
  { 
    return GetMins() / 60; 
  }

  ///The number of days passed since the program started
  unsigned long GetDays() const 
  { 
    return GetHours() / 24; 
  }
  
  int GetCnt() const { return m_cnt; }

  static String GetVersion() { return "1.1"; }

  private:
  ///How often has millis overflown?
  mutable int m_cnt; 

  ///Current number of msecs passed, excluding the number of times millis has overflown
  mutable unsigned long m_cur_msec; 

    //There are 2147483648 unsigned long value
  static const unsigned long m_max = 2147483647;

  ///Previous number of msecs passed, excluding the number of times millis has overflown
  ///Used to detect overflow
  mutable unsigned long m_prev_msec;

  void Update() const
  { 
    m_cur_msec = millis();
    
    //Detect overflow
    if (m_cur_msec < m_prev_msec) ++m_cnt; 
    
    m_prev_msec = m_cur_msec;
  }
  
};
