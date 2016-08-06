// Copyright (C) 2016 Christian Roman
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef TABULR_FORMAT_H
#define TABULR_FORMAT_H

#include <vector>
#include <cstdint>

namespace Tabulr
{

enum class POSITION : std::uint8_t
{
    LEFT = 1,
    INTERNAL,
    RIGHT
};

class ColumnFormat
{
    public:
        ColumnFormat();

        ColumnFormat(int width);
        ColumnFormat(int width, int precision);
        ColumnFormat(int width, int precision, char fill);
        ColumnFormat(int width, int precision, char fill, POSITION position);

        ColumnFormat *SetWidth(int width);
        int GetWidth() const;

        ColumnFormat *SetPrecision(int precision);
        int GetPrecision() const;

        ColumnFormat *SetFill(char fill);
        char GetFill() const;

        ColumnFormat *SetPosition(POSITION position);
        POSITION GetPosition() const;

    private:
        // Field width
        int width;

        // Decimal precision
        int precision;

        // Fill character
        char fill;

        POSITION position;
};

// For convenience
typedef std::vector<ColumnFormat> ColumnFormatVector;

}

#endif
