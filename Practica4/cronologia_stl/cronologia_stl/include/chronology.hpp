/**
 * @file Cronology.hpp
 * @brief Fichero cabecera del TDA Chronology
 * @author Sofía Almeida Bruno (@SofiaAlmeida)
 * @author Jesús Sánchez de Lechina Tejada (@jojelupipa)
 * @author Pedro Bonilla Nadal (@pedrobn23)
 */

#ifndef __CHRONOLOGY
#define __CHRONOLOGY

#include "historic_event.h"
#include <iostream>
#include <map>

/**
 * @brief T.D.A. Chronology
 *
 * Una instancia @e h del tipo de datos abstracto @c Chronology se compone
 * de un conjunto de eventos históricos. Ver documentación de historic_event para más información.
 *
 * Un ejemplo de su uso:
 * @include ../src/pruebacronologia.cpp
 * @include ../src/union_cronologia.cpp
 */

class Chronology {
  
 private:
  /**
   * @page repConjunto Rep del TDA Chronology
   *
   * @section invConjunto Invariante de la representación
   *
   * El invariante es \e h.second no válido (consultar historic_event.h)
   *
   * @section faConjunto Función de abstracción
   *
   * Un objeto válido @e rep del TDA Chronology representa
   *
   *  
   * events[0].first#events[0].second[0]#...#events[0].secind[events.second.size()-1]
   *  ...
   *
   */

  map<int, HistoricEvent> events; /**<map de HistoricEvent>**/

 public:
  /**
   * @brief Constructor por defecto de la clase.
   */
  Chronology() {}

  /**
   * @brief Crea una cronología a partir de otra
   * @param chrono
   * @return Cronología con las propiedades de la anterior
   */
  Chronology(const Chronology& chrono);

  /**
   * @brief Constructor
   * @param h Vector de eventos
   * @return Cronología con vector de eventos h
   */
  Chronology(vector<HistoricEvent> h);

  typedef map<string, HistoricEvent>::iterator iterator;
  typedef map<string, HistoricEvent>::const_iterator const_iterator;

  /**
   * @brief Primer elemento del map
   * @return Iterador señalando al primer elemento
   */
  iterator begin() {return events.begin();}

  /**
   * @brief Primer elemento del map
   * @return Iterador constante señalando al primer elemento
   */
  const_iterator cbegin() const {return events.cbegin();}

  /**
   * @brief Último elemento del map
   * @return Iterador señalando al último elemento
   */
  iterator end() {return events.end();}

  /**
   * @brief Último elemento del map
   * @return Iterador constante señalando al último elemento
   */
  const_iterator cend() const {return events.cend();}

  /**
   * @brief Eventos
   * @return Devuelve un map de eventos Históricos
   */
  map<int, HistoricEvent> get_events() const {return events;};

  /**
   * @brief Obtiene un set con los acontecimientos de un año
   * @param date Año a buscar
   * @return set de acontecimientos del año date
   */
  set<string> get_befalls(int date);

  /**
   * @brief Inserta un evento en su posición correspondiente
   * @param date Fecha del evento
   * @param s Nombre del evento
   * @return Void
   */
  void insert_befall(int date, const string &s);

  /**
   * @brief Añade un HistoricEvent a la cronología
   * @param h Evento a añadir
   * @return Void
   */
  bool insert_event(const HistoricEvent &h);

  /**
   * @brief Borra un evento
   * @param date Fecha del evento a borrar
   * @return Void
   */
  void rm_event(int date);

  /**
   * @brief Eventos anteriores
   * @param d Año hasta el que guardar los eventos
   * @return Map con los eventos correspondientes
   */
  Chronology prev_events(int d);

  /**
   * @brief Eventos posteriores
   * @param d Año a partir del cual se buscan los eventos
   * @return Map con los eventos correspondientes
   */
  Chronology post_events(int d);

  /** @brief  Eventos en un rango
   * @param inf Extremo inferior de la búsqueda (fecha)
   * @param sup Extremo superior de la búsqueda (fecha)
   * @return Map con los eventos correspondientes
   */
  Chronology range(int inf, int sup);
  
  /**
   * @brief Busca los eventos en que se encuentra la palabra dada.
   *        Además, puede mostrar dichos eventos
   * @param s Palabra/s a buscar
   * @param be_shown si es true se mostrarán los eventos
   * @return Chronology con los eventos que contienen a s
   */
  Chronology word_search(const string &s, bool be_shown);

  /**
   * @brief Unir de forma ordenada dos cronologías
   * @param c Cronología a unir con la implícita
   * @return Cronología mezclada y ordenada
   */
  Chronology& operator+(const Chronology &c);
  
  /**
  * @brief Sobrecarga del operator []
  * @param d Año de la posición a devolver
  * @return HistoricEvent con el año d
  */
  HistoricEvent& operator[](unsigned int d) {return events[d];}

  /**
   * @brief Sobrecarga del operador de asignación
   * @param c Cronología a asignar
   * @return Referencia a cronología asignada 
   */
  Chronology& operator=(const Chronology &c) {events = c.events;}
  
  /**
   * @brief Sobrecarga del operador <<
   * @param os Flujo de salida
   * @param c Cronología a mostrar
   * @return Muestra una cronología con el formato:
   *         events[0].first#events[0].second[0]#...#events[0].secind[events.second.size()-1]
   *         ...
   */
  friend ostream& operator<<(ostream &os, const Chronology &c);

  /**
   * @brief Sobrecarga del operador >>
   * @param is Flujo de entrada
   * @param c Cronología a escribir
   * @return Flujo de entrada
   */
  friend istream& operator>>(istream &is, Chronology &c);
};

#endif
