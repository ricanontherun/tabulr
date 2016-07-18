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

#include <vector>
#include <iostream>

int main()
{
    std::vector<struct Tabulr::ColumnFormat> format;

    Tabulr::ColumnFormat col1 = {
        .width = 10, .precision = 1, .fill = ' ', .position = Tabulr::POSITION::LEFT
    };

    format.push_back(col1);

    Tabulr::ColumnFormat col2 = {
        .width = 10, .precision = 1, .fill = ' ', .position = Tabulr::POSITION::RIGHT
    };

    format.push_back(col2);

    Tabulr::ColumnFormat col3 = {
        .width = 20, .precision = 2, .fill = ' ', .position = Tabulr::POSITION::RIGHT
    };

    format.push_back(col3);

    // Make a new table.
    Tabulr::Table table;

    // Set the format, styling
    table.SetColumnFormat(format);

    // Make a row which will act as a header.
    Tabulr::Row *heading = table.MakeRow();

    heading->InsertCell("Quarter")->InsertCell("Manager")->InsertCell("Earnings");

    Tabulr::Row *row = table.MakeRow();

    row->InsertCell(1)->InsertCell("Christian")->InsertCell(13345.45);

    std::cout << table;
}
