#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits")
{
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(31, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(0, 0, 0) == NORMAL);
}

TEST_CASE("classify Temperature Breach")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 36) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 46) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 41) == TOO_HIGH);
}

TEST_CASE("check And Alert")
{
  checkAndAlert(TO_CONTROLLER, {HI_ACTIVE_COOLING, 0}, 46);
  checkAndAlert(TO_EMAIL, {HI_ACTIVE_COOLING, 0}, 46);
}

TEST_CASE("send To Controller")
{
  sendToController(TOO_HIGH);
}

TEST_CASE("send To Email")
{
  sendToEmail(TOO_HIGH);
  sendToEmail(TOO_LOW);
}

