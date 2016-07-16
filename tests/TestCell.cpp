#define CATCH_CONFIG_MAIN

#include "test_header.h"

#include <sstream>
#include <iostream>

#include <tabulr/cell.h>

SCENARIO("Cell tests", "[cell] [bdd]")
{
    GIVEN("A string cell with contents 'Christian Roman'")
    {
        Tabulr::Cell<std::string> cell("Christian Roman");

        WHEN("We output the cell into a stream")
        {
            std::stringstream ss;
            cell.Output(ss);

            THEN("The resulting string should equal 'Christian Roman'")
            {
                REQUIRE(ss.str() == "Christian Roman");
            }
        }
    }
}

