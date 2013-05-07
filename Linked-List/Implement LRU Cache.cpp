//http://www.geeksforgeeks.org/implement-lru-cache/

//最近最少页面置换算法，boost；

//数据结构：Queue:DLL和Hash.
#include <map>
#include <list>
#include <vector>

template<class T>
struct Countfn 
{
  unsigned long operator()(const T &x)
	{
		return 1;
	}
};

template< typename Key,typename Data,typename Sizefn=Countfn<Data> >
class LRUCache
{
public:
	typedef std::list<std::pair<Key,Data>> List;
	typedef typename List::iterator List_Iter;
	typedef typename List::const_iterator List_cIter;
	typedef std::vector<Key> Key_List;
	typedef	typename Key_List::iterator Key_List_Iter;
	typedef	typename Key_List::const_iterator Key_List_cIter;
	typedef std::map<Key,List_Iter> Map;
	typedef std::pair<Key,List_Iter> Pair;
	typedef typename Map::iterator Map_Iter;
	typedef typename Map::const_iterator Map_cIter;
private:
	List _list;
	Map _index;
	unsigned long _max_size;
	unsigned long _cur_size;
public:
	LRUCache(const unsigned long Size):_max_size(Size),_cur_size(0)
	{

	}
	~LRUCache()
	{
		clear();
	}
	inline const unsigned long size(void) const {  return _cur_size; }
	inline const unsigned long   maxsize(void) const {  return _max_size; }
	void clear()
	{
		_list.clear();
		_index.clear();
	}
	inline bool exists(const Key &key)
	{
		return _index.find(key)!=_index.end();
	}
	inline void remove(const Key &key)
	{
		Map_Iter miter=_index.find(key);
		if (miter==_index.end())
		{
			return ;
		}
		_remove(miter);
	}
	inline void touch(const Key &key)
	{
		_touch(key);
	}
	inline Data *fetch_ptr(const Key &key,bool touch=true)
	{
		Map_Iter miter=_index.find(key);
		if (miter==_index.end()) return NULL;
		_touch(key);
		return &(miter->second->second);
	}
	inline Data fetch(const Key &key,bool touch_data=true)
	{
		Map_Iter miter=_index.find(key);
		if (miter==_index.end()) return Data();
		Data tmp=miter->second->second;
		if (touch_data)
		{
			_touch(key);
		}
		return tmp;
	}
	inline bool fetch(const Key &key,Data &data,bool touch_data=true)
	{
		Map_Iter miter=_index.find(key);
		if (miter==_index.end()) return false;
		if (touch_data)
		{
			_touch(key);
		}
		data=miter->second->second;
		return true;
	}
	inline void insert(const Key &key, const Data &data)
	{
		Map_Iter miter=_touch(key);
		if (miter!=_index.end())
		{
			_remove(miter);
		}
		_list.push_front(std::make_pair(key,data));
		List_Iter liter=_list.begin();
		_index.insert(std::make_pair(key,liter));
		_cur_size+=Sizefn()(data);
		while(_cur_size>_max_size)
		{
			liter=_list.end();
			--liter;
			_remove(liter->first);
		}
	}
	inline const Key_List get_all_keys(void)
	{
		Key_List ret;
		for (List_cIter it=_list.begin();it!=_list.end();it++)
		{
			ret.push_back(it->first);
		}
		return ret;
	}
private:
	inline Map_Iter _touch(const Key &key)
	{
		Map_Iter miter=_index.find(key);
		if (miter==_index.end()) return miter;
		_list.splice(_list.begin(),_list,miter->second);
		return miter;
	}
	inline void _remove(const Map_Iter &miter)
	{
		_cur_size-=Sizefn()(miter->second->second);
	        _list.erase(miter->second);
		_index.erase(miter);
	}
	inline void _remove(const Key &key)
	{
		Map_Iter miter=_index.find(key);
		_remove(miter);
	}
}

