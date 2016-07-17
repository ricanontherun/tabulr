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
#include <tabulr/table.h>

#include <tabulr/format.h>

namespace Tabulr
{

Table::Table()
{

}

/**
 * Make a new row which is managed interally by the table.
 * The point returned by this function is managed interally, do not deleted it.
 *
 * @return
 */
Row *Table::MakeRow()
{
    // Add a new row.
    this->rows.push_back(std::make_unique<Row>());

    // Return a pointer to the row we just created.
    return this->rows.back().get();
}

/**
 * Set the column config. Each vector element represents the configuration
 * for it's associated column in the order the were added to each row.
 *
 * @param std::vector
 *
 * @return
 */
Table *Table::SetColumnFormat(std::vector<struct ColumnFormat> config)
{
    this->column_config = config;

    return this;
}

const std::vector<ColumnFormat> &Table::GetColumnFormat() const
{
    return this->column_config;
}

std::ostream &operator<<(std::ostream &out, const Table &table)
{
    for ( auto const &it : table.rows ) {
        it->ToStream(out, table.GetColumnFormat());

        out << std::endl;
    }

    return out;
}

}
