#define CATCH_CONFIG_MAIN

#include "test_header.h"

#include <sstream>
#include <iostream>

#include <tabulr/cell.h>
#include <tabulr/format.h>

class Mock
{
    public:
        friend std::ostream &operator<<(std::ostream &out, const Mock &mock)
        {
            out << "Hello from the Mock object";
            return out;
        }
};

SCENARIO("Cell tests, various formatting tests.", "[cell] [bdd]")
{
    GIVEN("A cell of type Mock")
    {
        Mock m;
        Tabulr::Cell<Mock> cell(m);

        WHEN("We output the mock object into a stream")
        {
            std::stringstream actual;
            cell.ToStream(actual);

            THEN("The stream should be equal to 'Hello from the Mock object'")
            {
                REQUIRE(actual.str() == "Hello from the Mock object");
            }
        }
    }

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
        Tabulr::Cell<double> cell(1234.45);

        WHEN("We output the cell into a string with 3 decimal points of precision")
        {
            Tabulr::ColumnFormat format;
            format.precision = 3;

            std::stringstream expected;
            expected << std::fixed << std::setprecision(3);
            expected << 1234.45;

            std::stringstream actual;
            cell.ToStream(actual, format);

            THEN("The two string should be identical")
            {
                REQUIRE(actual.str() == expected.str());
            }
        }
    }

    GIVEN("A cell with contents 'Fill to the left'")
    {
        Tabulr::Cell<std::string> cell("Fill to the left");

        WHEN("We output the cell with left positioning")
        {
            Tabulr::CellFormat format;
            format.width = 100;
            format.position = Tabulr::POSITION::LEFT;

            std::stringstream expected;
            expected << std::left;
            expected << std::setw(format.width);
            expected << "Fill to the left";

            std::stringstream actual;
            cell.ToStream(actual, format);

            THEN("The two strings should be identical")
            {
                REQUIRE(actual.str() == expected.str());
            }
        }

        WHEN("We output the cell with to the right of the string")
        {
            Tabulr::CellFormat format;
            format.width = 100;
            format.position = Tabulr::POSITION::RIGHT;

            std::stringstream expected;
            expected << std::right;
            expected << std::setw(format.width);
            expected << "Fill to the left";

            std::stringstream actual;
            cell.ToStream(actual, format);

            THEN("The two strings should be identical")
            {
                REQUIRE(actual.str() == expected.str());
            }
        }

    }
}

