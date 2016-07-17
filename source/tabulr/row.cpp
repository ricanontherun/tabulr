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

#include <tabulr/format.h>

namespace Tabulr
{

Row::Row()
{

}

std::ostream &Row::ToStream(
        std::ostream &out,
        const std::vector<ColumnFormat> &column_config
) const
{
    uint32_t index = 0;
    uint32_t config_size = column_config.size();

    for ( auto const &it : this->cells ) {
        // We need to determine if there is a associated configuration for this column.
        if ( index < config_size ) {
            ColumnFormat format = column_config[index];
            it.get()->ToStream(out, format);
        } else {
            it.get()->ToStream(out);
        }

        out << " ";

        index++;
    }

    return out;
}

}
