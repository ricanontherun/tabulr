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
#ifndef TABULR_TABLE_H
#define TABULR_TABLE_H

#include <memory>
#include <vector>

#include <tabulr/row.h>

namespace Tabulr
{

class Table
{
    public:
        /**
         * Default constructor
         */
        Table();

        /**
         * Copy Constructor
         *
         * @param
         */
        Table(const Table &);

        /**
         * Construct with the table's projected width (columns).
         *
         * @param num_columns
         */
        Table(std::size_t num_columns);

        /**
         * Construct with the table's projected dimensions.
         *
         * @param num_columns
         * @param num_rows
         */
        Table(std::size_t num_columns, std::size_t num_rows);

        /**
         * Make a new row which is managed interally by the table.
         * The point returned by this function is managed interally, do not deleted it.
         *
         * @return
         */
        Row *MakeRow();

        /**
         * Set the column config. Each vector element represents the configuration
         * for it's associated column in the order the were added to each row.
         *
         * @param std::vector
         *
         * @return
         */
        Table *SetColumnFormat(ColumnFormatVector);

        /**
         * Retrieve the column format for this table.
         *
         * @return
         */
        const ColumnFormatVector &GetColumnFormat() const;

        friend std::ostream &operator<<(std::ostream &, const Table &);
    private:
        ColumnFormatVector column_format;

        std::size_t num_columns;

        std::size_t num_rows;

        std::vector<std::unique_ptr<Row>> rows;

        std::size_t NumberOfColumns() const;
};

} // Namespace Tabulr

#endif
