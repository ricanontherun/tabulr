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

int main()
{
    // Make a new table.
    Tabulr::Table table;

    // Make a new row.
    // NOTE: The pointer returned is OWNED BY table, do don't delete it!
    Tabulr::Row *row = table.MakeRow();

    // Here in lies the power of this class.
    // We can add columns of ANY type.
    int i = 1122;
    row->AddNewColumn(i);

    double f = 12.3;
    row->AddNewColumn(f);

    std::string name("Christian Roman");
    row->AddNewColumn(name);

    // Print the row's cells.
    row->PrintRow();
}
