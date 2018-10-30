#ifndef STRSET_H
#define STRSET_H

#include <stddef.h>

#ifdef __cplusplus

#include <iostream>

extern "C" {
	namespace jnp1 {
#endif //__cplusplus

        typedef unsigned long idType;

		idType strset_new();
	
		void strset_delete(idType id);
	
		size_t strset_size(idType id);
	
		void strset_insert(idType id, const char* value);
	
		void strset_remove(idType id, const char* value);
	
		int strset_test(idType id, const char* value);
	
		void strset_clear(idType id);
	
		int strset_comp(idType id1, idType id2);

#ifdef __cplusplus
	}
}
#endif //__cplusplus

#endif //STRSET_H