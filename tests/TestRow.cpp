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

SCENARIO("Formatted row", "[row] [bdd]")
{
    GIVEN("A table row")
    {
        Tabulr::Row row;

        WHEN("We add some formatted columns")
        {
            Tabulr::ColumnFormatVector format = {
                { .width = 1, .precision = 0, .fill = ' ', .position = Tabulr::POSITION::LEFT },
                { .width = 10, .precision = 3, .fill = ' ', .position = Tabulr::POSITION::LEFT}
            };

            row.InsertCell("1")->InsertCell(311498.13);
            std::stringstream actual;
            row.ToStream(actual, format);

            // Expected.
            std::stringstream expected;
            expected << std::setw(format[0].width) << "1" << " " << std::setw(format[1].width) << std::fixed << std::setprecision(format[1].precision) << 311498.13;

            REQUIRE(actual.str() == expected.str());
        }
    }
}

