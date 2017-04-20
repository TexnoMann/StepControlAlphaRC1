#ifndef StepControl_h
#define StepControl_h

#include "Arduino.h"
 class StepControl{
 	public:
 		StepControl(int en, int step, int dir, int feth);
 		void setSpeeds(int speeds);
	 	void moveTo(int degrees);
	 	void moveToDistance(int mm);
	 	void setAcceleration(int accel);
 	private:
 		int setCurrentSpeeds(int step);
 		void delayMs(int steps);
 		int _mm;
 		int _feth;
 		int _enpin;
 		int _steppin;
 		int _dirpin;
 		int _degrees;
 		int _speeds;
 		int microsstep;
 		int i;
 		int _accel;
 		int currentspeeds;

 };
#endif

