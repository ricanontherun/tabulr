#include "test_header.h"

#include <tabulr/format.h>

TEST_CASE("Format unit tests", "[format] [unit]")
{
    Tabulr::ColumnFormat format;

    SECTION("It should default to sensible...defaults.")
    {
        REQUIRE(format.GetWidth() == 0);
        REQUIRE(format.GetPrecision() == 0);
        REQUIRE(format.GetFill() == ' ');
        REQUIRE(format.GetPosition() == Tabulr::POSITION::RIGHT);
    }

    SECTION("It can set it's width")
    {
        int width = 100;

        format.SetWidth(width);

        REQUIRE(format.GetWidth() == width);
    }

    SECTION("It can set it's precision")
    {
        // Super precise
        int precision = 10;

        format.SetPrecision(precision);

        REQUIRE(format.GetPrecision() == precision);
    }

    SECTION("It can set it's fill character")
    {
        char fill = '_';

        format.SetFill(fill);

        REQUIRE(format.GetFill() == fill);
    }

    SECTION("It can set it's position")
    {
        auto position = Tabulr::POSITION::INTERNAL;

        format.SetPosition(position);

        REQUIRE(format.GetPosition() == position);
    }
}

TEST_CASE("Format constructor tests", "[format] [unit]")
{
    SECTION("format(width)")
    {
        int width = 100;

        Tabulr::ColumnFormat format(width);

        REQUIRE(format.GetWidth() == width);
        REQUIRE(format.GetPrecision() == 0);
        REQUIRE(format.GetFill() == ' ');
        REQUIRE(format.GetPosition() == Tabulr::POSITION::RIGHT);
    }

    SECTION("format(width, precision)")
    {
        int width = 100;
        int precision = 10;

        Tabulr::ColumnFormat format(width, precision);

        REQUIRE(format.GetWidth() == width);
        REQUIRE(format.GetPrecision() == precision);
        REQUIRE(format.GetFill() == ' ');
        REQUIRE(format.GetPosition() == Tabulr::POSITION::RIGHT);

    }

    SECTION("format(width, precision, fill)")
    {
        int width = 10;
        int precision = 2;
        int fill = '-';

        Tabulr::ColumnFormat format(width, precision, fill);

        REQUIRE(format.GetWidth() == width);
        REQUIRE(format.GetPrecision() == precision);
        REQUIRE(format.GetFill() == fill);
        REQUIRE(format.GetPosition() == Tabulr::POSITION::RIGHT);

    }

    SECTION("format(width, precision, fill, position)")
    {
        int width = 15;
        int precision = 3;
        int fill = '*';
        auto position = Tabulr::POSITION::LEFT;

        Tabulr::ColumnFormat format(width, precision, fill, position);

        REQUIRE(format.GetWidth() == width);
        REQUIRE(format.GetPrecision() == precision);
        REQUIRE(format.GetFill() == fill);
        REQUIRE(format.GetPosition() == Tabulr::POSITION::LEFT);

    }
}
