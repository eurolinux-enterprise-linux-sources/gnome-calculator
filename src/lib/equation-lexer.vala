/*
 * Copyright (C) 2012 Arth Patel
 * Copyright (C) 2012 Robert Ancell
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version. See http://www.gnu.org/copyleft/gpl.html the full text of the
 * license.
 */

/* Enum for tokens generated by pre-lexer and lexer. */
public enum LexerTokenType
{
    UNKNOWN,              /* Unknown */

    /* These are all Pre-Lexer tokens, returned by pre-lexer */
    PL_DECIMAL,           /* Decimal separator */
    PL_DIGIT,             /* Decimal digit */
    PL_HEX,               /* A-F of Hex digits */
    PL_SUPER_DIGIT,       /* Super digits */
    PL_SUPER_MINUS,       /* Super minus */
    PL_SUB_DIGIT,         /* Sub digits */
    PL_FRACTION,          /* Fractions */
    PL_DEGREE,            /* Degree */
    PL_MINUTE,            /* Minutes */
    PL_SECOND,            /* Seconds */
    PL_LETTER,            /* Alphabets */
    PL_EOS,               /* End of stream */
    PL_SKIP,              /* Skip this symbol (whitespace or newline). */

    /* These are all tokens, returned by Lexer. */
    ADD,                /* Plus */
    SUBTRACT,           /* Minus */
    MULTIPLY,           /* Multiply */
    DIVIDE,             /* Divide  */
    MOD,                /* Modulus */
    L_FLOOR,            /* Floor ( Left ) */
    R_FLOOR,            /* Floor ( Right ) */
    L_CEILING,          /* Ceiling ( Left ) */
    R_CEILING,          /* Ceiling ( Right ) */
    ROOT,               /* Square root */
    ROOT_3,             /* Cube root */
    ROOT_4,             /* Fourth root */
    NOT,                /* Bitwise NOT */
    AND,                /* Bitwise AND */
    OR,                 /* Bitwise OR */
    XOR,                /* Bitwise XOR */
    IN,                 /* IN ( for converter ) */
    NUMBER,             /* Number */
    SUP_NUMBER,         /* Super Number */
    NSUP_NUMBER,        /* Negative Super Number */
    SUB_NUMBER,         /* Sub Number */
    FUNCTION,           /* Function */
    UNIT,               /* Unit of conversion */
    VARIABLE,           /* Variable name */
    ASSIGN,             /* = */
    L_R_BRACKET,        /* ( */
    R_R_BRACKET,        /* ) */
    L_S_BRACKET,        /* [ */
    R_S_BRACKET,        /* ] */
    L_C_BRACKET,        /* { */
    R_C_BRACKET,        /* } */
    ABS,                /* | */
    POWER,              /* ^ */
    FACTORIAL,          /* ! */
    PERCENTAGE,         /* % */
    ARGUMENT_SEPARATOR  /* ; (Function argument separator) */
}

// FIXME: Merge into lexer
public class PreLexer : Object
{
    public string stream; /* String being scanned */
    public int index;      /* Current character index */
    public int mark_index; /* Location, last marked. Useful for getting substrings as part of highlighting */
    private bool eos = false;

    public PreLexer (string input)
    {
        stream = input;
        index = 0;
        mark_index = 0;
    }

    /* Roll back last scanned unichar. */
    public void roll_back ()
    {
        if (eos)
        {
            eos = false;
            return;
        }
        unichar c;
        stream.get_prev_char (ref index, out c);
    }

    /* Set marker index. To be used for highlighting and error reporting. */
    public void set_marker ()
    {
        mark_index = index;
    }

    /* Get marked substring. To be used for error reporting. */
    public string get_marked_substring ()
    {
        return stream.substring (mark_index, index - mark_index);
    }

    /* Pre-Lexer tokanizer. To be called only by Lexer. */
    public LexerTokenType get_next_token ()
    {
        unichar c;
        if (!stream.get_next_char (ref index, out c))
        {
            // We have to flag if we ran out of chars, as roll_back from PL_EOS should have no effect
            eos = true;
            return LexerTokenType.PL_EOS;
        }
        eos = false;

        if (c == ',' || c == '.')
            return LexerTokenType.PL_DECIMAL;

        if (c.isdigit ())
            return LexerTokenType.PL_DIGIT;

        if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
            return LexerTokenType.PL_HEX;

        if (c == '⁰' || c == '¹' || c == '²' || c == '³' || c == '⁴' || c == '⁵' || c == '⁶' || c == '⁷' || c == '⁸' || c == '⁹')
            return LexerTokenType.PL_SUPER_DIGIT;

        if (c == '⁻')
            return LexerTokenType.PL_SUPER_MINUS;

        if (c == '₀' || c == '₁' || c == '₂' || c == '₃' || c == '₄' || c == '₅' || c == '₆' || c == '₇' || c == '₈' || c == '₉')
            return LexerTokenType.PL_SUB_DIGIT;

        if (c == '½' || c == '⅓' || c == '⅔' || c == '¼' || c == '¾' || c == '⅕' || c == '⅖' || c == '⅗' || c == '⅘' || c == '⅙' || c == '⅚' || c == '⅛' || c == '⅜' || c == '⅝' || c == '⅞')
            return LexerTokenType.PL_FRACTION;

        if (c == '°')
            return LexerTokenType.PL_DEGREE;

        if (c == '\'')
            return LexerTokenType.PL_MINUTE;

        if (c == '"')
            return LexerTokenType.PL_SECOND;

        if (c.isalpha () || c == '_')
            return LexerTokenType.PL_LETTER;

        if (c == '∧')
            return LexerTokenType.AND;

        if (c == '∨')
            return LexerTokenType.OR;

        if (c == '⊻' || c == '⊕')
            return LexerTokenType.XOR;

        if (c == '¬' || c == '~')
            return LexerTokenType.NOT;

        if (c == '+')
            return LexerTokenType.ADD;

        if (c == '-' || c == '−' || c == '–')
            return LexerTokenType.SUBTRACT;

        if (c == '*' || c == '×')
            return LexerTokenType.MULTIPLY;

        if (c == '/' || c == '∕' || c == '÷')
            return LexerTokenType.DIVIDE;

        if (c == '⌊')
            return LexerTokenType.L_FLOOR;

        if (c == '⌋')
            return LexerTokenType.R_FLOOR;

        if (c == '⌈')
            return LexerTokenType.L_CEILING;

        if (c == '⌉')
            return LexerTokenType.R_CEILING;

        if (c == '√')
            return LexerTokenType.ROOT;

        if (c == '∛')
            return LexerTokenType.ROOT_3;

        if (c == '∜')
            return LexerTokenType.ROOT_4;

        if (c == '=')
            return LexerTokenType.ASSIGN;

        if (c == '(')
            return LexerTokenType.L_R_BRACKET;

        if (c == ')')
            return LexerTokenType.R_R_BRACKET;

        if (c == '[')
            return LexerTokenType.L_S_BRACKET;

        if (c == ']')
            return LexerTokenType.R_S_BRACKET;

        if (c == '{')
            return LexerTokenType.L_C_BRACKET;

        if (c == '}')
            return LexerTokenType.R_C_BRACKET;

        if (c == '|')
            return LexerTokenType.ABS;

        if (c == '^')
            return LexerTokenType.POWER;

        if (c == '!')
            return LexerTokenType.FACTORIAL;

        if (c == '%')
            return LexerTokenType.PERCENTAGE;

        if (c == ';')
            return LexerTokenType.ARGUMENT_SEPARATOR;

        if (c == ' ' || c == '\r' || c == '\t' || c == '\n')
            return LexerTokenType.PL_SKIP;

        return LexerTokenType.UNKNOWN;
    }
}

/* Structure to hold single token. */
public class LexerToken : Object
{
    public string text;                /* Copy of token string. */
    public uint start_index;           /* Start index in original stream. */
    public uint end_index;             /* End index in original stream. */
    public LexerTokenType type;  /* Type of token. */
}

/* Structure to hold lexer state and all the tokens. */
public class Lexer : Object
{
    private Parser parser;           /* Pointer to the parser parser. */
    private PreLexer prelexer;       /* Pre-lexer  Pre-lexer is part of lexer. */
    public List<LexerToken> tokens;  /* Pointer to the dynamic array of LexerTokens. */
    private uint next_token;         /* Index of next, to be sent, token. */
    private int number_base;

    public Lexer (string input, Parser parser, int number_base = 10)
    {
        prelexer = new PreLexer (input);
        tokens = new List<LexerToken> ();
        next_token = 0;
        this.parser = parser;
        this.number_base = number_base;
    }

    public void scan ()
    {
        while (true)
        {
            var token = insert_next_token ();
            tokens.append (token);
            if (token.type == LexerTokenType.PL_EOS)
                break;
        }
    }

    /* Get next token interface. Will be called by parser to get pointer to next token in token stream. */
    public LexerToken get_next_token ()
    {
        if (next_token >= tokens.length ())
            return tokens.nth_data (tokens.length () - 1);
        return tokens.nth_data (next_token++);
    }

    /* Roll back one lexer token. */
    public void roll_back ()
    {
        if (next_token > 0)
            next_token--;
    }

    private bool check_if_function ()
    {
        var name = prelexer.get_marked_substring ();
        return parser.function_is_defined (name);
    }

    private bool check_if_unit ()
    {
        int super_count = 0;
        while (prelexer.get_next_token () == LexerTokenType.PL_SUPER_DIGIT)
            super_count++;

        prelexer.roll_back ();

        var name = prelexer.get_marked_substring ();
        if (parser.unit_is_defined (name))
            return true;

        while (super_count-- > 0)
            prelexer.roll_back ();

        name = prelexer.get_marked_substring ();
        return parser.unit_is_defined (name);
    }

    private bool check_if_number ()
    {
        int count = 0;
        var text = prelexer.get_marked_substring ();

        var tmp = mp_set_from_string (text, number_base);
        if (tmp != null)
            return true;
        else
        {
            /* Try to rollback several characters to see, if that yields any number. */
            while (text != "")
            {
                tmp = mp_set_from_string (text, number_base);
                if (tmp != null)
                    return true;
                count++;
                prelexer.roll_back ();
                text = prelexer.get_marked_substring ();
            }

            /* Undo all rollbacks. */
            while (count-- > 0)
                prelexer.get_next_token ();

            return false;
        }
    }

    /* Insert generated token to the lexer */
    private LexerToken insert_token (LexerTokenType type)
    {
        var token = new LexerToken ();
        token.text = prelexer.get_marked_substring ();
        token.start_index = prelexer.mark_index;
        token.end_index = prelexer.index;
        token.type = type;

        return token;
    }

    /* Generates next token from pre-lexer stream and call insert_token () to insert it at the end. */
    private LexerToken insert_next_token ()
    {
        /* Mark start of next token */
        prelexer.set_marker ();

        /* Ignore whitespace */
        var type = prelexer.get_next_token ();
        while (type == LexerTokenType.PL_SKIP)
        {
            prelexer.set_marker ();
            type = prelexer.get_next_token ();
        }

        if (type == LexerTokenType.AND || type == LexerTokenType.OR || type == LexerTokenType.XOR || type == LexerTokenType.NOT || type == LexerTokenType.ADD || type == LexerTokenType.SUBTRACT || type == LexerTokenType.MULTIPLY || type == LexerTokenType.DIVIDE || type == LexerTokenType.L_FLOOR || type == LexerTokenType.R_FLOOR || type == LexerTokenType.L_CEILING || type == LexerTokenType.R_CEILING || type == LexerTokenType.ROOT || type == LexerTokenType.ROOT_3 || type == LexerTokenType.ROOT_4 || type == LexerTokenType.ASSIGN || type == LexerTokenType.L_R_BRACKET || type == LexerTokenType.R_R_BRACKET || type == LexerTokenType.L_S_BRACKET || type == LexerTokenType.R_S_BRACKET || type == LexerTokenType.L_C_BRACKET || type == LexerTokenType.R_C_BRACKET || type == LexerTokenType.ABS || type == LexerTokenType.POWER || type == LexerTokenType.FACTORIAL || type == LexerTokenType.PERCENTAGE || type == LexerTokenType.ARGUMENT_SEPARATOR)
            return insert_token (type);

        /* [LexerTokenType.PL_SUPER_MINUS][LexerTokenType.PL_SUPER_DIGIT]+ */
        if (type == LexerTokenType.PL_SUPER_MINUS)
        {
            if ((type = prelexer.get_next_token ()) != LexerTokenType.PL_SUPER_DIGIT)
            {
                /* ERROR: expected LexerTokenType.PL_SUP_DIGIT */
                parser.set_error (ErrorCode.MP, prelexer.get_marked_substring (), prelexer.mark_index, prelexer.index);
                return insert_token (LexerTokenType.UNKNOWN);
            }

            /* Get all LexerTokenType.PL_SUPER_DIGITs. */
            while (prelexer.get_next_token () == LexerTokenType.PL_SUPER_DIGIT);
            prelexer.roll_back ();

            return insert_token (LexerTokenType.NSUP_NUMBER);
        }

        /* [LexerTokenType.PL_SUPER_DIGIT]+ */
        if (type == LexerTokenType.PL_SUPER_DIGIT)
        {
            while (prelexer.get_next_token () == LexerTokenType.PL_SUPER_DIGIT);
            prelexer.roll_back ();

            return insert_token (LexerTokenType.SUP_NUMBER);
        }

        /* [LexerTokenType.PL_SUB_DIGIT]+ */
        if (type == LexerTokenType.PL_SUB_DIGIT)
        {
            while (prelexer.get_next_token () == LexerTokenType.PL_SUB_DIGIT);
            prelexer.roll_back ();

            return insert_token (LexerTokenType.SUB_NUMBER);
        }

        /* [LexerTokenType.PL_FRACTION] */
        if (type == LexerTokenType.PL_FRACTION)
            return insert_token (LexerTokenType.NUMBER);

        if (type == LexerTokenType.PL_DIGIT)
            return insert_digit ();

        if (type == LexerTokenType.PL_DECIMAL)
            return insert_decimal ();

        if (type == LexerTokenType.PL_HEX)
            return insert_hex ();

        if (type == LexerTokenType.PL_LETTER)
            return insert_letter ();

        if (type == LexerTokenType.PL_EOS)
            return insert_token (LexerTokenType.PL_EOS);

        /* ERROR: Unexpected token */
        parser.set_error (ErrorCode.INVALID, prelexer.get_marked_substring (), prelexer.mark_index, prelexer.index);

        return insert_token (LexerTokenType.UNKNOWN);
    }

    private LexerToken insert_digit ()
    {
        var type = prelexer.get_next_token ();
        while (type == LexerTokenType.PL_DIGIT)
            type = prelexer.get_next_token ();

        if (type == LexerTokenType.PL_FRACTION)
            return insert_token (LexerTokenType.NUMBER);
        else if (type == LexerTokenType.PL_SUB_DIGIT)
        {
            while (prelexer.get_next_token () == LexerTokenType.PL_SUB_DIGIT);
            prelexer.roll_back ();
            return insert_token (LexerTokenType.NUMBER);
        }
        else if (type == LexerTokenType.PL_DEGREE)
        {
            type = prelexer.get_next_token ();
            if (type == LexerTokenType.PL_DIGIT)
            {
                while ((type = prelexer.get_next_token ()) == LexerTokenType.PL_DIGIT);
                if (type == LexerTokenType.PL_DECIMAL)
                    return insert_angle_num_dm ();

                else if (type == LexerTokenType.PL_MINUTE)
                {
                    type = prelexer.get_next_token ();
                    if (type == LexerTokenType.PL_DIGIT)
                    {
                        while ((type = prelexer.get_next_token ()) == LexerTokenType.PL_DIGIT);
                        if (type == LexerTokenType.PL_DECIMAL)
                            return insert_angle_num_dms ();
                        else if (type == LexerTokenType.PL_SECOND)
                            return insert_token (LexerTokenType.NUMBER);
                        else
                        {
                            /* ERROR: expected LexerTokenType.PL_SECOND */
                            parser.set_error (ErrorCode.MP, prelexer.get_marked_substring (), prelexer.mark_index, prelexer.index);
                            return insert_token (LexerTokenType.UNKNOWN);
                        }
                    }
                    else if (type == LexerTokenType.PL_DECIMAL)
                        return insert_angle_num_dms ();
                    else
                    {
                        prelexer.roll_back ();
                        return insert_token (LexerTokenType.NUMBER);
                    }
                }
                else
                {
                    /* ERROR: expected LexerTokenType.PL_MINUTE | LexerTokenType.PL_DIGIT */
                    parser.set_error (ErrorCode.MP, prelexer.get_marked_substring (), prelexer.mark_index, prelexer.index);
                    return insert_token (LexerTokenType.UNKNOWN);
                }
            }
            else if (type == LexerTokenType.PL_DECIMAL)
                return insert_angle_num_dm ();
            else
                return insert_token (LexerTokenType.NUMBER);
        }
        else if (type == LexerTokenType.PL_DECIMAL)
            return insert_decimal ();
        else if (type == LexerTokenType.PL_HEX)
            return insert_hex_dec ();
        else
        {
            prelexer.roll_back ();
            return insert_token (LexerTokenType.NUMBER);
        }
    }

    private LexerToken insert_angle_num_dm ()
    {
        var type = prelexer.get_next_token ();
        if (type != LexerTokenType.PL_DIGIT)
        {
            /* ERROR: expected LexerTokenType.PL_DIGIT */
            parser.set_error (ErrorCode.MP, prelexer.get_marked_substring (), prelexer.mark_index, prelexer.index);
            return insert_token (LexerTokenType.UNKNOWN);
        }

        while (type == LexerTokenType.PL_DIGIT);
            type = prelexer.get_next_token ();

        if (type == LexerTokenType.PL_MINUTE)
            return insert_token (LexerTokenType.NUMBER);
        else
        {
            /* ERROR: expected LexerTokenType.PL_MINUTE */
            parser.set_error (ErrorCode.MP, prelexer.get_marked_substring (), prelexer.mark_index, prelexer.index);
            return insert_token (LexerTokenType.UNKNOWN);
        }
    }

    private LexerToken insert_angle_num_dms ()
    {
        var type = prelexer.get_next_token ();
        if (type != LexerTokenType.PL_DIGIT)
        {
            /* ERROR: expected LexerTokenType.PL_DIGIT */
            parser.set_error (ErrorCode.MP, prelexer.get_marked_substring (), prelexer.mark_index, prelexer.index);
            return insert_token (LexerTokenType.UNKNOWN);
        }
        while ((type = prelexer.get_next_token ()) == LexerTokenType.PL_DIGIT);
        if (type == LexerTokenType.PL_SECOND)
            return insert_token (LexerTokenType.NUMBER);
        else
        {
            /* ERROR: expected LexerTokenType.PL_SECOND */
            parser.set_error (ErrorCode.MP, prelexer.get_marked_substring (), prelexer.mark_index, prelexer.index);
            return insert_token (LexerTokenType.UNKNOWN);
        }
    }

    private LexerToken insert_decimal ()
    {
        var type = prelexer.get_next_token ();
        if (type == LexerTokenType.PL_DIGIT)
        {
            while ((type = prelexer.get_next_token ()) == LexerTokenType.PL_DIGIT);
            if (type == LexerTokenType.PL_DEGREE)
                return insert_token (LexerTokenType.NUMBER);
            else if (type == LexerTokenType.PL_HEX)
                return insert_decimal_hex ();
            else if (type == LexerTokenType.PL_SUB_DIGIT)
            {
                while (prelexer.get_next_token () == LexerTokenType.PL_SUB_DIGIT);
                prelexer.roll_back ();
                return insert_token (LexerTokenType.NUMBER);
            }
            else
            {
                prelexer.roll_back ();
                return insert_token (LexerTokenType.NUMBER);
            }
        }
        else if (type == LexerTokenType.PL_HEX)
            return insert_decimal_hex ();
        else
        {
            /* ERROR: expected LexerTokenType.PL_DIGIT | LexerTokenType.PL_HEX */
            parser.set_error (ErrorCode.MP, prelexer.get_marked_substring (), prelexer.mark_index, prelexer.index);
            return insert_token (LexerTokenType.UNKNOWN);
        }
    }

    private LexerToken insert_hex ()
    {
        var type = prelexer.get_next_token ();
        while (type == LexerTokenType.PL_HEX)
            type = prelexer.get_next_token ();

        if (type == LexerTokenType.PL_DIGIT)
            return insert_hex_dec ();
        else if (type == LexerTokenType.PL_DECIMAL)
            return insert_decimal_hex ();
        else if (type == LexerTokenType.PL_SUB_DIGIT)
        {
            while (prelexer.get_next_token () == LexerTokenType.PL_SUB_DIGIT);
            prelexer.roll_back ();

            if (check_if_number ())
                return insert_token (LexerTokenType.NUMBER);
            else
            {
                if (check_if_function ())
                    return insert_token (LexerTokenType.FUNCTION);
                else if (check_if_unit ())
                    return insert_token (LexerTokenType.UNIT);
                else
                    return insert_token (LexerTokenType.VARIABLE);
            }
        }
        else if (type == LexerTokenType.PL_LETTER)
            return insert_letter ();
        else
        {
            prelexer.roll_back ();
            if (check_if_number ())
                return insert_token (LexerTokenType.NUMBER);
            else
            {
                if (check_if_function ())
                    return insert_token (LexerTokenType.FUNCTION);
                else if (check_if_unit ())
                    return insert_token (LexerTokenType.UNIT);
                else
                    return insert_token (LexerTokenType.VARIABLE);
            }
        }
    }

    private LexerToken insert_hex_dec ()
    {
        var type = prelexer.get_next_token ();
        while (type == LexerTokenType.PL_DIGIT || type == LexerTokenType.PL_HEX)
            type = prelexer.get_next_token ();

        if (type == LexerTokenType.PL_DECIMAL)
            return insert_decimal_hex ();
        else if (type == LexerTokenType.PL_SUB_DIGIT)
        {
            while (prelexer.get_next_token () == LexerTokenType.PL_SUB_DIGIT);
            prelexer.roll_back ();
            return insert_token (LexerTokenType.NUMBER);
        }
        else
        {
            if (check_if_number ())
                return insert_token (LexerTokenType.NUMBER);
            /* ERROR: expected LexerTokenType.PL_DECIMAL | LexerTokenType.PL_DIGIT | LexerTokenType.PL_HEX */
            parser.set_error (ErrorCode.MP, prelexer.get_marked_substring (), prelexer.mark_index, prelexer.index);
            return insert_token (LexerTokenType.UNKNOWN);
        }
    }

    private LexerToken insert_decimal_hex ()
    {
        /* Make up of digits and hexadecimal characters */
        var type = prelexer.get_next_token ();
        while (type == LexerTokenType.PL_DIGIT || type == LexerTokenType.PL_HEX)
            type = prelexer.get_next_token ();

        /* Allow a subdigit suffix */
        while (type == LexerTokenType.PL_SUB_DIGIT)
            type = prelexer.get_next_token ();

        prelexer.roll_back ();

        return insert_token (LexerTokenType.NUMBER);
    }

    private LexerToken insert_letter ()
    {
        /* Get string of letters */
        var type = prelexer.get_next_token ();
        while (type == LexerTokenType.PL_LETTER || type == LexerTokenType.PL_HEX)
            type = prelexer.get_next_token ();

        /* Allow a subdigit suffix */
        while (type == LexerTokenType.PL_SUB_DIGIT)
            type = prelexer.get_next_token ();

        prelexer.roll_back ();

        var name = prelexer.get_marked_substring ().down ();
        if (name == "mod")
            return insert_token (LexerTokenType.MOD);
        if (name == "and")
            return insert_token (LexerTokenType.AND);
        if (name == "or")
            return insert_token (LexerTokenType.OR);
        if (name == "xor")
            return insert_token (LexerTokenType.XOR);
        if (name == "not")
            return insert_token (LexerTokenType.NOT);
        if (name == "in")
            return insert_token (LexerTokenType.IN);
        if (check_if_function ())
            return insert_token (LexerTokenType.FUNCTION);
        if (check_if_unit ())
            return insert_token (LexerTokenType.UNIT);
        else
            return insert_token (LexerTokenType.VARIABLE);
    }
}
