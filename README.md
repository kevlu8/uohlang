# UOHLang

A minimal programming language that can be interpreted or compiled directly to x86-64 assembly (left as an exercise to the reader).

## Syntax

The syntax is very simple: every token is an instruction. This means that instructions are separated by whitespaces, whether that be a space, a tab, or a newline. The following instructions are supported:

`plap` - Increments the pointer by 1

`crot` - Decrements the pointer by 1

`cunny` - Prints the byte at the pointer as a character

`breasts` - Begins a comment

`thighs` - Ends a comment (multiline comments are allowed, but nested comments are not)

`loli` - Sets the current instruction as a label that can be jumped to. Having any other characters after `loli` will define different labels, for example `loli1`, `loliabc`, and `loli` are all valid labels.

`getpregnant` - Jumps to the label defined by `loli` with the matching terminating characters if the current byte at the pointer is nonzero. For example, `getpregnant1` will jump to `loli1`, `getpregnantabc` will jump to `loliabc`, and `getpregnant` will jump to `loli`.

`uoh` - Increments the byte at the pointer by however many `h` characters follow `uo`. For example, `uohhh` will increment the byte at the pointer by 3.

`ou` - Decrements the byte at the pointer by however many `u` characters follow `o`. For example, `ouu` will decrement the byte at the pointer by 2.

