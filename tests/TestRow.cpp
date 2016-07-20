#include "test_header.h"

#include <memory>
#include <tabulr/row.h>

SCENARIO("Plain row", "[row] [bdd]")
{
    GIVEN("A row")
    {
        Tabulr::Row row;

        WHEN("We add a cell")
        {
            row.InsertCell("Content");
        }
    }
}
