#include "typewise-alert.h"
#include <stdio.h>

double lowerCoolingLimits[] = {0, 0, 0};
double upperCoolingLimits[] = {35, 45, 40};

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  return inferBreach(temperatureInC, lowerCoolingLimits[coolingType], upperCoolingLimits[coolingType]);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  if(alertTarget == TO_CONTROLLER) {
    sendToController(breachType);
  }
  else{
    sendToEmail(breachType);
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  if(breachType == TOO_LOW) {
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
  }
  else if(breachType == TOO_HIGH){
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
  }
}
