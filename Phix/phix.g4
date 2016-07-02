grammar phix;

/*
 * Parser Rules
 */

primaryExpression
    :   Identifier
    |   Constant
    |   StringLiteral+
    |   LeftParen expression RightParen
	|	LeftParen compoundStatement RightParen
    ;

expression
	:	assignmentExpression
	|	expression Comma assignmentExpression
	;

assignmentOperator
	:	Assign | StarAssign | DivAssign | ModAssign | PlusAssign | MinusAssign | LeftShiftAssign | RightShiftAssign | AndAssign | OrAssign | XorAssign
	;

assignmentExpression
	:	conitionalExpression
	|	unaryExpression assignmentOperator assignmentExpression
	;

conditionalExpression
	:	logicalOrExpression (Question expression Colon conditionalExpression)?
	;

logicalOrExpression
    :   logicalAndExpression
    |   logicalOrExpression OrOr logicalAndExpression
    ;

logicalAndExpression
    :   inclusiveOrExpression
    |   logicalAndExpression AndAnd inclusiveOrExpression
    ;

inclusiveOrExpression
    :   exclusiveOrExpression
    |   inclusiveOrExpression Or exclusiveOrExpression
    ;

exclusiveOrExpression
    :   andExpression
    |   exclusiveOrExpression Xor andExpression
    ;

andExpression
    :   equalityExpression
    |   andExpression And equalityExpression
    ;

equalityExpression
    :   relationalExpression
    |   equalityExpression Equals relationalExpression
    |   equalityExpression NotEquals relationalExpression
    ;

relationalExpression
    :   shiftExpression
    |   relationalExpression LessThan shiftExpression
    |   relationalExpression GreaterThan shiftExpression
    |   relationalExpression LessThanEqual shiftExpression
    |   relationalExpression GreaterThanEqual shiftExpression
    ;

shiftExpression
    :   additiveExpression
    |   shiftExpression ShiftLeft additiveExpression
    |   shiftExpression ShiftRight additiveExpression
    ;

additiveExpression
    :   multiplicativeExpression
    |   additiveExpression Plus multiplicativeExpression
    |   additiveExpression Minus multiplicativeExpression
    ;

multiplicativeExpression
    :   castExpression
    |   multiplicativeExpression Star castExpression
    |   multiplicativeExpression Div castExpression
    |   multiplicativeExpression Mod castExpression
    ;

castExpression
    :   unaryExpression
    |   LeftParen typeName RightParen castExpression
    ;

unaryOperator
    :   And | Star | Plus | Minus | Tilde | Not
    ;

unaryExpression
    :   postfixExpression
    |	PlusPlus unaryExpression
    |   MinusMinus unaryExpression
    |   unaryOperator castExpression
    |   SizeOf LeftParen typeName RightParen
	|	TypeOf LeftParen typeName RightParen
	|	TypeOf LeftParen Identifier RightParen
    |   AndAnd Identifier // GCC extension address of label
    ;

argumentExpressionList
    :   assignmentExpression
    |   argumentExpressionList Comma assignmentExpression
    ;

postfixExpression
    :   primaryExpression
    |   postfixExpression LeftBracket expression RightBracket
    |   postfixExpression LeftParen argumentExpressionList? RightParen
    |   postfixExpression Dot Identifier
    |   postfixExpression PlusPlus
    |   postfixExpression MinusMinus
    |   LeftParen typeName RightParen LeftBrace initializerList RightBrace
    |   LeftParen typeName RightParen LeftBrace initializerList Comma RightBrace
    ;

constantExpression
    :   conditionalExpression
    ;

declaration
	:	declarator? Colon initDeclarationSpecifiers SemiColon
	;

initDeclarationSpecifiers
	:	declarationSpecifier+
	|	declarationSpecifier+ Assign initializer
	|	Assign initializer
	;

declarationSpecifier
    :   storageClassSpecifier
    |   typeSpecifier
    |   typeQualifier
    |   functionSpecifier
    |   alignmentSpecifier
    ;

storageClassSpecifier
    :   Typedef
    ;

typeSpecifier
    :   (Void
    |   Char
    |   Short
	|	Uint
	|	Sint
    |   Int
    |   Long
    |   Float
    |   Float32
    |   Float64
	|	Single
    |   Double
	|	Int8
	|	Int16
	|	Int32
	|	Int64
	|	UInt8
	|	UInt16
	|	UInt32
	|	UInt64)
    |   atomicTypeSpecifier
    |   structOrUnionSpecifier
    |   enumSpecifier
    |   typedefName
    ;

structOrUnionSpecifier
    :    Identifier? ColonColon structOrUnion LeftBrace structDeclarationList RightBrace
    ;

structOrUnion
    :   Struct
    |   Union
    ;

structDeclarationList
    :   structDeclaration
    |   structDeclarationList structDeclaration
    ;

structDeclaration
    :   specifierQualifierList structDeclaratorList? Semicolon
	;

// TODO: Finish Struct Declaration

//

/*
 * Lexer Rules
 */

Bool						:	"bool";
Break						:	"break";
Byte						:	"byte";
Case						:	"case";
Char						: 	"char";
Continue					:	"continue";
Delete						:	"delete";
Do							:	"do";
Double						: 	"double";
Else						:	"else";
False						:	"false";
Float						: 	"float";
Float32						:	"float32";
Float64						:	"float64";
For							:	"for";
Foreach						:	"foreach";
If							:	"if";
Inline						:	"inline";
Int							: 	"int";
Int16						:	"int16";
Int32						:	"int32";
Int64						:	"int64";
Int8						:	"int8";
Is							:	"is";
Long						:	"long";
New							:	"new";
Null						:	"null";
Return						:	"return";
Short						:	"short";
Single						: 	"single";
Sint						: 	"sint";
Sizeof						:	"sizeof";
String						: 	"string";
Struct						:	"struct";
Switch						:	"switch";
This						:	"this";
True						:	"true";
Typedef						:	"typedef";
Typeof						:	"typeof";
Uint						: 	"uint";
Uint16						:	"uint16"
Uint32						: 	"uint32";
Uint64						: 	"uint64";
Uint8						:	"uint8";
Ulong						:	"ulong";
Union						:	"union";
Ushort						:	"ushort";
Usong						:	"using";
Var							:	"var";
Void						:	"void";
While						:	"while";

LeftParen					:	"(";
RightParen					:	")";
LeftBracket					:	"[";
RightBracket				:	"]";
LeftBrace					:	"{";
RightBrace					:	"}";

LessThan					:	"<";
LessThanEqual				:	"<=";
GreaterThan					:	">";
GreaterThanEqual			:	">=";
LeftShift					:	"<";
RightShift					:	"<";

Plus						:	"+";
PlusPlus					:	"++";
Minus						:	"-";
MinusMinus					:	"--";
Star						:	"*";
StarStar					:	"**";
Div							:	"/";
Mod							:	"%";

And							:	'&';
Or							:	'|';
Xor							:	'^|';
AndAnd						:	'&&';
OrOr						:	'||';
Caret						:	'^';
Not							:	'!';
Tilde						:	'~';

Question					:	'?';
Colon						:	':';
DoubleColon					:	'::';
Semi						:	';';
Comma						:	',';

Assign						:	'=';
StarAssign					:	'*=';
DivAssign					:	'/=';
ModAssign					:	'%=';
PlusAssign					:	'+=';
MinusAssign					:	'-=';
LeftShiftAssign				:	'<<=';
RightShiftAssign			:	'>>=';
AndAssign					:	'&=';
XorAssign					:	'|||=';
OrAssign					:	'|=';

Equal						:	"==";
NotEqual					:	"!=";

Arrow						:	"->";
Dot							:	".";
Ellipsis					:	"...";

Identifier
    :   IdentifierNondigit
        (   IdentifierNondigit
        |   Digit
        )*
    ;

fragment
IdentifierNondigit
    :   Nondigit
    |   UniversalCharacterName
    ;

fragment
Nondigit
    :   [a-zA-Z_]
    ;

fragment
Digit
    :   [0-9]
    ;

fragment
UniversalCharacterName
    :   '\\u' HexQuad
    |   '\\U' HexQuad HexQuad
    ;

fragment
HexQuad
    :   HexadecimalDigit HexadecimalDigit HexadecimalDigit HexadecimalDigit
    ;

Constant
    :   IntegerConstant
    |   FloatingConstant
    |   CharacterConstant
    ;

fragment
IntegerConstant
    :   DecimalConstant IntegerSuffix?
    |   OctalConstant IntegerSuffix?
    |   HexadecimalConstant IntegerSuffix?
    |	BinaryConstant
    ;

fragment
BinaryConstant
	:	'0' [bB] [0-1]+
	;

fragment
DecimalConstant
    :   NonzeroDigit Digit*
    ;

fragment
OctalConstant
    :   '0' OctalDigit*
    ;

fragment
HexadecimalConstant
    :   HexadecimalPrefix HexadecimalDigit+
    ;

fragment
HexadecimalPrefix
    :   '0' [xX]
    ;

fragment
NonzeroDigit
    :   [1-9]
    ;

fragment
OctalDigit
    :   [0-7]
    ;

fragment
HexadecimalDigit
    :   [0-9a-fA-F]
    ;

fragment
IntegerSuffix
    :   UnsignedSuffix LongSuffix?
    |   UnsignedSuffix LongLongSuffix
    |   LongSuffix UnsignedSuffix?
    |   LongLongSuffix UnsignedSuffix?
    ;

fragment
UnsignedSuffix
    :   [uU]
    ;

fragment
LongSuffix
    :   [lL]
    ;

fragment
LongLongSuffix
    :   'll' | 'LL'
    ;

fragment
FloatingConstant
    :   DecimalFloatingConstant
    |   HexadecimalFloatingConstant
    ;

fragment
DecimalFloatingConstant
    :   FractionalConstant ExponentPart? FloatingSuffix?
    |   DigitSequence ExponentPart FloatingSuffix?
    ;

fragment
HexadecimalFloatingConstant
    :   HexadecimalPrefix HexadecimalFractionalConstant BinaryExponentPart FloatingSuffix?
    |   HexadecimalPrefix HexadecimalDigitSequence BinaryExponentPart FloatingSuffix?
    ;

fragment
FractionalConstant
    :   DigitSequence? '.' DigitSequence
    |   DigitSequence '.'
    ;

fragment
ExponentPart
    :   'e' Sign? DigitSequence
    |   'E' Sign? DigitSequence
    ;

fragment
Sign
    :   '+' | '-'
    ;

fragment
DigitSequence
    :   Digit+
    ;

fragment
HexadecimalFractionalConstant
    :   HexadecimalDigitSequence? '.' HexadecimalDigitSequence
    |   HexadecimalDigitSequence '.'
    ;

fragment
BinaryExponentPart
    :   'p' Sign? DigitSequence
    |   'P' Sign? DigitSequence
    ;

fragment
HexadecimalDigitSequence
    :   HexadecimalDigit+
    ;

fragment
FloatingSuffix
    :   'f' | 'l' | 'F' | 'L'
    ;

fragment
CharacterConstant
    :   '\'' CCharSequence '\''
    |   'L\'' CCharSequence '\''
    |   'u\'' CCharSequence '\''
    |   'U\'' CCharSequence '\''
    ;

fragment
CCharSequence
    :   CChar+
    ;

fragment
CChar
    :   ~['\\\r\n]
    |   EscapeSequence
    ;
fragment
EscapeSequence
    :   SimpleEscapeSequence
    |   OctalEscapeSequence
    |   HexadecimalEscapeSequence
    |   UniversalCharacterName
    ;
fragment
SimpleEscapeSequence
    :   '\\' ['"?abfnrtv\\]
    ;
fragment
OctalEscapeSequence
    :   '\\' OctalDigit
    |   '\\' OctalDigit OctalDigit
    |   '\\' OctalDigit OctalDigit OctalDigit
    ;
fragment
HexadecimalEscapeSequence
    :   '\\x' HexadecimalDigit+
    ;
StringLiteral
    :   EncodingPrefix? '"' SCharSequence? '"'
    ;
fragment
EncodingPrefix
    :   'u8'
    |   'u'
    |   'U'
    |   'L'
    ;
fragment
SCharSequence
    :   SChar+
    ;
fragment
SChar
    :   ~["\\\r\n]
    |   EscapeSequence
    |   '\\\n'   // Added line
    |   '\\\r\n' // Added line
    ;

Whitespate
	:	[ \t]+
		-> skip
	;

Newline
	:	(	'\r' '\n'?
		|	'\n'
		)
		-> skip
	;

BlockComment
    :   '/*' .*? '*/'
        -> skip
    ;

LineComment
    :   '//' ~[\r\n]*
        -> skip
    ;