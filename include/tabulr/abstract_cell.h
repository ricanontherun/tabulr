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
#ifndef TABULR_ABSTRACT_COLUMN_H
#define TABULR_ABSTRACT_COLUMN_H

#include <iostream>

namespace Tabulr
{

class AbstractCell
{
    public:
        AbstractCell() {};
        virtual ~AbstractCell() {};

        // This is, as far as I know, the only way to print the contents of a Column<T>
        // given it's base class.
        virtual std::ostream &Output(std::ostream &) const = 0;
};

}

#endif