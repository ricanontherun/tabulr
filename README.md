# Tabulr [![Build Status](https://travis-ci.org/ricanontherun/tabulr.svg?branch=master)](https://travis-ci.org/ricanontherun/tabulr) [![Build Status](https://travis-ci.org/ricanontherun/tabulr.svg?branch=dev)](https://travis-ci.org/ricanontherun/tabulr)
Generating terminal tables in C++ can be verbose. Tabulr features an simple API for creating terminal tables.

## Include
```cpp
#include <tabulr/tabulr.h>
```

## Basic Usage
```cpp
    Tabulr::Table table;
    
    // Create a new Tabulr::Row. NOTE, this pointer is managed internally by table, don't delete it.
    // Rows are placed in the heirarchy as they are created, so this is the top row.
    Tabulr::Row *header = table.MakeRow();
    
    // Each row contains cells (columns) which can be of any type.

    // When each cell is generated, Tabulr uses the << operator internally
    // to place the cells' contents into an output stream. Any objects inserted into cells
    // need to have this operator overloaded with this in mind.
        
    // Also, method chaining ftw
    header->InsertCell("Quarter")->InsertCell("Team")->InsertCell("Earnings");

    // Let's make another row with some actual data.
    Tabulr::Row *row = table.MakeRow();
    
    // Similar to rows, cells are displayed in the order they are created.
    row->InsertCell(1)->InsertCell("Sales")->InsertCell(1234.56);
    
    // To output the table, simply use the << operator.
    std::cout << table;
```
