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
            Tabulr::ColumnFormatVector format;

            Tabulr::ColumnFormat one;
            one.SetWidth(1)->SetPrecision(0)->SetFill(' ');

            Tabulr::ColumnFormat two;
            two.SetWidth(10)->SetPrecision(3)->SetFill(' ');

            format.push_back(one);
            format.push_back(two);

            row.InsertCell("1")->InsertCell(311498.13);
            std::stringstream actual;
            row.ToStream(actual, format);

            // Expected.
            std::stringstream expected;
            expected << std::setw(format[0].GetWidth()) << "1" << " " << std::setw(format[1].GetWidth()) << std::fixed << std::setprecision(format[1].GetPrecision()) << 311498.13;

            REQUIRE(actual.str() == expected.str());
        }
    }
}

