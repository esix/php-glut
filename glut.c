/* glut extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_glut.h"
#include "glut_arginfo.h"

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif



/* {{{ void test1() */
PHP_FUNCTION(test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "glut");
}
/* }}} */

/* {{{ string test2( [ string $var ] ) */
PHP_FUNCTION(test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ void glutInit( array $var ) */
PHP_FUNCTION(glutInit)
{
	zval *args = NULL;
	int i;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(args)
	ZEND_PARSE_PARAMETERS_END();

	uint32_t array_len = zend_hash_num_elements(Z_ARRVAL_P(args));

	// Z_TYPE(args) == IS_ARRAY

	HashTable *ht = Z_ARRVAL_P(args);

	size_t buffer_size = 0;
	size_t argc = 0;

	for (i = 0; i < array_len; i++) {
		zval *zv_dest = zend_hash_index_find(ht, i);
		if (zv_dest && Z_TYPE(zv_dest) == IS_STRING) {
			argc++;
			buffer_size += zv_dest->value.str->len;
			buffer_size++;
			php_printf("glutInit arg: (%d) %Z\n", Z_TYPE(*zv_dest), zv_dest);
			php_printf("as string: (%d) %s\n", zv_dest->value.str->len, zv_dest->value.str->val);
		}
	}
	php_printf("glutInit: Buffer size = %d\n", buffer_size);

	char *buffer = NULL;
	char **argv = NULL;

	if (buffer_size) {
		buffer = malloc(buffer_size * sizeof(char));
		argv = malloc(argc * sizeof(char*));
	}

	char* p = buffer;

	for (int i = 0, idx = 0; i < array_len; i++) {
		zval *zv_dest = zend_hash_index_find(ht, i);
		if (zv_dest && Z_TYPE(zv_dest) == IS_STRING) {
			argv[idx++] = p;
			strncpy(p, zv_dest->value.str->val, zv_dest->value.str->len);
			p += zv_dest->value.str->len;
			*p++ = 0;
		}
	}

 	glutInit(&argc, argv);

 	if (buffer_size) {
		free(argv);
		free(buffer);
	}

  // ZVAL_EMPTY_STRING(&user_display_func);
}
/* }}}*/

/* {{{ void glutInitDisplayMode( int $var ) */
PHP_FUNCTION(glutInitDisplayMode)
{
	long mode = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();

	glutInitDisplayMode(mode);
}
/* }}}*/

/* {{{ void glutInitWindowSize( int $width, int $height ) */
PHP_FUNCTION(glutInitWindowSize)
{
	long width = 0, height = 0;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	glutInitWindowSize(width, height);
}
/* }}}*/

/* {{{ void glutCreateWindow( string $name ) */
PHP_FUNCTION(glutCreateWindow)
{
	char *name = NULL;
	size_t name_len = 1024;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(name, name_len)
	ZEND_PARSE_PARAMETERS_END();

	glutCreateWindow(name);
}
/* }}}*/









GLint Width = 512, Height = 512;		/* начальная ширина и высота окна */
const int CubeSize = 200;/* размер куба */




zend_fcall_info display_fci;
zend_fcall_info_cache display_fcc;

zend_fcall_info reshape_fci;
zend_fcall_info_cache reshape_fcc;


/* эта функция управляет всем выводом на экран */
void Display(void) 
{
	php_printf("Display: (%d) %Z\n", Z_TYPE(display_fci.function_name), &display_fci.function_name);

	if (ZEND_FCI_INITIALIZED(display_fci)) {
		zval retval;
		display_fci.retval = &retval;
		display_fci.param_count = 0;
		display_fci.params = NULL;

		php_printf("Display: CALLING\n");
		if (zend_call_function(&display_fci, &display_fcc) == FAILURE) {
			php_printf("Display: FAILURE\n");
		} else {
			php_printf("Display: SUCCEEDED\n");
		}
	}
}

/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)
{
		php_printf("Reshape: (%d) %Z\n", Z_TYPE(reshape_fci.function_name), &reshape_fci.function_name);

		if (ZEND_FCI_INITIALIZED(reshape_fci)) {
			zval params[2];
			ZVAL_LONG(&params[0], w);
			ZVAL_LONG(&params[1], h);
			zval retval;

			reshape_fci.retval = &retval;
			reshape_fci.param_count = 2;
			reshape_fci.params = params;

			php_printf("Reshape:: RESHAPE\n");
			if (zend_call_function(&reshape_fci, &reshape_fcc) == FAILURE) {
				php_printf("Reshape: FAILURE\n");
			} else {
				php_printf("Reshape: SUCCEEDED\n");
			}
		}

    Width = w;
    Height = h;

}

/* Функция обрабатывает сообщения от клавиатуры */
void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'

    if( key == ESCAPE )
        exit(0);
}


/* {{{ void glutDisplayFunc( callable $func ) */
PHP_FUNCTION(glutDisplayFunc)
{
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_FUNC(display_fci, display_fcc)
	ZEND_PARSE_PARAMETERS_END();

	// if (!ZEND_FCI_INITIALIZED(fci)) { /* unset user-defined handler */
	// 	ZVAL_UNDEF(&EG(user_display_func));
	// 	return;
	// }
	// ZVAL_COPY(&user_display_func, &(fci.function_name));
	// php_printf("glutDisplayFunc arg: (%d)\n", fci.params);
  glutDisplayFunc(Display);
}
/* }}}*/


/* {{{ void glutReshapeFunc( callable $func ) */
PHP_FUNCTION(glutReshapeFunc)
{
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_FUNC(reshape_fci, reshape_fcc)
	ZEND_PARSE_PARAMETERS_END();

  glutReshapeFunc(Reshape);
	//
  glutKeyboardFunc(Keyboard);
}
/* }}}*/

/* {{{ void glutMainLoop() */
PHP_FUNCTION(glutMainLoop)
{
	ZEND_PARSE_PARAMETERS_NONE();
	glutMainLoop();
}
/* }}} */


/////////////////////////////////////////////////////////////////////


/* {{{ void glClearColor( double $red, double $green, double $blue, double $alpha ) */
PHP_FUNCTION(glClearColor)
{
	double red = 0, green = 0, blue = 0, alpha = 0;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_DOUBLE(red)
		Z_PARAM_DOUBLE(green)
		Z_PARAM_DOUBLE(blue)
		Z_PARAM_DOUBLE(alpha)
	ZEND_PARSE_PARAMETERS_END();

	glClearColor(red, green, blue, alpha);
}
/* }}}*/

/* {{{ void glClear( int $mask ) */
PHP_FUNCTION(glClear)
{
	long mask = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();

	glClear(mask);
}
/* }}}*/

/* {{{ void glColor3ub( int $red, int $green, int $blue ) */
PHP_FUNCTION(glColor3ub)
{
	long red = 0, green = 0, blue = 0;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(red)
		Z_PARAM_LONG(green)
		Z_PARAM_LONG(blue)
	ZEND_PARSE_PARAMETERS_END();

	glColor3ub(red, green, blue);
}
/* }}}*/


/* {{{ void glBegin( int $mode ) */
PHP_FUNCTION(glBegin)
{
	long mode = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();

	glBegin(mode);
}
/* }}}*/

/* {{{ void glEnd() */
PHP_FUNCTION(glEnd)
{
	ZEND_PARSE_PARAMETERS_NONE();
	glEnd();
}
/* }}}*/

/* {{{ void glFinish() */
PHP_FUNCTION(glFinish)
{
	ZEND_PARSE_PARAMETERS_NONE();
	glFinish();
}
/* }}}*/

/* {{{ void glVertex2f( int $x, int $y ) */
PHP_FUNCTION(glVertex2f)
{
	double x, y;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	glVertex2f(x, y);
}
/* }}}*/

/* {{{ void glViewport( int $x, int $y, int $width, int $height ) */
PHP_FUNCTION(glViewport)
{
	long x, y, width, height;

	ZEND_PARSE_PARAMETERS_START(4, 4)
			Z_PARAM_LONG(x)
			Z_PARAM_LONG(y)
			Z_PARAM_LONG(width)
			Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	glViewport(x, y, width, height);
}
/* }}}*/


/* {{{ void glMatrixMode( int $mode ) */
PHP_FUNCTION(glMatrixMode)
{
	long mode = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();

	glMatrixMode(mode);
}
/* }}}*/

/* {{{ void glLoadIdentity() */
PHP_FUNCTION(glLoadIdentity)
{
	ZEND_PARSE_PARAMETERS_NONE();
	glLoadIdentity();
}
/* }}} */

/* {{{ void glOrtho( int $x, int $y ) */
PHP_FUNCTION(glOrtho)
{
	double $left, $right, $bottom, $top, $zNear, $zFar;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_DOUBLE($left)
		Z_PARAM_DOUBLE($right)
		Z_PARAM_DOUBLE($bottom)
		Z_PARAM_DOUBLE($top)
		Z_PARAM_DOUBLE($zNear)
		Z_PARAM_DOUBLE($zFar)
	ZEND_PARSE_PARAMETERS_END();

	glOrtho($left, $right, $bottom, $top, $zNear, $zFar);
}


/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(glut)
{
#if defined(ZTS) && defined(COMPILE_DL_GLUT)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(glut)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "glut support", "enabled");
	php_info_print_table_end();

	// REGISTER_LONG_CONSTANT("GL_VENDOR", GL_VENDOR , CONST_CS | CONST_PERSISTENT);
}
/* }}} */

/* {{{ glut_module_entry */
zend_module_entry glut_module_entry = {
	STANDARD_MODULE_HEADER,
	"glut",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(glut),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(glut),			/* PHP_MINFO - Module info */
	PHP_GLUT_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GLUT
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(glut)
#endif
