#include "test_header.h"

#include <sstream>
#include <iostream>
#include <tabulr/tabulr.h>

TEST_CASE("Table unit test", "[table] [unit]") {
    SECTION("A table's rows should default to capacity of zero") {
        Tabulr::Table table;

        std::shared_ptr<Tabulr::Row> row = table.MakeRow();

        REQUIRE(row->Capacity() == 0);

        std::shared_ptr<Tabulr::Row> another_row = table.MakeRow();

        REQUIRE(another_row->Capacity() == 0);
    }

    SECTION("When a column argument is provided, the capacity of table row's should reflect it.") {
        std::size_t columns = 10;

        Tabulr::Table table(columns);

        std::shared_ptr<Tabulr::Row> row = table.MakeRow();

        REQUIRE(row->Capacity() == columns);

        std::shared_ptr<Tabulr::Row> another_row = table.MakeRow();

        REQUIRE(another_row->Capacity() == columns);
    }

}

SCENARIO("Test a table with no formatting.", "[table], [bdd]") {
    GIVEN("A table") {
        Tabulr::Table table;

        WHEN("We add columns and rows") {
            std::shared_ptr<Tabulr::Row> row = table.MakeRow();

            row->InsertCell("Row 1 Column 1")->InsertCell("Row 1 Column 2");

            row = table.MakeRow();

            row->InsertCell("Row 2 Column 1")->InsertCell("Row 2 Column 2");

            THEN("The output should be valid") {
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

SCENARIO("Test a table with formatting", "[table] [bdd]") {
    GIVEN("A table") {
        Tabulr::Table table;

        WHEN("We add formatted columns and rows") {
            Tabulr::ColumnFormatVector format;

            Tabulr::ColumnFormat one;
            one.SetWidth(5)->SetPrecision(2)->SetFill('-')->SetPosition(Tabulr::POSITION::LEFT);

            Tabulr::ColumnFormat two;
            two.SetWidth(6)->SetPrecision(3)->SetFill('*');

            format.push_back(one);
            format.push_back(two);

            table.SetColumnFormat(format);

            std::shared_ptr<Tabulr::Row> row = table.MakeRow();

            row->InsertCell("A")->InsertCell(12.34);

            row = table.MakeRow();

            row->InsertCell("C")->InsertCell(56.78);

            THEN("The output should match an output table created the same way manually") {
                std::stringstream actual;
                actual << table;

                std::stringstream expected;

                // First row, first column
                expected << std::setw(format[0].GetWidth()) << std::setprecision(2) << std::setfill(format[0].GetFill())
                         << std::left << "A" << " ";

                // First row, second column.
                expected << std::setw(format[1].GetWidth()) << std::setprecision(3) << std::fixed << std::right
                         << std::setfill(format[1].GetFill()) << 12.34 << std::endl;

                // Second row
                expected << std::setw(format[0].GetWidth()) << std::setprecision(2) << std::left
                         << std::setfill(format[0].GetFill()) << "C" << " ";

                expected << std::setw(format[1].GetWidth()) << std::setprecision(3) << std::fixed << std::right
                         << std::setfill(format[1].GetFill()) << 56.78 << std::endl;

                REQUIRE(actual.str() == expected.str());
            }
        }
    }

    GIVEN("A table") {
        Tabulr::Table table;

        WHEN("We add formatted columns and rows, and construct from another table") {
            Tabulr::ColumnFormatVector format;

            Tabulr::ColumnFormat one;
            one.SetWidth(5)->SetPrecision(2)->SetFill('-')->SetPosition(Tabulr::POSITION::LEFT);

            Tabulr::ColumnFormat two;
            two.SetWidth(6)->SetPrecision(3)->SetFill('*');

            format.push_back(one);
            format.push_back(two);

            table.SetColumnFormat(format);

            std::shared_ptr<Tabulr::Row> row = table.MakeRow();

            row->InsertCell("A")->InsertCell(12.34);

            row = table.MakeRow();

            row->InsertCell("C")->InsertCell(56.78);

            Tabulr::Table second_table(table);

            THEN("The output should match an output table created the same way manually") {
                std::stringstream actual;
                actual << second_table;

                std::stringstream expected;

                // First row, first column
                expected << std::setw(format[0].GetWidth()) << std::setprecision(2) << std::setfill(format[0].GetFill())
                         << std::left << "A" << " ";

                // First row, second column.
                expected << std::setw(format[1].GetWidth()) << std::setprecision(3) << std::fixed << std::right
                         << std::setfill(format[1].GetFill()) << 12.34 << std::endl;

                // Second row
                expected << std::setw(format[0].GetWidth()) << std::setprecision(2) << std::left
                         << std::setfill(format[0].GetFill()) << "C" << " ";

                expected << std::setw(format[1].GetWidth()) << std::setprecision(3) << std::fixed << std::right
                         << std::setfill(format[1].GetFill()) << 56.78 << std::endl;

                REQUIRE(actual.str() == expected.str());
            }
        }
    }
}
