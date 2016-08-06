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
        int width = 0;
        int precision = 0;
        char fill = ' ';
        POSITION position;

        ColumnFormat();

        ColumnFormat *SetWidth(int width);
        int GetWidth() const;

        ColumnFormat *SetPrecision(int precision);
        int GetPrecision() const;

        ColumnFormat *SetFill(char fill);
        char GetFill() const;

        ColumnFormat *SetPosition(POSITION position);
        POSITION GetPosition() const;
};

// For convenience
typedef std::vector<ColumnFormat> ColumnFormatVector;

}

#endif
