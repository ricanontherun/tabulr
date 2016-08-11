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

#include <tabulr/row.h>

namespace Tabulr
{

Row::Row()
{
}

Row::Row(std::size_t size)
{
    this->cells.reserve(size);
}

std::ostream &Row::ToStream(std::ostream &out) const
{
    size_t size = this->cells.size();
    size_t index = 0;

    for ( auto const &cell_it : this->cells ) {
        cell_it.get()->ToStream(out);

        // We're only going to print a space for cells in between the start and end cells.
        if ( size != 1 && index != size - 1 ) {
            out << " ";
        }

        index++;
    }

    return out;
}

std::ostream &Row::ToStream(
        std::ostream &out,
        const ColumnFormatVector &column_format
) const
{
    size_t index = 0;
    size_t size = this->cells.size();
    size_t config_size = column_format.size();

    for ( auto const &cell_it : this->cells ) {
        // We need to determine if there is a associated configuration for this column.
        if ( index < config_size ) {
            ColumnFormat format = column_format.at(index);
            cell_it.get()->ToStream(out, format);
        } else {
            cell_it.get()->ToStream(out);
        }

        // We're only going to print a space for cells in between the start and end cells.
        if ( size != 1 && index != size - 1 ) {
            out << " ";
        }

        index++;
    }

    return out;
}

std::size_t Row::Capacity() const
{
    return this->cells.capacity();
}

} // End Tabulr
