#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {

EXPECT_EQ(inferBreach(-2.5, 0, 35), TOO_LOW);
}
