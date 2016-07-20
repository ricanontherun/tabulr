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
#ifndef TABULR_ROW_H
#define TABULR_ROW_H

#include <memory>
#include <vector>
#include <iostream>

#include <tabulr/cell.h>
#include <tabulr/format.h>

namespace Tabulr
{

class Row
{
    public:
        Row();

        /**
         * Insert a new, managed cell into the row.
         *
         * @param content
         *
         * @return
         */
        template <typename T>
        Row *InsertCell(T content);

        std::ostream &ToStream(std::ostream &) const;
        std::ostream &ToStream(
                std::ostream &,
                const std::vector<ColumnFormat> &
        ) const;
    private:
        std::vector<std::unique_ptr<AbstractCell>> cells;
};

template <typename T>
Row *Row::InsertCell(T content)
{
    this->cells.push_back(std::make_unique<Cell<T>>(content));

    return this;
}

}

#endif
