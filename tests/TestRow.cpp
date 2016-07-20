#include "test_header.h"

#include <memory>
#include <sstream>

#include <tabulr/row.h>

SCENARIO("Plain row", "[row] [bdd]")
{
    GIVEN("A row")
    {
        Tabulr::Row row;

        WHEN("We add zero cells")
        {
            THEN("The output should be empty")
            {
                std::stringstream actual;
                row.ToStream(actual);

                std::stringstream expected;

                REQUIRE(actual.str() == "");
                REQUIRE(actual.str() == expected.str());
            }
        }

        WHEN("We add a cell with contents 'Sales Quarter' and output to a stream")
        {
            row.InsertCell("Sales Quarter");

            THEN("It should be properly formatted")
            {
                std::stringstream actual;
                row.ToStream(actual);

                std::stringstream expected;
                expected << "Sales Quarter";

                REQUIRE(actual.str() == expected.str());
            }
        }

        WHEN("We add two cells and output to a stream")
        {
            row.InsertCell("Sales Quarter")->InsertCell("Earnings");

            THEN("It should be properly formatted")
            {
                std::stringstream actual;
                row.ToStream(actual);

                std::stringstream expected;
                expected << "Sales Quarter Earnings";

                REQUIRE(actual.str() == expected.str());
            }
        }
    }
}

