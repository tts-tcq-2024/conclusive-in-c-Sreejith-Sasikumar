#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {

  EXPECT_EQ(inferBreach(-2.5, 0, 35), TOO_LOW);
  EXPECT_EQ(inferBreach(-2.5, 0, 40), TOO_LOW);
  EXPECT_EQ(inferBreach(-2.5, 0, 45), TOO_LOW);

  BatteryCharacter batteryA = {PASSIVE_COOLING, "Brand_A"};
  BatteryCharacter batteryB = {MED_ACTIVE_COOLING, "Brand_B"};
  BatteryCharacter batteryC = {HI_ACTIVE_COOLING, "Brand_C"};

  checkAndAlert(TO_CONTROLLER, batteryA, -2.5);
  checkAndAlert(TO_CONTROLLER, batteryA, 5);
  checkAndAlert(TO_CONTROLLER, batteryA, 36);

  checkAndAlert(TO_CONTROLLER, batteryB, -1);
  checkAndAlert(TO_CONTROLLER, batteryB, 36);
  checkAndAlert(TO_CONTROLLER, batteryB, 41);

  checkAndAlert(TO_CONTROLLER, batteryC, -10);
  checkAndAlert(TO_CONTROLLER, batteryC, 42);
  checkAndAlert(TO_CONTROLLER, batteryC, 46);
}
