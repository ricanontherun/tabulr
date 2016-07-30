# Tabulr [![Build Status](https://travis-ci.org/ricanontherun/tabulr.svg?branch=master)](https://travis-ci.org/ricanontherun/tabulr)
## Basic Usage
#### Creating a table
```cpp
Tabulr::Table my_table;
```
#### Adding structure
Rows are displayed in the order they are created, top to bottom.
```cpp
    // Create a new row. Note: Rows are managed by the table via smart pointers, don't worry about them.
    Tabulr::Row *first_row = my_table.MakeRow();
```
Cells are added to rows and are displayed in the order they are added, left to right. Spaces are printed between cells
automatically.
```cpp
    // Add some headings to first_row.
    first_row->InsertCell("Quarter")->InsertCell("Earnings");
    
    // Add a second row with data.
    Tabulr::Row *second_row = my_table->MakeRow();
    
    // Cells can be of any type.
    second_row->InsertCell(1)->InsertCell(5133667.12);
    
    // Output the entire table to any stream.
    std::cout << my_table.
    
```
#### Fomatting
Tabulr provides formatting in the form of Tabulr::ColumnFormats

