/* glut extension for PHP */

#ifndef PHP_GLUT_H
# define PHP_GLUT_H

extern zend_module_entry glut_module_entry;
# define phpext_glut_ptr &glut_module_entry

# define PHP_GLUT_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_GLUT)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_GLUT_H */
