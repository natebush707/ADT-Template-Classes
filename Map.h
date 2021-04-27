#ifndef MAP_H
#define MAP_H_

#include "Map_Set.h"
#include "Pair.h"

using namespace std;

template <typename K, typename V>
class Map
{
public:
	Map() {}

	V& operator [] (K index)
	{
		typename Set<Pair<K, V>>::iterator here;
		Pair<K, V> probe(index, V());
		here = themap.insert(probe);
		return (*here).second;
	}

	void remove(K key)
	{
		Pair<K, V> probe;
		probe.first = key;
		themap.remove(probe);
		return;
	}

	Set<K> keys()
	{
		Set<K> thekeys;
		typename Set<Pair<K, V>>::iterator itr = themap.begin();

		for (; itr != themap.end(); ++itr)
			thekeys.insert((*itr).first);
		return thekeys;
	}

	Set<V> values()
	{
		Set<V> thevalues;
		typename Set<Pair<K, V>>::iterator itr = themap.begin();

		for (; itr != themap.end(); ++itr)
			thevalues.insert((*itr).second);
		return thevalues;
	}

	void printMap(ostream& out = cout)
	{
		typename Set<Pair<K, V>>::iterator itr = themap.begin();
		for (; itr != themap.end(); ++itr)
		{
			out << (*itr).first << ":" << (*itr).second << endl;
		}
	}

private:
	Set<Pair<K, V>> themap;
};

#endif