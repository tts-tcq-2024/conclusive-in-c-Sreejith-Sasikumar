#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {

  BatteryCharacter batteryA = {PASSIVE_COOLING, "Brand_A"};
  BatteryCharacter batteryB = {MED_ACTIVE_COOLING, "Brand_B"};
  BatteryCharacter batteryC = {HI_ACTIVE_COOLING, "Brand_C"};

  checkAndAlert(TO_CONTROLLER, batteryA, -2.5);   //Tests PASSIVE_COOLING TOO_LOW breach alert TO_CONTROLLER
  checkAndAlert(TO_CONTROLLER, batteryA, 5);      //Tests PASSIVE_COOLING NORMAL message TO_CONTROLLER
  checkAndAlert(TO_CONTROLLER, batteryA, 36);     //Tests PASSIVE_COOLING TOO_HIGH breach alert TO_CONTROLLER

  checkAndAlert(TO_CONTROLLER, batteryB, -1);    //Tests MED_ACTIVE_COOLING TOO_LOW breach alert TO_CONTROLLER
  checkAndAlert(TO_CONTROLLER, batteryB, 36);    //Tests MED_ACTIVE_COOLING NORMAL message TO_CONTROLLER
  checkAndAlert(TO_CONTROLLER, batteryB, 41);    //Tests MED_ACTIVE_COOLING TOO_HIGH breach alert TO_CONTROLLER

  checkAndAlert(TO_CONTROLLER, batteryC, -10);  //Tests HI_ACTIVE_COOLING TOO_LOW breach alert TO_CONTROLLER
  checkAndAlert(TO_CONTROLLER, batteryC, 42);   //Tests HI_ACTIVE_COOLING NORMAL message TO_CONTROLLER
  checkAndAlert(TO_CONTROLLER, batteryC, 46);   //Tests HI_ACTIVE_COOLING TOO_HIGH breach alert TO_CONTROLLER

  checkAndAlert(TO_EMAIL, batteryA, -2.5);    //Tests PASSIVE_COOLING TOO_LOW breach alert TO_EMAIL
  checkAndAlert(TO_EMAIL, batteryA, 5);       //Normal - no mails
  checkAndAlert(TO_EMAIL, batteryA, 36);      //Tests PASSIVE_COOLING TOO_HIGH breach alert TO_EMAIL

  checkAndAlert(TO_EMAIL, batteryB, -1);    //Tests MED_ACTIVE_COOLING TOO_LOW breach alert TO_EMAIL
  checkAndAlert(TO_EMAIL, batteryA, 36);    //Normal - no mails
  checkAndAlert(TO_EMAIL, batteryB, 41);    //Tests MED_ACTIVE_COOLING TOO_HIGH breach alert TO_EMAIL

  checkAndAlert(TO_EMAIL, batteryC, -10);    //Tests HI_ACTIVE_COOLING TOO_LOW breach alert TO_EMAIL
  checkAndAlert(TO_EMAIL, batteryA, 42);     //Normal - no mails
  checkAndAlert(TO_EMAIL, batteryC, 46);     //Tests HI_ACTIVE_COOLING TOO_HIGH breach alert TO_EMAIL
}
