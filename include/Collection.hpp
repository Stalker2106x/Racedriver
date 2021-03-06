#ifndef COLLECTION_HPP_
#define COLLECTION_HPP_

#include <iostream>
#include <vector>
#include <sol.hpp>
#include <DataFile.hh>
#include <Menu.hh>
#include "Part.hpp"

//Forward declaring parts
class Car;
class Engine;
class Tires;
class Spoiler;

/*!
 * @brief Dummy Collection declaration to allow SFINAE specification
 */
template <typename T, typename enable = void>
class Collection;

/*!
 * @brief "Container" for any class with a based on Part.
 */
template <typename T>
class Collection<T, typename std::enable_if_t<std::is_base_of<Part, T>::value>>
{
public:
  void push_back(const T &obj)
  {
    _collection.push_back(obj);
  }

  size_t size() const
  {
    return (_collection.size());
  }

  T &operator[](const std::string &key) {
    for (size_t i = 0; i < _collection.size(); i++)
    {
      if (dynamic_cast<Part&>(_collection[i]).getId() == key) return (_collection[i]);
    }
    throw std::runtime_error("Uknown part");
  }

  T &operator[](int index) {
    return (_collection[index]);
  }

  T &at(int index) {
    return (_collection[index]);
  }

  Collection<T> filterCompatible(const Car &p)
  {
    Collection<T> subset;

    for (size_t i = 0; i < _collection.size(); i++)
    {
      if (_collection[i].socket == "Generic" || _collection[i].socket == dynamic_cast<const Part &>(p).socket) subset.push_back(_collection[i]);
    }
    return (subset);
  }

  template <typename ST>
  static const std::string getPath()
  {
    std::string path = "./Data/";
    if (!std::is_same<ST, Car>::value) //Parts have different location
    {
     path += "Parts/";
    }
    path += ST::getPath();
    return (path+".json");
  }

  template <typename ST>
  static void load(Collection<ST> &collection)
  {
    std::string path;
    try {
      path = getPath<ST>();
    } catch (const std::exception &e) {
      throw std::runtime_error("Cannot load collection:"+std::string(e.what()));
    }
    DataFile collectionFile(path);

    if (!collectionFile.load())
    {
      throw std::runtime_error("Cannot load collection file:"+path);
    }
    const json &data = collectionFile.getData();
    for (size_t i = 0; i < data["collection"].size(); i++)
    {
      try {
        ST obj(data["collection"][i]);
        collection.push_back(obj);
      } catch (std::exception &e) {
        Menu::alert("Corrupted data");
      }
    }
  }

  static void expose(sol::environment &lua)
  {
    lua.new_usertype<Collection<T>>(T::getPath()+"Collection",
      // constructor
      sol::constructors<Collection<T>()>(),

      "size", &Collection<T>::size,
      "filterCompatible", &Collection<T>::filterCompatible,
      sol::meta_function::index, static_cast<T &(Collection<T>::*)(int)>(&Collection<T>::operator[]),
      "get", static_cast<T &(Collection<T>::*)(const std::string &)>(&Collection<T>::operator[])
    );
  }

private:
  std::vector<T> _collection;
};

#endif /* !COLLECTION_HPP_ */