#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits")
{
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(31, 20, 30) == TOO_HIGH);
}

TEST_CASE("classify Temperature Breach")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 36) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 46) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(3, 41) == TOO_HIGH);
}

TEST_CASE("check And Alert")
{
  REQUIRE(checkAndAlert(TO_CONTROLLER, HI_ACTIVE_COOLING, 46));
  REQUIRE(checkAndAlert(TO_EMAIL, HI_ACTIVE_COOLING, 46));
  REQUIRE(checkAndAlert(2, HI_ACTIVE_COOLING, 46));
}

TEST_CASE("send To Controller")
{
  REQUIRE(sendToController(TOO_HIGH));
}

TEST_CASE("send To Email")
{
  REQUIRE(sendToEmail(TOO_HIGH));
  REQUIRE(sendToEmail(TOO_LOW));
  REQUIRE(sendToEmail(3));
}

