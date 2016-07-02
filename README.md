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
char* someString;
```
In Phix, that would look like:
```cpp
someString : string;
```

Note: `string` is a built in type that houses basic string operation support. However, it casts to and from `^char` seamlessly.

#### Type Specifiers

In almost every modern programming language, type specifiers have an unusual precedent being set

In C and C++, Array notation is specified on the Identifier:
```cpp
float floatArray[32];
```
And pointer & reference specifiers are suffixes to the type name:
```cpp
float* floatPointer;
char& charReference;
```
However, similar to Jai, the Grammar for type specification follows a "pointer to type" format, rather than a "type, pointer to" format:
```cpp
floatArray : []float;
intPointer : ^int;
charReference : &char;

// Combining:
stringPointerArray2DReference: &[,]^string;
```

#### Variable Initialization

Just like in most programming languages, initialization can be done at declaration or after.

At the declaration:
```cpp
helloWorld : string = "Hello, World!";
```

After declaration:
```cpp
helloWorld : string;

helloWorld = "Hello, World";
```

Declare and Initialize via Type Inference:
```cpp
helloWorld := "Hello, World!";
```

*TODO: Continue comprehensive list of features in Phix*

