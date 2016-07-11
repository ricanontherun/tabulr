#define CATCH_CONFIG_MAIN

#include "test_header.h"

#include <sstream>
#include <column.h>

TEST_CASE("Tabulr::Column")
{
    SECTION("Test a simple column with no configuration")
    {
        Tabulr::Column<std::string> int_col("Christian");
        std::string name = "Christian";

        std::ostringstream out;
        out << int_col;

        REQUIRE(name == out.str());
    }
}
