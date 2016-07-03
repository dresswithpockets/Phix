# Phix
Phix is an imperative programming language that is heavily inspired by C and Jai.

The language is designed to recover several of C's pitfalls such as inconsistent type schemes, and a lack of a backend runtime provided services such as minimalistic type management. For an entire list of features, see below

## Features

Heres a WIP list of features that Phix is planned to support. Not all of these features are implemented in the latest version of Phix. Look for a (***RELEASED***) next to each feature to denote whether or not its in the latest stable edition of the Phix compiler.

### Grammatically Correct

Modern Programming Languages follow unusual grammar schemes. Transliterating small phrases of code into english, for the purposes of explanation, often require immediate lookahead of phrases and words.

Phix follows some strict grammar rules that more fluidly transliterate to english.

#### Variable Declaration

Variables follow a "variable of type" grammar rather than the standard "type, variable of" grammar thats notable in C and C++.

Heres a typical variable declaration in C++:
```cpp
char* some_string;
```
In Phix, that would look like:
```cpp
some_string : string = ---;
```
What is `---`? It means "don't initialize". If you don't specify `---` then the variable will default to its respective type's default value:
```cpp
init_string : string;
print(init_string); // prints an empty string

no_init_string : string = ---;
print(no_init_string); // causes a fatal error, crashing the application.
```

Note: `string` is a built in type that houses basic string operation support. However, it casts to and from `^char` seamlessly.

#### Type Specifiers

In almost every modern programming language, type specifiers have an unusual precedent being set

In C and C++, Array notation is specified on the Identifier:
```cpp
float float_array[32];
```
And pointer & reference specifiers are suffixes to the type name:
```cpp
float* float_pointer;
char& char_reference;
```
However, similar to Jai, the Grammar for type specification follows a "pointer to type" format, rather than a "type, pointer to" format:
```cpp
float_array : []float = ---;
int_pointer : ^int = ---;
char_reference : &char = ---;

// Combining:
string_pointer_array2D_reference: &[,]^string = ---;
```

#### Variable Initialization

Just like in most programming languages, initialization can be done at declaration or after.

At the declaration:
```cpp
hello_world : string = "Hello, World!";
```

After declaration:
```cpp
hello_world : string = ---;

hello_world = "Hello, World";
```

Declare and Initialize via Type Inference using `:=`:
```cpp
// The type is inferred at compiletime from the right-hand-side.
// This works with function calls too.
hello_world := "Hello, World!";
```

#### Constant Declaration

Constants are defined with the `::` operator:

Usually, the type is inferred like so:
```cpp
CONSANT_VALUE :: "Some Value";
```

But you can define a constant with a type as well:
```cpp
CONSTANT_VALUE : string :: "Some Value";
```

#### Dynamically-sized Types

A few of the primitive types in Phix are dynamically allocated by default.

`int`, `uint`, `float`, `string`, and `array` are all types which, by default, change in size over their lifetime automatically, dependant upon what values they are set to at runtime.

```cpp
// The runtime will automatically determine that this number is small enough to be an 8-bit integer.
auto_int : int = 5;

// Since 3491 > 256, this will automatically reallocate itself to 16 bits, rather than 8.
auto_int = 3491;
```

Its important to note that reallocation **does not** change the location of the value in memory. `^autoInt` would return the same pointer before and after the assignment to 3491.

Note: If you dont want an integer or floating point value that automatically reallocates itself, you can use the types: `int8`, `int16`, `int32`, `int64`, `short`, `long`, `uint8`, `uint16`, `uint32`, `uint64`, `ushort`, `ulong`, `float32`, `float64`, `single`, `double`.

As for statically-sized arrays, go to the [Arrays section](#Arrays).

#### Pointer Bridges (Dynamically-sized types cont.)

The runtime allocates a new pointer that is another byte long. It then treats this new pointer as the starting pointer when converting from bytes to int16:

```cpp
(5)
0xab0710 : 0000 0101
```
becomes:
```cpp
(3491)
0xab0710 : 1010 0011 // the last 8 bits of (3491) as binary are assigned to this address
0xab0850 : 0000 1101 // then this new address is allocated
```
Now, when getting the value of `auto_int`, the runtime returns the result of `(^(0xab0850) << 8) + ^(0xab0710)`

The original location is still at `0xab0710`, and `^auto_int` returns that address.

Whats occuring here in the runtime is labled as a *"pointer bridge"*. This pointer bridge is mapped out in the runtime so that any direct calls to get values at specific locations based on that variable will cause a jump in memory after the call-length of the first address is exceeded.

Basically: `(^auto_int)[1]` will return `(0xab0850)[0]` or `0000 1101`.

This pointer bridge will exist until `delete` is called on `auto_int`.

#### Arrays

Arrays can contain any type at declaration, except for `void`. Arrays can be multi dimensional and dynamically or statically sized.

A normal, dynamically-sized array is defined and used like so:

```cpp
string_array : []string;

// You can add a value to the end
add_to_array(^string_array, "Hello, ");
add_to_array(^string_array, "World!");

for (it < string_array.length) {
  print("%", string_array[it]);
}
```
Which will output:
```cpp
> Hello, World!
```

#### Generic Types and Parameters


*TODO: Continue comprehensive list of features in Phix*

