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

Table::Table() : num_columns(0), num_rows(0)
{

}

Table::Table(const Table &table)
: num_columns(table.num_columns), num_rows(table.num_rows)
{
}

Table::Table(
    std::size_t num_columns
) : num_columns(num_columns), num_rows(0)
{
}

Table::Table(
    std::size_t num_columns,
    std::size_t num_rows
) : num_columns(num_columns), num_rows(num_rows)
{
    this->rows.reserve(num_rows);
}

/**
 * Make a new row which is managed interally by the table.
 * The point returned by this function is managed interally, do not deleted it.
 *
 * @return
 */
Row *Table::MakeRow()
{
    this->rows.push_back(
        std::make_unique<Row>(this->NumberOfColumns())
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

        out << "\n";
    }

    return out;
}

std::size_t Table::NumberOfColumns() const
{
    if ( this->num_columns != 0 )
    {
        return this->num_columns;
    }

    if ( this->rows.size() >= 1 )
    {
        // Get the number of columns in the first row.
        return this->rows.front()->Capacity();
    }

    return 0;
}

}
