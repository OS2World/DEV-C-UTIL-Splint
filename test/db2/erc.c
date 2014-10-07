# include <stdlib.h>
# include "erc.h"

static size_t int_toSize (int x)
{
  size_t res = (size_t) x;

  if ((int) res != x)
    {
      fprintf (stderr, "Error: int_toSize failure: %d", x);
      return 0;
    }
  else
    {
      return res;
    }
}

erc erc_create (void) 
{
  erc c;

  c = (erc) malloc (sizeof (ercInfo));

  if (c == 0) 
    {
      printf ("Malloc returned null in erc_create\n");
      exit (EXIT_FAILURE);
    }
  
  c->vals = 0;
  c->size = 0;
  return c;
}

void erc_clear (erc c) /*@ensures isnull c->vals, c->next@*/
{
  ercList elem;
  ercList next;

  for (elem = c->vals; elem != 0; elem = next) 
    {
      next = elem->next; elem->next = NULL;
      free (elem);
    }
  
  c->vals = 0;
  c->size = 0;
}

void erc_final (erc c) 
{
  erc_clear (c);
  free (c); 
}

bool erc_member (eref er, erc c) 
{
  ercList tmpc;

  for (tmpc = c->vals; tmpc != 0; tmpc = tmpc->next)
    if (eref_equal (tmpc->val, er)) return TRUE; 

  return FALSE;
}

void erc_insert (erc c, eref er) 
{
  ercList newElem;
  newElem = (ercElem *) malloc (sizeof (ercElem));

  if (newElem == 0) 
    {
      printf ("Malloc returned null in erc_insert\n");
      exit (EXIT_FAILURE);
    }

  newElem->val = er;
  newElem->next = c->vals;
  c->vals = newElem;
  c->size++;
}

bool erc_delete (erc c, eref er) 
{
  ercList elem;
  ercList prev;
  
  for (prev = 0, elem = c->vals;
       elem != 0;
       prev = elem, elem = elem->next) 
    {
      if (eref_equal (elem->val, er))
	{ 
	  if (prev == 0)
	    { c->vals = elem->next; elem->next = NULL; }
	  else 
	    { prev->next = elem->next; elem->next = NULL; }
	  
	  free (elem); 
	  c->size--;
	  return TRUE;
	}
    }
  
  return FALSE;
}

void erc_join (erc c1, erc c2) 
{
  ercList tmpc;

  for (tmpc = c2->vals; tmpc != 0; tmpc = tmpc->next)
    erc_insert (c1, tmpc->val);
}

char *erc_sprint (erc c)
{
  int len;
  char *result;

  result = (char *) 
    malloc (int_toSize (erc_size (c) * (employeePrintSize + 1) + 1));

  if (result == 0) 
    {
      printf ("Malloc returned null in erc_sprint\n");
      exit (EXIT_FAILURE);
    }

  len = 0;

  erc_elements(c, er)
    {
      employee_sprint(&(result[len]), eref_get(er));
      len += employeePrintSize;
      result[len++] = '\n';
    } end_erc_elements;

  result[len] = '\0';
  return result;
}

