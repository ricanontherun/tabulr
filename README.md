# Tabulr
[![Build Status](https://travis-ci.org/ricanontherun/tabulr.svg?branch=dev)](https://travis-ci.org/ricanontherun/tabulr)

## Dependencies
* C++14

## Tests
To run the test suite:
```sh
cd tests
sh run-tests.sh
```

## Basic Usage
#### Creating a table
The more information you give a table, the smarter it will allocate memory.
```cpp
// Default constructor
Tabulr::Table my_table;

// Provide number of columns, faster than the default constructor.
Tabulr::Table four_column_table(4);

// Provide number of columns and rows. 30% faster than default, on average.
Tabulr::Table four_column_three_row_table(4,3);
```
#### Adding structure
Rows are displayed in the order they are created, top to bottom.
```cpp
    // Create a new row.
    // Note: Rows are managed by the table via smart pointers, don't worry about them.
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
Tabulr provides formatting in the form of Tabulr::ColumnFormats, more information coming soon.
For now, check out main.cpp for usage examples.
