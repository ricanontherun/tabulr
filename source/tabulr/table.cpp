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

Table::Table() : num_columns(0)
{

}

Table::Table(std::size_t n) : num_columns(n)
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
    this->rows.push_back(
        std::make_unique<Row>(this->GetNumberOfColumns())
    );

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
Table *Table::SetColumnFormat(ColumnFormatVector format)
{
    this->column_format = format;

    return this;
}

const ColumnFormatVector &Table::GetColumnFormat() const
{
    return this->column_format;
}

std::ostream &operator<<(std::ostream &out, const Table &table)
{
    for ( auto const &row_it : table.rows ) {
        row_it->ToStream(out, table.GetColumnFormat());

        out << std::endl;
    }

    return out;
}

std::size_t Table::GetNumberOfColumns() const
{
    if ( this->rows.size() == 0 )
    {
        return this->num_columns;
    }

    return this->num_columns;
}

}
