#include "Arduino.h"
#include "StepControl.h"

StepControl::StepControl(int en, int step, int dir, int feth){
	_degrees=0L;
	_mm=0L;
	_feth=feth;
	_enpin=en;
	_steppin=step;
	_dirpin=dir;
	microsstep=1000;
	i=0L;
	_speeds=400;
	pinMode(_enpin, OUTPUT);
	pinMode(_dirpin,OUTPUT);
	pinMode(_steppin,OUTPUT);
	digitalWrite(_enpin, LOW);
}

void StepControl::setSpeeds(int speeds){
	_speeds=speeds;
	microsstep= 1000000/_speeds;
}

void StepControl::moveTo(long long degrees){
	_degrees= degrees;
	if(_degrees!=0){
	
		if(_degrees>0){
			digitalWrite(_dirpin, HIGH);
	  		for(i=0L;i<_degrees; i++){
				digitalWrite(_steppin, HIGH);
	  			delayMicroseconds(microsstep); 
	  			digitalWrite(_steppin, LOW);
	  		}
	  	}
	  	else{
	  		digitalWrite(_dirpin, LOW);
	  		for(i=0L;i>_degrees; i--){
				digitalWrite(_steppin, HIGH);
	  			delayMicroseconds(microsstep); 
	  			digitalWrite(_steppin, LOW);
	  		}
		  }
	
	}
}

void StepControl::moveToDistance(double mm){
	_mm=mm;
	_degrees=_mm*_feth;
	moveTo(_degrees);
}

void StepControl::go(boolean g){
	_g=g;
	if(_g) moveTo(1);
	else moveTo(-1);
}




