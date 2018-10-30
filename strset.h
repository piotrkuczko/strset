#ifndef JNP_STRSET_H
#define JNP_STRSET_H

#include <cstdlib>

extern "C" {

	namespace jnp1 {

        using idType = unsigned long;

		idType strset_new();

		//Tworzy nowy zbiór i zwraca jego identyfikator.
	
		void strset_delete(idType id);

		/*Jeżeli istnieje zbiór o identyfikatorze id, usuwa go, a w przeciwnym
		przypadku nie robi nic.*/
	
		size_t strset_size(idType id);

		/*Jeżeli istnieje zbiór o identyfikatorze id, zwraca liczbę jego elementów,
		a w przeciwnym przypadku zwraca 0.*/
	
		void strset_insert(idType id, const char* value);

		/*Jeżeli istnieje zbiór o identyfikatorze id i element value nie należy do
		tego zbioru, to dodaje element do zbioru, a w przeciwnym przypadku nie
		robi nic.*/
	
		void strset_remove(idType id, const char* value);
	
		/*Jeżeli istnieje zbiór o identyfikatorze id i element value należy do tego
		zbioru, to usuwa element ze zbioru, a w przeciwnym przypadku nie robi nic.*/
	
		int strset_test(idType id, const char* value);
	
		/*Jeżeli istnieje zbiór o identyfikatorze id i element value należy do tego
		zbioru, to zwraca 1, a w przeciwnym przypadku 0.*/
	
		void strset_clear(idType id);
	
		/*Jeżeli istnieje zbiór o identyfikatorze id, usuwa wszystkie jego elementy,
		a w przeciwnym przypadku nie robi nic.*/
	
		int strset_comp(idType id1, idType id2);
	
		/*Porównuje zbiory o identyfikatorach id1 i id2. Niech sorted(id) oznacza
		posortowany leksykograficznie zbiór o identyfikatorze id. Takie ciągi już
		porównujemy naturalnie: pierwsze miejsce, na którym się różnią, decyduje
		o relacji większości. Jeśli jeden ciąg jest prefiksem drugiego, to ten
		będący prefiks jest mniejszy. Funkcja strset_comp(id1, id2) zwraca:
		-1, gdy sorted(id1) < sorted(id2),
		0, gdy sorted(id1) = sorted(id2),
		1, gdy sorted(id1) > sorted(id2).
		Jeżeli zbiór o którymś z identyfikatorów nie istnieje, to jest traktowany
		jako równy zbiorowi pustemu.*/
	}
}

#endif //JNP_STRSET_H