/* equation.c generated by valac 0.40.6, the Vala compiler
 * generated from equation.vala, do not modify */

/*
 * Copyright (C) 2004-2008 Sami Pietila
 * Copyright (C) 2008-2012 Robert Ancell.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version. See http://www.gnu.org/copyleft/gpl.html the full text of the
 * license.
 */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_ERROR_CODE (error_code_get_type ())

#define TYPE_EQUATION (equation_get_type ())
#define EQUATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_EQUATION, Equation))
#define EQUATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_EQUATION, EquationClass))
#define IS_EQUATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_EQUATION))
#define IS_EQUATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_EQUATION))
#define EQUATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_EQUATION, EquationClass))

typedef struct _Equation Equation;
typedef struct _EquationClass EquationClass;
typedef struct _EquationPrivate EquationPrivate;

#define TYPE_NUMBER (number_get_type ())
#define NUMBER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_NUMBER, Number))
#define NUMBER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_NUMBER, NumberClass))
#define IS_NUMBER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_NUMBER))
#define IS_NUMBER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_NUMBER))
#define NUMBER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_NUMBER, NumberClass))

typedef struct _Number Number;
typedef struct _NumberClass NumberClass;

#define TYPE_ANGLE_UNIT (angle_unit_get_type ())
enum  {
	EQUATION_0_PROPERTY,
	EQUATION_NUM_PROPERTIES
};
static GParamSpec* equation_properties[EQUATION_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))

#define TYPE_PARSER (parser_get_type ())
#define PARSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PARSER, Parser))
#define PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PARSER, ParserClass))
#define IS_PARSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PARSER))
#define IS_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PARSER))
#define PARSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PARSER, ParserClass))

typedef struct _Parser Parser;
typedef struct _ParserClass ParserClass;

#define TYPE_EQUATION_PARSER (equation_parser_get_type ())
#define EQUATION_PARSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_EQUATION_PARSER, EquationParser))
#define EQUATION_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_EQUATION_PARSER, EquationParserClass))
#define IS_EQUATION_PARSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_EQUATION_PARSER))
#define IS_EQUATION_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_EQUATION_PARSER))
#define EQUATION_PARSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_EQUATION_PARSER, EquationParserClass))

typedef struct _EquationParser EquationParser;
typedef struct _EquationParserClass EquationParserClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _parser_unref0(var) ((var == NULL) ? NULL : (var = (parser_unref (var), NULL)))
typedef struct _ParserPrivate ParserPrivate;
typedef struct _EquationParserPrivate EquationParserPrivate;

#define TYPE_FUNCTION_MANAGER (function_manager_get_type ())
#define FUNCTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FUNCTION_MANAGER, FunctionManager))
#define FUNCTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FUNCTION_MANAGER, FunctionManagerClass))
#define IS_FUNCTION_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FUNCTION_MANAGER))
#define IS_FUNCTION_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FUNCTION_MANAGER))
#define FUNCTION_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FUNCTION_MANAGER, FunctionManagerClass))

typedef struct _FunctionManager FunctionManager;
typedef struct _FunctionManagerClass FunctionManagerClass;

#define TYPE_UNIT_MANAGER (unit_manager_get_type ())
#define UNIT_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_UNIT_MANAGER, UnitManager))
#define UNIT_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_UNIT_MANAGER, UnitManagerClass))
#define IS_UNIT_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_UNIT_MANAGER))
#define IS_UNIT_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_UNIT_MANAGER))
#define UNIT_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_UNIT_MANAGER, UnitManagerClass))

typedef struct _UnitManager UnitManager;
typedef struct _UnitManagerClass UnitManagerClass;

typedef enum  {
	ERROR_CODE_NONE,
	ERROR_CODE_INVALID,
	ERROR_CODE_OVERFLOW,
	ERROR_CODE_UNKNOWN_VARIABLE,
	ERROR_CODE_UNKNOWN_FUNCTION,
	ERROR_CODE_UNKNOWN_CONVERSION,
	ERROR_CODE_MP
} ErrorCode;

typedef enum  {
	ANGLE_UNIT_RADIANS,
	ANGLE_UNIT_DEGREES,
	ANGLE_UNIT_GRADIANS
} AngleUnit;

struct _Equation {
	GObject parent_instance;
	EquationPrivate * priv;
	gint base;
	gint wordlen;
	AngleUnit angle_units;
};

struct _EquationClass {
	GObjectClass parent_class;
	gboolean (*variable_is_defined) (Equation* self, const gchar* name);
	Number* (*get_variable) (Equation* self, const gchar* name);
	gboolean (*unit_is_defined) (Equation* self, const gchar* name);
	void (*set_variable) (Equation* self, const gchar* name, Number* x);
	gboolean (*function_is_defined) (Equation* self, const gchar* name);
	Number* (*convert) (Equation* self, Number* x, const gchar* x_units, const gchar* z_units);
};

struct _EquationPrivate {
	gchar* expression;
};

struct _Parser {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ParserPrivate * priv;
	gint number_base;
	gint wordlen;
	AngleUnit angle_units;
};

struct _ParserClass {
	GTypeClass parent_class;
	void (*finalize) (Parser *self);
	gboolean (*variable_is_defined) (Parser* self, const gchar* name);
	Number* (*get_variable) (Parser* self, const gchar* name);
	void (*set_variable) (Parser* self, const gchar* name, Number* x);
	gboolean (*function_is_defined) (Parser* self, const gchar* name);
	gboolean (*unit_is_defined) (Parser* self, const gchar* name);
	Number* (*convert) (Parser* self, Number* x, const gchar* x_units, const gchar* z_units);
};

struct _EquationParser {
	Parser parent_instance;
	EquationParserPrivate * priv;
};

struct _EquationParserClass {
	ParserClass parent_class;
};

struct _EquationParserPrivate {
	Equation* equation;
};


static gpointer equation_parent_class = NULL;
static gpointer equation_parser_parent_class = NULL;

gint sub_atoi (const gchar* data);
gint super_atoi (const gchar* data);
GType error_code_get_type (void) G_GNUC_CONST;
gchar* mp_error_code_to_string (ErrorCode error_code);
GType equation_get_type (void) G_GNUC_CONST;
GType number_get_type (void) G_GNUC_CONST;
GType angle_unit_get_type (void) G_GNUC_CONST;
#define EQUATION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_EQUATION, EquationPrivate))
Equation* equation_new (const gchar* expression);
Equation* equation_construct (GType object_type,
                              const gchar* expression);
Number* equation_parse (Equation* self,
                        guint* representation_base,
                        ErrorCode* error_code,
                        gchar* * error_token,
                        guint** error_start,
                        guint** error_end);
gpointer parser_ref (gpointer instance);
void parser_unref (gpointer instance);
GParamSpec* param_spec_parser (const gchar* name,
                               const gchar* nick,
                               const gchar* blurb,
                               GType object_type,
                               GParamFlags flags);
void value_set_parser (GValue* value,
                       gpointer v_object);
void value_take_parser (GValue* value,
                        gpointer v_object);
gpointer value_get_parser (const GValue* value);
GType parser_get_type (void) G_GNUC_CONST;
GType equation_parser_get_type (void) G_GNUC_CONST;
EquationParser* equation_parser_new (Equation* equation,
                                     const gchar* expression);
EquationParser* equation_parser_construct (GType object_type,
                                           Equation* equation,
                                           const gchar* expression);
const gchar* number_get_error (void);
void number_set_error (const gchar* value);
Number* parser_parse (Parser* self,
                      guint* representation_base,
                      ErrorCode* error_code,
                      gchar* * error_token,
                      guint* error_start,
                      guint* error_end);
static guint* _uint_dup (guint* self);
gboolean equation_variable_is_defined (Equation* self,
                                       const gchar* name);
static gboolean equation_real_variable_is_defined (Equation* self,
                                            const gchar* name);
Number* equation_get_variable (Equation* self,
                               const gchar* name);
static Number* equation_real_get_variable (Equation* self,
                                    const gchar* name);
gboolean equation_unit_is_defined (Equation* self,
                                   const gchar* name);
static gboolean equation_real_unit_is_defined (Equation* self,
                                        const gchar* name);
void equation_set_variable (Equation* self,
                            const gchar* name,
                            Number* x);
static void equation_real_set_variable (Equation* self,
                                 const gchar* name,
                                 Number* x);
gboolean equation_function_is_defined (Equation* self,
                                       const gchar* name);
static gboolean equation_real_function_is_defined (Equation* self,
                                            const gchar* name);
Number* equation_convert (Equation* self,
                          Number* x,
                          const gchar* x_units,
                          const gchar* z_units);
static Number* equation_real_convert (Equation* self,
                               Number* x,
                               const gchar* x_units,
                               const gchar* z_units);
static void equation_finalize (GObject * obj);
#define EQUATION_PARSER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_EQUATION_PARSER, EquationParserPrivate))
Parser* parser_new (const gchar* input,
                    gint number_base,
                    gint wordlen,
                    AngleUnit angle_units);
Parser* parser_construct (GType object_type,
                          const gchar* input,
                          gint number_base,
                          gint wordlen,
                          AngleUnit angle_units);
static gboolean equation_parser_real_variable_is_defined (Parser* base,
                                                   const gchar* name);
static Number* equation_parser_real_get_variable (Parser* base,
                                           const gchar* name);
Number* number_new_eulers (void);
Number* number_construct_eulers (GType object_type);
Number* number_new_i (void);
Number* number_construct_i (GType object_type);
Number* number_new_pi (void);
Number* number_construct_pi (GType object_type);
static void equation_parser_real_set_variable (Parser* base,
                                        const gchar* name,
                                        Number* x);
static gboolean equation_parser_real_function_is_defined (Parser* base,
                                                   const gchar* name);
GType function_manager_get_type (void) G_GNUC_CONST;
FunctionManager* function_manager_get_default_function_manager (void);
gboolean function_manager_is_function_defined (FunctionManager* self,
                                               const gchar* name);
static gboolean equation_parser_real_unit_is_defined (Parser* base,
                                               const gchar* name);
GType unit_manager_get_type (void) G_GNUC_CONST;
UnitManager* unit_manager_get_default (void);
gboolean unit_manager_unit_is_defined (UnitManager* self,
                                       const gchar* name);
static Number* equation_parser_real_convert (Parser* base,
                                      Number* x,
                                      const gchar* x_units,
                                      const gchar* z_units);
static void equation_parser_finalize (Parser * obj);


static gboolean
string_get_next_char (const gchar* self,
                      gint* index,
                      gunichar* c)
{
	gunichar _vala_c = 0U;
	gboolean result = FALSE;
	gunichar _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	_vala_c = g_utf8_get_char (((gchar*) self) + (*index));
	_tmp0_ = _vala_c;
	if (_tmp0_ != ((gunichar) 0)) {
		gchar* _tmp1_;
		_tmp1_ = g_utf8_next_char (((gchar*) self) + (*index));
		*index = (gint) (_tmp1_ - ((gchar*) self));
		result = TRUE;
		if (c) {
			*c = _vala_c;
		}
		return result;
	} else {
		result = FALSE;
		if (c) {
			*c = _vala_c;
		}
		return result;
	}
	if (c) {
		*c = _vala_c;
	}
}


gint
sub_atoi (const gchar* data)
{
	gint result = 0;
	static const gunichar digits[10] = {8320U, 8321U, 8322U, 8323U, 8324U, 8325U, 8326U, 8327U, 8328U, 8329U};
	gint index = 0;
	gunichar c = 0U;
	gint value = 0;
	g_return_val_if_fail (data != NULL, 0);
	index = 0;
	value = 0;
	while (TRUE) {
		gunichar _tmp0_ = 0U;
		gboolean _tmp1_;
		gboolean is_subdigit = FALSE;
		gboolean _tmp10_;
		_tmp1_ = string_get_next_char (data, &index, &_tmp0_);
		c = _tmp0_;
		if (!_tmp1_) {
			break;
		}
		is_subdigit = FALSE;
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp2_ = FALSE;
				_tmp2_ = TRUE;
				while (TRUE) {
					gint _tmp4_;
					gunichar _tmp5_;
					gint _tmp6_;
					gunichar _tmp7_;
					if (!_tmp2_) {
						gint _tmp3_;
						_tmp3_ = i;
						i = _tmp3_ + 1;
					}
					_tmp2_ = FALSE;
					_tmp4_ = i;
					if (!(_tmp4_ < G_N_ELEMENTS (digits))) {
						break;
					}
					_tmp5_ = c;
					_tmp6_ = i;
					_tmp7_ = digits[_tmp6_];
					if (_tmp5_ == _tmp7_) {
						gint _tmp8_;
						gint _tmp9_;
						_tmp8_ = value;
						_tmp9_ = i;
						value = (_tmp8_ * 10) + _tmp9_;
						is_subdigit = TRUE;
						break;
					}
				}
			}
		}
		_tmp10_ = is_subdigit;
		if (!_tmp10_) {
			result = -1;
			return result;
		}
	}
	result = value;
	return result;
}


gint
super_atoi (const gchar* data)
{
	gint result = 0;
	static const gunichar digits[10] = {8304U, 185U, 178U, 179U, 8308U, 8309U, 8310U, 8311U, 8312U, 8313U};
	gint index = 0;
	gunichar c = 0U;
	gunichar _tmp0_ = 0U;
	gint sign = 0;
	gunichar _tmp1_;
	gint value = 0;
	gint _tmp13_;
	gint _tmp14_;
	g_return_val_if_fail (data != NULL, 0);
	index = 0;
	string_get_next_char (data, &index, &_tmp0_);
	c = _tmp0_;
	sign = 1;
	_tmp1_ = c;
	if (_tmp1_ == 8315U) {
		sign = -1;
	} else {
		index = 0;
	}
	value = 0;
	while (TRUE) {
		gunichar _tmp2_ = 0U;
		gboolean _tmp3_;
		gboolean is_superdigit = FALSE;
		gboolean _tmp12_;
		_tmp3_ = string_get_next_char (data, &index, &_tmp2_);
		c = _tmp2_;
		if (!_tmp3_) {
			break;
		}
		is_superdigit = FALSE;
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp4_ = FALSE;
				_tmp4_ = TRUE;
				while (TRUE) {
					gint _tmp6_;
					gunichar _tmp7_;
					gint _tmp8_;
					gunichar _tmp9_;
					if (!_tmp4_) {
						gint _tmp5_;
						_tmp5_ = i;
						i = _tmp5_ + 1;
					}
					_tmp4_ = FALSE;
					_tmp6_ = i;
					if (!(_tmp6_ < G_N_ELEMENTS (digits))) {
						break;
					}
					_tmp7_ = c;
					_tmp8_ = i;
					_tmp9_ = digits[_tmp8_];
					if (_tmp7_ == _tmp9_) {
						gint _tmp10_;
						gint _tmp11_;
						_tmp10_ = value;
						_tmp11_ = i;
						value = (_tmp10_ * 10) + _tmp11_;
						is_superdigit = TRUE;
						break;
					}
				}
			}
		}
		_tmp12_ = is_superdigit;
		if (!_tmp12_) {
			result = 0;
			return result;
		}
	}
	_tmp13_ = sign;
	_tmp14_ = value;
	result = _tmp13_ * _tmp14_;
	return result;
}


gchar*
mp_error_code_to_string (ErrorCode error_code)
{
	gchar* result = NULL;
	switch (error_code) {
		case ERROR_CODE_NONE:
		{
			gchar* _tmp0_;
			_tmp0_ = g_strdup ("ErrorCode.NONE");
			result = _tmp0_;
			return result;
		}
		case ERROR_CODE_INVALID:
		{
			gchar* _tmp1_;
			_tmp1_ = g_strdup ("ErrorCode.INVALID");
			result = _tmp1_;
			return result;
		}
		case ERROR_CODE_OVERFLOW:
		{
			gchar* _tmp2_;
			_tmp2_ = g_strdup ("ErrorCode.OVERFLOW");
			result = _tmp2_;
			return result;
		}
		case ERROR_CODE_UNKNOWN_VARIABLE:
		{
			gchar* _tmp3_;
			_tmp3_ = g_strdup ("ErrorCode.UNKNOWN_VARIABLE");
			result = _tmp3_;
			return result;
		}
		case ERROR_CODE_UNKNOWN_FUNCTION:
		{
			gchar* _tmp4_;
			_tmp4_ = g_strdup ("ErrorCode.UNKNOWN_FUNCTION");
			result = _tmp4_;
			return result;
		}
		case ERROR_CODE_UNKNOWN_CONVERSION:
		{
			gchar* _tmp5_;
			_tmp5_ = g_strdup ("ErrorCode.UNKNOWN_CONVERSION");
			result = _tmp5_;
			return result;
		}
		case ERROR_CODE_MP:
		{
			gchar* _tmp6_;
			_tmp6_ = g_strdup ("ErrorCode.MP");
			result = _tmp6_;
			return result;
		}
		default:
		{
			gchar* _tmp7_;
			_tmp7_ = g_strdup ("Unknown parser error");
			result = _tmp7_;
			return result;
		}
	}
}


GType
error_code_get_type (void)
{
	static volatile gsize error_code_type_id__volatile = 0;
	if (g_once_init_enter (&error_code_type_id__volatile)) {
		static const GEnumValue values[] = {{ERROR_CODE_NONE, "ERROR_CODE_NONE", "none"}, {ERROR_CODE_INVALID, "ERROR_CODE_INVALID", "invalid"}, {ERROR_CODE_OVERFLOW, "ERROR_CODE_OVERFLOW", "overflow"}, {ERROR_CODE_UNKNOWN_VARIABLE, "ERROR_CODE_UNKNOWN_VARIABLE", "unknown-variable"}, {ERROR_CODE_UNKNOWN_FUNCTION, "ERROR_CODE_UNKNOWN_FUNCTION", "unknown-function"}, {ERROR_CODE_UNKNOWN_CONVERSION, "ERROR_CODE_UNKNOWN_CONVERSION", "unknown-conversion"}, {ERROR_CODE_MP, "ERROR_CODE_MP", "mp"}, {0, NULL, NULL}};
		GType error_code_type_id;
		error_code_type_id = g_enum_register_static ("ErrorCode", values);
		g_once_init_leave (&error_code_type_id__volatile, error_code_type_id);
	}
	return error_code_type_id__volatile;
}


Equation*
equation_construct (GType object_type,
                    const gchar* expression)
{
	Equation * self = NULL;
	gchar* _tmp0_;
	g_return_val_if_fail (expression != NULL, NULL);
	self = (Equation*) g_object_new (object_type, NULL);
	_tmp0_ = g_strdup (expression);
	_g_free0 (self->priv->expression);
	self->priv->expression = _tmp0_;
	return self;
}


Equation*
equation_new (const gchar* expression)
{
	return equation_construct (TYPE_EQUATION, expression);
}


static guint*
_uint_dup (guint* self)
{
	guint* dup;
	dup = g_new0 (guint, 1);
	memcpy (dup, self, sizeof (guint));
	return dup;
}


static gpointer
__uint_dup0 (gpointer self)
{
	return self ? _uint_dup (self) : NULL;
}


Number*
equation_parse (Equation* self,
                guint* representation_base,
                ErrorCode* error_code,
                gchar* * error_token,
                guint** error_start,
                guint** error_end)
{
	guint _vala_representation_base = 0U;
	ErrorCode _vala_error_code = 0;
	gchar* _vala_error_token = NULL;
	guint* _vala_error_start = NULL;
	guint* _vala_error_end = NULL;
	Number* result = NULL;
	EquationParser* parser = NULL;
	const gchar* _tmp0_;
	EquationParser* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	Number* z = NULL;
	EquationParser* _tmp4_;
	guint _tmp5_ = 0U;
	ErrorCode _tmp6_ = 0;
	gchar* _tmp7_ = NULL;
	guint _tmp8_ = 0U;
	guint _tmp9_ = 0U;
	Number* _tmp10_;
	guint _tmp11_;
	guint* _tmp12_;
	guint _tmp13_;
	guint* _tmp14_;
	ErrorCode _tmp15_;
	const gchar* _tmp16_;
	const gchar* _tmp17_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->expression;
	_tmp1_ = equation_parser_new (self, _tmp0_);
	parser = _tmp1_;
	_tmp2_ = number_get_error ();
	_tmp3_ = _tmp2_;
	number_set_error (NULL);
	_tmp4_ = parser;
	_tmp10_ = parser_parse ((Parser*) _tmp4_, &_tmp5_, &_tmp6_, &_tmp7_, &_tmp8_, &_tmp9_);
	_vala_representation_base = _tmp5_;
	_vala_error_code = _tmp6_;
	_g_free0 (_vala_error_token);
	_vala_error_token = _tmp7_;
	_g_free0 (_vala_error_start);
	_tmp11_ = _tmp8_;
	_tmp12_ = __uint_dup0 (&_tmp11_);
	_vala_error_start = _tmp12_;
	_g_free0 (_vala_error_end);
	_tmp13_ = _tmp9_;
	_tmp14_ = __uint_dup0 (&_tmp13_);
	_vala_error_end = _tmp14_;
	z = _tmp10_;
	_tmp15_ = _vala_error_code;
	if (_tmp15_ != ERROR_CODE_NONE) {
		result = NULL;
		_g_object_unref0 (z);
		_parser_unref0 (parser);
		if (representation_base) {
			*representation_base = _vala_representation_base;
		}
		if (error_code) {
			*error_code = _vala_error_code;
		}
		if (error_token) {
			*error_token = _vala_error_token;
		} else {
			_g_free0 (_vala_error_token);
		}
		if (error_start) {
			*error_start = _vala_error_start;
		} else {
			_g_free0 (_vala_error_start);
		}
		if (error_end) {
			*error_end = _vala_error_end;
		} else {
			_g_free0 (_vala_error_end);
		}
		return result;
	}
	_tmp16_ = number_get_error ();
	_tmp17_ = _tmp16_;
	if (_tmp17_ != NULL) {
		_vala_error_code = ERROR_CODE_MP;
		result = NULL;
		_g_object_unref0 (z);
		_parser_unref0 (parser);
		if (representation_base) {
			*representation_base = _vala_representation_base;
		}
		if (error_code) {
			*error_code = _vala_error_code;
		}
		if (error_token) {
			*error_token = _vala_error_token;
		} else {
			_g_free0 (_vala_error_token);
		}
		if (error_start) {
			*error_start = _vala_error_start;
		} else {
			_g_free0 (_vala_error_start);
		}
		if (error_end) {
			*error_end = _vala_error_end;
		} else {
			_g_free0 (_vala_error_end);
		}
		return result;
	}
	result = z;
	_parser_unref0 (parser);
	if (representation_base) {
		*representation_base = _vala_representation_base;
	}
	if (error_code) {
		*error_code = _vala_error_code;
	}
	if (error_token) {
		*error_token = _vala_error_token;
	} else {
		_g_free0 (_vala_error_token);
	}
	if (error_start) {
		*error_start = _vala_error_start;
	} else {
		_g_free0 (_vala_error_start);
	}
	if (error_end) {
		*error_end = _vala_error_end;
	} else {
		_g_free0 (_vala_error_end);
	}
	return result;
}


static gboolean
equation_real_variable_is_defined (Equation* self,
                                   const gchar* name)
{
	gboolean result = FALSE;
	g_return_val_if_fail (name != NULL, FALSE);
	result = FALSE;
	return result;
}


gboolean
equation_variable_is_defined (Equation* self,
                              const gchar* name)
{
	g_return_val_if_fail (self != NULL, FALSE);
	return EQUATION_GET_CLASS (self)->variable_is_defined (self, name);
}


static Number*
equation_real_get_variable (Equation* self,
                            const gchar* name)
{
	Number* result = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	result = NULL;
	return result;
}


Number*
equation_get_variable (Equation* self,
                       const gchar* name)
{
	g_return_val_if_fail (self != NULL, NULL);
	return EQUATION_GET_CLASS (self)->get_variable (self, name);
}


static gboolean
equation_real_unit_is_defined (Equation* self,
                               const gchar* name)
{
	gboolean result = FALSE;
	g_return_val_if_fail (name != NULL, FALSE);
	result = FALSE;
	return result;
}


gboolean
equation_unit_is_defined (Equation* self,
                          const gchar* name)
{
	g_return_val_if_fail (self != NULL, FALSE);
	return EQUATION_GET_CLASS (self)->unit_is_defined (self, name);
}


static void
equation_real_set_variable (Equation* self,
                            const gchar* name,
                            Number* x)
{
	g_return_if_fail (name != NULL);
	g_return_if_fail (x != NULL);
}


void
equation_set_variable (Equation* self,
                       const gchar* name,
                       Number* x)
{
	g_return_if_fail (self != NULL);
	EQUATION_GET_CLASS (self)->set_variable (self, name, x);
}


static gboolean
equation_real_function_is_defined (Equation* self,
                                   const gchar* name)
{
	gboolean result = FALSE;
	g_return_val_if_fail (name != NULL, FALSE);
	result = FALSE;
	return result;
}


gboolean
equation_function_is_defined (Equation* self,
                              const gchar* name)
{
	g_return_val_if_fail (self != NULL, FALSE);
	return EQUATION_GET_CLASS (self)->function_is_defined (self, name);
}


static Number*
equation_real_convert (Equation* self,
                       Number* x,
                       const gchar* x_units,
                       const gchar* z_units)
{
	Number* result = NULL;
	g_return_val_if_fail (x != NULL, NULL);
	g_return_val_if_fail (x_units != NULL, NULL);
	g_return_val_if_fail (z_units != NULL, NULL);
	result = NULL;
	return result;
}


Number*
equation_convert (Equation* self,
                  Number* x,
                  const gchar* x_units,
                  const gchar* z_units)
{
	g_return_val_if_fail (self != NULL, NULL);
	return EQUATION_GET_CLASS (self)->convert (self, x, x_units, z_units);
}


static void
equation_class_init (EquationClass * klass)
{
	equation_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (EquationPrivate));
	((EquationClass *) klass)->variable_is_defined = (gboolean (*) (Equation *, const gchar*)) equation_real_variable_is_defined;
	((EquationClass *) klass)->get_variable = (Number* (*) (Equation *, const gchar*)) equation_real_get_variable;
	((EquationClass *) klass)->unit_is_defined = (gboolean (*) (Equation *, const gchar*)) equation_real_unit_is_defined;
	((EquationClass *) klass)->set_variable = (void (*) (Equation *, const gchar*, Number*)) equation_real_set_variable;
	((EquationClass *) klass)->function_is_defined = (gboolean (*) (Equation *, const gchar*)) equation_real_function_is_defined;
	((EquationClass *) klass)->convert = (Number* (*) (Equation *, Number*, const gchar*, const gchar*)) equation_real_convert;
	G_OBJECT_CLASS (klass)->finalize = equation_finalize;
}


static void
equation_instance_init (Equation * self)
{
	self->priv = EQUATION_GET_PRIVATE (self);
}


static void
equation_finalize (GObject * obj)
{
	Equation * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_EQUATION, Equation);
	_g_free0 (self->priv->expression);
	G_OBJECT_CLASS (equation_parent_class)->finalize (obj);
}


GType
equation_get_type (void)
{
	static volatile gsize equation_type_id__volatile = 0;
	if (g_once_init_enter (&equation_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (EquationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) equation_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Equation), 0, (GInstanceInitFunc) equation_instance_init, NULL };
		GType equation_type_id;
		equation_type_id = g_type_register_static (G_TYPE_OBJECT, "Equation", &g_define_type_info, 0);
		g_once_init_leave (&equation_type_id__volatile, equation_type_id);
	}
	return equation_type_id__volatile;
}


static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}


EquationParser*
equation_parser_construct (GType object_type,
                           Equation* equation,
                           const gchar* expression)
{
	EquationParser* self = NULL;
	gint _tmp0_;
	gint _tmp1_;
	AngleUnit _tmp2_;
	Equation* _tmp3_;
	g_return_val_if_fail (equation != NULL, NULL);
	g_return_val_if_fail (expression != NULL, NULL);
	_tmp0_ = equation->base;
	_tmp1_ = equation->wordlen;
	_tmp2_ = equation->angle_units;
	self = (EquationParser*) parser_construct (object_type, expression, _tmp0_, _tmp1_, _tmp2_);
	_tmp3_ = _g_object_ref0 (equation);
	_g_object_unref0 (self->priv->equation);
	self->priv->equation = _tmp3_;
	return self;
}


EquationParser*
equation_parser_new (Equation* equation,
                     const gchar* expression)
{
	return equation_parser_construct (TYPE_EQUATION_PARSER, equation, expression);
}


static gboolean
equation_parser_real_variable_is_defined (Parser* base,
                                          const gchar* name)
{
	EquationParser * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	Equation* _tmp2_;
	self = (EquationParser*) base;
	g_return_val_if_fail (name != NULL, FALSE);
	if (g_strcmp0 (name, "e") == 0) {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = g_strcmp0 (name, "i") == 0;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = g_strcmp0 (name, "π") == 0;
	}
	if (_tmp0_) {
		result = TRUE;
		return result;
	}
	_tmp2_ = self->priv->equation;
	result = equation_variable_is_defined (_tmp2_, name);
	return result;
}


static Number*
equation_parser_real_get_variable (Parser* base,
                                   const gchar* name)
{
	EquationParser * self;
	Number* result = NULL;
	self = (EquationParser*) base;
	g_return_val_if_fail (name != NULL, NULL);
	if (g_strcmp0 (name, "e") == 0) {
		Number* _tmp0_;
		_tmp0_ = number_new_eulers ();
		result = _tmp0_;
		return result;
	} else {
		if (g_strcmp0 (name, "i") == 0) {
			Number* _tmp1_;
			_tmp1_ = number_new_i ();
			result = _tmp1_;
			return result;
		} else {
			if (g_strcmp0 (name, "π") == 0) {
				Number* _tmp2_;
				_tmp2_ = number_new_pi ();
				result = _tmp2_;
				return result;
			} else {
				Equation* _tmp3_;
				Number* _tmp4_;
				_tmp3_ = self->priv->equation;
				_tmp4_ = equation_get_variable (_tmp3_, name);
				result = _tmp4_;
				return result;
			}
		}
	}
}


static void
equation_parser_real_set_variable (Parser* base,
                                   const gchar* name,
                                   Number* x)
{
	EquationParser * self;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	Equation* _tmp2_;
	self = (EquationParser*) base;
	g_return_if_fail (name != NULL);
	g_return_if_fail (x != NULL);
	if (g_strcmp0 (name, "e") == 0) {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = g_strcmp0 (name, "i") == 0;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = g_strcmp0 (name, "π") == 0;
	}
	if (_tmp0_) {
		return;
	}
	_tmp2_ = self->priv->equation;
	equation_set_variable (_tmp2_, name, x);
}


static gboolean
equation_parser_real_function_is_defined (Parser* base,
                                          const gchar* name)
{
	EquationParser * self;
	gboolean result = FALSE;
	FunctionManager* function_manager = NULL;
	FunctionManager* _tmp0_;
	FunctionManager* _tmp1_;
	Equation* _tmp2_;
	self = (EquationParser*) base;
	g_return_val_if_fail (name != NULL, FALSE);
	_tmp0_ = function_manager_get_default_function_manager ();
	function_manager = _tmp0_;
	_tmp1_ = function_manager;
	if (function_manager_is_function_defined (_tmp1_, name)) {
		result = TRUE;
		_g_object_unref0 (function_manager);
		return result;
	}
	_tmp2_ = self->priv->equation;
	result = equation_function_is_defined (_tmp2_, name);
	_g_object_unref0 (function_manager);
	return result;
}


static gboolean
equation_parser_real_unit_is_defined (Parser* base,
                                      const gchar* name)
{
	EquationParser * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp5_ = FALSE;
	gboolean _tmp6_ = FALSE;
	UnitManager* unit_manager = NULL;
	UnitManager* _tmp7_;
	UnitManager* _tmp8_;
	Equation* _tmp9_;
	self = (EquationParser*) base;
	g_return_val_if_fail (name != NULL, FALSE);
	if (g_strcmp0 (name, "hex") == 0) {
		_tmp6_ = TRUE;
	} else {
		_tmp6_ = g_strcmp0 (name, "hexadecimal") == 0;
	}
	if (_tmp6_) {
		_tmp5_ = TRUE;
	} else {
		_tmp5_ = g_strcmp0 (name, "dec") == 0;
	}
	if (_tmp5_) {
		_tmp4_ = TRUE;
	} else {
		_tmp4_ = g_strcmp0 (name, "decimal") == 0;
	}
	if (_tmp4_) {
		_tmp3_ = TRUE;
	} else {
		_tmp3_ = g_strcmp0 (name, "oct") == 0;
	}
	if (_tmp3_) {
		_tmp2_ = TRUE;
	} else {
		_tmp2_ = g_strcmp0 (name, "octal") == 0;
	}
	if (_tmp2_) {
		_tmp1_ = TRUE;
	} else {
		_tmp1_ = g_strcmp0 (name, "bin") == 0;
	}
	if (_tmp1_) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = g_strcmp0 (name, "binary") == 0;
	}
	if (_tmp0_) {
		result = TRUE;
		return result;
	}
	_tmp7_ = unit_manager_get_default ();
	unit_manager = _tmp7_;
	_tmp8_ = unit_manager;
	if (unit_manager_unit_is_defined (_tmp8_, name)) {
		result = TRUE;
		_g_object_unref0 (unit_manager);
		return result;
	}
	_tmp9_ = self->priv->equation;
	result = equation_unit_is_defined (_tmp9_, name);
	_g_object_unref0 (unit_manager);
	return result;
}


static Number*
equation_parser_real_convert (Parser* base,
                              Number* x,
                              const gchar* x_units,
                              const gchar* z_units)
{
	EquationParser * self;
	Number* result = NULL;
	Equation* _tmp0_;
	Number* _tmp1_;
	self = (EquationParser*) base;
	g_return_val_if_fail (x != NULL, NULL);
	g_return_val_if_fail (x_units != NULL, NULL);
	g_return_val_if_fail (z_units != NULL, NULL);
	_tmp0_ = self->priv->equation;
	_tmp1_ = equation_convert (_tmp0_, x, x_units, z_units);
	result = _tmp1_;
	return result;
}


static void
equation_parser_class_init (EquationParserClass * klass)
{
	equation_parser_parent_class = g_type_class_peek_parent (klass);
	((ParserClass *) klass)->finalize = equation_parser_finalize;
	g_type_class_add_private (klass, sizeof (EquationParserPrivate));
	((ParserClass *) klass)->variable_is_defined = (gboolean (*) (Parser *, const gchar*)) equation_parser_real_variable_is_defined;
	((ParserClass *) klass)->get_variable = (Number* (*) (Parser *, const gchar*)) equation_parser_real_get_variable;
	((ParserClass *) klass)->set_variable = (void (*) (Parser *, const gchar*, Number*)) equation_parser_real_set_variable;
	((ParserClass *) klass)->function_is_defined = (gboolean (*) (Parser *, const gchar*)) equation_parser_real_function_is_defined;
	((ParserClass *) klass)->unit_is_defined = (gboolean (*) (Parser *, const gchar*)) equation_parser_real_unit_is_defined;
	((ParserClass *) klass)->convert = (Number* (*) (Parser *, Number*, const gchar*, const gchar*)) equation_parser_real_convert;
}


static void
equation_parser_instance_init (EquationParser * self)
{
	self->priv = EQUATION_PARSER_GET_PRIVATE (self);
}


static void
equation_parser_finalize (Parser * obj)
{
	EquationParser * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_EQUATION_PARSER, EquationParser);
	_g_object_unref0 (self->priv->equation);
	PARSER_CLASS (equation_parser_parent_class)->finalize (obj);
}


GType
equation_parser_get_type (void)
{
	static volatile gsize equation_parser_type_id__volatile = 0;
	if (g_once_init_enter (&equation_parser_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (EquationParserClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) equation_parser_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (EquationParser), 0, (GInstanceInitFunc) equation_parser_instance_init, NULL };
		GType equation_parser_type_id;
		equation_parser_type_id = g_type_register_static (TYPE_PARSER, "EquationParser", &g_define_type_info, 0);
		g_once_init_leave (&equation_parser_type_id__volatile, equation_parser_type_id);
	}
	return equation_parser_type_id__volatile;
}



