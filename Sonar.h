#ifndef Sonar_h
#define Sonar_h

class Sonar
{
  private:
    int triggerPin;
    int echoPin;

  public:
    Sonar(int tp, int ep);
    long getDistance();
};

#endif
