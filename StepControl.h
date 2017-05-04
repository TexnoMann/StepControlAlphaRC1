#ifndef StepControl_h
#define StepControl_h

#include "Arduino.h"
 class StepControl{
 	public:
 		StepControl(int en, int step, int dir, int feth);
 		void setSpeeds(int speeds);
	 	void moveTo(long long degrees);
	 	void moveToDistance(double mm);
	 	void go(boolean g);
 	private:
 		boolean _g;
 		double _mm;
 		int _feth;
 		int _enpin;
 		int _steppin;
 		int _dirpin;
 		long long _degrees;
 		int _speeds;
 		int microsstep;
 		long long i;

 };
#endif

