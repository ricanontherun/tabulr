#include "test_header.h"

#include <tabulr/format.h>

TEST_CASE("Format unit tests", "[format] [unit]")
{
    SECTION("We should be able to set the width of a format")
    {
        int width = 100;

        Tabulr::ColumnFormat format;

        format.SetWidth(width);
    }
}
