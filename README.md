# Tabulr
[![Build Status](https://travis-ci.org/ricanontherun/tabulr.svg?branch=master)](https://travis-ci.org/ricanontherun/tabulr)

## Dependencies
* C++14
* cmake >= 2.8.7

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
Tabulr provides formatting in the form of Tabulr::ColumnFormat vectors. Each vector element represents a the formatting for all
cells in that colunm. ColumnFormat objects specify things like a column's width, fill, precision and position.
```cpp
    // Create a ColumnFormatVector
    Tabulr::ColumnFormatVector format;
    
    // Add a column format of width 10 and precision 2.
    format.push_back(Tabulr::ColumnFormat(10, 2));
    
    // Add another column format with just a width of 20
    format.push_back(Tabulr::ColunmFormat(100));
    
    // Set the table's format vector
    table.SetColumnFormat(format);
```
## More Documentation on the way

