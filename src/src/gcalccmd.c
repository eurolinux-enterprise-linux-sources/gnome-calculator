/* gcalccmd.c generated by valac 0.20.1, the Vala compiler
 * generated from gcalccmd.vala, do not modify */

/*
 * Copyright (C) 2009 Rich Burridge
 * Copyright (C) 2012 Robert Ancell
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version. See http://www.gnu.org/copyleft/gpl.html the full text of the
 * license.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include "langinfo.h"
#include <stdio.h>
#include <locale.h>


#define TYPE_SERIALIZER (serializer_get_type ())
#define SERIALIZER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SERIALIZER, Serializer))
#define SERIALIZER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SERIALIZER, SerializerClass))
#define IS_SERIALIZER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SERIALIZER))
#define IS_SERIALIZER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SERIALIZER))
#define SERIALIZER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SERIALIZER, SerializerClass))

typedef struct _Serializer Serializer;
typedef struct _SerializerClass SerializerClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

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

#define TYPE_ERROR_CODE (error_code_get_type ())
#define _number_unref0(var) ((var == NULL) ? NULL : (var = (number_unref (var), NULL)))
#define _equation_unref0(var) ((var == NULL) ? NULL : (var = (equation_unref (var), NULL)))

#define TYPE_DISPLAY_FORMAT (display_format_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_date_time_unref0(var) ((var == NULL) ? NULL : (var = (g_date_time_unref (var), NULL)))

typedef enum  {
	ANGLE_UNIT_RADIANS,
	ANGLE_UNIT_DEGREES,
	ANGLE_UNIT_GRADIANS
} AngleUnit;

struct _Equation {
	GTypeInstance parent_instance;
	volatile int ref_count;
	EquationPrivate * priv;
	gint base;
	gint wordlen;
	AngleUnit angle_units;
};

struct _EquationClass {
	GTypeClass parent_class;
	void (*finalize) (Equation *self);
	gboolean (*variable_is_defined) (Equation* self, const gchar* name);
	Number* (*get_variable) (Equation* self, const gchar* name);
	void (*set_variable) (Equation* self, const gchar* name, Number* x);
	gboolean (*function_is_defined) (Equation* self, const gchar* name);
	Number* (*get_function) (Equation* self, const gchar* name, Number* x);
	Number* (*convert) (Equation* self, Number* x, const gchar* x_units, const gchar* z_units);
};

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
	DISPLAY_FORMAT_AUTOMATIC,
	DISPLAY_FORMAT_FIXED,
	DISPLAY_FORMAT_SCIENTIFIC,
	DISPLAY_FORMAT_ENGINEERING
} DisplayFormat;


extern Serializer* result_serializer;
Serializer* result_serializer = NULL;

#define MAXLINE 1024
GType serializer_get_type (void) G_GNUC_CONST;
void solve (const gchar* equation);
Equation* equation_new (const gchar* expression);
Equation* equation_construct (GType object_type, const gchar* expression);
gpointer equation_ref (gpointer instance);
void equation_unref (gpointer instance);
GParamSpec* param_spec_equation (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_equation (GValue* value, gpointer v_object);
void value_take_equation (GValue* value, gpointer v_object);
gpointer value_get_equation (const GValue* value);
GType equation_get_type (void) G_GNUC_CONST;
gpointer number_ref (gpointer instance);
void number_unref (gpointer instance);
GParamSpec* param_spec_number (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_number (GValue* value, gpointer v_object);
void value_take_number (GValue* value, gpointer v_object);
gpointer value_get_number (const GValue* value);
GType number_get_type (void) G_GNUC_CONST;
GType angle_unit_get_type (void) G_GNUC_CONST;
GType error_code_get_type (void) G_GNUC_CONST;
Number* equation_parse (Equation* self, guint* representation_base, ErrorCode* error_code, gchar** error_token, guint* error_start, guint* error_end);
void serializer_set_representation_base (Serializer* self, guint representation_base);
gchar* serializer_to_string (Serializer* self, Number* x);
gchar* mp_get_error (void);
gint _vala_main (gchar** args, int args_length1);
GType display_format_get_type (void) G_GNUC_CONST;
Serializer* serializer_new (DisplayFormat format, gint number_base, gint trailing_digits);
Serializer* serializer_construct (GType object_type, DisplayFormat format, gint number_base, gint trailing_digits);


static gchar* string_replace (const gchar* self, const gchar* old, const gchar* replacement) {
	gchar* result = NULL;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (old != NULL, NULL);
	g_return_val_if_fail (replacement != NULL, NULL);
	{
		const gchar* _tmp0_;
		gchar* _tmp1_ = NULL;
		gchar* _tmp2_;
		GRegex* _tmp3_;
		GRegex* _tmp4_;
		GRegex* regex;
		GRegex* _tmp5_;
		const gchar* _tmp6_;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_;
		_tmp0_ = old;
		_tmp1_ = g_regex_escape_string (_tmp0_, -1);
		_tmp2_ = _tmp1_;
		_tmp3_ = g_regex_new (_tmp2_, 0, 0, &_inner_error_);
		_tmp4_ = _tmp3_;
		_g_free0 (_tmp2_);
		regex = _tmp4_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch0_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_tmp5_ = regex;
		_tmp6_ = replacement;
		_tmp7_ = g_regex_replace_literal (_tmp5_, self, (gssize) (-1), 0, _tmp6_, 0, &_inner_error_);
		_tmp8_ = _tmp7_;
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch0_g_regex_error;
			}
			_g_regex_unref0 (regex);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		result = _tmp8_;
		_g_regex_unref0 (regex);
		return result;
	}
	goto __finally0;
	__catch0_g_regex_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_assert_not_reached ();
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


void solve (const gchar* equation) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	gchar* tsep_string;
	gboolean _tmp2_ = FALSE;
	const gchar* _tmp3_;
	gboolean _tmp5_;
	const gchar* _tmp7_;
	const gchar* _tmp8_;
	gchar* _tmp9_ = NULL;
	gchar* _tmp10_;
	Equation* _tmp11_;
	Equation* _tmp12_;
	Equation* e;
	Equation* _tmp13_;
	Equation* _tmp14_;
	Equation* _tmp15_;
	ErrorCode ret = 0;
	guint representation_base = 0U;
	Equation* _tmp16_;
	guint _tmp17_ = 0U;
	ErrorCode _tmp18_ = 0;
	Number* _tmp19_ = NULL;
	Number* z;
	Serializer* _tmp20_;
	guint _tmp21_;
	Number* _tmp22_;
	g_return_if_fail (equation != NULL);
	_tmp0_ = nl_langinfo (THOUSEP);
	_tmp1_ = g_strdup (_tmp0_);
	tsep_string = _tmp1_;
	_tmp3_ = tsep_string;
	if (_tmp3_ == NULL) {
		_tmp2_ = TRUE;
	} else {
		const gchar* _tmp4_;
		_tmp4_ = tsep_string;
		_tmp2_ = g_strcmp0 (_tmp4_, "") == 0;
	}
	_tmp5_ = _tmp2_;
	if (_tmp5_) {
		gchar* _tmp6_;
		_tmp6_ = g_strdup (" ");
		_g_free0 (tsep_string);
		tsep_string = _tmp6_;
	}
	_tmp7_ = equation;
	_tmp8_ = tsep_string;
	_tmp9_ = string_replace (_tmp7_, _tmp8_, "");
	_tmp10_ = _tmp9_;
	_tmp11_ = equation_new (_tmp10_);
	_tmp12_ = _tmp11_;
	_g_free0 (_tmp10_);
	e = _tmp12_;
	_tmp13_ = e;
	_tmp13_->base = 10;
	_tmp14_ = e;
	_tmp14_->wordlen = 32;
	_tmp15_ = e;
	_tmp15_->angle_units = ANGLE_UNIT_DEGREES;
	_tmp16_ = e;
	_tmp19_ = equation_parse (_tmp16_, &_tmp17_, &_tmp18_, NULL, NULL, NULL);
	representation_base = _tmp17_;
	ret = _tmp18_;
	z = _tmp19_;
	_tmp20_ = result_serializer;
	_tmp21_ = representation_base;
	serializer_set_representation_base (_tmp20_, _tmp21_);
	_tmp22_ = z;
	if (_tmp22_ != NULL) {
		FILE* _tmp23_;
		Serializer* _tmp24_;
		Number* _tmp25_;
		gchar* _tmp26_ = NULL;
		gchar* _tmp27_;
		_tmp23_ = stdout;
		_tmp24_ = result_serializer;
		_tmp25_ = z;
		_tmp26_ = serializer_to_string (_tmp24_, _tmp25_);
		_tmp27_ = _tmp26_;
		fprintf (_tmp23_, "%s\n", _tmp27_);
		_g_free0 (_tmp27_);
	} else {
		ErrorCode _tmp28_;
		_tmp28_ = ret;
		if (_tmp28_ == ERROR_CODE_MP) {
			FILE* _tmp29_;
			gchar* _tmp30_ = NULL;
			gchar* _tmp31_;
			_tmp29_ = stderr;
			_tmp30_ = mp_get_error ();
			_tmp31_ = _tmp30_;
			fprintf (_tmp29_, "Error %s\n", _tmp31_);
			_g_free0 (_tmp31_);
		} else {
			FILE* _tmp32_;
			ErrorCode _tmp33_;
			_tmp32_ = stderr;
			_tmp33_ = ret;
			fprintf (_tmp32_, "Error %d\n", (gint) _tmp33_);
		}
	}
	_number_unref0 (z);
	_equation_unref0 (e);
	_g_free0 (tsep_string);
}


static gchar* string_strip (const gchar* self) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _result_;
	const gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self);
	_result_ = _tmp0_;
	_tmp1_ = _result_;
	g_strstrip (_tmp1_);
	result = _result_;
	return result;
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	GDateTime* _tmp0_;
	GDateTime* now;
	GDateTime* _tmp1_;
	gint _tmp2_ = 0;
	Serializer* _tmp3_;
	gchar* _tmp4_ = NULL;
	gchar* buffer;
	gint buffer_length1;
	gint _buffer_size_;
	_tmp0_ = g_date_time_new_now_utc ();
	now = _tmp0_;
	_tmp1_ = now;
	_tmp2_ = g_date_time_get_microsecond (_tmp1_);
	g_random_set_seed ((guint32) _tmp2_);
	setlocale (LC_ALL, "");
	_tmp3_ = serializer_new (DISPLAY_FORMAT_AUTOMATIC, 10, 9);
	_g_object_unref0 (result_serializer);
	result_serializer = _tmp3_;
	_tmp4_ = g_new0 (gchar, 1024);
	buffer = _tmp4_;
	buffer_length1 = 1024;
	_buffer_size_ = buffer_length1;
	while (TRUE) {
		FILE* _tmp5_;
		FILE* _tmp6_;
		gchar* _tmp7_;
		gint _tmp7__length1;
		const gchar* _tmp8_ = NULL;
		gchar* _tmp9_;
		gchar* line;
		const gchar* _tmp10_;
		gchar* _tmp11_ = NULL;
		gboolean _tmp12_ = FALSE;
		gboolean _tmp13_ = FALSE;
		gboolean _tmp14_ = FALSE;
		const gchar* _tmp15_;
		gboolean _tmp17_;
		gboolean _tmp19_;
		gboolean _tmp21_;
		const gchar* _tmp22_;
		_tmp5_ = stdout;
		fprintf (_tmp5_, "> ");
		_tmp6_ = stdin;
		_tmp7_ = buffer;
		_tmp7__length1 = buffer_length1;
		_tmp8_ = fgets (_tmp7_, _tmp7__length1, _tmp6_);
		_tmp9_ = g_strdup (_tmp8_);
		line = _tmp9_;
		_tmp10_ = line;
		_tmp11_ = string_strip (_tmp10_);
		_g_free0 (line);
		line = _tmp11_;
		_tmp15_ = line;
		if (_tmp15_ == NULL) {
			_tmp14_ = TRUE;
		} else {
			const gchar* _tmp16_;
			_tmp16_ = line;
			_tmp14_ = g_strcmp0 (_tmp16_, "exit") == 0;
		}
		_tmp17_ = _tmp14_;
		if (_tmp17_) {
			_tmp13_ = TRUE;
		} else {
			const gchar* _tmp18_;
			_tmp18_ = line;
			_tmp13_ = g_strcmp0 (_tmp18_, "quit") == 0;
		}
		_tmp19_ = _tmp13_;
		if (_tmp19_) {
			_tmp12_ = TRUE;
		} else {
			const gchar* _tmp20_;
			_tmp20_ = line;
			_tmp12_ = g_strcmp0 (_tmp20_, "") == 0;
		}
		_tmp21_ = _tmp12_;
		if (_tmp21_) {
			_g_free0 (line);
			break;
		}
		_tmp22_ = line;
		solve (_tmp22_);
		_g_free0 (line);
	}
	result = EXIT_SUCCESS;
	buffer = (g_free (buffer), NULL);
	_g_date_time_unref0 (now);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}



