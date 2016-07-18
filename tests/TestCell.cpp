#define CATCH_CONFIG_MAIN

#include "test_header.h"

#include <sstream>
#include <iostream>

#include <tabulr/cell.h>
#include <tabulr/format.h>

SCENARIO("Cell tests, various formatting tests.", "[cell] [bdd]")
{
    GIVEN("A string cell with contents 'Christian Roman'")
    {
        Tabulr::Cell<std::string> cell("Christian Roman");

        WHEN("We output the cell into a stream")
        {
            std::stringstream ss;
            cell.ToStream(ss);

            THEN("The resulting string should equal 'Christian Roman'")
            {
                REQUIRE(ss.str() == "Christian Roman");
            }
        }
    }

    GIVEN("A string with contents 'Christian Roman'")
    {
        Tabulr::Cell<std::string> cell("Christian Roman");

        WHEN("We output the cell into a stream with a width of 100")
        {
            Tabulr::ColumnFormat format;
            format.width = 100;

            std::stringstream expected;
            expected << std::setw(format.width);
            expected << "Christian Roman";

            std::stringstream actual;
            cell.ToStream(actual, format);

            THEN("The two string should be identical")
            {
                REQUIRE(actual.str() == expected.str());
            }
        }
    }

    GIVEN("A cell with contents 1234.45")
    {
        Tabulr::Cell<double> cell_double(1234.45);

        WHEN("The thing is placed into a string with decimal places of precision")
        {
            Tabulr::ColumnFormat format;
            format.precision = 3;

            std::stringstream expected;
            expected << std::fixed << std::setprecision(3);
            expected << 1234.45;

            std::stringstream actual;
            thing.ToStream(actual, format);

            double("The two string should be identical")
            {
                REQUIRE(actual.str() == expected.str());
            }
        }
    }
}

