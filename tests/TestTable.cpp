#include "test_header.h"

#include <sstream>
#include <iostream>
#include <tabulr/tabulr.h>

TEST_CASE("Table unit test", "[table] [unit]")
{
    SECTION("Test that a table rows are defaulted to having zero cells.")
    {
        Tabulr::Table table;

        Tabulr::Row *row = table.MakeRow();

        REQUIRE(row->GetCellCount() == 0);
    }

    SECTION("Test that, when give a size constructor, table rows have that many columns by default.")
    {
        Tabulr::Table table(10);

        Tabulr::Row *first_row = table.MakeRow();

        REQUIRE(first_row->GetCellCount() == 10);
    }
}

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
            //Trying to represent all of the different formatting options.
            Tabulr::ColumnFormatVector format = {
                { .width = 5, .precision = 2, .fill = '-', .position = Tabulr::POSITION::LEFT },
                { .width = 6, .precision = 3, .fill = '*', .position = Tabulr::POSITION::RIGHT}
            };

            table.SetColumnFormat(format);

            Tabulr::Row *row = table.MakeRow();

            row->InsertCell("A")->InsertCell(12.34);

            row = table.MakeRow();

            row->InsertCell("C")->InsertCell(56.78);

            THEN("The output should match an output table created the same way manually")
            {
                std::stringstream actual;
                actual << table;

                std::stringstream expected;

                // First row, first column
                expected << std::setw(format[0].width) << std::setprecision(2) << std::setfill(format[0].fill) << std::left << "A" << " ";

                // First row, second column.
                expected << std::setw(format[1].width) << std::setprecision(3) << std::fixed << std::right << std::setfill(format[1].fill) << 12.34 << std::endl;

                // Second row
                expected << std::setw(format[0].width) << std::setprecision(2) << std::left << std::setfill(format[0].fill) << "C" << " ";

                expected << std::setw(format[1].width) << std::setprecision(3) << std::fixed << std::right << std::setfill(format[1].fill) << 56.78 << std::endl;

                REQUIRE(actual.str() == expected.str());
            }
        }
    }
}
