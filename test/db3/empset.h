# ifndef F_EMPSET_H
# define F_EMPSET_H

# include "eref.h"
# include "erc.h"
# include "ereftab.h"

typedef erc empset;

/*
  Abstraction function, toEmpSet:
    e \in toEmpSet(s) == 
      exists er (count(er, s.val) = 1
        /\ getERef(known, e) = er)

  Rep invariant:
    forall s: empset
      (forall er: eref (count(er, s.val) <= 1)
      /\ s.activeIters = 0
      /\ forall er: eref (count(er, s.val) = 1
        => in(known, er)))
*/

# include "empset.lh"

# define empset_create()  (erc_create())
# define empset_final(s) (erc_final(s))
# define empset_size(es) (erc_size(es))
# define empset_choose(es) (eref_get(erc_choose(es)))
# define empset_sprint(es) (erc_sprint(es))

#define empset_elements(e, m_x) \
   erc_elements(e, m_y) { employee m_x = eref_get(m_y);
#define end_empset_elements        } end_erc_elements

# endif
