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

std::ostream &Row::ToStream(std::ostream &out, const std::vector<ColumnConfig> &column_config) const
{
    for ( auto const &it : this->cells ) {
        // Does this cell have an associated configuration?

        // We need to give each cell it's associated confiration, if applicable.
        it.get()->Output(out);

        out << " ";
    }

    return out;
}

}
