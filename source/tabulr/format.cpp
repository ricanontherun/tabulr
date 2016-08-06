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
#include <tabulr/format.h>


namespace Tabulr
{

ColumnFormat::ColumnFormat()
: width(0), precision(0), fill(' '), position(POSITION::RIGHT)
{

}

ColumnFormat::ColumnFormat(int width)
: width(width), precision(0), fill(' '), position(POSITION::RIGHT)
{

}

ColumnFormat::ColumnFormat(int width, int precision)
: width(width), precision(precision), fill(' '), position(POSITION::RIGHT)
{

}

ColumnFormat::ColumnFormat(int width, int precision, char fill)
: width(width), precision(precision), fill(fill), position(POSITION::RIGHT)
{

}

ColumnFormat::ColumnFormat(int width, int precision, char fill, POSITION position)
: width(width), precision(precision), fill(fill), position(position)
{

}

ColumnFormat *ColumnFormat::SetWidth(int width)
{
    this->width = width;

    return this;
}

int ColumnFormat::GetWidth() const
{
    return this->width;
}

ColumnFormat *ColumnFormat::SetPrecision(int precision)
{
    this->precision = precision;

    return this;
}

int ColumnFormat::GetPrecision() const
{
    return this->precision;
}

ColumnFormat *ColumnFormat::SetFill(char fill)
{
    this->fill = fill;

    return this;
}

char ColumnFormat::GetFill() const
{
    return this->fill;
}

ColumnFormat *ColumnFormat::SetPosition(POSITION position)
{
    this->position = position;

    return this;
}

POSITION ColumnFormat::GetPosition() const
{
    return this->position;
}

} // End Tabulr
