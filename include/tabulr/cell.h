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

#include <sstream>
#include <iostream>
#include <iomanip>

namespace Tabulr {

    template<class T>
    class Cell : public AbstractCell {
    public:
        Cell(T);

        ~Cell() {};

        std::ostream &ToStream(std::ostream &out) const;

        std::ostream &ToStream(std::ostream &out, const ColumnFormat &) const;

    private:
        T content;
    };

    template<class T>
    Cell<T>::Cell(T content) : content(content) {

    }

    template<class T>
    std::ostream &Cell<T>::ToStream(std::ostream &out) const {
        out << this->content;
        return out;
    }

    template<class T>
    std::ostream &Cell<T>::ToStream(std::ostream &out, const ColumnFormat &format) const {
        if (format.GetWidth() != 0) {
            out << std::setw(format.GetWidth());
        }

        out << std::setfill(format.GetFill());

        if (format.GetPrecision() != 0) {
            out << std::fixed;
            out << std::setprecision(format.GetPrecision());
        }

        std::uint8_t position = static_cast<std::uint8_t>(format.GetPosition());

        if (position) {
            switch (format.GetPosition()) {
                case POSITION::LEFT:
                    out << std::left;
                    break;
                case POSITION::INTERNAL:
                    out << std::internal;
                    break;
                case POSITION::RIGHT:
                    out << std::right;
                    break;
            }
        }

        return this->ToStream(out);
    }

}

#endif

