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
    Tabulr::Row *heading = table.MakeRow();

    heading->InsertCell("Quarter")->InsertCell("Manager")->InsertCell("Earnings");

    Tabulr::Row *row = table.MakeRow();

    row->InsertCell(1)->InsertCell("Christian")->InsertCell(13345.45);

    std::cout << table;
}
