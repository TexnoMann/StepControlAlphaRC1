#ifndef StepControl_h
#define StepControl_h

#include "Arduino.h"
 class StepControl{
 	public:
 		StepControl(int en, int step, int dir, int feth);
 		void setSpeeds(int speeds);
 		void setAcceleration(int accel);
 		void setMinSpeeds(int minspeeds);
	 	void moveTo(long long degrees);
	 	void moveToDistance(double mm);
	 	void go(boolean g);
 	private:
 		int _minspeeds;
 		int _accel;
 		void setCurSpeeds();
 		int _curspeeds;
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

