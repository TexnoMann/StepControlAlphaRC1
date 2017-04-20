#include "Arduino.h"
#include "StepControl.h"

StepControl::StepControl(int en, int step, int dir, int feth){
	_feth=feth;
	_enpin=en;
	_steppin=step;
	_dirpin=dir;
	microsstep=0;
	i=0;
	_speeds=0;
	currentspeeds=0;
	_accel=0;
	pinMode(_enpin, OUTPUT);
	pinMode(_dirpin,OUTPUT);
	pinMode(_steppin,OUTPUT);
	digitalWrite(_enpin, LOW);
}

void StepControl::setSpeeds(int speeds){
	_speeds=speeds;
}
int StepControl::setCurrentSpeeds(int step){
	currentspeeds=100+_accel*step;
	if (currentspeeds>_speeds) currentspeeds=_speeds;
	microsstep= 1000000/currentspeeds;
	return microsstep;
}

void StepControl::setAcceleration(int accel){
	_accel=accel;
}

void StepControl::moveTo(int degrees){
	_degrees= degrees;
	currentspeeds=0;
	if(_degrees!=0){
	
		if(_degrees>0){
			
			digitalWrite(_dirpin, HIGH);
	  		for(i=0;i<_degrees; i++){
				digitalWrite(_steppin, HIGH);
	  			delayMs(i);
	  			digitalWrite(_steppin, LOW);
	  		}
	  	}
	  	else{
	  		digitalWrite(_dirpin, LOW);
	  		for(i=0;i>_degrees; i--){
				digitalWrite(_steppin, HIGH);
	  			delayMs(i);
	  			digitalWrite(_steppin, LOW);
	  		}
		  }
	
	}
}

void StepControl::moveToDistance(int mm){
	_mm=mm;
	moveTo(_mm*_feth);
}

void StepControl:: delayMs(int steps){
	delayMicroseconds(setCurrentSpeeds(steps)); 
} 




