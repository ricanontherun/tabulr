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
                expected << "Row 1 Column 1 " << "Row 1 Column 2\n";
                expected << "Row 2 Column 1 " << "Row 2 Column 2\n";

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
                { .width = 5, .precision = 1, .fill = '-', .position = Tabulr::POSITION::LEFT },
                { .width = 5, .precision = 1, .fill = '*', .position = Tabulr::POSITION::RIGHT}
            };

            table.SetColumnFormat(format);

            Tabulr::Row *row = table.MakeRow();

            row->InsertCell("A")->InsertCell("B");

            row = table.MakeRow();

            row->InsertCell("C")->InsertCell("D");

            THEN("The output should match an output table created the same way manually")
            {
                std::stringstream actual;
                actual << table;

                std::stringstream expected;

                // First row, first column
                expected << std::setw(format[0].width) << std::setprecision(1) << std::setfill(format[0].fill) << std::left << "A" << " ";

                // First row, second column.
                expected << std::setw(format[1].width) << std::setprecision(1) << std::right << std::setfill(format[1].fill) << "B" << std::endl;

                // Second row
                expected << std::setw(format[0].width) << std::setprecision(1) << std::setfill(format[0].fill) << std::left << "C" << " ";

                expected << std::setw(format[1].width)  << std::setprecision(1) << std::right << std::setfill(format[1].fill) << "D" << std::endl;

                REQUIRE(expected.str() == actual.str());
            }
        }
    }
}
