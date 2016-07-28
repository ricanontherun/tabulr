#include "test_header.h"

#include <sstream>
#include <iostream>
#include <tabulr/tabulr.h>

SCENARIO("Test a table with no formatting.", "[table], [bdd]")
{
    GIVEN("A table")
    {
        Tabulr::Table table;

        WHEN("We add columns and rows")
        {
            Tabulr::Row *row = table.MakeRow();

            row->InsertCell("Row 1 Column 1")->InsertCell("Row 1 Column 2");

            row = table.MakeRow();

            row->InsertCell("Row 2 Column 1")->InsertCell("Row 2 Column 2");

            THEN("The output should be valid")
            {
                std::stringstream actual;
                actual << table;

                std::stringstream expected;
                expected << "Row 1 Column 1 " << "Row 1 Column 2" << std::endl;
                expected << "Row 2 Column 1 " << "Row 2 Column 2" << std::endl;

                REQUIRE(actual.str() == expected.str());
            }
        }
    }
}

SCENARIO("Test a table with formatting", "[table] [bdd]")
{
    GIVEN("A table")
    {
        Tabulr::Table table;

        WHEN("We add formatted columns and rows")
        {
            std::vector<Tabulr::ColumnFormat> format = {
                { .width = 20, .precision = 1, .fill = ' ', .position = Tabulr::POSITION::LEFT },
                { .width = 50, .precision = 1, .fill = '*', .position = Tabulr::POSITION::RIGHT}
            };

            table.SetColumnFormat(format);

            Tabulr::Row *row = table.MakeRow();

            row->InsertCell("Row 1 Column 1")->InsertCell("Row 1 Column 2");

            row = table.MakeRow();

            row->InsertCell("Row 2 Column 1")->InsertCell("Row 2 Column 2");

            THEN("The output should be valid.")
            {
                std::stringstream actual;
                actual << table;

                std::stringstream expected;
                expected << std::setw(20) << std::setprecision(1) << std::setfill(' ') << std::left << "Row 1 Column 1 " << std::setw(50) << std::setprecision(1) << std::right << std::setfill('*') << "Row 1 Column 2" << std::endl;
                expected << std::setw(20) << std::setprecision(1) << std::setfill(' ') << std::left << "Row 2 Column 1 " << std::setw(50) << std::setprecision(1) << std::right << std::setfill('*') << "Row 2 Column 2" << std::endl;

                std::cout << actual.str();
                std::cout << expected.str();
            }
        }
    }
}
