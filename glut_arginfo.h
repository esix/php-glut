/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 5cc3a4be4a874fff56fea6b9969ddeda6621ea31 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test1, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test2, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, str, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glutInit, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, args, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glutInitDisplayMode, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glutInitWindowSize, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glutCreateWindow, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glutDisplayFunc, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, func, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_glutReshapeFunc arginfo_glutDisplayFunc

#define arginfo_glutMainLoop arginfo_test1

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glClearColor, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glClear, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, mask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glColor3ub, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, red, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_glBegin arginfo_glutInitDisplayMode

#define arginfo_glEnd arginfo_test1

#define arginfo_glFinish arginfo_test1

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glVertex2f, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glViewport, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_glMatrixMode arginfo_glutInitDisplayMode

#define arginfo_glLoadIdentity arginfo_test1

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_glOrtho, 0, 6, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, left, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, right, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, bottom, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, top, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, zNear, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, zFar, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(test1);
ZEND_FUNCTION(test2);
ZEND_FUNCTION(glutInit);
ZEND_FUNCTION(glutInitDisplayMode);
ZEND_FUNCTION(glutInitWindowSize);
ZEND_FUNCTION(glutCreateWindow);
ZEND_FUNCTION(glutDisplayFunc);
ZEND_FUNCTION(glutReshapeFunc);
ZEND_FUNCTION(glutMainLoop);
ZEND_FUNCTION(glClearColor);
ZEND_FUNCTION(glClear);
ZEND_FUNCTION(glColor3ub);
ZEND_FUNCTION(glBegin);
ZEND_FUNCTION(glEnd);
ZEND_FUNCTION(glFinish);
ZEND_FUNCTION(glVertex2f);
ZEND_FUNCTION(glViewport);
ZEND_FUNCTION(glMatrixMode);
ZEND_FUNCTION(glLoadIdentity);
ZEND_FUNCTION(glOrtho);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(test1, arginfo_test1)
	ZEND_FE(test2, arginfo_test2)
	ZEND_FE(glutInit, arginfo_glutInit)
	ZEND_FE(glutInitDisplayMode, arginfo_glutInitDisplayMode)
	ZEND_FE(glutInitWindowSize, arginfo_glutInitWindowSize)
	ZEND_FE(glutCreateWindow, arginfo_glutCreateWindow)
	ZEND_FE(glutDisplayFunc, arginfo_glutDisplayFunc)
	ZEND_FE(glutReshapeFunc, arginfo_glutReshapeFunc)
	ZEND_FE(glutMainLoop, arginfo_glutMainLoop)
	ZEND_FE(glClearColor, arginfo_glClearColor)
	ZEND_FE(glClear, arginfo_glClear)
	ZEND_FE(glColor3ub, arginfo_glColor3ub)
	ZEND_FE(glBegin, arginfo_glBegin)
	ZEND_FE(glEnd, arginfo_glEnd)
	ZEND_FE(glFinish, arginfo_glFinish)
	ZEND_FE(glVertex2f, arginfo_glVertex2f)
	ZEND_FE(glViewport, arginfo_glViewport)
	ZEND_FE(glMatrixMode, arginfo_glMatrixMode)
	ZEND_FE(glLoadIdentity, arginfo_glLoadIdentity)
	ZEND_FE(glOrtho, arginfo_glOrtho)
	ZEND_FE_END
};
