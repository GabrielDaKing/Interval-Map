#ifndef INTERVALMAP_HPP
#define INTERVALMAP_HPP

#include <map>
#include <string>

using namespace std;
template<typename K, typename V>
class interval_map{

	public:
		V m_valBegin;
		std::map<K,V> m_map;

		// constructor associates whole range of K with val
		interval_map(V const& val)
		: m_valBegin(val)
		{}

		void assign( K const& keyBegin, K const& keyEnd, V const& val );

		V operator[]( K key );

		void display();

};

#endif // INTERVALMAP_HPP