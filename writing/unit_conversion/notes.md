# Universal Measurement

## Problem

We would like a program that takes a measurement in one unit (e.g., 4.5 quarts) and
converts it to another unit (e.g., liters). For example, this conversion request

> 450 km miles

would result in this program output.

> 450.0000 km = 279.6247 miles

The program should produce an error message if a conversion between two units of different class (e.g., liquid volume to distance) is requested. The program should taken a database of conversion information form an input file before accepting conversion problems entered interactively  by the user. The user should be able to specify the units either by name (e.g., kilograms) or by abbreviation (e.g.,kg).

## Analysis

This program's basic data objects are units of measurement. We need to define a structure type that groups all relevant attributes about one units. We can then store a database of these structures in an array and look up conversion factors as needed. To convert a measurement, the user will need to provide the measurement as a number string (e.g., 5 kg or 6.5 inches). The user must also enter the name or abbreviation of the desired units.

The attributes of a unit include its name and abbreviation, its class (mass, distance, and so on), and a representation of the unit in terms of the chosen standard unit for its class. If we allow the actual unit name, class names, and standard units to be determined by the contents of the input file, the program will be usable for any class of measurements and for units in any language based on our character set.

## DATA REQUIREMENTS

### Structured Data Type

`unit_t`
    components:
    `name` /*character string such as "milligrams"*/ \
    `abbrev` /*shorter character string such as "mg"*/ \
    `class` /*character string "liquid_volume", "distance", or "mass"*/ \
    `standard` /*number of standard units that are equivalent to this unit*/ \

### Problem Constants

`NAME_LEN 30` /*storage allocated for a unit one*/ \
`ABBREV_LEN 15` /*storage allocated for a unit abbreviation*/ \
`CLASS LEN 20` /*storage allocated for a measurement class*/ \
`MAX_UNITS 20` /*maximum number of different units handled*/ \

### Problem Inputs

`unit_t units[MAX_UNITS]` /*array representing unit conversion factors database*/ \
`double quantity` /*value to convert*/ \
`char old_units[NAME_LEN]` /*name or abbreviation of units to be converted*/ \
`char new_units[NAME_LEN]` /*name or abbreviation of units to convert to*/ \

### Problem Output

Message giving conversion.

## DESIGN

### Algorithm

$1.$ Load units of measurement database. \
$2.$ Get value to convert and old new unit names. \
$3.$ Repeat until data format error encountered.\
&emsp; &emsp; $4.$ Search for old units in database. \
&emsp; &emsp; $5.$ Search for new units in database. \
$6.$ if conversion is impossible. \
&emsp; &emsp; $7.$  Issue appropriate error message. \
&emsp; `else`
&emsp; &emsp; $8.$ Compute and display conversion. \
$9.$ Get value to convert and old and new unit names.

The refinement of step $1.$ follows. \
$1.1$ Open database file. \
$1.2$ Initialize subscripting variable `i`. \
$1.3$ Scan a unit structure from the database file. \
$1.4$ Repeat until `EOF`, data format error, or attempted overflow of `units` list \
&emsp; &emsp; $1.4.1$ Store unit structure in `units` array. \
&emsp; &emsp; $1.4.2$ Update `i`. \
&emsp; &emsp; $1.4.3$ Scan next unit structure from file.
$1.5$ Close the database file.

We will develop separate functions for step $1$ `load_units`, for step 1.3 and step $1.4.3$ `(fscan_unit)`, for the search used in step $4$ and step $5$, and for the conversion aspect of step $8$. We can base our `search` function on the linear search algorithm used in Fig $7.14$.

## Array Search

**FIGURE 7.14** &nbsp; ***Linear Search***: Function That Searches for a Target Value in an Array.

In order to search an array, we need to know the array element value we are seeking, or the search *target*. Then, we can perform the search by examining in turn  each array element using a loop and by testing whether the element matches the  target. The search loop should be exited when the target value is found; this process is called a linear search . The following algorithm for *linear search* sets a flag (for loop control) when the element being tested matches the target.

## IMPLEMENTATION

Code that implements our universal conversion program is shown in **FIGURE 10.12**
