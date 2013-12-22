#include <cstdio>

class TunIf
{
  int m_tunfd;
  
public:
  TunIf();
  virtual ~TunIf();

  int openTun();
  
  int getFd();
  void read();
  void write();
};

