#include <iostream>
#include "interval_map.hpp"
#include <string>

using namespace std;

template<typename K, typename V>
void interval_map<K,V>::assign( K const& keyBegin, K const& keyEnd, V const& val ) {
	
	// check if keybegin greater than keyend
	if (!(keyBegin < keyEnd)){
		return;
	}
	
	// if the value to be set already exists at keybegin position
	if (val == interval_map::m_map[keyBegin]){
		K next_key = interval_map::m_map.upper_bound(keyBegin)->first;
		V current_val = interval_map::m_map[keyBegin];
		
		// replace all keys in interval appropriately
		while (next_key < keyEnd){
			current_val = interval_map::m_map[next_key];
			interval_map::m_map.erase(next_key);
			next_key  = interval_map::m_map.upper_bound(next_key)->first;
		};
		
		// existing values continue correctly after interval
		if (keyEnd < next_key && !(current_val==val)){
			interval_map::m_map[keyEnd] = current_val;
		};
			
	}else{
		K next_key = m_map.upper_bound(keyBegin)->first;

		V current_val = interval_map::m_map[keyBegin];
		interval_map::m_map[keyBegin] = val;

		// replace all keys in interval appropriately
		while (next_key < keyEnd){
			current_val = interval_map::m_map[next_key];
			interval_map::m_map.erase(next_key);
			next_key = interval_map::m_map.upper_bound(next_key)->first;
		};
		
		// existing values continue correctly after interval
		if (keyEnd < next_key && !(current_val==val)){
			interval_map::m_map[keyEnd] = current_val;
		};
	};
}

// look-up of the value associated with key
template<typename K, typename V>
V interval_map<K,V>::operator[]( K key )  {
	auto it=interval_map::m_map.upper_bound(key);
	if(it==interval_map::m_map.begin()) {
		return m_valBegin;
	} else {
		return (--it)->second;
	}
}
	
template<typename K, typename V>
void interval_map<K,V>::display(){
	// std::map<K,V>::iterator it = m_map.begin();

//     // Iterate through the map and print the elements
//     while (it != m_map.end()) {
//         cout << "Key: " << it->first << ", Value: " << it->second << endl;
//         ++it;
//     }
	
	// for (auto const& [key, val] : interval_map::m_map){
	//     cout<<key<<" "<<val<<endl;
	// }
	// cout<<"blah\n";
	return ;
}