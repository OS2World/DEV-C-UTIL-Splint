#ifndef BOOL_H
#define BOOL_H

#ifndef FALSE
#define FALSE false
#endif

#ifndef TRUE
#define TRUE true
#endif
/*@-cppnames@*/
typedef int bool;
/*@=cppnames@*/
/*
** bool_initMod has no real effect
** Declared with modifies internalState, so no noeffect errors are 
** reported when it is called.)
*/

extern /*@unused@*/ void bool_initMod (void) /*@modifies internalState@*/ ;
/*@-mustmod@*/
# define bool_initMod()
/*@=mustmod@*/

extern /*@unused@*/ /*@observer@*/ char *bool_unparse (bool) /*@*/ ;
# define bool_unparse(b) ((b) ? "true" : "false" )

extern /*@unused@*/ bool bool_not (bool) /*@*/ ;
# define bool_not(b) ((b) ? FALSE : TRUE)

extern /*@unused@*/ bool bool_equal (bool, bool) /*@*/ ;
# define bool_equal(a,b) ((a) ? (b) : !(b))

# endif
