#include "standardlibrary.h"
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

// rif. https://en.cppreference.com/w/cpp/container/vector
static void esempio_vector() {
  std::vector<int> contenitore{1, 2, 3, 4, 5, 6, 7, 8};
  std::cout << "Dimensione: " << contenitore.size() << '\n';
  // Iterazione sul vector
  for (const auto &x : contenitore) {
    std::cout << x << ',';
  }
  std::cout << std::endl;
  // Inserimento di un elemento in fondo
  contenitore.push_back(9);
  std::cout << "Dimensione: " << contenitore.size() << '\n';
  for (const auto &x : contenitore) {
    std::cout << x << ',';
  }
  std::cout << std::endl;
  // Rimozione di un elemento
  contenitore.pop_back();

  for (const auto &x : contenitore) {
    std::cout << x << ',';
  }
  std::cout << std::endl;

  std::cout << "Elimino il secondo elemento\n";
  contenitore.erase(contenitore.begin() + 1);
  for (const auto &x : contenitore) {
    std::cout << x << ',';
  }
  std::cout << std::endl;

  contenitore.clear();
  std::cout << "Dimensione: " << contenitore.size() << '\n';

  std::vector<double *> contenitore2;
  contenitore2.push_back(new double{3.14});
  auto p{contenitore2.at(0)}; // vado a prendere l'elemento alla posizione 0
  delete p;                   // libero la memoria
  contenitore2.clear();

  for (auto v : {1.1, 2.2, 3.3}) {
    contenitore2.push_back(new double{v});
  }
  // deallocazione
  for (auto &v : contenitore2) {
    delete v;
  }
}

struct MyVectorOfInt {
  // Initializer list permette di passare più valori al costruttore
  MyVectorOfInt(const std::initializer_list<int> &values) {
    std::cout << "Capacità attuale: " << data.capacity() << '\n';
    data.reserve(values.size());
    std::cout << "Capacità attuale: " << data.capacity() << '\n';
    for (const auto &v : values) {
      data.push_back(v);
    }
    std::cout << "MyVectorOfInt(const std::initializer_list<int> &values)\n";
  }

  // Preallochiamo la memoria
  MyVectorOfInt(int i) {
    std::cout << "Capacità attuale: " << data.capacity() << '\n';
    data.reserve(i);
    std::cout << "Capacità attuale: " << data.capacity() << '\n';
    std::cout << "MyVectorOfInt(int i)\n";
  }

  void aggiungi(int i) {
    auto capacity_prima{data.capacity()};
    data.push_back(i);
    if (data.capacity() != capacity_prima) {
      std::cout << "Riallocazione: Elementi: " << data.size()
                << " Capacità attuale: " << data.capacity() << '\n';
    }
  }

private:
  std::vector<int> data;
};

void standardlibrary_run() {
  MyVectorOfInt mvi{1, 2, 3, 4, 5, 6, 7, 8, 9};
  MyVectorOfInt k{1}; // con le "graffe" il costruttore che accetta una
                      // initializer list ha la precedenza
  for (int i{0}; i < 10000; ++i) {
    k.aggiungi(i);
  }

  MyVectorOfInt k2(10000);
  for (int i{0}; i < 10000; ++i) {
    k2.aggiungi(i);
  }

  // https://en.cppreference.com/w/cpp/container/list
  std::list<MyVectorOfInt> lista_concatenata;

  // https://en.cppreference.com/w/cpp/container/map
  std::map<std::string, unsigned int> compleanno;

  compleanno["paolo"] = 1988;
  compleanno["giovanni"] = 1989;
  compleanno["giacomo"] = 1966;
  std::cout << "Elementi: " << compleanno.size() << '\n';
  if (compleanno.count("aldo") && compleanno["aldo"] == 1978) {
    std::cout << compleanno["aldo"] << '\n';
  }

  // Iterazione
  for (const auto &kv : compleanno) {
    std::cout << "Nome: " << kv.first << " Anno di nascita: " << kv.second
              << '\n';
  }

  // esempio con structured binding (tema avanzato)
  for (const auto &[nome, anno] : compleanno) {
    std::cout << "Nome: " << nome << " Anno di nascita: " << anno << '\n';
  }

  std::cout << "Elementi: " << compleanno.size() << '\n';
  compleanno.erase("paolo");
  std::cout << "Elementi: " << compleanno.size() << '\n';
}