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

#include <iostream>
#include <memory>
#include <vector>

#include <tabulr/column.h>

namespace Tabulr
{

class Row
{
    public:
        Row();

        template <typename T>
        void AddNewColumn(T content);

        template <typename T>
        void PrintCell(const std::unique_ptr<AbstractColumn> &col) const;

        void PrintRow() const;
    private:
        std::vector<std::unique_ptr<AbstractColumn>> columns;
};

template <typename T>
void Row::AddNewColumn(T content)
{
    this->columns.push_back(std::make_unique<Column<T>>(content));
}

template <typename T>
void Row::PrintCell(const std::unique_ptr<AbstractColumn> &col) const
{
    Column<T> *column = dynamic_cast<Column<T> *>(col.get());

    std::cout << *column << std::endl;
}

void Row::PrintRow() const
{
    for (auto it : this->columns) {
        std::cout << it << std::endl;
    }
}

}

#endif
