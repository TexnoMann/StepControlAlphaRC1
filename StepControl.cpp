#include "Arduino.h"
#include "StepControl.h"

StepControl::StepControl(int en, int step, int dir, int feth){
	_feth=feth;
	_enpin=en;
	_steppin=step;
	_dirpin=dir;
	microsstep=1000;
	i=0;
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

void StepControl::moveTo(int degrees){
	_degrees= degrees;
	if(_degrees!=0){
	
		if(_degrees>0){
			digitalWrite(_dirpin, HIGH);
	  		for(i=0;i<degrees; i++){
				digitalWrite(_steppin, HIGH);
	  			delayMicroseconds(microsstep); 
	  			digitalWrite(_steppin, LOW);
	  		}
	  	}
	  	else{
	  		digitalWrite(_dirpin, HIGH);
	  		for(i=0;i>degrees; i--){
				digitalWrite(_steppin, HIGH);
	  			delayMicroseconds(microsstep); 
	  			digitalWrite(_steppin, LOW);
	  		}
		  }
	
	}
}

void StepControl::moveToDistance(int mm){
	_mm=mm;
	moveTo(_mm*_feth);
}




