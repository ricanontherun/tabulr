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
        Table();

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
        Table *SetColumnConfig(std::vector<struct ColumnConfig>);

        friend std::ostream &operator<<(std::ostream &, const Table &);
    private:
        std::vector<struct ColumnConfig> column_config;
        std::vector<std::unique_ptr<Row>> rows;
};

} // Namespace Tabulr

#endif
