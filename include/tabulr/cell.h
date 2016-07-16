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
#ifndef TABULR_COLUMN_H
#define TABULR_COLUMN_H

#include <tabulr/abstract_cell.h>

#include <iostream>
#include <sstream>

namespace Tabulr
{

template <class T>
class Cell : public AbstractCell
{
    public:
        Cell(T);
        ~Cell() {};

        std::ostream &Output(std::ostream &out) const;
    private:
        T content;
};

template <class T>
Cell<T>::Cell(T content) : content(content)
{

}

template <class T>
std::ostream &Cell<T>::Output(std::ostream &out) const
{
    out << this->content;
    return out;
}

}

#endif
