## modulo-calc

If you have ever wondered if C's modulo function returns the results you would expect compared to the modulo operator 
used in number theory (particularly with negative numbers), you can use this tool to check multiples cases without recompiling a one-line
print statement.

The [Euclidean definition](https://en.wikipedia.org/wiki/Euclidean_division) of mod says the result should always be non-negative:

`a mod b = r, where a = b * q + r and (0 <= r < b)`

So with this convention `-7 % 3 = 2`

as `-7 = 3 * q + r`  
which, given (0 <= r < b), must be `-7 = 3 * -3 + 2`.

The [C99 Standard](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html) defines the mod operation differently:

"Modular division returns the remainder produced after performing integer division on the two operands. 
The operands must be of a primitive integer type."

So for C `-7 % 3 = -1`

I'm curious about the rest of this story, but for now this is a simple tool to explore these different conventions.

